# include <stdio.h>
# include <stdlib.h>

// FUNCIONES VARIAS EN BINARIOS

int main() {
	FILE * pArchivo;
	int registro, posicion,registro2;

	pArchivo = fopen("datos.dat", "ab+");
	if (pArchivo == NULL) {
		exit(1);
	} else {
	    //FSEEK( 1°, 2°, 3°)
	    // 1) El archivo donde nos vamos a mover
	    // 2) La cantidad de bytes que nos vamos a mover
	    // 3) Dependiendo del parametro, como se va a comportar FSEEK:
	    // SEEK_SET: Nos posicionamos al principio del archivo,esto hace que nos movamos la cantidad de bytes determinada en el 2° parametro, pero DESDE EL PRINCIPIO DEL ARCHIVO.
	    // SEEK_END: Nos posicionamos al final del archivo, idem anterior, pero desde el final (2°parametro con '-x', retrocedera desde el final)
	    // SEEK_CUR: Se desplaza a partir de donde este el cursor, si anteriormente nos habiamos posicionado en el 5to byte y hacemos:
        //  fseek(archivo, 5, SEEK_CUR) = terminaremos en el 10mo byte.
	    //
		fseek(pArchivo,0, SEEK_END); //Posicionamos el puntero al final del archivo //preguntar por el '0'
		registro = ftell(pArchivo)/sizeof(int); //Lo dividimos por el tamanio de las variables, por que el ftell() nos dice que tamanio tiene el archivo en bytes.
		printf("Numero de registros en el archivo: %d\n", registro);
		//Leer una posicion en especifico
		fseek(pArchivo, 3*sizeof(int), SEEK_SET); //por que hay que multiplicar por sizeof(tipo)?
		fread(&registro, sizeof(int),1,pArchivo); //Leo la posicion en la que esta el puntero, y la guardo en la variable 'registro'
		printf("4to valor: %d\n", registro);
		//Modificar una posicion en especifico
		fseek(pArchivo, 0, SEEK_SET); //Me posiciono al principio == idem que rewind(archivo)
		printf("Que posicion queres modificar?: ");
		scanf("%d", &posicion);//Una vez posicionado donde quiero cambiar el dato:
		fflush(stdin);
		printf("Por que valor queres cambiarlo?: ");
		scanf("%d", &registro2);
		fseek(pArchivo, posicion*sizeof(int),SEEK_SET); //Me posiciono en la celda para leer el dato
		fread(&registro, sizeof(int),1,pArchivo);       //Y guardarlo en registro.
		printf("Valor anterior de la %d celda: %d\n", posicion+1, registro);
		fseek(pArchivo, posicion*sizeof(int), SEEK_CUR); //Me posiciono en la celda para cambiar el dato
		registro = registro2;
		fseek(pArchivo, -sizeof(int), SEEK_CUR);        //Desde donde estoy, retrocedo una determinada cantidad de bytes para cambiar el dato, SEEK_SET y SEEK_CUR nos dejan una posicion mas adelante de la leida
		fwrite(&registro, sizeof(int),1, pArchivo);     //Sobreescribo el dato;
		printf("Valor de la %d posicion: %d\n", posicion+1, registro);
        //
        fclose(pArchivo);
	}
	return 0;
}

