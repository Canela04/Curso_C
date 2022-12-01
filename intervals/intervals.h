#ifndef __INTERVALS_H
#define __INTERVALS_H
#include<stdbool.h>
#define max(a,b) (a > b) ? a : b

float beta;
int k;
float fky[4000][10], fkx[10][4000], fkz[200][10];
//int size;

typedef struct INTERVAL {
    float lower;
    float upper;
}INTERVAL;

typedef struct COALITION{
    float lowerC;
    float upperC;
    float lowerD;
    float upperD;
    float dxy;
}COALITION;

typedef struct SOLUTION{
    int index;
    int _xSy, _xPry;
}SOLUTION;

INTERVAL VectorW[100], vectorQ[100], vectorV[100], lambda;

void run(int, int, int);

float PED(INTERVAL, INTERVAL);

float PED2(float  intA, INTERVAL intB);

float coalitions(INTERVAL, float);
COALITION concordance_index(int, int, int);
float discordance_index();
void read_DM(int, int);
int read_solutions(int, int);

float outranking();
int xSy(float (*matrix_sigma)[*], int, int);
int xPry(float (*matrix_sigma) [*], int, int);
bool xdominatey();
float chebyshev(float, float);
float euclidiana(float, float);
void find_execution();

#endif