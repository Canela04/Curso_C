#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<math.h>

typedef struct INTERVAL {
    float lower;
    float upper;
}INTERVAL;

INTERVAL iVectorW[100], iVectorQ[100], iVectorV[100], lambda;
float beta;

float generateRandomValue(float a, float b) {
    
    float random = ((float) rand()) / (float) RAND_MAX;
    float diff = b - a;
    float r = random * diff;
    return a + r;
}

float max(float a, float b){
	float result;
	   if (a > b)
	      result = a;
	   else
	      result = b;
	   return result;
}

float min(float a, float b){
	float result;
	   if (a < b)
	      result = a;
	   else
	      result = b;
	   return result;
}

int compare_float(const void *p, const void *q){
	float a, b;
	a = *(float *) p;
	b = *(float *) q;
	//menor a mayor
	if(a<b){
		return -1;
	}
	if (a==b){
		return 0;
	}
	return 1;
}

int main(int argc, char const *argv[])
{
	char buffer[100];
	int goOn=1;
	while (goOn)
	{
	
    float low;
    srand(time(NULL));
    float x;
    int k , intentos = 0;//cantidad de numeros
    k = 3;
	float base[k], wp[k];
    float tmp, auxLow=0, auxUp=0, sumLow=0, sumUp=0, epsilon;
	
	epsilon = 0.03;

	FILE *archivo;
	char str[100];
	sprintf(str, "output.txt");
	archivo = fopen(str, "r");
	float tempweight = 0;
    //RANDOM SEED
	//if(archivo == NULL){
		printf("The file %s couldn't be found... creating..\n", str);
		archivo = fopen(str, "w");
		//LAMBDA
		lambda.lower = generateRandomValue(0.5, 0.65);
        lambda.upper = lambda.lower + 0.05;
        
		fprintf(archivo, "%.2f %.2f\n", lambda.lower,lambda.upper);

		//BETA
		beta = 0.5;
		fprintf(archivo, "%.2f\n", beta);

		//VECTOR DE PESOS
		/*while(goOn){
			auxLow = 0;
			auxUp = 0;*/
			for (int i = 0; i < k; i++)
			{
				base[i] = generateRandomValue(0,1);
				printf("base[%d]= %.2f\n", i+1, base[i]);
				
			}// 1
			qsort(base, k, sizeof(float), &compare_float);
			printf("Ordenado\n");
			for (int i = 0; i < k; i++)
			{
				printf("base[%d]= %.2f\n", i+1, base[i]);
			}// 1.5

			//correccion: generar n-1, numeros aleatorios
			for ( int i = 0; i < k; i++)
			{
				if (i==0)
				{
					wp[i] = base[i];
				}
				if (i==(k-1)){
					wp[i] = 1 - base[i-1];	
				}else{
					wp[i] = base[i] - base[i-1];
				}
				//printf("wp[%d]= %.2f\n", i+1, wp[i]);
			}// 2
			for (int i = 0; i < k; i++)
			{
				iVectorW[i].lower = max(0, wp[i] - epsilon);
				iVectorW[i].upper = min(1, wp[i] + epsilon);
				auxLow += iVectorW[i].lower;
				auxUp += iVectorW[i].upper;
				//printf("Intervalo[%d]:%.2f %.2f\n", i+1,iVectorW[i].lower, iVectorW[i].upper);
			}// 3 y 4
			/*sumLow = auxLow;
			sumUp = auxUp;
			if(sumLow<=1 && sumUp >= 1){
				intentos++;
    		    goOn = 0;
    		}else{
				intentos++;
    		    goOn = 1;
    		}

		}
		printf("Intentos: %d\n",intentos);*/



		for(int i = 0;i < k; i++){
			fprintf(archivo, "%.2f %.2f", iVectorW[i].lower, iVectorW[i].upper);
			if(i == (k-1)){
				fprintf(archivo, "\n");
			}else{
				fprintf(archivo, ",");
			}
		}
		//fclose(archivo);
		printf("\nInferiores: %f\nSuperiores: %f\n",auxLow,auxUp);

		//VECTOR INDIFERENCIA
		for(int i = 0;i < k; i++){
			iVectorQ[i].lower = generateRandomValue(0.01, 0.04);
			iVectorQ[i].upper = generateRandomValue(iVectorQ[i].lower + 0.01, 0.06);
			fprintf(archivo, "%.2f %.2f", iVectorQ[i].lower, iVectorQ[i].upper);
			if(i == (k-1)){
				fprintf(archivo, "\n");
			}else{
				fprintf(archivo, ",");
			}
		}

		//VECTOR DE VETO
		for(int i = 0; i < k; i++){
			iVectorV[i].lower = generateRandomValue(iVectorQ[i].upper  * 3, (iVectorQ[i].upper * 4));
			iVectorV[i].upper = generateRandomValue(iVectorV[i].lower, (iVectorV[i].lower * 2));
			fprintf(archivo, "%.2f %.2f", iVectorV[i].lower, iVectorV[i].upper);
			if(i == (k-1)){
				fprintf(archivo, "\n");
			}else{
				fprintf(archivo, ",");
			}
		}

		fclose(archivo);
		printf("Precione 0 para terminar\n");
		scanf("%99s", buffer);
		if (strcmp("0", buffer) == 0){
			goOn =0;
		}
	}
    return 0;
}


