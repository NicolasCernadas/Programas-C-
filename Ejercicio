///Construye un programa que lea una secuencia de números enteros por teclado y los almacene en un array dinámico.
///A partir de él, se deben crear tres array de modo que en el primero se almacenen los números que dan resto uno al dividirlos por tres, en la segunda los de resto dos, y en la tercera los divisibles por tres.
///El programa deberá emitir la lista inicial y las tres nuevas listas.
# include <stdio.h>
# include <stdlib.h>

int* resto_uno(int * x, int y);
int* resto_dos(int * x, int y);
int* resto_tres(int * x, int y);

//FUNCION PRINCIPAL
int main() {
     int *p, *resto1, *resto2, *resto3, N;

     printf("Cuantos elementos va a tener el array?:\n");
     scanf("%d",&N);

     p = (int*)malloc(N*sizeof(int));

     printf("Ingresa uno por uno los elementos (dando enter al finalizar cada unidad)\n");
     for (int i=0; i<N;i++) {
               int j=i;
          printf("%d Elemento: ", j+1);
          scanf("%d",&*(p+i));
     }
     printf("Array completo: ");
     for (int i=0; i<N;i++) {
          printf("%d |", *(p+i));
     }
     printf("\n");
     resto1 = resto_uno(p, N);
     printf("\n");
     resto2 = resto_dos(p, N);
     printf("\n");
     resto3 = resto_tres(p, N);
     free(p);
     free(resto1);
     free(resto2);
     free(resto3);
     return 0;
}

//FUNCION DE ELEMENTOS CON RESTO 1 (%3)
int* resto_uno(int * x, int y) {
     int * p1,aux1=0,j1=0;

     p1 = (int*)calloc(y,sizeof(int));

     for (int i=0; i<y; i++) {
          if ((*(x+i)%3) == 1) {
               *(p1+j1)=*(x+i);
               aux1++;
               j1++;
          }else{}
     }
     p1 = (int*)realloc(p1,aux1*sizeof(int));
     printf("Array de resto 1: ");
     for (int i=0; i<aux1; i++) {
          printf("%d |", *(p1+i));
      }
return p1;
}

//FUNCION DE ELEMENTOS CON RESTO 2 (%3)
int* resto_dos(int * x, int y) {

     int * p2,aux2=0,j2=0;

     p2 = (int*)calloc(y,sizeof(int));

     for (int i=0; i<y; i++) {
          if ((*(x+i)%3) == 2) {
               *(p2+j2)=*(x+i);
               aux2++;
               j2++;
          }else{}
     }
     p2 = (int*)realloc(p2,aux2*sizeof(int));
     printf("Array de resto 2: ");
     for (int i=0; i<aux2; i++) {
          printf("%d |", *(p2+i));
      }
return p2;
}

//FUNCION DE ELEMENTOS CON RESTO 0 (%3)
int* resto_tres(int * x, int y) {
     int * p3,aux3=0,j3=0;

     p3 = (int*)calloc(y,sizeof(int));

     for (int i=0; i<y; i++) {
          if ((*(x+i)%3) == 0) {
               *(p3+j3)=*(x+i);
               aux3++;
               j3++;
          }else{}
     }
     p3 = (int*)realloc(p3,aux3*sizeof(int)); //Por que me aparecen las otras posiciones del array en 0? Deberian aparecerme solo las de cuando entra al IF
     printf("Array de resto 0: ");
     for (int i=0; i<aux3; i++) {
          printf("%d |", *(p3+i));
      }
return p3;
}

