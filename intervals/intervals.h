#ifndef __INTERVALS_H
#define __INTERVALS_H

typedef struct INTERVAL {
    float lower;
    float upper;
}INTERVAL;

typedef struct COALITION{
    float lowerC;
    float upperC;
    float lowerD;
    float upperD;
}COALITION;

INTERVAL VectorW[100], vectorQ[100], vectorV[100], lambda;
float fkx[10][10];




void run(int);
void initValuesK2();
void initValuesK5();
void initValuesK10();

float PED(INTERVAL, INTERVAL);

float PED2(float  intA, INTERVAL intB);

float coalitions(INTERVAL, float);
COALITION concordance_index(int, int, int);
float discordance_index();
void read_values(char const *);

float outranking();
int XSY();
int xdominatey();

#endif