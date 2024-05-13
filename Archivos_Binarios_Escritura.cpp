# include <stdio.h>
# include <stdlib.h>

//ESCRITURA EN ARCHIVOS BINARIOS

int main() {
	FILE * pArchivo;
	int num;
	pArchivo = fopen("datos.dat", "wb+");
	if (pArchivo == NULL) {
		printf("ocurrio un error inesperado...intentelo nuevamente");
		exit(1);
	} else {
		do {
			printf("ingresa un numero (0 para terminar): ");
			scanf("%d",&num);
			if (num != 0) {
				fwrite(&num, sizeof(int),1,pArchivo); //escritura de en un archivo, con la direccion de la variable a escribir, el tamanio, la cantidad de caracteres, y donde escribirlo.
			} else {}
		}while (num != 0);
		fclose(pArchivo);
	}
	return 0;
}

////LECTURA DE ARCHIVOS BINARIOS

//int main() {
//	FILE * pArchivo;
//	int num;
//	pArchivo = fopen("datos.dat", "rb+");
//	if (pArchivo == NULL) {
//		printf("Ocurrio un error inesperado...Intentelo nuevamente");
//		exit(1);
//	} else {
//		fread(&num, sizeof(int),1,pArchivo);
//		while (!feof(pArchivo)) {
//			printf("%d\n", num);
//			fread(&num, sizeof(int),1,pArchivo);
//		}
//		fclose(pArchivo);
//	}
//	return 0;
//}
