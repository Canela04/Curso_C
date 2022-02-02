#include<stdio.h>

int main()
{
    /* code */
    int n = 5;
    int * pi = &n;

    char c = 'A';
    char * pc = &c;

    printf("Antes pi = %p y pc = %p\n", pi, pc);
    pi++;
    pc++;
    printf("Despues pi = %p y pc = %p\n", pi, pc);

    int * pi2;
    int a=5, b=1;
    pi2 = &a;
    printf("\nAntes a = %d, &a = %p, b = %d, b = %p, pi2 = %p\n", a, &a, b, &b, pi2);
    pi2++;
    *pi2=10;
    printf("Despues a = %d, &a = %p, b = %d, b = %p, pi2 = %p\n", a, &a, b, &b, pi2);

    return 0;
}