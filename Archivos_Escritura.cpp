# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int main() {
	int num;
	char frase[50];
	FILE * pfile;

	pfile = fopen("Archivo_de_Escritura.txt", "w");
	if (pfile == NULL) {
		printf("No se pudo abrir el archivo.\n");
		exit(1);
	}
	do {
		printf("Introduce un numero por teclado: ");
		scanf("%d",&num);
		if (num != 0) {
			if ((num%2)==0) {
				fprintf(pfile,"%d\n",num);
			}
		}
	} while (num!=0);
	fflush(stdin);
	printf("Introduce ahora una frase: ");
	fgets(frase, 50, stdin);
	fflush(stdin);
	fprintf(pfile, "%s\n",frase);

	fclose(pfile);
	rewind(pfile);

return 0;
}
