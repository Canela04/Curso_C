//Realiza un programa que reciba cadenas de caracteres por linea de comandos y emita la cadena mas larga
#include<stdio.h>
#include<string.h>

int main(int argc, char const *argv[])
{
    char *max="";//Variable que almacenara el malor mas grande

    if (argc < 3)
    {
        printf("Ingrese 2 o mas cadenas de caracter\n");
    }//Condicion para que ingrese 2 o mas cadenas para comparar

    max=argv[1];//se inicializa el valor con el cual empezaremos a comparar

    for ( int i = 1; i < argc; i++)
    {
        if (strlen(argv[i])>strlen(max))
        {
            strcpy(max, argv[i]);  
        }//Condicion para establecer la cadena mas grande
  
    }//Ciclo para comparar todas las cadenas ingresadas

    printf("La palabra mas larga es: %s", max);//Resultado
    return 0;
}


