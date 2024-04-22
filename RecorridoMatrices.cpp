# include <stdio.h>
# include <stdlib.h>

int main(){
    int matriz[3][3] = {0};

    printf("Valores dentro de la matriz escrita asi: matriz[i][j]:\n");
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            printf("%d |",matriz[i][j]);
        }
        printf("\n");
    }

    printf("\nValores dentro de la matriz escrita asi: matriz[i]+j:\n");
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            printf("%d |",matriz[i]+j);
        }
        printf("\n");
    }

    printf("\nValores dentro de la matriz escrita asi: *(matriz[i])+j:\n");
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            printf("%d |",*(matriz[i])+j);
        }
        printf("\n");
    }

    printf("\nValores dentro de la matriz escrita asi: *(matriz + i)+ j:\n");
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            printf("%d |",*(matriz+i)+j);
        }
        printf("\n");
    }

    printf("\nValores dentro de la matriz escrita asi: *(*(matriz + i)+ j):\n");
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            printf("%d |",*(*(matriz + i)+ j));
        }
        printf("\n");
    }

return 0;
}
