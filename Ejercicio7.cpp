# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <string.h>
# define N 2

//ESTRUCTURAS
typedef struct{
     char apellido[20];
     char nombre[20];
     char * nombrecompleto = {};
     float calificaciones[5];
     float prom=0;
     float maxcal=0;
}alumnado;

//PROTOTIPO DE FUNCIONES
void carganotas(alumnado x[]);
void carganombre(alumnado x[]);
void prom(alumnado x[]);
void nota_maxima(alumnado x[]);
void menu(alumnado x[]);
void muestranotas(alumnado x[]);

//MAIN
int main(){
     srand(time(NULL));
     alumnado alumno[N]; //Genero las 10 estructuras para c/uno de los alumnos
     menu(alumno);

return 0;
}

//DEFINICION DE FUNCIONES
void menu(alumnado x[]){
     char key;
     int op;
     do {
          do {
               printf("Ingresa:\n1) Si queres cargar a los alumnos\n2) Si queres conocer sus promedios\n3) Si queres conocer la mayor nota de cada uno\n4) Si queres cargar sus notas\n5) Si queres conocer todas sus notas: ");
               scanf("%d",&op);
               if ((op==2 && x[0].nombrecompleto == NULL)){
                    printf("Todavia no cargaste los alumnos...\n");
                    op = 6;
               }
               if ((op==3 && x[0].nombrecompleto == NULL)){
                    printf("Todavia no cargaste los alumnos...\n");
                    op = 6;
               }
               if ((op==4 && x[0].nombrecompleto == NULL)){
                    printf("Todavia no cargaste los alumnos...\n");
                    op = 6;
               }
               if ((op==5 && x[0].nombrecompleto == NULL)){
                    printf("Todavia no cargaste a los alumnos...\n");
                    op = 6;
               }
               fflush(stdin);
          }while(op < 1 || 5 < op);

          switch (op) {
               case 1: carganombre(x); break;
               case 2: prom(x); break;
               case 3:  nota_maxima(x); break;
               case 4: carganotas(x); break;
               case 5: muestranotas(x); break;
          }
          printf("Queres hacer algo mas? (S/N): ");
          scanf("%c",&key);
          fflush(stdin);
     }while(key == 'S' || key == 's');
}
//Funciones del struct
void muestranotas(alumnado x[]){
     printf("==========================\n");
     for(int i=0; i<N; i++){
          printf("Alumno: %s\n",x[i].nombrecompleto);
          for (int j=0; j<5; j++){
               printf("%.2f |",x[i].calificaciones[j]);
          }
          printf("\n\n");
     }
}
void carganotas(alumnado x[]){
     printf("==========================\n");
     for(int i=0; i<N; i++){
          for (int j=0; j<5; j++){
               x[i].calificaciones[j] = (rand () % 87)/10.0f; //Calificacion con coma
          }
     }
}
void carganombre(alumnado x[]){
     for (int i=0; i<N; i++){
          printf("Ingresa el nombre del %d° alumno: ",i+1);
          scanf("%s",&x[i].nombre);
          fflush(stdin);
          printf("Ingresa el apellido: ");
          scanf("%s",&x[i].apellido);
          fflush(stdin);
          strcat(x[i].apellido, ", ");
          x[i].nombrecompleto = strcat(x[i].apellido, x[i].nombre);
          strupr(x[i].nombrecompleto);
          printf("Nombre completo: %s\n",x[i].nombrecompleto);
          fflush(stdin);
     }

}
void prom(alumnado x[]){
      printf("==========================\n");
     for (int i=0; i<N; i++){
          for (int j=0; j<5; j++){
               x[i].prom += x[i].calificaciones[j];
          }
          x[i].prom /= 5;
          printf("Promedio de %s: %.2f\n",x[i].nombrecompleto, x[i].prom);
     }
}
void nota_maxima(alumnado x[]){
     float aux=0;
      printf("==========================\n");
     for (int i=0; i<N; i++){
          for (int j=0; j<5; j++){
               if (x[i].calificaciones[j] > aux){
                    aux = x[i].calificaciones[j];
               }
          }
          x[i].maxcal = aux;
          printf("Calificacion maxima de %s: %.2f\n",x[i].nombrecompleto, x[i].maxcal);
          fflush(stdin);
          aux=0;
     }
}

