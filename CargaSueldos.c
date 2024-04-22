# include <stdio.h>
# include <stdlib.h>
# define N 3
# define sueldo 2250.50

void menu(struct ficha x[], int y);
void emite_empleados(struct ficha x[], int y);
void carga_empleados(struct ficha x[], int y);
void pago_total(struct ficha x[], int y);

struct ficha {
    char apellido[15];
    char sexo;
    float horas_trabajadas;
    float sueldo_x_hora = sueldo;
};

int main() {
    struct ficha empleado[N]; //Genero la cantidad de variables tipo struct como pide el ejercicio
    menu(empleado, N);
    return 0;
}
//Menu de opciones
void menu(struct ficha x[], int y) {
    int selec;
    do {
        printf("Ingresa:\n1) Para cargar y mostrar empleados\n2) Pago total por sexo y promedio\nSeleccion (si es 0 cierra el programa): ");
        fflush(stdin);
        scanf("%i",&selec);
        switch(selec){
            case 0: break;
            case 1: {
                carga_empleados(x,y);
                emite_empleados(x,y);
                fflush(stdin); break;
                }
            case 2: {
                pago_total(x,y);
                fflush(stdin); break;
            }
            default: printf("Ingreso no reconocido, reinicie el programa");
        }
    }while (selec != 0);

}
//Cargo los empleados, 1 a 1
void carga_empleados(struct ficha x[],int y) {
    printf("Carga de empleados\n");
    fflush(stdin);
    printf("==================\n");
    fflush(stdin);
    for (int i=0; i<y; i++) {
        printf("Ingresa el apellido del empleado: ");
        fflush(stdin);
        scanf("%s",&x[i].apellido);
        printf("Ahora ingresa el sexo (m o f(indistinto may o min)): ");
        fflush(stdin);
        scanf("%c",&x[i].sexo);
        printf("Las horas trabajadas: ");
        fflush(stdin);
        scanf("%f",&x[i].horas_trabajadas);
        printf("Y el sueldo por hora: ");
        fflush(stdin);
        scanf("%f",&x[i].sueldo_x_hora);
        if (x[i].sueldo_x_hora == 0) {
            x[i].sueldo_x_hora = sueldo;
        } else {}
        printf("\n===========================\n");
    }
}
//Muestro en pantalla los datos individuales
void emite_empleados(struct ficha x[], int y) {
    for (int i=0; i<y; i++) {
        printf("\n\n%d Empleado\n",i+1);
        fflush(stdin);
        printf("===========\n\n");
        fflush(stdin);
        printf("Apellido: %s\nSexo: %c\nHoras trabajadas: %.2f\nSueldo por hora: %.2f",x[i].apellido,x[i].sexo,x[i].horas_trabajadas,x[i].sueldo_x_hora);
        fflush(stdin);
        printf("\n===========================\n");
    }
}
//Datos extras pedidos por ejercicio
void pago_total(struct ficha x[], int y) {
    int cont_masc=0, cont_fem=0;
    float sueldos_masc=0, sueldos_fem=0;
    float aux_masc=0,aux_masc2=0, aux_fem=0, aux_fem2=0;
    for (int i=0; i<y; i++) {
        if ((x[i].sexo == 'm') || (x[i].sexo== 'M')) {
            cont_masc++;
            aux_masc2 += (x[i].horas_trabajadas); //Acumulo las horas trabajadas
            aux_masc = ((x[i].sueldo_x_hora)*aux_masc2); //aux_masc se va a ir pisando a medida que encuentre nuevas horas acumuladas
        } else if ((x[i].sexo == 'f') || (x[i].sexo == 'F')) {
            cont_fem++;
            aux_fem2 += (x[i].horas_trabajadas);
            aux_fem = ((x[i].sueldo_x_hora)*aux_fem2);
        } else {}
        sueldos_masc = aux_masc;
        if (sueldos_masc == 0) {
            cont_masc = 1;
        }
        sueldos_fem = aux_fem;
        if (sueldos_fem == 0) {
            cont_fem = 1;
        }
    }
    printf("\n===========================\n");
    printf("Total Masculino:\nHoras totales trabajadas = %.2f\nSueldo total = %.2f\n",aux_masc2,aux_masc);
    printf("Sueldo promedio masculino = %.2f\n",(sueldos_masc/cont_masc));
    printf("Total Femenino:\nHoras totales trabajadas = %.2f\nSueldo total = %.2f\n",aux_fem2,aux_fem);
    printf("Sueldo promedio femenino = %.2f\n",(sueldos_fem/cont_fem));
    printf("\n===========================\n");
}

