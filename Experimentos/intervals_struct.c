#include<stdio.h>
#include<stdlib.h>

typedef struct INTERVAL {
    
    char index[1];
    int lower;
    int upper;

} INTERVAL;

void printInterval(INTERVAL intervalo);

int main(int argc, char const *argv[])
{
    INTERVAL i1 = {"A", 4, 10};
    INTERVAL i2 = {"B", 7, 15};
    
    printInterval(i1);
    printInterval(i2);

    return 0;
}

void printInterval(INTERVAL intervalo){
    printf("Intervalo: %s[ %d, %d] \n", intervalo.index, 
    intervalo.lower , intervalo.upper);
}

