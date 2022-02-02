#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

typedef struct INTERVAL {
    float lower;
    float upper;
}INTERVAL;

#define PRIMER(_1, ...)  (_1)
#define RESTO(_1, ...) __VA_ARGS__

#define suma(...)                             \
  _Generic(                                   \
    PRIMER(__VA_ARGS__),                      \
    float: intervalSum3,                      \
    INTERVAL:                                 \
      _Generic(PRIMER(RESTO(__VA_ARGS__)),    \
               float: intervalSum1, \
               INTERVAL: intervalSum))(__VA_ARGS__)


float PED(INTERVAL  intA, INTERVAL intB);
INTERVAL intervalSum(INTERVAL  intA, INTERVAL intB, INTERVAL sum);
INTERVAL intervalSub(INTERVAL  intA, INTERVAL intB, INTERVAL sub);
//sobrecarga PWD
float PED1(INTERVAL  intA, float intB);
float PED2(float  intA, INTERVAL intB);
float PED3(float  intA, float intB);
//sobrecarga SUMA
INTERVAL intervalSum1(INTERVAL  intA, float intB, INTERVAL sum);
INTERVAL intervalSum2(float  intA, INTERVAL intB, INTERVAL sum);
INTERVAL intervalSum3(float  intA, float intB, INTERVAL sum);
//Sobrecarga Resta
INTERVAL intervalSub1(INTERVAL  intA, float intB, INTERVAL sub);
INTERVAL intervalSub2(float  intA, INTERVAL intB, INTERVAL sub);
INTERVAL intervalSub3(float  intA, float intB, INTERVAL sub);

float coalitions(INTERVAL qk, float fky_fkx, int i);
INTERVAL concordance_index(float wk_lowerC, float wk_upperC, float wk_lowerD, float wk_upperD);

int main()
{
    INTERVAL VectorW[3], vectorQ[3], vectorV[3], lambda;

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

    //Peso V<[0.,0.70], [0.25,0.35], [0.40,0.60]>
    vectorV[0].lower=4;
    vectorV[0].upper=7.5;

    vectorV[1].lower=7;
    vectorV[1].upper=11;

    vectorV[2].lower=6;
    vectorV[2].upper=9;

    /******************/
    float fky_fkx[3] = {8.5, 2.5, 6.7};
    float wk_lowerC, wk_upperC, wk_lowerD, wk_upperD;
    INTERVAL C_index;

    for (int i = 0; i < 3; i++)
    {  
        if (coalitions(vectorQ[i], fky_fkx[i], i) >= 0.5 ){
            printf("Coalicion de concordancia\n");
            wk_lowerC+=VectorW[i].lower;
            wk_upperC+=VectorW[i].upper;
        }else{
            printf("Coalicion de discordancia\n");
            wk_lowerD += VectorW[i].lower;
            wk_upperD += VectorW[i].upper;
        }
    }
    printf("\nSuma limites inferior en coalicion de concordancia: %f\n",wk_lowerC);
    printf("Suma limites superior en coalicion de concordancia: %f\n",wk_upperC);
    printf("Suma limites inferior en coalicion de discordancia: %f\n",wk_lowerD);
    printf("Suma limites superior en coalicion de discordancia: %f\n",wk_upperD);

    C_index = concordance_index(wk_lowerC,wk_upperC,wk_lowerD,wk_upperD);
    printf("\nIndice de concordancia\nC(x,y)=[ %f, %f ]\n", C_index.lower, C_index.upper);

    return 0;
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

INTERVAL concordance_index(float wk_lowerC, float wk_upperC, float wk_lowerD, float wk_upperD){
    INTERVAL C_index;

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