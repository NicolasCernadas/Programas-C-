/* Ordenamiento de un vector de numeros enteros*/
/* Metodo: insercion */
/* Ejemplo de paso de vectores como parametros */

#include <stdlib.h>
#include <time.h>
#include <stdio.h>

void cargaelem(int * v, int d)
{
    int i;
    srand(time(NULL));
    for (i = 0; i < d; i++) {
        *(v+i) = 1 + rand() % 50;
    }
}

void emiteelem(int * v, int d)
{
    int i;
    for (i = 0; i < d; i++) {
        printf ("%5d", *(v+i));
    }
    printf("\n");
}

void ordenaelem(int * v, int d)
{
    int i,j, k, cont, aux;
    /* Ordenar y mostrar resultados intermedios*/
    for (cont = 1; cont<d; cont++)
    {
        /* Colocar v[cont] */
        aux = v[cont];
        k = cont-1; /* posicion del elemento a comparar */
        while ((*(v+k) > aux) && (k>0))
        {
            /* Desplazar elementos */
            *(v+(k+1)) = *(v+k);
            k--;
        }
        if (*(v+k) <= aux)
        {
            /* posicion intermedia */
            *(v+(k+1)) = aux;
        }
        else  /* colocar el primero */
        {
            *(v+1) = *(v);
            *(v) = aux;
        }
    }
    /* Fin ordenamiento*/
}

int main()
{
    const int dim=10;
    int vec[dim];
    cargaelem(vec,dim);

    printf ("\nElementos ingresados: \n");
    emiteelem(vec,dim);

    ordenaelem(vec,dim);

    printf ("\nResultado despuus de ordenar: \n");
    emiteelem(vec,dim);
    getchar();
    return 0;

}
