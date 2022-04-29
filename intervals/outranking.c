#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include"intervals.h"
#include<stdbool.h>
#include<math.h>
int dim;

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

float coalitions(INTERVAL qk, float fky_fkx){
    float ped;
    INTERVAL _qk;
    _qk.lower = (qk.upper*(-1));
    _qk.upper = (qk.lower*(-1));
    ped = PED2 (fky_fkx, _qk);//Cambio revisar implementacion!
    return ped;
}

COALITION concordance_index(int i,int j,int z){
    COALITION sumW;
    sumW.lowerC= 0;
    sumW.upperC= 0;
    sumW.lowerD= 0;
    sumW.upperD= 0;
    sumW.dxy=0;
    
    if(coalitions(vectorQ[z], (fkx[z][i]-fkx[z][j])) >= 0.5 ){
        sumW.lowerC = VectorW[z].lower;
        sumW.upperC = VectorW[z].upper;
    }else{
        sumW.lowerD = VectorW[z].lower;
        sumW.upperD = VectorW[z].upper;
        sumW.dxy = PED2(fkx[z][j]-fkx[z][i],vectorV[z]);
    }
    return sumW;
}

float discordance_index(int i, int j, int z){
    float d_index;
    float max=0 , aux;
    PED2(fkx[z][j]-fkx[z][i],vectorV[z]);
    return d_index;
}

void read_DM(int current_dm, int current_DTLZ){
    char str[100];
	sprintf(str, "DMs/DTLZ%d_%dD_DM%d_config.txt", current_DTLZ, k, current_dm);
    FILE *in = fopen(str, "r");
    if(in==NULL){
        printf("Error en la apertura del archivo de DM: %s\n", str);
        exit(1);
    }
 
    char buffer[5000];
    int linea = 0;

    while (fgets(buffer,2000,in))
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
    	            VectorW[cont_in].lower= atof(ptr); 
    	            ptr = strtok(NULL, delim);
    	            VectorW[cont_in].upper= atof(ptr);
    	        }//weight
    	        if (linea == 3)
    	        {
    	            vectorQ[cont_in].lower= atof(ptr); 
    	            ptr = strtok(NULL, delim);
    	            vectorQ[cont_in].upper= atof(ptr);
    	        }//indifference
    	        if (linea == 4)
    	        {
    	            vectorV[cont_in].lower= atof(ptr); 
    	            ptr = strtok(NULL, delim);
    	            vectorV[cont_in].upper= atof(ptr);
    	        }//veto
    	        ptr = strtok(NULL, delim);
    	        cont_in++;
    	    }
    	    linea++;
    	}
    fclose(in);
    
}

int read_solutions(int current_dm, int current_DTLZ){
    char str2[100];
	sprintf(str2, "Soluciones/DM%d_DTLZ%d_%dD_solutions.txt", current_dm, current_DTLZ, k);
    FILE *in2 = fopen(str2, "r");
    if(in2==NULL){
        printf("Error en la apertura del archivo de soluciones %s\n", str2);
        exit(2);
    }
 
    //char buffer[5000];
    int linea = 0;
    char buffer2[5000];

    while (fgets(buffer2,2000,in2))
    {
    	char delim[] = " ";
    	char *ptr = strtok(buffer2, delim);
    	int cont_in=0;
    	while (ptr != NULL)
    	{
            fky[linea][cont_in] = atof(ptr);
            //printf("%f\t%d\t%d\n",atof(ptr),linea,cont_in);
            ptr = strtok(NULL, delim);
    	    cont_in++;
    	}
    	linea++;
    }
    //printf("tamanio: %d\n", size);
    fclose(in2);
    
    for (int i = 0; i < linea; i++)
    {
        for (int j = 0; j < k; j++)
        {
            //printf("%f \t", fky[i][j]);
            fkx[j][i]=fky[i][j]; 
        }
        //printf("\n");
    }
    //printf("\n\n");
    /*for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 30; j++)
        {
            printf("%f \t", fkx[i][j]);
            //fky[j][i]=fkx[i][j]; 
        }
        printf("\n");
    }*/
    printf("size: %d\nk: %d\n", linea, k);
    return linea;
    
}

bool xdominatey(int i, int j){
	int atleastone = 0;
	int minlimit = 0;

	for(int z = 0; z < k; z++){
		if(fkx[z][i] > fkx[z][j]){
			minlimit++; 
		}
		if(fkx[z][i] > fkx[z][j]){
			atleastone++;
		}
	}

	if(minlimit == 0 && atleastone > 0){
		return 1;
	}else{
		return 0;
	}
}

int xSy(float matrix_sigma[dim][dim], int i, int j){
    if(matrix_sigma[i][j] >= beta){
        return 1;
    }else{
        return 0;
    }
    //return matrix_sigma[i][j] >= beta;
}

int xPry(float matrix_sigma[dim][dim], int i, int j){
    //return xdominatey(i, j) || (xSy(matrix_sigma, i, j) && !xSy(matrix_sigma, j, i));
    if(xdominatey(i, j) || (xSy(matrix_sigma, i, j) && !xSy(matrix_sigma, j, i))){
        return 1;
    }else{
        return 0;
    }
}

float chebyshev(float xi, float x){
    // float d;
    // printf("%f - %f = %f\n", xi, x, xi-x);
    // d = xi-x;
    // printf("%f\n",fabs(xi-x));

    return fabs(xi-x);
}

int compare(const void *p1, const void *p2){
	// float a, b;
	// a = *(float *) p;
	// b = *(float *) q;
    // //menor a mayor
	// if(a<b){
	// 	return -1;
	// }
	// if (a==b){
	// 	return 0;
	// }
	// return 1;

    SOLUTION *a, *b;
	double anorm, bnorm;
	a = (SOLUTION *)p1;
	b = (SOLUTION *)p2;

	//programar:
	/*
		Si A tiene un valor menor que B en strictOR: implia que A es mejor
			Como A es mejor: se devuelve numero positivo
		Si B tiene un valor menor que A en strictOR: implia que B es mejor
			Devolver numero negativo
		Si A.strictOR = B.strictOR
			Si A tiene un valor mas grande que B en weakOR Entonces A es mejor
				Como A es mejor devuelve un positivo
			Si B tiene un valor mas grande que A en weakOR Entonces B es mejor
				Devuelve negativo
			
	*/
	if(a->_xPry < b->_xPry){
		return -1;
	}
	
	if(a->_xPry > b->_xPry){
		return 1;
	}
	if (a->_xPry == b->_xPry)
	{
		if(a->_xSy > b->_xSy) {
			return -1;
		}else if (a->_xSy < b->_xSy){
			return 1;
		}
		
	}
	return 0;
}

float euclidiana(float xi, float x){
    float d;
    d=sqrt(pow((x-xi),2));
    return d;
}

void run(int current_dm, int current_DTLZ, int size){
    dim = size;
    printf("inicia outranking de DM%d_DTLZ%d_%dD.txt\n", current_dm, current_DTLZ, k);
    printf("sizee= %d\n", size);
    INTERVAL C_XY[size][size];
   printf("breakpoint 0.3\n");
    float sigma[size][size];
    printf("breakpoint 0.6\n");
    float d_XY[size][size];
    printf("breakpoint 0.9\n");
    COALITION sumW;
    printf("breakpoint 1\n");
    for (int i = 0; i < size; i++)
    {   
        for (int j = 0; j < size; j++)
        {
            float wk_lowerC = 0, wk_upperC=0, wk_lowerD = 0, wk_upperD = 0, dxy=-999999;
            if(i != j){

                for (int z = 0; z < k; z++)
                {
                    sumW = concordance_index(i,j,z);
                    wk_lowerC += sumW.lowerC;
                    wk_upperC += sumW.upperC;
                    wk_lowerD += sumW.lowerD;
                    wk_upperD += sumW.upperD;

                    if(sumW.dxy > dxy){
                        dxy = sumW.dxy;
                    }

                }

                if((wk_lowerC + wk_upperD) >= 1){
                    C_XY[i][j].lower=wk_lowerC;
                }else{
                    C_XY[i][j].lower=(1-wk_upperD);
                }
                if ((wk_upperC + wk_lowerD)<=1)
                {
                    C_XY[i][j].upper = wk_upperC;
                }else{
                    C_XY[i][j].upper = (1-wk_lowerD);
                }

                d_XY[i][j] = 1-dxy;

                if(PED(C_XY[i][j],lambda)<d_XY[i][j]){
                    sigma[i][j]=PED(C_XY[i][j],lambda);
                }else{
                    sigma[i][j]=d_XY[i][j];
                }
            }
        } 
    }//matriz analogica de concordancia, discordancia y sigma
    //printf("breakpoint 2\n");

    // for (int i = 0; i < size; i++)
    // {
    //     for (int j = 0; j < size; j++)
    //     {
    //         if(i != j){
    //             xSy_matrix[i][j] = 0;
    //             xPry_matrix[i][j] = 0;
    //         }
            
    //     }
        
    // }
    // int xSyM[k][size];
    // int xPryM[k][size];

    // int xSyM[size];
    // int xPryM[size];
    SOLUTION _x[size]; 
    
        for (int i = 0; i < size; i++)
        {
            _x[i].index = i;
            _x[i]._xSy = 0;
            _x[i]._xPry = 0;
            for (int j = 0; j < size; j++)
            {
                if(i != j){
                    // xSy_matrix[i][j] += xSy(sigma,i,j);
                    // xPry_matrix[i][j] += xPry(sigma,j,i);

                    /*xSyM[k][i] += xSy(sigma,i,j);
                    xPryM[k][i] += xPry(sigma,j,i);*/

                    _x[i]._xSy += xSy(sigma,i,j);
                    _x[i]._xPry += xPry(sigma,j,i);

                }

            }

        }
    //printf("breakpoint 3\n");
    
    qsort(_x, size, sizeof(SOLUTION), (int (*)(const void *, const void *))&compare); 
    printf("Termina outranking\n");
    imprimir_datos(C_XY, d_XY, sigma, _x, current_dm, current_DTLZ, size);
    printf("Terminada validacion DM%d_DTLZ%d_%dD.txt\n\n", current_dm, current_DTLZ, k);
    
}

void imprimir_datos(INTERVAL C_XY[dim][dim], float d_XY[dim][dim], float sigma[dim][dim], SOLUTION _x[dim], int current_dm, int current_DTLZ, int size){
    FILE *arch;
    char str[100];
    sprintf(str, "validaciones/Validacion_de_DM%d_DTLZ%d_%dD.txt", current_dm, current_DTLZ, k);
    arch = fopen(str, "w");
    if(arch == NULL){
		printf("Error! The file %s couldn't be created\n", str);
		exit(-1);
	}
    int i, j;

    // fprintf(arch, "\nIndice de concordancia\n");
    // for (int i = 0; i < size; i++)
    // {
    //     for (int j = 0; j < size; j++)
    //     {   if (i != j)
    //         {
    //             fprintf(arch, "%f,%f\t",C_XY[i][j].lower,C_XY[i][j].upper);
    //         }else{
    //             fprintf(arch,"null\t");
    //         }
            
    //     }
    //     fprintf(arch,"\n");  
    // }

    // fprintf(arch, "\nIndice de  discordancia\n");
    // for (int i = 0; i < size; i++)
    // {
    //     for (int j = 0; j < size; j++)
    //     {   if (i != j)
    //         { 
    //             fprintf(arch, "%f\t",d_XY[i][j]);
    //         }else{
    //             fprintf(arch, "null\t");
    //         }
            
    //     }
    //     fprintf(arch, "\n");  
    // }

    // fprintf(arch, "\nMatrix sigma\n");
    // for (int i = 0; i < size; i++)
    // {
    //     for (int j = 0; j < size; j++)
    //     {   if (i != j)
    //         { 
    //             fprintf(arch, "%f\t",sigma[i][j]);
    //         }else{
    //             fprintf(arch, "null\t");
    //         }
    //     }
    //     fprintf(arch, "\n");  
    // }

    // fprintf(arch, "\nMatrix xSy\n");
    // for (int i = 0; i < size; i++)
    // {
    //     for (int j = 0; j < size; j++)
    //     {   if (i != j)
    //         { 
    //             fprintf(arch, "%d\t", xSy_matrix[i][j]);
    //         }else{
    //             fprintf(arch, "null\t");
    //         }
    //     }
    //     fprintf(arch, "\n");  
    // }

    // fprintf(arch, "\nMatrix xPry\n");
    // for (int i = 0; i < size; i++)
    // {
    //     for (int j = 0; j < size; j++)
    //     {   if (i != j)
    //         { 
    //             fprintf(arch, "%d\t",xPry_matrix[i][j]);
    //         }else{
    //             fprintf(arch, "null\t");
    //         }
    //     }
    //     fprintf(arch, "\n");  
    // }

    // for (int i = 0; i < size; i++)
    // {
    //     for (int j = 0; j < size; j++)
    //     {
    //         for (int z = 0; z < k; z++)
    //         {
    //             if(xSy_matrix[i][j]==0 && xPry_matrix[i][j]==1){
    //                 fprintf(arch, "K%d: %f\n",z,fkx[z][i]);
    //             }
    //         }
            
    //     }
        
    // }
    // for (int i = 0; i < 30; i++)
    // {
    //     for (int j = 0; j < 3; j++)
    //     {
    //         fprintf(arch,"%f \t", fky[i][j]);
    //         //fkx[j][i]=fky[i][j]; 
    //     }
    //     fprintf(arch,"\n");
    // }
    // fprintf(arch,"\n\n");
    // for (int i = 0; i < 3; i++)
    // {
    //     for (int j = 0; j < 30; j++)
    //     {
    //         fprintf(arch,"%f \t", fkx[i][j]);
    //         //fky[j][i]=fkx[i][j]; 
    //     }
    //     fprintf(arch,"\n");
    // }

    //strictOR = xPry
    //weakOR = sXy
    fprintf(arch, "Valores\tSize: %d\n", size);
    int totalsoluciones=0;
    for (int i = 0; i < size; i++)
    {
        fprintf(arch, "Solucion no. %d \t\t", _x[i].index+1);
        fprintf(arch, "xSy: %d  xPry: %d\t\t", _x[i]._xSy,_x[i]._xPry);
        fprintf(arch, "Valores de la solucion: ");
        for (int j = 0; j < k; j++)
        {
            fprintf(arch, "%f ",fkx[j][_x[i].index]);
        }
        fprintf(arch, "\n");
    }

    fprintf(arch, "\nMejores soluciones\n");
    bool original = true; //Original IMOACOr?
	int strictOR = _x[0]._xPry;
	int weakOR = _x[0]._xSy;
    
    for (int i = 0; i < size; i++)
    {
        int breakline = 0;
        for (int j = 0; j < k; j++)
        {
            if (_x[i]._xPry <= strictOR)
            {
                strictOR = _x[i]._xPry;
                if (_x[i]._xSy <= weakOR)
                {
                    weakOR = _x[i]._xSy;
                    fprintf(arch, "%f", fkx[j][_x[i].index]);
                    totalsoluciones++;
                    breakline = 1;
                }
                
            }
            if (j != k - 1 && breakline)
            {
                fprintf(arch, " ");
            }
        }
        if(breakline){
		    fprintf(arch, "\n");
        }
        
    }
    fprintf(arch, "Total: %d\n",totalsoluciones);
    
    //strictOR = xPry
    //weakOR = sXy
    SOLUTION x_;
    x_ = _x[0];

    // fprintf(arch,"\n\n");
    // fprintf(arch, "\nDistancia Ecuclidiana\n");
    // for (int i = 0; i < size; i++)
    // {
    //     if (x_.index != _x[i].index)
    //     {
    //         for (int j = 0; j < k; j++)
    //         {
    //             fprintf(arch,"%f\t",euclidiana(fkx[j][i], fkx[j][x_.index]));
    //         }
    //     }else{
    //         fprintf(arch,"NULL");
    //     }
    //     fprintf(arch,"\n");
        
    // }
    // fprintf(arch,"\n\n");
    // fprintf(arch, "\nDistancia de Chebyshev\n");
    // for (int i = 0; i < size; i++)
    // {
    //     if (x_.index != _x[i].index)
    //     {
    //         for (int j = 0; j < k; j++)
    //         {
    //             fprintf(arch,"%f\t",chebyshev(fkx[j][i], fkx[j][x_.index]));
    //         }
    //     }else{
    //         fprintf(arch,"NULL");
    //     }
    //     fprintf(arch,"\n");
        
    // }
    fclose(arch);
}