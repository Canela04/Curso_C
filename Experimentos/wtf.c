#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef char NAME[100];

typedef struct INTERVAL{
    NAME name;
    int lower;
    int upper;
}INTERVAL;

void imprimir(INTERVAL * intervalo, int listSize);

int main(int argc, const char * argv[])
{
    INTERVAL * vector = NULL;//conjunto de intervalos no limitados
    char buffer[100];
    int goOn, vectorSize = 0;
    int limit;

    do{
        printf("Nombre intervalo(0 para terminar): \n");
        scanf("%99s", buffer);
        if(strcmp("0", buffer) != 0){
            if(!vector){//vector vacio
                vector = malloc(sizeof(INTERVAL));
            }else{
                vector = realloc (vector, sizeof(INTERVAL) * (vectorSize + 1));
            }

            strcpy(vector[vectorSize].name, buffer);
            printf("Intervalo %s, limite inferior: \n", buffer);
            scanf("%d", &vector[vectorSize].lower);
            
            printf("Intervalo %s, limite superior: \n", buffer);
            scanf("%d", &vector[vectorSize].upper);
            
            /*printf("Intervalo %s, limite superior: \n", buffer);
            limit = atoi(scanf("%99s", buffer));
            vector[vectorSize].upper=limit;*/

            goOn=1;
            vectorSize++;

        }else{
            goOn = 0;
        }

    }while(goOn);

    imprimir(vector, vectorSize);
    free(vector);
    return 0;   
}

void imprimir(INTERVAL * intervalo, int listSize){
    printf("\nEsta es tu lista de intervalos:\n");
    for (int i = 0; i < listSize; i++)
    {
        printf("Intervalo: %s[ %d, %d ]\n", intervalo[i].name, intervalo[i].lower, intervalo[i].upper);
    }

    
}