/*    B�squeda binaria */

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void ordenaelem(int v[], int d);
void cargaelem(int v[], int d);
int busquedaBinaria( const int b[], int claveDeBusqueda, int bajo, int alto, int d );
void emitelem(int v[], int d);

int main()
{
    const int dim=10;
    int vec[ dim ]; /* crea el arreglo a */
    int llave; /* valor a localizar en el arreglo a */
    int resultado; /* variable para almacenar la ubicaci�n de la llave o -1 */

    cargaelem(vec, dim);
    ordenaelem(vec, dim);
    emitelem(vec, dim);
    printf( "Introduzca un n�mero a buscar:\n" );
    scanf( "%d", &llave );
    resultado = busquedaBinaria( vec, llave, 0, dim - 1, dim );

    if ( resultado != -1 )
    {
        printf( "\n%d se encuentra en la posicion %d del arreglo\n", llave, (resultado+1));
    }
    else
    {
        printf( "\n%d no se encuentra\n", llave );
    }
    getchar();
    return 0;

} /* fin de main */

void cargaelem(int v[], int d)
{
    int i;
    srand(time(NULL));
    for(i=0; i<d; i++)
    {
        v[i] = 1 + rand() % 50;
    }
}

void ordenaelem(int v[], int d)
{
    int i,j, aux, cambio;
    /* Ordenamiento*/
    for (i = 0; i < d-1; i++)
    {
        cambio = 0;
        for (j = 0; j < d-(i+1); j++)
        {
            if (v[j] > v[j+1])
            {
                aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;
                cambio = 1;
            }
        }
    }
    /* Fin ordenamiento*/
}

void emitelem(int v[], int d)
{
    int i;

    for(i=0; i<d; i++) printf("%d - ",v[i]);

    printf("\n");

}

int busquedaBinaria( const int b[], int claveDeBusqueda, int bajo, int alto, int d )
{
    int central;
    while ( bajo <= alto )
    {
        central = ( bajo + alto ) / 2;
        if ( claveDeBusqueda == b[ central ] )
        {
            return central;
        }
        else if ( claveDeBusqueda < b[ central ] )
        {
            alto = central - 1;
        }
        else
        {
            bajo = central + 1;
        }
    }
    return -1;
}
