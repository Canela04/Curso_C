#include<stdlib.h>
#include<stdio.h>
#include<string.h>

typedef struct INTERVAL {
    float lower;
    float upper;
}INTERVAL;

INTERVAL VectorW[100], lambda;

int main(int argc, char const *argv[])
{
    FILE *in = fopen("entrada.txt", "r");
    if(in==NULL){
        perror("Error en la apertura del archivo\n");
        return 1;
    }

    char caracter;
    int nl = 0;
    int cm = 0, bl = 0;
    char c;
   /* while ((c = fgetc(in)) != EOF){//mientras se obtengan caraceres sigue leyendo. EOF constante end of file
        printf("%c",c);
        if (c == ' ')
            bl = bl + 1;
        if (c == ',')
            cm++;
        if (c == '\n')
            ++nl;
    }*/
    char buffer[5000];
    int linea = 0;
    //printf("%s",fgets(buffer,2000,in));
    while (fgets(buffer,2000,in))
    {
        char delim[] = " ,";
        char delim2[] = ",";
        char *ptr = strtok(buffer, delim);
        int cont_in=0;
        while (ptr != NULL)
        {
            if(linea == 0){
                printf("0.1.- %s\n",ptr);
                lambda.lower = atof(ptr);
                ptr = strtok(NULL, delim);
                printf("0.2.- %s\n",ptr);
                lambda.upper = atof(ptr);
            }
            if (linea == 1)
            {
                printf("1.1.- %s\n",ptr);
                VectorW[cont_in].lower= atof(ptr); 
                ptr = strtok(NULL, delim);
                printf("1.2.- %s\n",ptr);
                VectorW[cont_in].upper= atof(ptr);
            }
            ptr = strtok(NULL, delim);
            cont_in++;
        }
        linea++;
        
    }

    printf("Lambda inferior: %f\nLambda Superior: %f\n",lambda.lower,lambda.upper);
    for (int i = 0; i < 3; i++)
    {
        printf("Intervalo %d\t[ %f, %f]\n",i,VectorW[i].lower,VectorW[i].upper);
    }
    
    
    /*printf("\nHay blancos: %d, comas: %d y nueva linea %d\n",
           bl, cm, nl);*/

    fclose(in);
    printf("\n\nSe ha leido el archivo correctamente...\n");

    return 0;
}
