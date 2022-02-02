#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

typedef char NAME[100];

typedef struct INTERVAL{
    NAME name;
    float lower;
    float upper;
}INTERVAL;

void imprimir(INTERVAL * intervalo, int listSize);
float PED(INTERVAL * intervalo, int E, int D);
INTERVAL * createInterval(INTERVAL * intervalo, int i,char buffer[]);
float generateRandomValue(float min, float max);


int main(int argc, const char * argv[])
{
    INTERVAL * vector = NULL;//conjunto de intervalos no limitados
    char buffer[100];
    char opcion[10];
    char ind[100];
    int goOn, vectorSize = 0;
    srand(time(NULL));

    printf("Ingresar intervalos?(y/n)");
    scanf("%1s", opcion);
    if (opcion[0] == 'y')
    {
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
            scanf("%f", &vector[vectorSize].lower);
            
            printf("Intervalo %s, limite superior: \n", buffer);
            scanf("%f", &vector[vectorSize].upper);

            goOn=1;
            vectorSize++;

        }else{
            goOn = 0;
        }

        }while(goOn);

    }else{
        printf("Numero de intervalos?\n");
        scanf("%d", &vectorSize);
        vector = malloc(sizeof(INTERVAL));//

        for(int i=0; i < vectorSize; i++ ){

            * buffer = 'Q'+((char)((i+1)));
            
            vector = createInterval(vector, i, buffer);
            vector = realloc (vector, sizeof(INTERVAL) * (vectorSize + 1));//
        }
    }
    
    imprimir(vector, vectorSize);
    free(vector);
    return 0;   
}//main

float generateRandomValue(float min, float max) {
    float random = ((float) rand()) / (float) RAND_MAX;
    float diff = max - min;
    float r = random * diff;
    return min + r;
}//generateRandomvalue

float PED(INTERVAL * intervalo, int E, int D){
//Modificar para que reciba 2 intervalos diferentes
//Sobrecargar las funcionies para numeros reales
//viernes 5
    float ped;
    float r;

    ped = ( (intervalo[E].upper - intervalo[D].lower)/( ( intervalo[E].upper-intervalo[E].lower ) + ( intervalo[D].upper - intervalo[D].lower) ) );
    if (ped > 1){
        return 1;
    }else if (ped >= 0 && ped <= 1){
        return ped;
    }else{
        return 0;
    }
       
}//PED

INTERVAL * createInterval(INTERVAL * q, int i,char buffer[]){
    float low;
    float up;
    strcpy(q[i].name, buffer);
    q[i].lower = (low = generateRandomValue(0.0,1.0));
    q[i].upper = generateRandomValue(low, 1.0);
    return q;
    
}//createInterval

void imprimir(INTERVAL * intervalo, int listSize){
    int i, j;
    float ped;

    printf("\nEsta es tu lista de intervalos:\n");
    for (i = 0; i < listSize; i++)
    {
        printf("Intervalo: %s[ %f, %f ]\n", intervalo[i].name, intervalo[i].lower, intervalo[i].upper);
    }

    printf("\nValores ped:\n");

    for (i = 0; i < listSize; i++)
    {
        for ( j = 0; j < listSize; j++)
        {
            if(i != j){
                ped = PED(intervalo, i, j);
                printf("PED de %s con %s es= %f\n", intervalo[i].name, intervalo[j].name, ped);
            }else{
                printf("Intervalo %s con %s\n", intervalo[i].name, intervalo[j].name);
            }
        }  
    }
}//imprimir

