# include <stdio.h>
# include <stdlib.h>

int main() {
     //Declaro una variable puntero para el fichero
     FILE * pArchivo;
     char aux;
     char aux2[100];
     char nombre[] = "Archivo.txt";

     //Para abrir el archivo, necesito usar la siguiente funcion con 2 parametros
     pArchivo = fopen(nombre, "r"); // 'r': Abre un archivo para lectura. Si no existe devuelve error.
                                                                     // ' w': Abre un archivo para escritura. Si el fichero no existe crea uno nuevo, si ya existe lo elimina y genera uno nuevo.
                                                                     // 'a': Abre un archivo para añadir datos al final. Si no existe se crea.
     if (pArchivo == NULL) {
          printf("No se pudo abrir el archivo.");
          exit(1);
     }

     //Metodo para leer un archivo caracter a caracter
     while (aux != EOF) { //empieza a recorrer los caracteres del texto, cuando llega al EOF, sale del bucle
          aux = fgetc(pArchivo);
          printf("%c",aux);
     }
     printf("\n");
     fclose(pArchivo);

     //Metodo para leer un archivo con una cadena de caracteres
     pArchivo = fopen(nombre, "r");
     if (pArchivo == NULL) {
          printf("No se pudo abrir el archivo.");
          exit(1);
     }
     while (!feof(pArchivo)) { // '!' => NOT feof (pArchivo)
          fgets(aux2,100,pArchivo);
          printf("%s", aux2);
     }
     printf("\n");
     fclose(pArchivo);




return 0;
}
