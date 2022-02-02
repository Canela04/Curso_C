#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    FILE * fp = fopen(argv[1], "r");//El primer parametro es el archivo que queremos abrir, el segundo el modo en que lo queremos abrir
    char c;//esta variable permite leer el archivo caracter a caracter

    while ((c = fgetc(fp)) != EOF){//mientras se obtengan caraceres sigue leyendo. EOF constante end of file
        printf("%c",c);
    }

    fclose(fp);
    return 0;
}
