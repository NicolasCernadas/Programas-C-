# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# define f 5
# define c 5

float ** crea_matriz();
void carga_matriz(float ** xx);
void emite_matriz(float ** xx);
void simetria();
void suma_matricez(float ** xx, float ** yy, float ** zz);
void resta_matricez(float ** xx, float ** yy, float ** zz);
void mult_matricez(float ** xx, float ** yy, float ** zz);

int main(){
    float ** pp1, ** pp2, **pp3;
    srand(time(NULL));
    printf("Primera matriz: \n");
    pp1 = crea_matriz();
    carga_matriz(pp1);
    emite_matriz(pp1);
    printf("\n==============================\n\n");
    printf("Segunda matriz: \n");
    pp2 = crea_matriz();
    carga_matriz(pp2);
    emite_matriz(pp2);
    printf("\n==============================\n\n");
    printf("Tercera matriz: (suma de las 2 anteriores, guardada en una tercera)\n");
    pp3 = crea_matriz();
    suma_matricez(pp1, pp2, pp3);
    emite_matriz(pp3);
    printf("\n==============================\n\n");
    printf("Cuarta matriz: (resta de las 2 primeras, guardada en la tercera)\n");
    resta_matricez(pp1, pp2, pp3);
    emite_matriz(pp3);
    printf("\n==============================\n\n");
    printf("Quinta matriz: (multiplicacion de las 2 primeras, guardada en la tercera)\n");
    mult_matricez(pp1, pp2, pp3);
    emite_matriz(pp3);

return 0;
}
//creo la matriz
float ** crea_matriz(){
    float ** xx;
    xx = (float**)malloc(f*sizeof(float*));
    for (int i=0; i<f; i++){
        xx[i] = (float*)malloc(c*sizeof(float));
    }
return xx;
}
//cargo la matriz
void carga_matriz(float ** xx){
    for (int i=0; i<f; i++){
        for (int j=0; j<c; j++){
            xx[i][j] = ((rand () % 4441)/1000.0f);
        }
    }
}
//emito
void emite_matriz(float ** xx){
    for (int i=0; i<f; i++){
        for (int j=0; j<c; j++){
            printf("  %.2f  |",xx[i][j]);
        }
        printf("\n");
    }
}
//reviso simetria
void simetria(){
    int cont1=0,cont2=0;
    for (int i=0; i<f; i++){
        cont1++;
    }
    for (int j=0; j<c; j++){
        cont2++;
    }
    if(cont1==cont2){
        printf("Es una matriz simetrica!");
    } else{
        printf("No es una matriz simetrica!");
    }
}
//sumo y guardo en una tercer matriz
void suma_matricez(float ** xx, float ** yy, float ** zz){
    for(int i=0; i<f; i++){
        for(int j=0; j<c; j++){
            zz[i][j]=xx[i][j]+yy[i][j];
        }
    }
}
//resto y guardo en la misma tercer matriz anterior
void resta_matricez(float ** xx, float ** yy, float ** zz){
    for(int i=0; i<f; i++){
        for(int j=0; j<c; j++){
            zz[i][j]=xx[i][j]-yy[i][j];
        }
    }
}
//mismo procedimiento de antes, pero ahora multiplico
void mult_matricez(float ** xx, float ** yy, float ** zz){
    for(int i=0; i<f; i++){
        for(int j=0; j<c; j++){
            zz[i][j]=(xx[i][j]*yy[i][j]);
        }
    }
}
