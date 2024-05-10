# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int main() {
	FILE * pfile;
	char frase[100];
	char caracter;
	pfile = fopen("Archivo_de_Escritura.txt", "a+");
	if (pfile != NULL) {
		printf	("Apertura de Archivo exitosa.-\n\n");

	}
	 else {
		printf("Algo fallo, intentalo nuevamente.-\n");
	}

	//	Leido caracter a caracter:
	 printf("Leido caracter por caracter: \n");
	 while (caracter != EOF) { //EOF = final del archivo
	 	caracter = fgetc(pfile);
	 	printf("%c", caracter);
	 }
	 rewind(pfile);
	 getchar();

	//	Para leer por linea:
	printf("Leido de a lineas: \n");
	while (!feof(pfile)) {
		if (fgets(frase, 100, pfile)) {
			printf("%s", frase);
		}
	}
	fclose(pfile);
	getchar();
return 0;
}
