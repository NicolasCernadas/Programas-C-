# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# define N 5
# define M 5

int ** crea_matriz();
void carga_matriz(int ** xx) ;
void emite_matriz(int ** xx);
void suma_columnas(int ** xx);
//void ordena_matriz(int ** xx);

int main() {
     int ** pp;
     srand(time(NULL));
     pp = crea_matriz();
     carga_matriz(pp);
     emite_matriz(pp);
     suma_columnas(pp);
     //ordena_matriz(pp);
     //emite_matriz(pp);

return 0;
}
//creo la matriz a travez de un puntero a puntero
int ** crea_matriz(){
     int ** xx;
     xx = (int**)malloc(N*sizeof(int*));
     for (int i=0; i<N; i++) {
          xx[i] = (int*)malloc(M*sizeof(int));
     }
return xx;
}
//cargo
void carga_matriz(int ** xx) {
     for (int i=0; i<N; i++) {
          for (int j=0; j<M; j++) {
               xx[i][j] = rand () % 10;
          }
     }
}
//emito
void emite_matriz(int ** xx) {
     for (int i=0; i<N; i++) {
          for (int j=0; j<M; j++) {
               printf("%d |",xx[i][j]);
          }
          printf("\n");
     }
}
//sumo columnas
void suma_columnas(int ** xx) {
     int suma=0;
     for (int i=0; i<N; i++) {
          for (int j=0; j<M; j++) {
               suma += xx[j][i];
          }
          printf("Sumatoria de la %d columna: %d\n",i+1,suma);
          suma = 0;
     }
}
//Como seria para ordenar???
//void ordena_matriz(int ** xx) {
//     int * aux;
//     for (int i=0; i<N; i++) {
//          for (int j=i+1; j<M; j++) {
//               if (xx[i] > xx[j]) {
//                    aux = xx[i];
//                    xx[i] = xx[j];
//                    xx[j]= aux;
//               }
//          }
//     }
//     for (int i=0; i<N; i++) {
//          for (int j=0; j<M; j++) {
//               printf("%d |"), xx[i][j];
//          }
//          printf("\n");
//     }
//}
