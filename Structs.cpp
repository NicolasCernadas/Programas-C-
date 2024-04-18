//Estructuras

# include <stdio.h>
# include <stdlib.h>

void pide_datos(struct Alumnos x);

//Structs anidados
struct Cursada {
     int numero;
     char comision;
};
//Podemos declarar los miembros de la estructura de 2 formas.
//Seguido del mismo struct:
struct Alumnos {
    char nombre[15];
    char apellido[15];
    struct Cursada curso;
}   alumno1 = {"Jorge", "Sanazi",1,'A'},
    alumno2 = {"Josefina", "Valdez",2,'B'},
    //alumnado[x];

int main(){
     //O en el codigo, asi:
    struct Alumnos alumno3 = {"Matias", "Isoro",1,'A'}, alumno4 = {"Octavio", "Sanazi",2,'A'}; //Rellenamos como un array
    printf("Nombre: %s\nApellido: %s\nCurso: %d%c\n",alumno3.nombre,alumno3.apellido,alumno3.curso.numero,alumno3.curso.comision);
     struct Alumnos alumno5;
    //O con un for:
    pide_datos(alumno5);

    return 0;
}

void pide_datos( struct Alumnos x) {
     for (int i=0; i<=4;i++) {
        if (i=1) {
            printf("Ingrese el nombre del alumno:");
            fflush(stdin);
            scanf("%s",&x.nombre);
        } else {}
        if (i=2) {
            printf("Ingrese el apellido del alumno:");
            fflush(stdin);
            scanf("%s",&x.apellido);
        } else {}
        if (i=3) {
            printf("Ingrese el curso:");
            fflush(stdin);
            scanf("%d",&x.curso.numero);
        } else {}
         if (i=4) {
            printf("Ingrese la comision:");
            fflush(stdin);
            scanf("%c",&x.curso.comision);
        } else {}
    }
    printf("Nombre: %s\nApellido: %s\nCurso: %d%c",x.nombre,x.apellido,x.curso.numero,x.curso.comision);


}
