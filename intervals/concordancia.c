#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include "intervals.h"

int main(int argc, char const *argv[])
{  
    int b = atoi(argv[1]);
    k=b;
    int dm = 10;
    int DTLZs = 2;
    int size;
    //read_values(argv[1], argv[2]);
    //run();
    
    // for ( int i = 1; i <= dm; i++)
    // {
        // for (int j = 1; j <= DTLZs; j++)
        // {
            read_DM(5,2);
            size = read_solutions(5,2);
            run(5, 2, size);
        //}
        
    //}
    
    return 0;
}


