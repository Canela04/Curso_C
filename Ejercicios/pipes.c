#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<wait.h>

#define MSGSIZE 16//Contaste del tamaño del mensaje, se ira leyendo de 16 caracteres

int main(int argc, char const *argv[])
{
    FILE * in;
    int pid, p[2];

    if (pipe(p) < 0){// = 0, por algun motivo los pipes no puedieron ser creados
        printf("No pude crear los pipes\n");
        return -2;
    }

    if ( !(in = fopen (argv[1], "r"))){//abrir archivo de entrada
        printf("No pude leer el archivo %s\n",argv[1]);//si no funciona
        return -1;
    }

    //Momneto de bifurcacion
    if(pid = fork()){//Si soy el proceso padre
        char buffer[MSGSIZE];
        printf ("++ Soy el padre, Voy a leer desde %s\n", argv[1]);
        while (fgets (buffer, MSGSIZE, in)){//mientras sea posible leer mensaje del tamaño msg size
            printf(" Lei %s. Dime %d: Cual es el caracter mas grande?\n", buffer, pid);//aqui se le pide al proceso hijo cual es el caracter mas grande
            write(p[1], buffer,MSGSIZE);
        }

        close(p[1]);
        printf("Esperando a mis hijos\n");
        wait(NULL);
        fclose(in);
    }else{
        close(p[1]);
        printf("-- Soy el hijo. Espero que aparezca algo en el pipe\n");
        char buffer[MSGSIZE], max;

        while (read(p[0], buffer, MSGSIZE )>0){//lei mas de 0 bytes
            printf("Lei '%s' desde el pipe\n", buffer);
            //Calcular el maximo de los caracteres
            max = buffer[0];
            for (int i = 0; i < MSGSIZE; i++)
            {
                if (buffer[i]> max){
                    max=buffer[i];
                }
            }
        }
        printf("Max: '%c'\n", max);
    }
    //Si si escribes sobre el pipe 1 el pipe 0 es el que lee
    return 0;
    
}
