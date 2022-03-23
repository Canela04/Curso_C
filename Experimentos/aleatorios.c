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

int main(int argc, char const *argv[])
{
    float low;
    srand(time(NULL));
    float x;
    int k , intentos = 0, goOn=1;//cantidad de numeros
    k = 6;
	float base[k], wp[k];
    float tmp, auxLow, auxUp, sumLow=0, sumUp=0, epsilon;
	
	epsilon = 0.03;
	int i, j;

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
		while(goOn){
    		auxLow = 0;
			auxUp = 0;
			for ( i = 0; i < k; i++)
			{
				base[i] = generateRandomValue(0,1);
				//printf("base[%d]= %.2f\n", i+1, base[i]);
			}// 1
			for ( i = 0; i < k; i++)
			{
				if (i==0)
				{
					wp[i] = base[i];
				}else{
					wp[i] = base[i] - base[i-1];
					if (wp[i]<0)
					{
						wp[i]=base[i];
					}	
				}
				//printf("wp[%d]= %.2f\n", i+1, wp[i]);
			}// 2
			for ( i = 0; i < k; i++)
			{
				iVectorW[i].lower = max(0, wp[i] - epsilon);
				iVectorW[i].upper = min(1, wp[i] + epsilon);
				auxLow += iVectorW[i].lower;
				auxUp += iVectorW[i].upper;

			}// 3 y 4
			sumLow = auxLow;
			sumUp = auxUp;
    		if(sumLow<=1 && sumUp >= 1){
				intentos++;
    		    goOn = 0;
    		}else{
				intentos++;
    		    goOn = 1;
    		}
			//printf("SumLow = %.2f\n",sumLow);
			//printf("SumUp = %.2f\n",sumUp);	
		}
		printf("Intentos: %d\n",intentos);	
		for(i = 0;i < k; i++){
			fprintf(archivo, "%.2f %.2f", iVectorW[i].lower, iVectorW[i].upper);
			if(i == (k-1)){
				fprintf(archivo, "\n");
			}else{
				fprintf(archivo, ",");
			}
		}
		//fclose(archivo);
		//printf("Inferiores: %f\nSuperiores: %f\n",sumLow,sumUp);

		//VECTOR INDIFERENCIA
		for(i = 0;i < k; i++){
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
		for(i = 0;i < k; i++){
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
	/*}else{
		char buffer[5000];
    	int linea = 0;
    	while (fgets(buffer,2000,archivo))
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
    	        }//lambda
    	        if(linea == 1){
    	            beta = atof(ptr);
    	        }//beta
    	        if (linea == 2)
    	        {
    	            iVectorW[cont_in].lower= atof(ptr); 
    	            ptr = strtok(NULL, delim);
    	            iVectorW[cont_in].upper= atof(ptr);
    	        }//weight
    	        if (linea == 3)
    	        {
    	            iVectorQ[cont_in].lower= atof(ptr); 
    	            ptr = strtok(NULL, delim);
    	            iVectorQ[cont_in].upper= atof(ptr);
    	        }//indifference
    	        if (linea == 4)
    	        {
    	            iVectorV[cont_in].lower= atof(ptr); 
    	            ptr = strtok(NULL, delim);
    	            iVectorV[cont_in].upper= atof(ptr);
    	        }//veto
    	        ptr = strtok(NULL, delim);
    	        cont_in++;
    	    }
    	    linea++;
    	}
    	fclose(archivo);
	}*/

    return 0;
}


