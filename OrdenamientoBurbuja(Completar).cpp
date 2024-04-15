# include <stdio.h>
# include <stdlib.h>
# include <time.h>

#define N 20

void emitirelem(float * v, int d);
void ordenaelem(float * v, int d);
// void eliminaelem(float * v, int d);

int main(){
    float *vect;

    vect = (float*)malloc(N*sizeof(float));
    srand(time(NULL));
    for (int i = 0; i < N; i++) {
        *(vect+i) = 1 + rand() % 50;
    }
    printf("Elementos ingresados:\n");
    emitirelem(vect, N);
    ordenaelem(vect, N);
    // eliminaelem(vect, N);
    // printf("\n");
    // emitirelem(vect, N);

    return 0;
}

void emitirelem(float * v, int d) {
    for (int i=0; i < d; i++){
        printf("%.2f |", *(v+i));
    }
}

void ordenaelem(float * v, int d) {
    float aux;
    for (int i=0; i < ( d - 1 ); i++) {
        for (int j=i+1; j < d; j++){
            if ((*(v+i))>(*(v+j))) {
                aux = *(v+i);
                *(v+i) = *(v+j);
                *(v+j) = aux;
            }
        }
    }
    printf("\nElemento ordenado:\n");
    for (int i=0; i < d; i++){
        printf("%.2f |", *(v+i));
    }
}

// void eliminaelem(float * v, int d) {
//     float aux;
//     for (int i=0; i < (d - 1); i++) {
//         for (int j = i + 1; j < d; j++) {
//             if ((*(v+i)==(*(v+j)))) {
//                 aux = *(v+i);
//                 *(v+i) = *(v+j);
//                 *(v+j) = 0;
//             }
//         }
//     }
//     for (int i=0; i < d; i++) {
//         if ((*(v+i))==0) {
//             *v += d;
//         }
//     }
// }