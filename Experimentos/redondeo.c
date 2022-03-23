#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<math.h>

float generateRandomValue(float a, float b) {
    
    float random = ((float) rand()) / (float) RAND_MAX;
    float diff = b - a;
    float r = random * diff;
    return a + r;
}

 int main(int argc, char const *argv[])
 {
     float num;
     num = generateRandomValue(10,100);
     printf("Numero aleatorio: %f\n",num);
     printf("Numero aleatorio: %.2f\n",num);
     printf("\nNumero aleatorio redondeado: %f\n", floorf(num));
     return 0;
 }
 