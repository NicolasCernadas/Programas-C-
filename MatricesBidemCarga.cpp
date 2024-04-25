# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int pide_columna();
int pide_fila();
int ** crea_matriz(int y, int z);
void emite_matriz(int ** xx, int y, int z);

int main(){
     int ** pp = NULL, c, f;

     c = pide_columna();
     f = pide_fila();
     pp = crea_matriz(c, f);
     emite_matriz(pp, c,f);


return 0;
}
int pide_columna() {
     int y;
     printf("Cuantas columnas queres que tenga?: ");
     scanf("%d",&y);
     if (y<=0) {
          printf("No se puede asi pa...");
          exit(-1);
     }
return y;
}
int pide_fila() {
     int x;
     printf("Cuantas columnas queres que tenga?: ");
     scanf("%d",&x);
     if (x<=0) {
          printf("No se puede asi pa...");
          exit(-1);
     }
return x;
}

// Crea la matriz dinamica a travez de un puntero a puntero
int ** crea_matriz(int col, int fil) {
     int ** xx;
    
     /* Definimos un vector de punteros. */
     xx = (int**)malloc(fil*sizeof(int*)); //Primero creamos la cantidad de filas
     for(int i=0; i<fil; i++) { //En base a la cantidad de filas, creamos las columnas que va a tener la matriz
          xx[i]=(int*)malloc(col*sizeof(int));
     }
     /*Carga matriz con 0's en este caso*/
     for (int i=0; i<fil; i++){ //Primero por filas
          for(int j=0; j<col; j++) { //Despues por columnas
               xx[i][j]=0;
          }
     }

     return xx; //Devolvemos el puntero ya cargado, se puede cargar a parte
}

void emite_matriz(int ** xx, int y, int z) {
     for (int i=0; i<z; i++) {
          for (int j=0; j<y; j++) {
               printf("%d |",xx[i][j]); //emitimos la matriz, vease que se esta tratando como un array cualquiera, sin importar que sea **
          }
          printf("\n");
     }
}

