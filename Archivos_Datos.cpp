# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct {
	char * nombre;
	int edad;

}trabajadores;

trabajadores *trab;

void vaciar(char x[]); //Limpia el array
void copiar(char x[], int i); //Genera los espacios de memoria y copia los arrays

int main() {
	char aux;
	int cont = 0;
	char nombre[50];
	FILE * pfile;

	pfile = fopen("trabajadores.txt","r");
	if (pfile == NULL) {
		printf("No se pudo abrir el archivo\n");
		exit(1);
	}
	while (!feof(pfile)) {
		fgets(nombre,50,pfile); //Lee la primera linea, suma 1 al contador, lee la segunda...y asi sucesivamente (esto para saber de cuantas posiciones generar el array)
		cont++;
	}
	rewind(pfile); //Volvemos el cursor al inicio o en cualquiera sea la posicion en la que haya terminado

	//Creo el array con esa cantidad
	trab = (trabajadores*)malloc(cont*sizeof(trabajadores));
	if (trab == NULL) {
		printf("No se pudo reservar la memoria\n");
		exit(1);
	}
	//Cargo lo del archivo al cmd
	for (int i=0; !feof(pfile); i++) {
		vaciar(nombre); //Ya la habiamos llenado para contar las lineas
		aux = '0';
		for (int j=0; aux != '-'; j++) {
			aux = fgetc(pfile);
			if (aux != '-') {
				nombre[j] = aux;
			}
		}
		copiar(nombre,i); //Le paso la variable, y el contador del for
		//Aprovechando que el cursor ahora se encontraria despues del '-', lo que hacemos es tomar todo lo que queda de linea, pero como no
		//queremos agarrar 50 caracteres xq solo tenemos 2 numeros, el cambio de linea y el enter, ponemos un 4.
		fgets(nombre,4,pfile);
		trab[i].edad = atoi(nombre);
		printf("Nombre: %s\nEdad: %d\n=====\n",trab[i].nombre, trab[i].edad);
	}


return 0;
}

void vaciar(char x[]) {
	for (int i=0; i<50; i++) {
		x[i] = '\0'; //Limpio individualmente cada espacio
	}
}
void copiar(char x[], int i) {
	int N = strlen(x) + 1; //Cantidad de caracteres en la variable, mas el \n
	trab[i].nombre = (char*)malloc(N*sizeof(char)); //Reservo memoria para el array
	if (trab[i].nombre == NULL) {
		printf("No se pudo reservar la memoria.\n");
		exit(1);
	}
	strcpy(trab[i].nombre, x);


}
