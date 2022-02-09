#ifndef __INTERVALS_H
#define __INTERVALS_H

typedef struct INTERVAL {
    float lower;
    float upper;
}INTERVAL;

INTERVAL VectorW[100], vectorQ[100], vectorV[100], lambda, C_index;
int k, coaliciones[100];
float fky_fkx[100];
float fkx_fky[100];
float wk_lowerC, wk_upperC, wk_lowerD, wk_upperD;
float d_index;


void run(int);
void initValuesK3();
void initValuesK5();
void initValuesK10();

float PED(INTERVAL, INTERVAL);
INTERVAL intervalSum(INTERVAL, INTERVAL, INTERVAL);
INTERVAL intervalSub(INTERVAL, INTERVAL, INTERVAL);
//sobrecarga PWD
float PED1(INTERVAL  intA, float intB);
float PED2(float  intA, INTERVAL intB);
float PED3(float  intA, float intB);
//sobrecarga SUMA
INTERVAL intervalSum1(INTERVAL, float, INTERVAL);
INTERVAL intervalSum2(float, INTERVAL, INTERVAL);
INTERVAL intervalSum3(float, float, INTERVAL);
//Sobrecarga Resta
INTERVAL intervalSub1(INTERVAL, float, INTERVAL);
INTERVAL intervalSub2(float, INTERVAL, INTERVAL);
INTERVAL intervalSub3(float, float, INTERVAL);

float coalitions(INTERVAL, float, int);
INTERVAL concordance_index();
float discordance_index();
void read_values();
#endif