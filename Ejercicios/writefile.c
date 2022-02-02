#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    FILE * out;// puntero al archivo
    char buffer[100];//almacenar entradas de usuario

    if (!(out = fopen(argv[1],"w"))){//Pregunta si el archivo pudo ser abierto
        printf("no puedo escribir el archivo %s\n", argv[1]);
        return -1;
    }

    do{
        printf("Ingrese una palabra:");
        scanf("%99s", buffer);
        fputs(buffer, out);
        fputs("\n", out);//guarda el buffer en el archivo de escritura (fputs)dfghdf
        printf("Grabada! otra? (s/n)" );
        scanf("%1s", buffer);
    }while(buffer[0] != 'n');

    fclose(out);
    return 0;
}
