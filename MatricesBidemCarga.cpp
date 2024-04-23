#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void creoDim (int * n){
    do
    {
        printf("N%cmero de filas/columnas del array:\n", 163);
        scanf("%d", n); //como 'n' es un puntero, se guarda sin &
    }
    while (*n<=0);
}

int ** creoMat(int nFilas, int nCols){
    int ** ppa, f;
    /* Asignar memoria para el array de punteros */
    ppa = (int **)malloc(nFilas * sizeof(int *));

    /* Asignar memoria para cada una de las filas */
    for (f = 0; f < nFilas; f++)
        ppa[f] = (int *)malloc(nCols * sizeof(int));

 return ppa; //tiene que devolver un elemento del mismo tipo que la funcion: (int **)
}


void cargoMat(int ** ppa, int nFilas, int nCols)
{
    int f,c;
    srand(time(NULL));
    /* Inicializamos el array */
    for ( f = 0; f < nFilas; f++ )
    {
        for ( c = 0; c < nCols; c++ )
        {
            ppa[f][c] = 10 + rand() % 99;
            //O podria ser manualmente
            //printf("ingrese el dato[%d][%d]\n", f, c);
            //scanf("%d", ppa[f][c]);
        }
    }
}


void emitoMat(int ** ppa, int nFilas, int nCols)
{
    int f,c;
    for ( f = 0; f < nFilas; f++ )
    {
        printf("\n");
        for ( c = 0; c < nCols; c++ )
            printf("dato[%d][%d]--> %d | ",f,c, ppa[f][c]);
    }

}

void liberoMem(int ** ppa, int nFilas){
    int f;
    /* Liberar la memoria asignada a cada una de las filas */
    for ( f = 0; f < nFilas; f++ ) {
        free(ppa[f]);
    }
    /* Liberar la memoria asignada al array de punteros */
    free(ppa);
}

int main()
{
    int **pp = NULL;
    int fil, col;
    creoDim(&fil); //Como la funcion es un void, pasa la direccion de la variable para que se guarde sin retornar
    creoDim(&col);
    pp=creoMat(fil,col); //pp es int **, la funcion es int **
    cargoMat(pp,fil,col);
    emitoMat(pp,fil,col);
    liberoMem(pp,fil);
    getchar();
    return 0;
}

