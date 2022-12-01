#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include "intervals.h"

int main(int argc, char const *argv[])
{  
    int b = atoi(argv[1]);
    printf("el valor de B es: %d\n", b);
    k=b;
    printf("el valor de K es: %d\n", k);
    int dm = 1;
    int DTLZs = 1;
    int size;
    //read_values(argv[1], argv[2]);
    //run();
    
    // for ( int i = 1; i <= dm; i++)
    // {
        // for (int j = 1; j <= DTLZs; j++)
        // {
            read_DM(1,1);
            size = read_solutions(1,1);
            printf("Size vale: %d\n", size);
            run(1, 1, size);
        //}
        
    //}
    
    return 0;
}


