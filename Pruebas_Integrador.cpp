# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct {
    int orden, dia, mes, anio, cuotas, importe;
    char cliente[40], electro[20];
    float impCuota, Iva, totalCuota;
}creditos;


void bienvenida();
void menu(FILE * punteroArchivoBin, FILE * punteroArchivo, char * lineaTexto, creditos * personas);
void imprime_creditoscsv(FILE * x, char * y);
void vaciar_cadena(char * y);
void extrae_datos(FILE * f,char * y, char * o);
void genera_binario(FILE * x);
void carga_binario(FILE * xx, FILE * x, char * nombre, char * lineaTexto, creditos * personas);
void lee_binario(FILE * xx, char * y, creditos * personas);
void nuevos_clientes(FILE * xx, char * y, creditos * personas);
void lista_binario(FILE * xx, creditos * personas);
void lista_heladera(FILE * xx, creditos * personas);
void lista_televisor(FILE * xx, creditos * personas);
void lista_lavarropa(FILE * xx, creditos * personas);
int verifica_orden(int x, FILE * xx, creditos * personas);
//Pruebas
void genera_cliente(int ord, FILE * xx, creditos * personas);


int main() {
    FILE * ptfile;
    FILE * pbfile;
    char linea[2000];

    creditos personas[17];
    bienvenida();
    menu(pbfile, ptfile, linea, personas);

    printf("\n");
    return 0;
}
void bienvenida() {
    printf("-- Bienvenida al primer trabajo integrador --\n\n");
    printf("Alumno: Cernadas, Nicolas\nComision: C-TI04\nFecha de entrega: 20/05/2024\n");
    printf("Archivos utilizados: Creditos .csv\n\n");
    printf(" # Aclaraciones # \n Para una mejor visualizacion del trabajo, se recomienda maximizar el tama%co de la consola de comando.\n\n",164);
    printf("===================================================\n\n");
}
void menu(FILE * punteroArchivoBin, FILE * punteroArchivo, char * lineaTexto, creditos * personas) {
    int flag = 0, flag2 = 0, flag3 = 0;
    char * nombre;
    int opcion;
    char s;
    do{
        do{
        printf("\n -- Menu de opciones -- \n1)Para imprimir el archivo: 'creditos.csv' original\n2)Para generar el archivo binario\n3)Para pasar los datos del .txt al .dat\n4)Para imprimir el archivo.dat\n5)Para agregar nuevos clientes\n0)Para salir del menu de opciones\nSeleccion => ");
        fflush(stdin);
        scanf("%d", &opcion);
        if ((opcion != 1) && (opcion != 2) && (opcion != 3) && (opcion != 4) && (opcion != 5) && (opcion != 0)) {
            printf("\nIngresa una opcion valida.");
            printf("\n");
        }
        }while((opcion != 1) &&( opcion != 2) && (opcion != 3) && (opcion != 4) &&( opcion != 5) && (opcion != 0));
        printf("\n");
        switch(opcion) {
            case 0: {
                printf("Hasta la proxima!");
                printf("\n");
                getchar();
                exit(0);
            } break;
            case 1: {
                imprime_creditoscsv(punteroArchivo, lineaTexto);
                printf("\n");
            } break;
            case 2: {
                flag = 1;
                genera_binario(punteroArchivoBin);
                getchar();
            } break;
            case 3: {
                if (flag == 0) {
                    printf("Todavia no generaste el archivo...No tenemos donde cargar los datos!\n");
                } else {
                    flag2 = 1;
                    carga_binario(punteroArchivoBin, punteroArchivo, nombre, lineaTexto, personas);
                    getchar();
                }
            } break;
            case 4: {
                if (flag == 0) {
                    printf("Todavia no generaste el archivo!\n");
                } else if (flag2 == 0) {
                    printf("Aun no hay datos cargados en el archivo.-\n");
                } else {
                    lee_binario(punteroArchivoBin,lineaTexto, personas);
                    getchar();
                }
            } break;
            case 5: {
                nuevos_clientes(punteroArchivoBin, lineaTexto, personas);
                getchar();
            }
            case 6: {

            }
            case 7: {

            }
        }
        do {
            printf("\nDesea continuar? (y/n): ");
            fflush(stdin);
            scanf("%c",&s);
            if ((s!='y') && (s!='Y') && (s!='n') && (s!='N')) {
                printf("\nIngresa: Y o y para continuar, N o n para salir.\n");
            }
        }while((s!='y') && (s!='Y') && (s!='n') && (s!='N'));
    }while ((s=='y')||(s=='Y'));
}
//Imprimo para visualizacion del archivo: creditos.txt
void imprime_creditoscsv(FILE * x, char * y) {
    char * token, * token1, * token2, * token3, * token4, * token5, * token6, * token7, * token8, * token9, * token10, * token11;
    x = fopen("creditos.txt", "r");
    if (x != NULL) {
        printf(" -- Creditos.CSV -- \n\n");
        while(!feof(x)) {
            fgets(y, 2000, x); //Lee la primer linea del archivo
            token = strtok(y, ",;"); //Guarda hasta el primer ';'
            token1 = strtok(NULL, ";"); //guarda hasta el segundo ';'
            token2 = strtok(NULL, ";"); //guarda hasta el tercero ';'
            token3 = strtok(NULL, ";"); //idem para el resto
            token4 = strtok(NULL, ";");
            token5 = strtok(NULL, ";");
            token6 = strtok(NULL, ";");
            token7 = strtok(NULL, ";");
            token8 = strtok(NULL, ";");
            token9 = strtok(NULL, ";");
            token10 = strtok(NULL, ";");
            token11 = strtok(NULL, ";");
            printf("%5s| %-17s| %-9s| %-12s| %-5s| %-5s| %-7s| %-12s| %-14s| %-10s| %s",
                   token, token1, token2, token3, token4, token5, token6, token7, token8, token9, token10, token11);
            fflush(stdin);
        }
    } else {
        printf("Ocurrio algo inesperado...Intentelo nuevamente");
        exit(1);
    }
    fclose(x);
}
void genera_binario(FILE * xx) {
    xx = fopen("pruebas.dat", "wb");
    if (xx == NULL) {
        printf("Ocurrio un error inesperado...Intentelo nuevamente.\n");
        exit(1);
    } else {
        printf("Archivo generado con exito.\n");
        fclose(xx);
    }
}
void carga_binario(FILE * xx, FILE * x, char * n, char * lineaTexto, creditos * personas) {
    char * token, * token2;
    x = fopen("creditos.txt", "rt");
    xx = fopen("pruebas.dat", "wb+");
    if ((x == NULL) || (xx == NULL)) {
        printf("Ocurrio un error inesperado...Intentalo nuevamente.\n");
        exit(1);
    } else {
        fgets(lineaTexto, 2000, x);
        while(!feof(x)){
            fgets(lineaTexto, 2000, x);
            fseek(xx, 0, SEEK_SET);
            token = strtok(lineaTexto, ";");
            personas->orden = atoi(token);
            token = strtok(NULL, ";");
            strcpy(personas->cliente, token);
            token = strtok(NULL, ";");
            personas->importe = atoi(token);
            token = strtok(NULL, ";");
            strcpy(personas->electro,token);
            token = strtok(NULL, ";");
            personas->dia = atoi(token);
            token = strtok(NULL, ";");
            personas->mes = atoi(token);
            token = strtok(NULL, ";");
            personas->anio = atoi(token);
            token = strtok(NULL, ";");
            personas->cuotas = atoi(token);
            token2 = strtok(NULL,",");
            token = strtok(NULL, ";");
            personas->impCuota = atof(token2) + (atof(token)/100);
            token2 = strtok(NULL,",");
            token = strtok(NULL, ";");
            personas->Iva = atof(token2) + (atof(token)/100);
            token2 = strtok(NULL,",");
            token = strtok(NULL, ";");
            personas->totalCuota = atof(token2) + (atof(token)/100);
            fwrite(&personas,sizeof(personas),1,xx);
        }
        printf("Datos cargados exitosamente.\n");
        fclose(x);
        fclose(xx);
    }
}
//Lee el archivo binario con tipos
void lee_binario(FILE * xx, char * y, creditos * personas) {
    int opcion, opcion2;
    do {
        printf("\n-- Opciones del archivo -- \n\n");
        printf("1)Listar todos\n2)Por nombre del electrodomestico\n0)Para salir\nSeleccion => ");
        fflush(stdin);
        scanf("%d",&opcion);
        if((opcion!= 1)&&(opcion!= 2)&&(opcion!= 3)&&(opcion!= 0)) {
            printf("\nPor favor, selecciona una opcion valida.\n");
        }
        switch(opcion) {
            case 1: {
                lista_binario(xx, personas);
            } break;
            case 2: {
                do {
                    printf("\nElegi el tipo de electrodomestico a visualizar\n1)Heladera\n2)Televisor\n3)Lavarropa\n0)Para volver atras\nSeleccion => ");
                    fflush(stdin);
                    scanf("%d",&opcion2);
                    if ((opcion2 != 1) && (opcion2 != 2) && (opcion2 != 3) && (opcion2 != 0)) {
                        printf("\nPor favor, selecciona una opcion valida.\n");
                    }
                    switch(opcion2) {
                        case 1: {
                            lista_heladera(xx, personas);
                            getchar();
                        } break;
                        case 2: {
                            lista_televisor(xx, personas);
                            getchar();
                        } break;
                        case 3: {
                            lista_lavarropa(xx, personas);
                            getchar();
                        } break;
                    }
                }while(opcion2 != 0);
            } break;
            case 0: {
            } break;
        }
    }while(opcion != 0);
}
//FUNCIONES DE IMPRESION BINARIAS
//BINARIO COMPLETO
void lista_binario(FILE * xx, creditos * personas){
    xx = fopen("pruebas.dat", "rb");
    if (xx == NULL) {
        printf("Ocurrio un error inesperado...Intentelo nuevamente.\n");
        exit(1);
    } else {
        printf("\n");
        rewind(xx);
        fread(&personas, sizeof(personas),1,xx);
        printf("Orden| Cliente          | Importe  | Electro     | Dia  | Mes  | Anio   | Nro.Cuotas  | ImporteCuota  | IVA       | TotalCuota\n");
        while(!feof(xx)) {
            printf("%5d| %-17s| %-9d| %-12s| %-5d| %-5d| %-7d| %-12d| %-14.2f| %-10.2f| %.2f\n",
            personas->orden,personas->cliente,personas->importe,personas->electro,personas->dia,personas->mes,personas->anio,personas->cuotas,personas->impCuota,personas->Iva,personas->totalCuota);
            fread(&personas, sizeof(personas),1,xx);
        }
        fclose(xx);
    }
}
//BINARIOS INDIVIDUALES, 1)HELADERA, 2)TELEVISOR Y 3)LAVARROPA
void lista_heladera(FILE * xx, creditos * personas) {
    xx = fopen("pruebas.dat", "rb+");
    if (xx == NULL) {
        printf("Ocurrio un error inesperado...Intentelo nuevamente.\n");
        exit(1);
    } else {
        rewind(xx);
        printf("\n-- Creditos para 'Heladera' --\n");
        printf("Orden| Cliente          | Importe  | Electro     | Dia  | Mes  | Anio   | Nro.Cuotas  | ImporteCuota  | IVA       | TotalCuota\n");
        fread(&personas, sizeof(personas),1,xx);
        while(!feof(xx)) {
            if ((strcmp(personas->electro,"Heladera")) == 0) {
                printf("%5d| %-17s| %-9d| %-12s| %-5d| %-5d| %-7d| %-12d| %-14.2f| %-10.2f| %.2f\n",
                    personas->orden,personas->cliente,personas->importe,personas->electro,personas->dia,personas->mes,personas->anio,personas->cuotas,personas->impCuota,personas->Iva,personas->totalCuota);
                fread(&personas, sizeof(personas),1,xx);
            } else {
                fread(&personas, sizeof(personas),1,xx);
            }
        }
        fclose(xx);
    }
}
void lista_televisor(FILE * xx, creditos * personas) {
    xx = fopen("pruebas.dat", "rb+");
    if (xx == NULL) {
        printf("Ocurrio un error inesperado...Intentelo nuevamente.\n");
        exit(1);
    } else {
        rewind(xx);
        printf("\n-- Creditos para 'Televisor' --\n");
        printf("Orden| Cliente          | Importe  | Electro     | Dia  | Mes  | Anio   | Nro.Cuotas  | ImporteCuota  | IVA       | TotalCuota\n");
        fread(&personas, sizeof(personas),1,xx);
        while(!feof(xx)) {
            if ((strcmp(personas->electro,"Televisor")) == 0) {
                printf("%5d| %-17s| %-9d| %-12s| %-5d| %-5d| %-7d| %-12d| %-14.2f| %-10.2f| %.2f\n",
                    personas->orden,personas->cliente,personas->importe,personas->electro,personas->dia,personas->mes,personas->anio,personas->cuotas,personas->impCuota,personas->Iva,personas->totalCuota);
                fread(&personas, sizeof(personas),1,xx);
            } else {
                fread(&personas, sizeof(personas),1,xx);
            }
        }
        fclose(xx);
    }
}
void lista_lavarropa(FILE * xx, creditos * personas) {
    xx = fopen("pruebas.dat", "rb+");
    if (xx == NULL) {
        printf("Ocurrio un error inesperado...Intentelo nuevamente.\n");
        exit(1);
    } else {
        rewind(xx);
        printf("\n-- Creditos para 'Lavarropa' --\n");
        printf("Orden| Cliente          | Importe  | Electro     | Dia  | Mes  | Anio   | Nro.Cuotas  | ImporteCuota  | IVA       | TotalCuota\n");
        fread(&personas, sizeof(personas),1,xx);
        while(!feof(xx)) {
            if ((strcmp(personas->electro,"Lavarropa")) == 0) {
                printf("%5d| %-17s| %-9d| %-12s| %-5d| %-5d| %-7d| %-12d| %-14.2f| %-10.2f| %.2f\n",
                    personas->orden,personas->cliente,personas->importe,personas->electro,personas->dia,personas->mes,personas->anio,personas->cuotas,personas->impCuota,personas->Iva,personas->totalCuota);
                fread(&personas, sizeof(personas),1,xx);
            } else {
                fread(&personas, sizeof(personas),1,xx);
            }
        }
        fclose(xx);
    }
}
//MENU PARA NUEVOS CLIENTES
//Funciones integradas de busqueda en binario
void nuevos_clientes(FILE * xx, char * y, creditos * personas) {
    int i,tamanio = 17,nuevotam, flag, orden, opcion;
    do {
        printf("\n -- Nuevos clientes --\n");
        printf("\n1)Para ingresar el orden del cliente\n0)Para salir\nSeleccion => ");
        scanf("%d",&opcion);
        switch(opcion){
            case 1: {
                do {
                    printf("\n\nIngresa el numero de orden: ");
                    scanf("%d",&orden);
                    fflush(stdin);
                    if(orden < 0) {
                        printf("\nIngrese un numero de orden valido.\n");
                    }
                }while(orden < 0);
                //Recorre todo el archivo desde el principio, si algun orden coincide, emite falla.
                //obs: cierra el archivo al terminar.
                flag = verifica_orden(orden, xx, personas);
                    if (flag == 0) {
                            genera_cliente(orden, xx, personas);
                        }
            }break;
            case 2: {

            } break;
        }
    }while(opcion != 0);
}
//FUNCION DE RECORRIDO
//Recorre todo el archivo desde el principio, si coincide el orden, emite falla.
int verifica_orden(int x, FILE * xx, creditos * personas) {
	int flag;
	xx = fopen("pruebas.dat","ab+");
    if (xx == NULL) {
        printf("Ocurrio un error inesperado...Intentelo nuevamente.");
        exit(1);
    } else {
    	rewind(xx);
    	flag = 0;
    	fread(&personas,sizeof(personas),1,xx);
        while(!feof(xx)) {
            if (personas->orden == x) {
                printf("\nEse numero de orden ya esta registrado a otro nombre, elija uno nuevo\n");
                flag = 1;
                break;
            }
            fread(&personas,sizeof(personas),1,xx);
        }
        fclose(xx);
    }
    return flag;
}
//Alta de nuevos clientes
void genera_cliente(int ord, FILE * xx, creditos * personas) {
	char nombre[20];
	int cuotas, importe,opcion;
	float importeCuota, IVA, total;
	xx = fopen("pruebas.dat","ab+");
	if (xx == NULL) {
		printf("Ocurrio un error inesperado...Intentalo denuevo mas tarde\n");
		exit(1);
	} else {
		rewind(xx);
		fseek(xx, ord*sizeof(personas),SEEK_SET);
		personas->orden = ord;
		printf("Ingresa el nombre del nuevo cliente: ");
        fflush(stdin);
		gets(nombre);
		strcpy(personas->cliente, nombre);
		printf("Ingresa el importe: ");
		fflush(stdin);
		scanf("%d",&importe);
		personas->importe = importe;
		do {
			printf("Que electrodomestico va a comprar?\n1)Heladera\n2)Lavarropa\n3)Televisor\nSeleccion => ");
			scanf("%d",&opcion);
			if ((opcion!=1) && (opcion!=2) && (opcion!=3)) {
				printf("\n Ingresa una opcion valida! \n");
			}
		}while((opcion!=1) && (opcion!=2) && (opcion!=3));
		switch(opcion) {
			case 1: {
				strcpy(personas->electro, "Heladera");
			} break;
			case 2: {
				strcpy(personas->electro, "Lavarropa");
			} break;
			case 3: {
				strcpy(personas->electro, "Televisor");
			} break;
		}
		personas->dia = 10;
		personas->mes = 01;
		personas->anio = 2024;
		printf("En cuantas cuotas lo va a pagar?: ");
		fflush(stdin);
		scanf("%d",&cuotas);
		personas->cuotas = cuotas;
		personas->impCuota = (importe/cuotas);
		importeCuota = personas[ord].impCuota;
		personas->Iva = (importe*1.21) - importe;
		personas->totalCuota =  importeCuota + ((importe*1.21) - importe);
		fwrite(&personas, sizeof(personas),1,xx);
		printf("Cliente cargado con exito!\n");
	}
}

//Funcion de vaciado de cadena, de ser necesario
void vaciar_cadena(char * y) {
    for (int i=0; i<2000; i++) {
        y[i] = '\0';
    }
}
