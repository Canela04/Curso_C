#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

float generateRandomValue(float a, float b) {
    
    float random = ((float) rand()) / (float) RAND_MAX;
    float diff = b - a;
    float r = random * diff;
    return a + r;
}

int main(int argc, char const *argv[])
{
    float low;
    srand(time(NULL));
    float x;
    //inicializar el generador de numeros aleatorios
    //se le pasa la hora actual
    int k , intentos = 0, goOn=1;//cantidad de numeros
    k = 6;
    float tmp, aux, sum;
while(goOn){
    aux = 0;
    for (int i = 0; i < k; i++)
    {
        tmp = generateRandomValue(0,1)/(1+i);
        aux += tmp;
        printf("Numero %d: %f\n",i+1,tmp);
        /*printf("limite inferior: %f\n", low= generateRandomValue(0.5,1.0));
        printf("Limite superior: %f\n\n", generateRandomValue(low, 1));*/
    }
    sum=aux;
    if(sum<=1){
        goOn = 0;
    }else{
        goOn = 1;
    }
}
printf("Suma: %f\n",sum);
    return 0;
}


