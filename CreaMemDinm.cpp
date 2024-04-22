# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>

int pide_cantidad();
void crea_array(int * x, int y);
void carga_array(int * x, int y);
void muestra_array(int * x, int y);


int main() {
    int N;
    int * p;
    N = pide_cant();
    crea_array(p,N);
    muestra_array(p,N);
    carga_array(p,N);
    muestra_array(p,N);
    free(p);

return 0;
}

int pide_cant(){
    int x;
    printf("Ingresa la cantidad de elementos que queres que tenga el array: ");
    scanf("%d",&x);
return x;
}

void crea_array(int * x, int y){
    x = (int*)calloc(y,sizeof(int));
}
void muestra_array(int * x, int y){
    printf("\nArray: ");
    for(int i=0; i<y; i++){
        printf("%p |",*(x+i));
    }

}
void carga_array(int * x, int y){
    srand(time(NULL));
    for (int i=0; i<y; i++){
        *(x + i) = rand() % 50 + 1;
    }
}
