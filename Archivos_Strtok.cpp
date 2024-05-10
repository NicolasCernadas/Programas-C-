# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int main() {
	char array[] = "Esto, es una prueba. Para mas, hacer mas ejemplos.";
	char delimitadores[] = ",.";
	//Con esto y el strtok, vamos a leer cadenas hasta ciertos delimitadores definidos por nosotros.
	char * token;

	printf("Texto inicial (sin strtok): %s\n", array);

	//Guardo en el token los delimitadores, y de que texto (o archivo) los vamos a sacar:
	token = strtok(array, delimitadores);

	//Obtenemos el resto de tokens. (SIEMPRE pasamos NULL como primer parametro, para no borrar lo anterior)
	do {
		printf("%s\n", token);
		token = strtok(NULL, delimitadores);
	} while(token != NULL);
	getchar();

return 0;
}
