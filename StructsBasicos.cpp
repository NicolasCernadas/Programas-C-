# include <stdlib.h>
# include <stdio.h>

//Declaracion de un STRUCT
//struct <nombre del struc>
//{
//
//    tipo nombrevariable
//    tipo nombrevariable2
//    ...
//
//}; cierro con punto y coma

struct alumno //struct cargado por programador
{
    char nombre[10];
    char apellido[10];
    int edad;
};

struct alumno_a_mano //struct cargado por consola
{
    char nombre2[10];
    char apellido2[10];
    int edad2;
};

//Tambien los podemos anidar:
struct fecha {
    int dia, anio;
    char mes[10];
};
struct vuelo {
    char origen[5];
    char destino[5];
    int duracion;
    float precio;
    struct fecha date;
};

int main() {
    int decision;
    //Podemos declarar de 2 maneras, seguido de la declaracion del array del struct (array a partir de la estructura):
    struct alumno alumno1 = {"Lionel","Messi",38};
    printf("%d\n",alumno1.nombre); //Si lo quiero llamar, lo traigo con el nombre del struct.<campo_a_traer>

    //O por consola:
    struct alumno_a_mano alumno2;
    printf("Ingresa primero el nombre, despues el apellido y despues la edad: (todo con enter de por medio)\n");
    scanf("%s",alumno2.nombre2);
    scanf("%s",alumno2.apellido2);
    scanf("%d",&alumno2.edad2); //Ahora si ponemos el '&', por que es una variable de tipo entero

    //Structs anidados:
    struct vuelo vuelo1;

    printf("Ingresa:\n1: Si queres ingresar el origen\n2: Si queres ingresar las fechas\n");
    printf("Seleccion: ");
    scanf("%d",&decision);

    switch (decision)
    {
        case 1: {
            printf("Ingresa el Origen de partida: ");
            scanf("%s",vuelo1.origen);
            printf("Origen de vuelo: %s", vuelo1.origen);
            break;
        }
        case 2: {
            printf("Ingresa primero el dia, despues el mes, y despues el anio\n");
            scanf("%d",&vuelo1.date.dia); // Dentro de la variable 'vuelo1', dentro de 'date', guardo el dia
            scanf("%s",vuelo1.date.mes); // "      "           "                  ", guardo el mes
            scanf("%d",&vuelo1.date.anio); // "      "           "                  ", guardo el anio
            printf("Dia: %d, Mes: %s, Anio: %d",vuelo1.date.dia,vuelo1.date.mes, vuelo1.date.anio);
            break;
        }
    }

    return 0;
}
