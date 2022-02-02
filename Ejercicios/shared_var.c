#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include<sys/types.h>
#include<wait.h>
#include<unistd.h>

int main(int argc, char const *argv[])
{
    int shared = 2;
    int pid = fork();//variable con el numero de identificaciondel proceso
    //la funcion fork va crear un nuevo proceso que va a ejecutar en principio el mismo codigo que estoy escribiendo, tendre 2 procesos corriendo el mismo codigo
    
    //como puedo saber si estoy en el proceso padre o proceso hijo?
    if(pid){//pid != 0
        shared = 1; 
        printf("Father PID is %d and SON PID is %d, shared = %d\n", getpid(), pid, shared);
        wait (NULL);
        printf("soy nuevamente el padre %d\n", shared);
    }else{//pid = 0
        shared = 0;
        printf("Soy el hijo mi PID es: %d, shared: %d\n", getpid(), shared);
        sleep(2);
        //cuando se hace un fork se crea una copia del codigo no se trabaja sobre la misma variable
    }
    
    return 0;
}


