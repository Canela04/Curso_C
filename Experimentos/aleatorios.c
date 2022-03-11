#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

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

int main(int argc, char const *argv[])
{
    float low;
    srand(time(NULL));
    float x;
    int k , intentos = 0, goOn=1;//cantidad de numeros
    k = 6;
    float tmp, auxLow, auxUp, sumLow, sumUp;

	//printf("Suma: %f\n",sum);
	int i, j;

	FILE *archivo;
	char str[100];
	sprintf(str, "output.txt");
	archivo = fopen(str, "r");
	float tempweight = 0;
    //RANDOM SEED
	if(archivo == NULL){
		printf("The file %s couldn't be found... creating..\n", str);
		archivo = fopen(str, "w");
		//LAMBDA
        low = generateRandomValue(0.5, 1);
        lambda.upper = generateRandomValue(low, 1);
        lambda.lower = low;
		fprintf(archivo, "%f %f\n", lambda.lower,lambda.upper);

		//BETA
		beta = generateRandomValue(0.5, 1);
		fprintf(archivo, "%f\n", beta);

		//VECTOR DE PESOS
		while(goOn){
    		auxLow = 0;
			auxUp = 0;
    		for (int i = 0; i < k; i++)
    		{
    		    iVectorW[i].lower = generateRandomValue(0,1)/(1+i);
				iVectorW[i].upper = generateRandomValue(iVectorW[i].lower, (iVectorW[i].lower + 1));
    		    auxLow += iVectorW[i].lower;
				auxUp += iVectorW[i].upper;
    		}
    		sumLow= auxLow;
			sumUp = auxUp;
    		if(sumLow<=1 && sumUp >= 1){
    		    goOn = 0;
    		}else{
    		    goOn = 1;
    		}
			
		}
		for(i = 0;i < k; i++){
			fprintf(archivo, "%f %f", iVectorW[i].lower, iVectorW[i].upper);
			if(i == (k-1)){
				fprintf(archivo, "\n");
			}else{
				fprintf(archivo, ",");
			}
		}
		//fclose(archivo);
		printf("Inferiores: %f\nSuperiores: %f\n",sumLow,sumUp);

		//VECTOR INDIFERENCIA
		for(i = 0;i < k; i++){
			iVectorQ[i].lower = generateRandomValue(0, 10);
			iVectorQ[i].upper = generateRandomValue(iVectorQ[i].lower, 15);
			fprintf(archivo, "%f %f", iVectorQ[i].lower, iVectorQ[i].upper);
			if(i == (k-1)){
				fprintf(archivo, "\n");
			}else{
				fprintf(archivo, ",");
			}
		}

		//VECTOR DE VETO
		for(i = 0;i < k; i++){
			iVectorV[i].lower = generateRandomValue(iVectorQ[i].lower, (iVectorQ[i].lower + 3));
			iVectorV[i].upper = generateRandomValue(iVectorQ[i].upper, (iVectorQ[i].upper + 3));
			fprintf(archivo, "%f %f", iVectorV[i].lower, iVectorV[i].upper);
			if(i == (k-1)){
				fprintf(archivo, "\n");
			}else{
				fprintf(archivo, ",");
			}
		}

		fclose(archivo);
		archivo = fopen(str, "r");
	}

	/*char line[5000];
	int contlimiter = 0;
	while( fgets(line,2000,archivo) ) {
		int init_size = strlen(line);
		char delim[] = " ";
		char *ptr = strtok(line, delim);
		int cont_in = 0;
		while(ptr != NULL)
		{
			if(contlimiter == 0){
				Epsilon = atof(ptr);
			}
			if(contlimiter == 1){
				Beta = atof(ptr);
			}
			if(contlimiter == 2){
				Lamdba = atof(ptr);
			}
			if(contlimiter == 3){
				vectorW[cont_in] = atof(ptr);
			}
			if(contlimiter == 4){
				vectorV[cont_in] = atof(ptr);
			}
			if(contlimiter == 5){
				vectorU[cont_in] = atof(ptr);
			}
			if(contlimiter == 6){
				vectorS[cont_in] = atof(ptr);
			}
			ptr = strtok(NULL, delim);
			cont_in++;
		}
		contlimiter++;
	}*/
    return 0;
}


