# include <stdio.h>
# include <stdlib.h>
# include <time.h>

# define N 1000

int * crea_array(int * x, int v);
void genera_elementos(int * x, int v);
void muestra_elementos(int * x, int v);
void ordena_elementos(int * x, int v);
void maximo_elemento(int * x, int v);


int main(){
    int * p;
    srand(time(NULL));

    p = crea_array(p, N); 
    genera_elementos(p, N);
    muestra_elementos(p, N);
    ordena_elementos(p, N);
    muestra_elementos(p, N);
    maximo_elemento(p, N);

    return 0;
}

int * crea_array(int * x, int v){
    x = (int*)malloc(v*sizeof(int));
    return x;
}

void genera_elementos(int *x, int v){
    for (int i=0; i<v; i++) {
        *(x+i) = rand() % 100;
    }
}

void muestra_elementos(int * x, int v) {
    for (int i=0; i<v; i++) {
        printf("%d |", *(x+i));
    }
    printf("\n");
}

void ordena_elementos(int * x, int v) {
    int aux;
    for (int i=0; i< (v-1); i++) {
        for (int j = i + 1; j < v; j++) {
            if (*(x+i)>*(x+j)) {
                aux = *(x+i);
                *(x+i) = *(x+j);
                *(x+j) = aux;
            }
        }
    }

}

void maximo_elemento(int * x, int v) {
    int maximo=0, contador=1;
    for (int i=0; i<v; i++) {
        if (*(x+i)>maximo) {
            maximo = *(x+i);
            contador = 1;
        } else if (*(x+i) == maximo) {
            contador++;
        } else {}
    }
    printf("El numero maximo es: %d\nY se repitio: %d veces\n",maximo, contador);
}