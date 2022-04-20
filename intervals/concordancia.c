#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include "intervals.h"

int main(int argc, char const *argv[])
{  
    int b = atoi(argv[3]);
    read_values(argv[1], argv[2]);
    run(b);
    
    return 0;
}


