#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include "intervals.h"

int main(int argc, char const *argv[])
{  
    int b = atoi(argv[1]);
    k=b;
    int dm = 1;
    int DTLZs = 1;
    int size;
    //read_values(argv[1], argv[2]);
    //run();
    
    // for ( int i = 1; i <= dm; i++)
    // {
        // for (int j = 1; j <= DTLZs; j++)
        // {
            read_DM(1,2);
            size = read_solutions(1,2);
            run(1, 2, size);
        //}
        
    //}
    
    return 0;
}


