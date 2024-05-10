#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* Se encarga de transformar una línea del archivo de texto
en los datos correspondientes. Para ello extrae los tokens
y los convierte al tipo adecuado*/

void extraeDatos(char *linea, char *tipo, int *modelo, double *precio){
	char *cadModelo, *cadPrecio, *delimit;
	delimit=strtok(linea,",;"); //Lee la linea, teniendo en cuenta estos delimitadores ",;" y guarda en delimit
	strcpy(tipo,delimit); //Copia el delimit a la variable tipo (que ya se guarda en la original por que es un puntero), esto es para las primeras letras del archivo
	cadModelo=strtok(NULL,";"); //Hago lo mismo para el puntero a modelo, que seria la segunda columna del archivo
	*modelo=atoi(cadModelo); //Y lo convierto a un numero, guardando el valor en lo que pasamos como una direccion
	cadPrecio=strtok(NULL,";"); //Idem para la tercer columna
	*precio=atof(cadPrecio); //Pero en este caso es un float
}

int main(){
	FILE *pArchivo=fopen("piezas.csv","r");
	char tipo[3]; //Aca van a ir mis delimitadores
	char linea[2000]; //Para leer la linea
	int modelo;
	double precio;
	if(pArchivo!=NULL) {
		fgets(linea,2000,pArchivo); //Lee la primer linea?
		while(!feof(pArchivo)) {
			extraeDatos(linea,tipo,&modelo,&precio);
			printf("%s %d %lf\n",tipo,modelo,precio);
			fgets(linea,2000,pArchivo); //No entiendo este fgets, lee la 2da linea?
		}
		fclose(pArchivo);
	}
	system("pause");
	return 0;
}

