#---------------------------------------------------
#               LIBRERIAS IMPORTADAS
#---------------------------------------------------
from kivy.app import App
from kivy.uix.widget import Widget
from kivy.uix.button import Button
from kivy.uix.boxlayout import BoxLayout
from kivy.uix.label import Label
from kivy.uix.slider import Slider
from kivy.graphics import Color, Line, Rectangle
from kivy.core.window import Window
from kivy.uix.filechooser import FileChooserIconView
from kivy.uix.popup import Popup
from kivy.uix.textinput import TextInput

#-----------------------------------------------------------------------
#                           FONDO DE LOS BOTONES
#-----------------------------------------------------------------------
# define el back de los botones
class ColoredBoxLayout(BoxLayout):
    def __init__(self, **kwargs):
        super(ColoredBoxLayout, self).__init__(**kwargs)
        with self.canvas.before:
            # Establece el color de fondo a verde azulado
            Color(0, 0.5, 0.5, 1)
            self.rect = Rectangle(pos=self.pos, size=self.size)
            self.bind(pos=self.actualizaRect, size=self.actualizaRect)

    # back de los botones
    def actualizaRect(self, *args):
        self.rect.pos = self.pos
        self.rect.size = self.size

#-----------------------------------------------------------------------------
#                           VENTANA DE DIBUJO (SECUNDARIA)
#-----------------------------------------------------------------------------
# Ventana principal
class MyPaintWidget(Widget):
    def __init__(self, **kwargs):
        super(MyPaintWidget, self).__init__(**kwargs)
        self.colorTrazo = (1, 0, 0)  # Color de línea predeterminado a rojo en RGB
        self.anchoTrazo = 2  # Ancho de línea predeterminado
        with self.canvas:
            # Establece el color de fondo a blanco
            Color(1, 1, 1, 1)
            self.rect = Rectangle(pos=self.pos, size=self.size)
            self.bind(pos=self.actualizaRect, size=self.actualizaRect)

    def actualizaRect(self, *args):
        self.rect.pos = self.pos
        self.rect.size = self.size

    #----------------------------------------------------------------------------------
    #                                 TRAZOS DE DIBUJO
    #----------------------------------------------------------------------------------
    # Primer paso al trazado de lineas con el mouse clickeado (on_touch_down)
    def on_touch_down(self, touch):
        if self.collide_point(touch.x, touch.y):  # Dentro de la ventana? entonces:
            with self.canvas:
                # Color segun seleccion actual
                Color(*self.colorTrazo)
                # Nueva línea en la posición del toque inicial
                touch.ud['line'] = Line(points=(touch.x, touch.y), width=self.anchoTrazo)

    # Desplazamiento del mouse
    def on_touch_move(self, touch):
        if self.collide_point(touch.x, touch.y):
            # Añade los nuevos puntos a la línea existente
            touch.ud['line'].points += [touch.x, touch.y]

#-----------------------------------------------------------------------------
#                               VENTANA PRINCIPAL
#-----------------------------------------------------------------------------
# Defino ventana principal
class MyPaintApp(App):
    def build(self):
        Window.size = (800, 600)  # Tamanio
        ventanaPrincipal = BoxLayout(orientation='vertical')
        self.painter = MyPaintWidget()  # Lienzo

        # Panel de colores y trazo
        muestraBoton = ColoredBoxLayout(size_hint_y=None, height=50)

        # boton de clear
        botonClear = Button(text='Limpiar')
        botonClear.bind(on_release=self.limpiaPantalla)
        muestraBoton.add_widget(botonClear)

        # Define los botones para cambiar el color de la línea
        colorEncabezado = {
            'Rojo': (1, 0, 0),
            'Verde': (0, 1, 0),
            'Azul': (0, 0, 1),
            'Amarillo': (1, 1, 0),
            'Violeta': (0.5, 0, 0.5),
            'Negro': (0, 0, 0)
        }
        for etiquetaColores, colorEtiqueta in colorEncabezado.items():
            boton = Button(text=etiquetaColores)
            # Vincula cada botón a la función para cambiar el color
            boton.bind(on_release=lambda instance, color=colorEtiqueta: self.colores(color))
            muestraBoton.add_widget(boton)

        # Panel del slider
        anchoCursor = ColoredBoxLayout(size_hint_y=None, height=50)
        anchoCursorBarra = Label(text='Ancho:', size_hint_x=None, width=100)  # Etiqueta del slider
        anchoCursor.add_widget(anchoCursorBarra)

        self.slider = Slider(min=1, max=10, value=2)
        self.slider.bind(value=self.tamanioCursor)
        anchoCursor.add_widget(self.slider)

        # Boton de guardado
        botonGuardado = Button(text='Guardar')
        botonGuardado.bind(on_release=self.ventanaDeGuardado)  # Vincula el boton a la funcion de popup
        muestraBoton.add_widget(botonGuardado)

        ventanaPrincipal.add_widget(muestraBoton)
        ventanaPrincipal.add_widget(anchoCursor)
        ventanaPrincipal.add_widget(self.painter)

        return ventanaPrincipal
    #-----------------------------------------------------------------------------
    #                           FUNCION DEL BOTON CLEAR  
    #-----------------------------------------------------------------------------
    def limpiaPantalla(self, obj):
        self.painter.canvas.clear()
        with self.painter.canvas:
            # Restablece
            Color(1, 1, 1, 1)
            self.painter.rect = Rectangle(pos=self.painter.pos, size=self.painter.size)
            self.painter.bind(pos=self.painter.actualizaRect, size=self.painter.actualizaRect)

    #-----------------------------------------------------------------------------
    #                     FUNCION DE DEFINICION DEL COLOR DEL TRAZO  
    #-----------------------------------------------------------------------------
    def colores(self, color):
        self.painter.colorTrazo = color

    #-----------------------------------------------------------------------------
    #                           FUNCION DEL ANCHO DEL TRAZO  
    #-----------------------------------------------------------------------------
    def tamanioCursor(self, instance, value):
        self.painter.anchoTrazo = value

    #-----------------------------------------------------------------------------
    #                     FUNCION DE GUARDADO CON VENTANA EMERGENTE
    #-----------------------------------------------------------------------------
    def ventanaDeGuardado(self, instance):
        contenido = BoxLayout(orientation='vertical')
        ubicacionGuardado = FileChooserIconView()
        contenido.add_widget(ubicacionGuardado)

        nombreArchivo = TextInput(text='DibujoEnKivy.png', multiline=False, size_hint_y=None, height=30)
        contenido.add_widget(nombreArchivo)

        botonGuardado = Button(text='Save', size_hint_y=None, height=50)
        botonGuardado.bind(on_release=lambda x: self.save_canvas(ubicacionGuardado.path, nombreArchivo.text))
        contenido.add_widget(botonGuardado)

        emergente = Popup(title='Guardar', content=contenido, size_hint=(0.9, 0.9))
        emergente.open()

    def save_canvas(self, path, filename):
        self.painter.export_to_png(f"{path}/{filename}")

if __name__ == '__main__':
    Applicacion = MyPaintApp()
    Applicacion.run()