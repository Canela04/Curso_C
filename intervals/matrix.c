#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char const *argv[])
{   
    int row1 = 1500, col1 = 1500;
    int row2 = 1500, col2 = 1500;
    float fkx[row1][col1];
    float fky[row2][col2];
    int x = 0;
    
    
    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col1; j++)
        {
            fkx[i][j] = x++;
            printf("%f\t",fkx[i][j]);
        }
        printf("\n"); 
    }
    printf("\n\n");
    int suma1 = 0, suma2 = 0, i,j;
    for (i = 0; i < row1; i++)
    {
        for (j = 0; j < col1; j++)
        {
            
            /*if (j==0){
                printf("%d\t",fkx[i][j]);
                fky[j][i] = fkx[i][j];
                suma1 += fkx[i][j];
            }
            if (j==1)
            {
                printf("%d\t",fkx[i][j]);
                fky[j][i] = fkx[i][j];
                suma2 +=fkx[i][j];
            }
            if (j==2)
            {
                printf("%d\t",fkx[i][j]);
                fky[j][i] = fkx[i][j];
            }
            */
           fky[j][i] = fkx[i][j];
            
        }
        
        printf("\n");
        
    }

    printf("\n\n");
    for (int i = 0; i < row2; i++)
    {
        for (int j = 0; j <col2; j++)
        {
            //fky[i][j] = x++;
            printf("%f\t",fky[i][j]);
        }
        printf("\n");
        
    }
    //printf("suma1: %d\nsuma2: %d\n",suma1,suma2);
    
    return 0;
}
