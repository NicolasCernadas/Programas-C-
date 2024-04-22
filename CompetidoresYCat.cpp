# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# define N 2

void carga_competidores(struct categoria x[], int y);
void emite_competidores(struct categoria x[], int y);
void categorias(struct categoria x[], int y);

struct corredor {
     char nombre[30];
     int edad;
     char sexo[15];
     char club[30];
};

struct categoria {
     char cat[10] ;
     struct corredor competidor;
};

int main() {
     struct categoria c[N];
     carga_competidores(c, N);
     categorias(c, N);
     emite_competidores(c, N);
return 0;
}

void carga_competidores(struct categoria x[], int y) {
     printf("Programa de Carga de competidores.-\n");
     for (int i=0; i<y ; i++) {
          printf("Ingresa el nombre del %d competidor: ",i+1);
          fflush(stdin);
          gets(x[i].competidor.nombre);
          printf("Ingresa la edad del competidor: ");
          fflush(stdin);
          scanf("%d",&x[i].competidor.edad);
          printf("Ingresa el sexo: ");
          fflush(stdin);
          scanf("%s",&x[i].competidor.sexo);
          printf("Ingresa el club de donde viene: ");
          fflush(stdin);
          gets(x[i].competidor.club);
     }
}
void categorias(struct categoria x[], int y) {
     char categoria1[10]= "Juvenil", categoria2[10] = "Senior", categoria3[10] = "Veterano";
     for (int i=0; i<y; i++) {
          if ((x[i].competidor.edad) <= 18) {
               strcpy(x[i].cat, categoria1);//{'j','u','v','e','n','i','l'};
          } else if (x[i].competidor.edad <= 40) {
               strcpy(x[i].cat, categoria2);//{'s','e','n','i','o','r'};
          } else {
                strcpy(x[i].cat, categoria3);//{'v','e','t','e','r','a','n','o'};
          }
     }
}
void emite_competidores(struct categoria x[], int y) {
     printf("Competidores\n");
     printf("===========\n");
     for (int i=0; i<y ; i++) {
     printf("%d) Competidor\n", i+1);
     printf("Nombre: %s\nEdad: %d\nSexo: %s\nClub de origen: %s\nCategoria: %s\n.-\n",x[i].competidor.nombre,x[i].competidor.edad,x[i].competidor.sexo,x[i].competidor.club,x[i].cat);
     }
}
