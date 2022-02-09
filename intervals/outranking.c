#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include"intervals.h"

void initValuesK3(){
    //Lambda
    lambda.lower=0.57;
    lambda.upper=0.89;

    //Peso W<[0.35,0.70], [0.25,0.35], [0.40,0.60]>
    VectorW[0].lower=0.35;
    VectorW[0].upper=0.70;

    VectorW[1].lower=0.25;
    VectorW[1].upper=0.35;

    VectorW[2].lower=0.40;
    VectorW[2].upper=0.60;

    //Indiferencia Q<[3.5,7.0], [6.5,9.5], [5.5,7.5]>
    vectorQ[0].lower=3.5;
    vectorQ[0].upper=7;

    vectorQ[1].lower=6.5;
    vectorQ[1].upper=9.5;

    vectorQ[2].lower=5.5;
    vectorQ[2].upper=7.5;

    //Veto V<[0.,0.70], [0.25,0.35], [0.40,0.60]>
    vectorV[0].lower=4;
    vectorV[0].upper=7.5;

    vectorV[1].lower=7;
    vectorV[1].upper=11;

    vectorV[2].lower=6;
    vectorV[2].upper=9;

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
    //Lambda
    lambda.lower=0.57;
    lambda.upper=0.89;

    //Peso W
    VectorW[0].lower=0.15;
    VectorW[0].upper=0.33;

    VectorW[1].lower=0.11;
    VectorW[1].upper=0.37;

    VectorW[2].lower=0.07;
    VectorW[2].upper=0.23;

    VectorW[3].lower=0.03;
    VectorW[3].upper=0.17;
    
    VectorW[4].lower=0.17;
    VectorW[4].upper=0.31;

    //Indiferencia Q
    vectorQ[0].lower=4.30;
    vectorQ[0].upper=8.3;

    vectorQ[1].lower=6.50;
    vectorQ[1].upper=9.5;

    vectorQ[2].lower=5.50;
    vectorQ[2].upper=6.3;

    vectorQ[3].lower=8.70;
    vectorQ[3].upper=12.30;

    vectorQ[4].lower=9.00;
    vectorQ[4].upper=12.70;

    //Veto V
    vectorV[0].lower=4.40;
    vectorV[0].upper=8.50;

    vectorV[1].lower=7.70;
    vectorV[1].upper=12.30;

    vectorV[2].lower=5.91;
    vectorV[2].upper=7.20;

    vectorV[3].lower=8.80;
    vectorV[3].upper=13.00;

    vectorV[4].lower=9.30;
    vectorV[4].upper=13.00;

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
    //Lambda
    lambda.lower=0.57;
    lambda.upper=0.89;

    //Peso W
    VectorW[0].lower=0.15;
    VectorW[0].upper=0.33;

    VectorW[1].lower=0.11;
    VectorW[1].upper=0.37;

    VectorW[2].lower=0.07;
    VectorW[2].upper=0.23;

    VectorW[3].lower=0.03;
    VectorW[3].upper=0.17;
    
    VectorW[4].lower=0.17;
    VectorW[4].upper=0.31;

    VectorW[5].lower=0.13;
    VectorW[5].upper=0.22;

    VectorW[6].lower=0.05;
    VectorW[6].upper=0.20;

    VectorW[7].lower=0.15;
    VectorW[7].upper=0.30;

    VectorW[8].lower=0.04;
    VectorW[8].upper=0.24;
    
    VectorW[9].lower=0.07;
    VectorW[9].upper=0.31;

    //Indiferencia Q
    vectorQ[0].lower=4.30;
    vectorQ[0].upper=8.3;

    vectorQ[1].lower=6.50;
    vectorQ[1].upper=9.5;

    vectorQ[2].lower=5.50;
    vectorQ[2].upper=7.5;

    vectorQ[3].lower=8.70;
    vectorQ[3].upper=12.30;

    vectorQ[4].lower=6.12;
    vectorQ[4].upper=8.24;

    vectorQ[5].lower=5.30;
    vectorQ[5].upper=9.60;

    vectorQ[6].lower=3.80;
    vectorQ[6].upper=6.10;

    vectorQ[7].lower=2.10;
    vectorQ[7].upper=7.70;

    vectorQ[8].lower=4.66;
    vectorQ[8].upper=7.33;

    vectorQ[9].lower=1.50;
    vectorQ[9].upper=4.70;

    //Veto V
    vectorV[0].lower=4.40;
    vectorV[0].upper=8.50;

    vectorV[1].lower=7.70;
    vectorV[1].upper=12.30;

    vectorV[2].lower=6.30;
    vectorV[2].upper=9.10;

    vectorV[3].lower=9.10;
    vectorV[3].upper=13.00;

    vectorV[4].lower=6.75;
    vectorV[4].upper=8.70;

    vectorV[5].lower=5.50;
    vectorV[5].upper=10.00;

    vectorV[6].lower=4.50;
    vectorV[6].upper=8.30;

    vectorV[7].lower=3.33;
    vectorV[7].upper=8.31;

    vectorV[8].lower=5.27;
    vectorV[8].upper=8.12;

    vectorV[9].lower=2.30;
    vectorV[9].upper=5.81;

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

void read_values(){
    
}