#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
//Para compilar se requiere el operador -lm library math
int main(int argc, char const *argv[])
{
    int a, b;

    a = atoi(argv[1]);
    b = atoi(argv[2]);

    printf("La hipotenusa mide: %.2f\n", sqrt( pow( a, 2) + pow( b, 2) ));
    return 0;
}
