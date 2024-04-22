# include <stdio.h>
# include <stdlib.h>

int main(){
    int matriz[5][5];
    int aux[25], i=0,p=0;

    //Cargo todos los impares en un vector unidimensional auxiliar
    for(int k=0;k<50;k++){
        if(k%2!=0){
            aux[i] = k;
            i++;
        }
    }
    //Recorro la matriz cargando el vector posicionado en otra variable.
    for(i=0;i<5; i++){
        for(int j=0; j<5; j++){
            matriz[i][j] = aux[p];
            p++;
        }
    }
    //Imprimo
    for(int i=0;i<5; i++){
        for(int j=0; j<5; j++){
            printf("%d |",matriz[i][j]);
        }
        printf("\n");
    }
return 0;
}

