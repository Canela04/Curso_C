#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include"intervals.h"

void initValuesK3(){
   
    //fky - fkx
    fky_fkx[0] = 8.5;
    fky_fkx[1] =2.5; 
    fky_fkx[2] =6.7;

    //fkx - fky
    fkx_fky[0]=4.5;
    fkx_fky[1]=2.5;
    fkx_fky[2]=10;

}

void initValuesK5(){
    
    //fky - fkx
    fky_fkx[0] = -7.00;
    fky_fkx[1] = -12.00; 
    fky_fkx[2] = -4.90;
    fky_fkx[3] = -10.00; 
    fky_fkx[4] = -11.00;

    //fkx - fky
    fkx_fky[0]= 7.00;
    fkx_fky[1]= 12.00;
    fkx_fky[2]= 4.90;
    fkx_fky[3]= 10.00;
    fkx_fky[4]= 11.00;
}

void initValuesK10(){
   
    //fky - fkx
    fky_fkx[0] =-7;
    fky_fkx[1] =-12; 
    fky_fkx[2] =1.20;
    fky_fkx[3] =5.00; 
    fky_fkx[4] =-7.42;
    fky_fkx[5] =-3.00;
    fky_fkx[6] =3.80; 
    fky_fkx[7] =4.00;
    fky_fkx[8] =-8.00; 
    fky_fkx[9] =-4.00;

    //fkx - fky
    fkx_fky[0]=7.00;
    fkx_fky[1]=12.00;
    fkx_fky[2]=-1.20;
    fkx_fky[3]=-5.00;
    fkx_fky[4]=7.42;
    fkx_fky[5]=3.00;
    fkx_fky[6]=-3.80;
    fkx_fky[7]=-4.00;
    fkx_fky[8]=8.00;
    fkx_fky[9]=4.00;
}

void run(int m){
    k=m;
    if(k==3){
    initValuesK3();
    }
    if(k==5){
    initValuesK5();
    }
    if(k==10){
    initValuesK10();
    }

    C_index = concordance_index();
    printf("\nIndice de concordancia\nC(x,y)=[ %f, %f ]\n", C_index.lower, C_index.upper);

    d_index = discordance_index();
    printf("\nIndice de discordancia\nd(x,y)= %f\n", d_index);
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

INTERVAL intervalSum(INTERVAL  intA, INTERVAL intB, INTERVAL sum){
    sum.lower = intA.lower + intB.lower;
    sum.upper= intA.upper + intB.upper;
    return sum;
}

INTERVAL intervalSub(INTERVAL  intA, INTERVAL intB, INTERVAL sub){
    sub.lower = intA.lower - intB.lower;
    sub.upper= intA.upper - intB.upper;
    return sub;
}

//Sobrecarga PED
float PED1(INTERVAL  intA, float intB){
    float ped;

    ped = ( (intA.upper - intB)/( ( intA.upper-intA.lower ) ) );

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

float PED3(float  intA, float intB){
    float ped;

    ped = (intA - intB);

    if (ped >= 1){
        return 1;
    }else{
        return 0;
    }

}

//Sobrecarga SUMA
INTERVAL intervalSum1(INTERVAL  intA, float intB, INTERVAL sum){
    sum.lower = intA.lower + intB;
    sum.upper= intA.upper + intB;
    return sum;
}

INTERVAL intervalSum2(float  intA, INTERVAL intB, INTERVAL sum){
    sum.lower = intA + intB.lower;
    sum.upper= intA+ intB.upper;
    return sum;
}

INTERVAL intervalSum3(float  intA, float intB, INTERVAL sum){
    sum.lower = intA + intB;
    sum.upper= intA + intB;
    return sum;
}

//Sobrecarga RESTA
INTERVAL intervalSub1(INTERVAL  intA, float intB, INTERVAL sub){
    sub.lower = intA.lower - intB;
    sub.upper= intA.upper - intB;
    return sub;
}

INTERVAL intervalSub2(float  intA, INTERVAL intB, INTERVAL sub){
    sub.lower = intA - intB.lower;
    sub.upper= intA - intB.upper;
    return sub;
}

INTERVAL intervalSub3(float  intA, float intB, INTERVAL sub){
    sub.lower = intA - intB;
    sub.upper= intA - intB;
    return sub;
}

float coalitions(INTERVAL qk, float fky_fkx, int i){
    float ped;
    INTERVAL _qk;
    _qk.lower = (qk.upper*(-1));
    _qk.upper = (qk.lower*(-1));
    //printf("Valores de qk en coalicion [%f,%f]\n",_qk.lower, _qk.upper);
    ped = PED2 (fky_fkx, _qk);//Cambio revisar implementacion!
    printf("\nPED con %f, es = %f\n", fky_fkx, ped);
    return ped;
}

INTERVAL concordance_index(){
    
    for (int i = 0; i < k; i++)
    {  
        if(coalitions(vectorQ[i], fky_fkx[i], i) >= 0.5 ){
            printf("Coalicion de concordancia\n");
            wk_lowerC+=VectorW[i].lower;
            wk_upperC+=VectorW[i].upper;
            coaliciones[i]=1;
        }else{
            printf("Coalicion de discordancia\n");
            wk_lowerD += VectorW[i].lower;
            wk_upperD += VectorW[i].upper;
            coaliciones[i]=0;
        }
    }
    printf("\nWk_lowerC= %f\n",wk_lowerC);
    printf("Wk_upperC= %f\n",wk_upperC);
    printf("Wk_lowerD= %f\n",wk_lowerD);
    printf("Wk_upperD= %f\n",wk_upperD);

    if((wk_lowerC + wk_upperD) >= 1){
        C_index.lower=wk_lowerC;
    }else{
        C_index.lower=(1-wk_upperD);
    }

    if ((wk_upperC + wk_lowerD)<=1)
    {
        C_index.upper = wk_upperC;
    }else{
        C_index.upper = (1-wk_lowerD);
    }

    return C_index;
    
}

float discordance_index(){

    float max=0 , aux;
    for (int i = 0; i < k; i++)
    {
        if (coaliciones[i]==0)
        {
            aux = PED2(fkx_fky[i], vectorV[i]);
            if (aux > max)
            {
                max = aux;
            }
            
        }
        
    }
    d_index = 1 - max;
    return d_index;
    
}

void read_values(char *arch, int k){
    
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
    
    printf("Lambda inferior: %f\nLambda Superior: %f\n",lambda.lower,lambda.upper);

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
    }

}