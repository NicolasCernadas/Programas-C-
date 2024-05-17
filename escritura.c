//FUNCION DE RECORRIDO
//Recorre todo el archivo desde el principio, si coincide el orden, emite falla.
int verifica_orden(int x, FILE * xx, creditos personas[]);
int verifica_orden(int x, FILE * xx, creditos personas[]) {
	int i, flag;
	xx = fopen("pruebas.dat","ab+");
    if (xx == NULL) {
        printf("Ocurrio un error inesperado...Intentelo nuevamente.");
        exit(1);
    } else {
    	rewind(xx);
    	i = 0;
    	flag = 0;
    	fread(&personas[i],sizeof(personas),1,xx);
        while(!feof(xx)) {
            if (personas[i].orden == x) {
                printf("\nEse numero de orden ya esta registrado a otro nombre, elija uno nuevo\n");
                flag = 1;
                break;
            }
            i++;
            fread(&personas[i],sizeof(personas),1,xx);
        }
        fclose(xx);
    }
    return flag;
}
//FUNCION DE AMPLIACION DE MEMORIA
//Amplia la memoria dinamica en base al orden buscado
void amplia_memoria(int t, int x, creditos personas[]);
void amplia_memoria(int t, int x, creditos personas[]) {
	char opcion;
	do {
		printf("\nNumero de orden validado, queres generar un espacio para un cliente nuevo? (y/n): ");
		scanf("%d",&opcion);
		if ((opcion!='Y')&&(opcion!='y')&&(opcion!='N')&&(opcion!='n')) {
			printf("Esa no es una opcion valida, por favor, ingresa Y para si, o N para no.");
		}
	}while((opcion!='Y')&&(opcion!='y')&&(opcion!='N')&&(opcion!='n'));
	if ((opcion == 'Y') || (opcion == 'y')) {
		personas = (creditos*)realloc(personas, x*sizeof(creditos));
		carga_ceros(xx, personas);
	}
}
void carga_ceros(FILE * xx, creditos personas[]) {
	xx = fopen("pruebas.dat", "ab+");
	if (xx == NULL) {
		printf("Ocurrio un error inesperado...Intentalo denuevo mas tarde.\n");
		exit(1);
	} else {
		fseek(xx, )

	}
}