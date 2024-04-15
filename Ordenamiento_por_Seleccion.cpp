/* ordenamiento de un vector de numeros enteros */
/* metodo: seleccion */
/* ejemplo de paso de vectores como parametros */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int posicion_maximo (int v[], int d)
{
    /* devuelve la posicion del elemento mayor del vector x */
    /* entrada: vector x, de tamano efectivo n */
    /* salida : posicion entre 1 y n-1 */
    int mprov, pprov, i;
    mprov = v[0];
    pprov = 0;
    for (i = 1; i < d; i++)
        if (v[i]> mprov)
        {
            mprov = v[i];
            pprov = i;
        }
    return pprov;
}
void intercambia (int * px, int * py)
{
    int n;
    n = *py;
    *py = *px;
    *px = n;
}

void coloca_el_ultimo (int v[], int d)
{
    /* intercambia los elementos maximo de x y ultimo de x
     colocando en ultimo lugar el maximo elemento */
    /* n es el tamanio efectivo de x */
    int p;
    p = posicion_maximo (v, d);
    if (v[p] !=  v[d-1])
        intercambia (&v[d-1], &v[p]);
}

void cargaelem(int v[], int d)
{
    int i;
    srand(time(NULL));
    for (i = 0; i < d; i++) v[i] = 1 + rand() % 50;
}

void emiteelem(int v[], int d)
{
    int i;
    for (i = 0; i < d; i++)
        printf ("%5d", v[i]);
    printf("\n");
}

void ordenaelem(int v[], int d)
{
    int cont;
    /* Ordenamiento*/
    for (cont = d; cont > 1; cont--)
    {
        /* tamanio desde el inicial hasta 2 */
        coloca_el_ultimo (v, cont);
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
    printf ("\nResultado despu�s de ordenar: \n");
    emiteelem(vec,dim);
    getchar();
    return 0;
}
