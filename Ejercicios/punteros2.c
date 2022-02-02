#include<stdio.h>

void duplicar(int * a)
{
    *a *= 2; 
}

int main()
{
    /* Pasaje por referencia */
    int a = 5;

    printf ("Antes de dupliucar a = %d\n", a);
    duplicar(&a);
    printf ("Despues de dupliucar a = %d\n", a);
    return 0;
}
