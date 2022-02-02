#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

typedef struct INTERVAL {
    float lower;
    float upper;
}INTERVAL;

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


int main()
{
    INTERVAL numI1 = { 6, 9 };      //V
    INTERVAL numI2 = { 5.5, 7.5 };            //Q
    
    float a=10.50, b=12.50, c=8.50, d=12.50;

    /******************/
    float fky_fkx1 = 8.5, fky_fkx2 = 5.8,fky_fkx3 = 3.2;
    INTERVAL Q;
    Q.lower = 3.5;
    Q.upper = 7.0;
    printf("PED diferencia alta: %f\n",PED2(fky_fkx1,Q));
    
    //printf("Intervalo 1 [%f,%f]\n",numI1.lower,numI1.upper);
    //printf("Intervalo 2 [%f,%f]\n",numI2.lower,numI2.upper);

    /*printf("ingresa el valor de [_ , X]\n");
    scanf("%f",intA.lower);

    printf("ingresa el valor de [X , _]\n");
    scanf("%f",intA.upper);

    printf("ingresa el valor de [_ , X]\n");
    scanf("%f",intB.lower);

    printf("ingresa el valor de [X , _]\n");
    scanf("%f",intB.upper);*/

   // printf("Funcion de posibilidad entre intervaloi 1 y 2\nPED= %f\n", PED(numI1, numI2));
    /*INTERVAL sum = suma(a, b, sum);
    INTERVAL sub = intervalSub(numI1, numI2, sub);

    printf("SUMA de intervalo 1 y 2\nSuma:  [ %f , %f ]\n", sum.lower, sum.upper);
    printf("Resta de intervalo 1 y 2\nResta:  [ %f , %f ]\n", sub.lower, sub.upper);/*/

    //Peso W<[0.35,0.70], [0.25,0.35], [0.40,0.60]>

    //Indiferencia Q<[3.5,7.0], [6.5,9.5], [5.5,7.5]>

    //Peso V<[0.,0.70], [0.25,0.35], [0.40,0.60]>

    


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