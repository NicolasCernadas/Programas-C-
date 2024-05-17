//Ultima vez actualizado: 14:48am, 17/05/2024
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct {
    int orden, dia, mes, anio, cuotas, importe;
    char cliente[40], electro[20];
    float impCuota, Iva, totalCuota;
}creditos;


void bienvenida();
void menu(FILE * punteroArchivoBin, FILE * punteroArchivo, char * lineaTexto, creditos personas[]);
void imprime_creditoscsv(FILE * x, char * y);
void vaciar_cadena(char * y);
void extrae_datos(FILE * f,char * y, char * o);
void genera_binario(FILE * x);
void carga_binario(FILE * xx, FILE * x, char * nombre, char * lineaTexto, creditos personas[]);
void lee_binario(FILE * xx, char * y, creditos personas[]);
void lista_binario(FILE * xx, creditos personas[]);
void lista_heladera(FILE * xx, creditos personas[]);
void lista_televisor(FILE * xx, creditos personas[]);
void lista_lavarropa(FILE * xx, creditos personas[]);


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
void menu(FILE * punteroArchivoBin, FILE * punteroArchivo, char * lineaTexto, creditos personas[]) {
    int flag = 0, flag2 = 0, flag3 = 0;
    char * nombre;
    int opcion;
    char s;
    do{
        do{
        printf("\n -- Menu de opciones -- \n1)Para imprimir el archivo: 'creditos.csv' original\n2)Para generar el archivo binario\n3)Para pasar los datos del .txt al .dat\n4)Para imprimir el archivo.dat\n0)Para salir del menu de opciones\nSeleccion => ");
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
    char nombreArch[] = "pruebas.dat";
//    printf("Ingrese el nombre que quiera poner al archivo (sin .dat): ");
//    scanf("%s",nombreArch);
//    fflush(stdin);
//    strcat(nombreArch,".dat");
    xx = fopen("pruebas.dat", "wb");
    if (xx == NULL) {
        printf("Ocurrio un error inesperado...Intentelo nuevamente.\n");
        exit(1);
    } else {
        printf("Archivo generado con exito.\n");
        fclose(xx);
    }
}
void carga_binario(FILE * xx, FILE * x, char * n, char * lineaTexto, creditos personas[]) {
    char * token, * token2;
    x = fopen("creditos.txt", "rt");
    xx = fopen("pruebas.dat", "wb+");
    if ((x == NULL) || (xx == NULL)) {
        printf("Ocurrio un error inesperado...Intentalo nuevamente.\n");
        exit(1);
    } else {
        fgets(lineaTexto, 2000, x);
        for (int i=0; i<17; i++) {
            fgets(lineaTexto, 2000, x);
            token = strtok(lineaTexto, ";");
            personas[i].orden = atoi(token);
            token = strtok(NULL, ";");
            strcpy(personas[i].cliente, token);
            token = strtok(NULL, ";");
            personas[i].importe = atoi(token);
            token = strtok(NULL, ";");
            strcpy(personas[i].electro,token);
            token = strtok(NULL, ";");
            personas[i].dia = atoi(token);
            token = strtok(NULL, ";");
            personas[i].mes = atoi(token);
            token = strtok(NULL, ";");
            personas[i].anio = atoi(token);
            token = strtok(NULL, ";");
            personas[i].cuotas = atoi(token);
            token2 = strtok(NULL,",");
            token = strtok(NULL, ";");
            personas[i].impCuota = atof(token2) + (atof(token)/100);
            token2 = strtok(NULL,",");
            token = strtok(NULL, ";");
            personas[i].Iva = atof(token2) + (atof(token)/100);
            token2 = strtok(NULL,",");
            token = strtok(NULL, ";");
            personas[i].totalCuota = atof(token2) + (atof(token)/100);
            fwrite(&personas[i],sizeof(personas),1,xx);
        }
        printf("Datos cargados exitosamente.\n");
        fclose(x);
        fclose(xx);
    }
}
//Lee el archivo binario con tipos
void lee_binario(FILE * xx, char * y, creditos personas[]) {
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
void lista_binario(FILE * xx, creditos personas[]){
    int i;
    xx = fopen("pruebas.dat", "rb+");
    if (xx == NULL) {
        printf("Ocurrio un error inesperado...Intentelo nuevamente.\n");
        exit(1);
    } else {
        rewind(xx);
        i = 0;
        fread(&personas[i], sizeof(personas),1,xx);
        printf("\n");
        printf("Orden| Cliente          | Importe  | Electro     | Dia  | Mes  | Anio   | Nro.Cuotas  | ImporteCuota  | IVA       | TotalCuota\n");
        while(!feof(xx)) {
            printf("%5d| %-17s| %-9d| %-12s| %-5d| %-5d| %-7d| %-12d| %-14.2f| %-10.2f| %.2f\n",
            personas[i].orden,personas[i].cliente,personas[i].importe,personas[i].electro,personas[i].dia,personas[i].mes,personas[i].anio,personas[i].cuotas,personas[i].impCuota,personas[i].Iva,personas[i].totalCuota);
            i++;
            fread(&personas[i], sizeof(personas),1,xx);
        }
        fclose(xx);
    }
}
//BINARIOS INDIVIDUALES, 1)HELADERA, 2)TELEVISOR Y 3)LAVARROPA
void lista_heladera(FILE * xx, creditos personas[]) {
    int j;
    xx = fopen("pruebas.dat", "rb+");
    if (xx == NULL) {
        printf("Ocurrio un error inesperado...Intentelo nuevamente.\n");
        exit(1);
    } else {
        rewind(xx);
        j = 0;
        printf("\n-- Creditos para 'Heladera' --\n");
        printf("Orden| Cliente          | Importe  | Electro     | Dia  | Mes  | Anio   | Nro.Cuotas  | ImporteCuota  | IVA       | TotalCuota\n");
        fread(&personas[j], sizeof(personas),1,xx);
        while(!feof(xx)) {
            if ((strcmp(personas[j].electro,"Heladera")) == 0) {
                printf("%5d| %-17s| %-9d| %-12s| %-5d| %-5d| %-7d| %-12d| %-14.2f| %-10.2f| %.2f\n",
                    personas[j].orden,personas[j].cliente,personas[j].importe,personas[j].electro,personas[j].dia,personas[j].mes,personas[j].anio,personas[j].cuotas,personas[j].impCuota,personas[j].Iva,personas[j].totalCuota);
                j++;
                fread(&personas[j], sizeof(personas),1,xx);
            } else {
                j++;
                fread(&personas[j], sizeof(personas),1,xx);
            }
        }
        fclose(xx);
    }
}
void lista_televisor(FILE * xx, creditos personas[]) {
    int j;
    xx = fopen("pruebas.dat", "rb+");
    if (xx == NULL) {
        printf("Ocurrio un error inesperado...Intentelo nuevamente.\n");
        exit(1);
    } else {
        rewind(xx);
        j = 0;
        printf("\n-- Creditos para 'Televisor' --\n");
        printf("Orden| Cliente          | Importe  | Electro     | Dia  | Mes  | Anio   | Nro.Cuotas  | ImporteCuota  | IVA       | TotalCuota\n");
        fread(&personas[j], sizeof(personas),1,xx);
        while(!feof(xx)) {
            if ((strcmp(personas[j].electro,"Televisor")) == 0) {
                printf("%5d| %-17s| %-9d| %-12s| %-5d| %-5d| %-7d| %-12d| %-14.2f| %-10.2f| %.2f\n",
                    personas[j].orden,personas[j].cliente,personas[j].importe,personas[j].electro,personas[j].dia,personas[j].mes,personas[j].anio,personas[j].cuotas,personas[j].impCuota,personas[j].Iva,personas[j].totalCuota);
                j++;
                fread(&personas[j], sizeof(personas),1,xx);
            } else {
                j++;
                fread(&personas[j], sizeof(personas),1,xx);
            }
        }
        fclose(xx);
    }
}
void lista_lavarropa(FILE * xx, creditos personas[]) {
    int j;
    xx = fopen("pruebas.dat", "rb+");
    if (xx == NULL) {
        printf("Ocurrio un error inesperado...Intentelo nuevamente.\n");
        exit(1);
    } else {
        rewind(xx);
        j = 0;
        printf("\n-- Creditos para 'Lavarropa' --\n");
        printf("Orden| Cliente          | Importe  | Electro     | Dia  | Mes  | Anio   | Nro.Cuotas  | ImporteCuota  | IVA       | TotalCuota\n");
        fread(&personas[j], sizeof(personas),1,xx);
        while(!feof(xx)) {
            if ((strcmp(personas[j].electro,"Lavarropa")) == 0) {
                printf("%5d| %-17s| %-9d| %-12s| %-5d| %-5d| %-7d| %-12d| %-14.2f| %-10.2f| %.2f\n",
                    personas[j].orden,personas[j].cliente,personas[j].importe,personas[j].electro,personas[j].dia,personas[j].mes,personas[j].anio,personas[j].cuotas,personas[j].impCuota,personas[j].Iva,personas[j].totalCuota);
                j++;
                fread(&personas[j], sizeof(personas),1,xx);
            } else {
                j++;
                fread(&personas[j], sizeof(personas),1,xx);
            }
        }
        fclose(xx);
    }
}

//Funcion de vaciado de cadena, de ser necesario
void vaciar_cadena(char * y) {
    for (int i=0; i<2000; i++) {
        y[i] = '\0';
    }
}
