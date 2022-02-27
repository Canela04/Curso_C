#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include"intervals.h"
#include<stdbool.h>

float Beta = 0.63;
int k;
int size = 3;

void initValuesK2(){
    fkx[0][0]=12;
    fkx[0][1]=23;
    fkx[0][2]=32;
    fkx[1][0]=42;
    fkx[1][1]=32;
    fkx[1][2]=30;
}

void initValuesK5(){
   /* fk1x[0]= 20;
    fk1x[1]= 25;
    fk1x[2]= 13.90;
    fk1x[3]= 30;
    fk1x[4]= 20;*/
}

void initValuesK10(){
    /*fk1x[0]=20;
    fk1x[1]=25;
    fk1x[2]=8.80;
    fk1x[3]=8;
    fk1x[4]=23.12;
    fk1x[5]=8;
    fk1x[6]=5.30;
    fk1x[7]=23;
    fk1x[8]=20;
    fk1x[9]=9;*/
}

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

/*float outranking(){
    printf("\nC_index [%f,%f]\n", C_index.lower,C_index.upper);
    printf("Lambda [%f,%f]\n", lambda.lower,lambda.upper);

    float cxy_lambda = PED(C_index,lambda);
    printf("PED: Cxy y Lambda: %f\n\n", cxy_lambda);

    if(cxy_lambda < d_index)
    {
        return cxy_lambda;
    }
    else{
        return d_index;
    }

}*/

void read_values(char const *arch){
    
    FILE *in = fopen(arch, "r");
    if(in==NULL){
        perror("Error en la apertura del archivo\n");
        exit(1);
    }

    char caracter;
    int nl = 0;
    int cm = 0, bl = 0;
    char c;
 
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
            }
            if (linea == 1)
            {
                VectorW[cont_in].lower= atof(ptr); 
                ptr = strtok(NULL, delim);
                VectorW[cont_in].upper= atof(ptr);
            }
            if (linea == 2)
            {
                vectorQ[cont_in].lower= atof(ptr); 
                ptr = strtok(NULL, delim);
                vectorQ[cont_in].upper= atof(ptr);
            }
            if (linea == 3)
            {
                vectorV[cont_in].lower= atof(ptr); 
                ptr = strtok(NULL, delim);
                vectorV[cont_in].upper= atof(ptr);
            }

            ptr = strtok(NULL, delim);
            cont_in++;
        }
        linea++;
    }
    fclose(in);
    
    /*printf("Lambda inferior: %f\nLambda Superior: %f\n",lambda.lower,lambda.upper);

    printf("VectorW\n");
    for (int i = 0; i < k; i++)
    {
        printf("Intervalo %d\t[ %f, %f]\n",i+1,VectorW[i].lower,VectorW[i].upper);
    }
    printf("VectorQ\n");
    for (int i = 0; i < k; i++)
    {
        printf("Intervalo %d\t[ %f, %f]\n",i+1,vectorQ[i].lower,vectorQ[i].upper);
    }
    printf("VectorV\n");
    for (int i = 0; i < k; i++)
    {
        printf("Intervalo %d\t[ %f, %f]\n",i+1,vectorV[i].lower,vectorV[i].upper);
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

bool xSy(float matrix_sigma[size][size], int i, int j){
    return matrix_sigma[i][j] >= Beta;
}

bool xPry(float matrix_sigma[size][size], int i, int j){
    return xdominatey(i, j) || (xSy(matrix_sigma, i, j) && !xSy(matrix_sigma, j, i));
}

void run(int m){
    k=m;
    if(k==2){
    initValuesK2();
    }
    if(k==5){
    initValuesK5();
    }
    if(k==10){
    initValuesK10();
    }

    float sigma[size][size];
    INTERVAL C_XY[size][size];
    float d_XY[size][size];

    for (int i = 0; i < size; i++)
    {  
        COALITION sumW; 
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

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if(i != j){

                xSy_matrix[i][j] = xSy(sigma,i,j);
                xPry_matrix[i][j] = xPry(sigma,i,j);
            }
            
        }
        
    }

    printf("\nIndice de concordancia\n");
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {   if (i != j)
            {
                printf("%f,%f\t",C_XY[i][j].lower,C_XY[i][j].upper);
            }else{
                printf("null\t");
            }
            
        }
        printf("\n");  
    }

    printf("\nIndice de  discordancia\n");
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {   if (i != j)
            { 
                printf("%f\t",d_XY[i][j]);
            }else{
                printf("null\t");
            }
            
        }
        printf("\n");  
    }

    printf("\nMatrix sigma\n");
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {   if (i != j)
            { 
                printf("%f\t",sigma[i][j]);
            }else{
                printf("null\t");
            }
        }
        printf("\n");  
    }

    printf("\nMatrix xSy\n");
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {   if (i != j)
            { 
                printf("%d\t",xSy_matrix[i][j]);
            }else{
                printf("null\t");
            }
        }
        printf("\n");  
    }

    printf("\nMatrix xPry\n");
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {   if (i != j)
            { 
                printf("%d\t",xPry_matrix[i][j]);
            }else{
                printf("null\t");
            }
        }
        printf("\n");  
    }

}