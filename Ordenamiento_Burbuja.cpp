// # DE YOUTUBE # //
#include<stdio.h>

int main(){
    int cadena[]={4,1,2,3,5};
    int i,t,f,aux,longitud=0;

    for (int a=0;cadena[a]!='\0';a++){
        if (cadena[a]!='\0'){
            longitud += 1;
        }else {}
    }

    printf("Longitud del array: %d\n",longitud);
    for(i=0;i<(longitud-1);i++){
        for (t = (i + 1); t<longitud;t++){
            if (cadena[i] > cadena[t]){
                aux = cadena[i];
                cadena[i] = cadena[t];
                cadena[t] = aux;
            }
        }
    }
    
    for (f=0;f<longitud;f++){
        printf("%d", cadena[f]);
    }

return 0;
}

// # EN CLASE # //
/* Ordenamiento de un vector de números enteros*/
/* Método: burbuja mejorado con centinela */
/* Ejemplo de paso de vectores como parámetros */

#include <stdlib.h>
#include <time.h>
#include <stdio.h>

void cargaelem(int v[], int d)
{
    int i;
    srand(time(NULL));
    for (i = 0; i < d; i++) v[i] = 1 + rand() % 50;
}

void emiteelem(int v[], int d)
{
    int i;
    for (i = 0; i < d; i++) printf ("%d - ", v[i]);
    printf("\n");
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

int main()
{
    const int dim=10;
    int vec[dim];

    cargaelem(vec,dim);
    printf ("\nElementos ingresados: \n");
    emiteelem(vec,dim);

    ordenaelem(vec,dim);

    printf ("\nResultado despues de ordenar: \n");
    emiteelem(vec,dim);

    getchar();
    return 0;
}