#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include"intervals.h"
#include<stdbool.h>

float Beta;
int k;
int size;

float PED(INTERVAL  intA, INTERVAL intB){
    float ped;

    ped = ( (intA.upper - intB.lower)/
    ( ( intA.upper-intA.lower ) + ( intB.upper - intB.lower) ) );

    if (ped > 1){
        return 1;
    }else if (ped >= 0 && ped <= 1){
        return ped;
    }else{
        return 0;
    }
}

float PED2(float  intA, INTERVAL intB){
    float ped;

    ped = ( (intA - intB.lower)/( ( intB.upper - intB.lower) ) );
    /*printf("ped: %f, intA: %f, intB.lower: %f, intB.upper: %f\n",ped, intA, intB.lower, intB.upper);*/
    if (ped > 1){
        return 1;
    }else if (ped >= 0 && ped <= 1){
        return ped;
    }else{
        return 0;
    }
}

float coalitions(INTERVAL qk, float fky_fkx){
    float ped;
    INTERVAL _qk;
    _qk.lower = (qk.upper*(-1));
    _qk.upper = (qk.lower*(-1));
    ped = PED2 (fky_fkx, _qk);//Cambio revisar implementacion!
    return ped;
}

COALITION concordance_index(int i,int j,int z){
    COALITION sumW;
    sumW.lowerC= 0;
    sumW.upperC= 0;
    sumW.lowerD= 0;
    sumW.upperD= 0;
    sumW.dxy=0;
    
    if(coalitions(vectorQ[z], (fkx[z][i]-fkx[z][j])) >= 0.5 ){
        sumW.lowerC = VectorW[z].lower;
        sumW.upperC = VectorW[z].upper;
    }else{
        sumW.lowerD = VectorW[z].lower;
        sumW.upperD = VectorW[z].upper;
        sumW.dxy = PED2(fkx[z][j]-fkx[z][i],vectorV[z]);
    }
    return sumW;
}

float discordance_index(int i, int j, int z){
    float d_index;
    float max=0 , aux;
    PED2(fkx[z][j]-fkx[z][i],vectorV[z]);
    return d_index;
}

void read_values(char const *arch, char const *arch2){
    
    FILE *in = fopen(arch, "r");
    if(in==NULL){
        perror("Error en la apertura del archivo de DM\n");
        exit(1);
    }
 
    char buffer[5000];
    int linea = 0;

    while (fgets(buffer,2000,in))
    {
    	    char delim[] = " ,";
    	    char *ptr = strtok(buffer, delim);
    	    int cont_in=0;
    	    while (ptr != NULL)
    	    {
				if(linea == 0){
    	            lambda.lower = atof(ptr);
    	            ptr = strtok(NULL, delim);
    	            lambda.upper = atof(ptr);
    	        }//lambda
    	        if(linea == 1){
    	            beta = atof(ptr);
    	        }//beta
    	        if (linea == 2)
    	        {
    	            VectorW[cont_in].lower= atof(ptr); 
    	            ptr = strtok(NULL, delim);
    	            VectorW[cont_in].upper= atof(ptr);
    	        }//weight
    	        if (linea == 3)
    	        {
    	            vectorQ[cont_in].lower= atof(ptr); 
    	            ptr = strtok(NULL, delim);
    	            vectorQ[cont_in].upper= atof(ptr);
    	        }//indifference
    	        if (linea == 4)
    	        {
    	            vectorV[cont_in].lower= atof(ptr); 
    	            ptr = strtok(NULL, delim);
    	            vectorV[cont_in].upper= atof(ptr);
    	        }//veto
    	        ptr = strtok(NULL, delim);
    	        cont_in++;
    	    }
    	    linea++;
    	}
    fclose(in);

    FILE *in2 = fopen(arch2, "r");
    if(in2==NULL){
        perror("Error en la apertura del archivo de soluciones\n");
        exit(2);
    }
 
    //char buffer[5000];
    linea = 0;
    char buffer2[5000];

    while (fgets(buffer2,2000,in2))
    {
    	char delim[] = " ";
    	char *ptr = strtok(buffer2, delim);
    	int cont_in=0;
    	while (ptr != NULL)
    	{
            fky[linea][cont_in] = atof(ptr);
            //printf("%f\t%d\t%d\n",atof(ptr),linea,cont_in);
            ptr = strtok(NULL, delim);
    	    cont_in++;
    	}
    	linea++;
    }
    size = linea;
    //printf("tamanio: %d\n", size);
    fclose(in2);

    for (int i = 0; i < 30; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            //printf("%f \t", fky[i][j]);
            fkx[j][i]=fky[i][j]; 
        }
        //printf("\n");
    }
    //printf("\n\n");
    /*for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 30; j++)
        {
            printf("%f \t", fkx[i][j]);
            //fky[j][i]=fkx[i][j]; 
        }
        printf("\n");
    }*/
    
}

bool xdominatey(int i, int j){
	int atleastone = 0;
	int minlimit = 0;

	for(int z = 0; z < k; z++){
		if(fkx[z][i] > fkx[z][j]){
			minlimit++; 
		}
		if(fkx[z][i] > fkx[z][j]){
			atleastone++;
		}
	}

	if(minlimit == 0 && atleastone > 0){
		return 1;
	}else{
		return 0;
	}
}

int xSy(float matrix_sigma[size][size], int i, int j){
    if(matrix_sigma[i][j] >= beta){
        return 1;
    }else{
        return 0;
    }
    //return matrix_sigma[i][j] >= beta;
}

int xPry(float matrix_sigma[size][size], int i, int j){
    //return xdominatey(i, j) || (xSy(matrix_sigma, i, j) && !xSy(matrix_sigma, j, i));
    if(xdominatey(i, j) || (xSy(matrix_sigma, i, j) && !xSy(matrix_sigma, j, i))){
        return 1;
    }else{
        return 0;
    }
}

float chebyshev(float x1, float x){
    
}

float euclidiana(float x1, float x){

}

void run(int m){
    k=m;

    float sigma[size][size];
    INTERVAL C_XY[size][size];
    float d_XY[size][size];
    COALITION sumW;

    for (int i = 0; i < size; i++)
    {   
        for (int j = 0; j < size; j++)
        {
            float wk_lowerC = 0, wk_upperC=0, wk_lowerD = 0, wk_upperD = 0, dxy=-999999;
            if(i != j){

                for (int z = 0; z < k; z++)
                {
                    sumW = concordance_index(i,j,z);
                    wk_lowerC += sumW.lowerC;
                    wk_upperC += sumW.upperC;
                    wk_lowerD += sumW.lowerD;
                    wk_upperD += sumW.upperD;

                    if(sumW.dxy > dxy){
                        dxy = sumW.dxy;
                    }

                }

                if((wk_lowerC + wk_upperD) >= 1){
                    C_XY[i][j].lower=wk_lowerC;
                }else{
                    C_XY[i][j].lower=(1-wk_upperD);
                }
                if ((wk_upperC + wk_lowerD)<=1)
                {
                    C_XY[i][j].upper = wk_upperC;
                }else{
                    C_XY[i][j].upper = (1-wk_lowerD);
                }

                d_XY[i][j] = 1-dxy;

                if(PED(C_XY[i][j],lambda)<d_XY[i][j]){
                    sigma[i][j]=PED(C_XY[i][j],lambda);
                }else{
                    sigma[i][j]=d_XY[i][j];
                }
            }
        } 
    }//matriz analogica de concordancia, discordancia y sigma

    int xSy_matrix[size][size];
    int xPry_matrix[size][size];

    // for (int i = 0; i < size; i++)
    // {
    //     for (int j = 0; j < size; j++)
    //     {
    //         if(i != j){
    //             xSy_matrix[i][j] = 0;
    //             xPry_matrix[i][j] = 0;
    //         }
            
    //     }
        
    // }
    int xSyM[size];
    int xPryM[size];

    for (int i = 0; i < size; i++)
    {
        xSyM[i]=0;
        xPryM[i]=0;
        for (int j = 0; j < size; j++)
        {
            if(i != j){
                // xSy_matrix[i][j] += xSy(sigma,i,j);
                // xPry_matrix[i][j] += xPry(sigma,j,i);
                xSyM[i] += xSy(sigma,i,j);
                xPryM[i] += xPry(sigma,j,i);

            }
            
        }
        
    }

    
    imprimir_datos(C_XY, d_XY, sigma, xSyM, xPryM);
    printf("Terminador\n");
    

}

void imprimir_datos(INTERVAL C_XY[size][size], float d_XY[size][size], float sigma[size][size],int xSyM[size], int xPryM[size]){
    FILE *arch;
    char str[100];
    sprintf(str, "resultados.txt");
    arch = fopen(str, "w");
    if(arch == NULL){
		printf("Error! The file %s couldn't be created\n", str);
		exit(-1);
	}
    int i, j;

    fprintf(arch, "\nIndice de concordancia\n");
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {   if (i != j)
            {
                fprintf(arch, "%f,%f\t",C_XY[i][j].lower,C_XY[i][j].upper);
            }else{
                fprintf(arch,"null\t");
            }
            
        }
        fprintf(arch,"\n");  
    }

    fprintf(arch, "\nIndice de  discordancia\n");
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {   if (i != j)
            { 
                fprintf(arch, "%f\t",d_XY[i][j]);
            }else{
                fprintf(arch, "null\t");
            }
            
        }
        fprintf(arch, "\n");  
    }

    fprintf(arch, "\nMatrix sigma\n");
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {   if (i != j)
            { 
                fprintf(arch, "%f\t",sigma[i][j]);
            }else{
                fprintf(arch, "null\t");
            }
        }
        fprintf(arch, "\n");  
    }

    // fprintf(arch, "\nMatrix xSy\n");
    // for (int i = 0; i < size; i++)
    // {
    //     for (int j = 0; j < size; j++)
    //     {   if (i != j)
    //         { 
    //             fprintf(arch, "%d\t", xSy_matrix[i][j]);
    //         }else{
    //             fprintf(arch, "null\t");
    //         }
    //     }
    //     fprintf(arch, "\n");  
    // }

    // fprintf(arch, "\nMatrix xPry\n");
    // for (int i = 0; i < size; i++)
    // {
    //     for (int j = 0; j < size; j++)
    //     {   if (i != j)
    //         { 
    //             fprintf(arch, "%d\t",xPry_matrix[i][j]);
    //         }else{
    //             fprintf(arch, "null\t");
    //         }
    //     }
    //     fprintf(arch, "\n");  
    // }

    // for (int i = 0; i < size; i++)
    // {
    //     for (int j = 0; j < size; j++)
    //     {
    //         for (int z = 0; z < k; z++)
    //         {
    //             if(xSy_matrix[i][j]==0 && xPry_matrix[i][j]==1){
    //                 fprintf(arch, "K%d: %f\n",z,fkx[z][i]);
    //             }
    //         }
            
    //     }
        
    // }

    fprintf(arch, "\nValores xSy\n");
    for (int i = 0; i < size; i++)
    {
        
        fprintf(arch, "%d\n", xSyM[i]); 
    }

    fprintf(arch, "\nValores xPry\n");
    for (int i = 0; i < size; i++)
    {
        
        fprintf(arch, "%d\n", xPryM[i]); 
    }
    
    for (int i = 0; i < size; i++)
    {
        fprintf(arch, "Indice: %d\n",i+1);
    }

}