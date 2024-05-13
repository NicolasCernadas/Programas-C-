# include <stdio.h>
# include <stdlib.h>

// FUNCIONES VARIAS EN BINARIOS

int main() {
	FILE * pArchivo;
	int registro;

	pArchivo = fopen("datos.dat", "ab+");
	if (pArchivo == NULL) {
		exit(1);
	} else {
		fseek(pArchivo,0, SEEK_END); //Posicionamos el puntero al final del archivo //preguntar por el '0'
		registro = ftell(pArchivo)/sizeof(int);
		printf("Numero de registros en el archivo: %d", registro);
		fclose(pArchivo);
	}
	return 0;
}

