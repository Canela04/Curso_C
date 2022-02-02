#include <stdio.h>
int main()
{
    int number = 109;
    int * pointToNumber = &number;
    
    printf("%p, %d\n", pointToNumber, *pointToNumber);
    /*se usa & para refenciar la direccion de memoria
        pointToNumber apunta a la direccion de memoria de number
        *pointToNumber traer el valor almacenado en la direccion de memoria*/
    return 0;
}
