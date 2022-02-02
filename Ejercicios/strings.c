#include<stdio.h>
#include<string.h>

int main()
{
    char * name = "Canela";
    char * otherName = "Hugo";

    printf("Name mide  %ld\n",strlen(name));

    printf("Los nombres son %s\n", 
    strcmp(name, otherName) == 0 ? "Iguales":"Distintos");
    // comparacion en linea: se toma el resultado de evaluar la exprecionn "=="
    // y si es verdadera el valor de la exprecion sera el primero si no el segundo

    /*
    ?
    compare
     0 son iguales
    -1 si la primera es menor que la segunda
     1 caso contrario
    */
    char * src = "Canela";
    char dst[20] = "No veras esto nunca!";

    strcpy(dst, src);
    printf("dst = %s\n", dst);

    return 0;
}