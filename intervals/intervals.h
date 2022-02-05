#ifndef __INTERVALS_H
#define __INTERVALS_H

typedef struct INTERVAL {
    float lower;
    float upper;
}INTERVAL;

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

#endif