#include<stdio.h>
#include<stdlib.h>

struct person{
    char name[100];
    unsigned int age;
};

int main(int argc, char const *argv[])
{
    FILE * out;
    char buffer [100];

    if(argc<2){
        printf("Indique el nombre del archivo de salida\n");
        return -1;
    }//Condicional para que el programa no crashe si se meten mal los parametros

    //Verificar si el archivo puede ser abierto
    if ( !( out = fopen( argv[1], "w") ) ){
        printf("No se puede abrir el archivo %s\n",argv[1]);
        return -2;
    }

    //Una ve veerificados los datos. se crea una variable para ingresar los datos de una persona
    struct person p;

    do
    {
        printf("ingrese el nombre de la persona: ");
        scanf("%99s", p.name);//no se pone & por que un arreglo ya es un puntero
        printf("ingrese la edad de la persona: ");
        scanf("%d", &(p.age));

        fwrite(&p, sizeof (struct person), 1, out);//funcionque no escribe en string si no diectamente en bonario
        /*Parametros: puntero a donde esta la informacion que quiero guardar
                    cuantoss bytes quiero guardar
                    cantidad de veces que quiero guardarlo
                    Donde lo quiero guardar
        */
        printf("Grabada! Otra? (s/n)");
        scanf("%1s",buffer);
    
    } while (buffer[0] != 'n');
    
    fclose( out );
    return 0;
}
