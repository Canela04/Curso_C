#include<stdio.h>
#include<stdlib.h>

struct person{
    char name[100];
    unsigned int age;
};

int main(int argc, char const *argv[])
{
    FILE * in;
    char buffer [100];

    if(argc<2){
        printf("Indique el nombre del archivo de entrada\n");
        return -1;
    }//Condicional para que el programa no crashe si se meten mal los parametros

    //Verificar si el archivo puede ser abierto
    if ( !( in = fopen( argv[1], "r") ) ){
        printf("No se puede leer el archivo %s\n",argv[1]);
        return -2;
    }

    //Una ve veerificados los datos. se crea una variable para ingresar los datos de una persona
    struct person p;

    while (fread( &p, sizeof ( struct person ), 1, in) ) //funcion para comenzar  leer un programa con la misma estructura
    {
        printf("%s tiene %d años \n", p.name, p.age);
    }
    
    
    fclose( in );
    return 0;
}
