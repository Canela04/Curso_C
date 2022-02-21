#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include"intervals.h"


float Beta = 0.63;
int k;


void initValuesK2(){
    fkx[0][0]=12;
    fkx[0][1]=23;
    fkx[0][2]=32;
    fkx[1][0]=42;
    fkx[1][1]=32;
    fkx[1][2]=30;

    /*for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%f\t",fkx[i][j]);
        }
        printf("\n");
        
    }*/
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
    //printf("Valores de qk en coalicion [%f,%f]\n",_qk.lower, _qk.upper);
    ped = PED2 (fky_fkx, _qk);//Cambio revisar implementacion!
    //printf("\nPED con %f, es = %f\n", fky_fkx, ped);
    return ped;
}

COALITION concordance_index(int i,int j,int z){
    COALITION sumW;
    //float wk_lowerC = 0, wk_upperC=0, wk_lowerD=0, wk_upperD=0;
    sumW.lowerC= 0;
    sumW.upperC= 0;
    sumW.lowerD= 0;
    sumW.upperD= 0;
    
    if(coalitions(vectorQ[z], (fkx[z][i]-fkx[z][j])) >= 0.5 ){
        /*printf("Concordancia K=%d! resta:[%f] - [%f]\n",z,fkx[z][i],fkx[z][j]);*/
        sumW.lowerC = VectorW[z].lower;
        sumW.upperC = VectorW[z].upper;
        /*printf("comprobar lowerC: %f\t%f\n",VectorW[z].lower,sumW.lowerC);
        printf("Comprobar upperC: %f\t%f\n",VectorW[z].upper,sumW.upperC);*/

    }else{
        //printf("Coalicion de discordancia\n");
        /*printf("Discordancia K=%d! resta:[%f] - [%f]\n",z,fkx[z][i],fkx[z][j]);*/
        sumW.lowerD = VectorW[z].lower;
        sumW.upperD = VectorW[z].upper;
        /*printf("comprobar lowerD: %f\t%f\n",VectorW[z].lower,sumW.lowerD);
        printf("Comprobar upperD: %f\t%f\n",VectorW[z].upper,sumW.upperD);*/
        
    }
    //printf("\n");
    /*printf("\nWk_lowerC= %f\n",wk_lowerC);
    printf("Wk_upperC= %f\n",wk_upperC);
    printf("Wk_lowerD= %f\n",wk_lowerD);
    printf("Wk_upperD= %f\n",wk_upperD);*/

    /*if((wk_lowerC + wk_upperD) >= 1){
        C_index.lower=wk_lowerC;
    }else{
        C_index.lower=(1-wk_upperD);
    }

    if ((wk_upperC + wk_lowerD)<=1)
    {
        C_index.upper = wk_upperC;
    }else{
        C_index.upper = (1-wk_lowerD);
    }*/

    return sumW;
    
}

/*float discordance_index(int index){
    float d_index;
    float max=0 , aux;
    if (coaliciones[index]==0)
    {
        aux = PED2((fkx[index]-fky[index]), vectorV[index]);
        if (aux > max)
        {
            max = aux;
        }
    }
    d_index = 1 - max;
    return d_index;
}*/

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


int xdominatey(int index1, int index2){
	int atleastone = 0;
	int minlimit = 0;
	int i;

	/*for(i = 0; i < k; i++){
		if(T.pheromones[index1].Fx[i] > T.pheromones[index2].Fx[i]){
			minlimit++; 
		}
		if(T.pheromones[index1].Fx[i] < T.pheromones[index2].Fx[i]){
			atleastone++;
		}
	}

	if(minlimit == 0 && atleastone > 0){
		return 1;
	}else{
		return 0;
	}*/
}

/*float sigma_xy(int index){
    float sigma;
    INTERVAL CXY = concordance_index(index);
    float dxy = discordance_index(index);
    float ped_c_lambda = PED(CXY,lambda);

    if (ped_c_lambda<dxy){
        return ped_c_lambda;
    }
    else{
        return dxy;
    }

}*/

int XYS(int index){
    
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
    int size = 3;//tamaño de la solucion
    float sigmaArray[size][size];
    //int xSy[size][size];
    INTERVAL CXY[size][size];

    for (int i = 0; i < size; i++)
    {  
        COALITION sumW;
        //printf("entre ciclo i:%d\n:",i); 
        for (int j = 0; j < size; j++)
        {
            float wk_lowerC = 0, wk_upperC=0, wk_lowerD = 0, wk_upperD = 0;
            //printf("entre ciclo j:%d\n:",j); 
            if(i != j){
                for (int z = 0; z < k; z++)
                {
                    //printf("entre ciclo z%d\n:",z); 
                    sumW = concordance_index(i,j,z);
                    wk_lowerC += sumW.lowerC; 
                    wk_upperC += sumW.upperC; 
                    wk_lowerD += sumW.lowerD; 
                    wk_upperD += sumW.upperD;
                }
                /*printf("lowerC: %f\n",wk_lowerC);
                printf("upperC: %f\n",wk_upperC);
                printf("lowerD: %f\n",wk_lowerD);
                printf("upperD: %f\n",wk_upperD);*/
                if((wk_lowerC + wk_upperD) >= 1){
                    CXY[i][j].lower=wk_lowerC;
                }else{
                    CXY[i][j].lower=(1-wk_upperD);
                }

                if ((wk_upperC + wk_lowerD)<=1)
                {
                    CXY[i][j].upper = wk_upperC;
                }else{
                    CXY[i][j].upper = (1-wk_lowerD);
                }
            }
            
        }
        
    }
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {   if (i != j)
            {
                printf("%f,%f\t",CXY[i][j].lower,CXY[i][j].upper);
            }else{
                printf("null\t");
            }
            
        }
        printf("\n");  
    } 
    
}