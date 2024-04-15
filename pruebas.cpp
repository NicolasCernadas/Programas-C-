#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int * p, N,flag=0;

    srand(time(NULL));
    printf("Tamanio del array:\n");
    scanf("%d",&N);
    p = (int*)malloc(N*sizeof(int));
    for (int i=0; i<N; i++) {
        printf("dato: ");
        scanf("%d",&(*(p+i)));
    //    *(p+i) = rand() % 10 + 1;
    //    printf("%d |");
    }
    for (int i=0; i < N; i++) {
        if (flag == 0){
            for (int j=(i+1); j < N; j++) {
                if (*(p+i) < *(p+j)){
                    flag = 0;
                }
                else {
                    flag = 1;
                    break;
                }
            }
        }else {}
    }
    if (flag == 0) {
        printf("El array esta ordenado");
    } else {
        printf("El array no esta ordenado");
    }

    free(p);
    return 0;
}