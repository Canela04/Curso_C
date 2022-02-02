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
for (size_t i = 0; i < 10; i++)
{
    printf("limite inferior: %f\n", low= generateRandomValue(0.0,1.0));
    printf("Limite superior: %f\n\n", generateRandomValue(low, 1));
}
    return 0;
}


