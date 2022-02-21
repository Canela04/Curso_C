#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char const *argv[])
{   float fkx[2][3];
    fkx[0][0]=12;
    fkx[0][1]=23;
    fkx[0][2]=32;
    fkx[1][0]=40;
    fkx[1][1]=32;
    fkx[1][2]=32;
    
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%f\t",fkx[i][j]);
        }
        printf("\n");
        
    }
    
    return 0;
}
