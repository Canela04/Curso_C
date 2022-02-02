#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include<sys/types.h>
#include<unistd.h>

int main(int argc, char const *argv[])
{
    int pid = fork();//variable con el numero de identificaciondel proceso
    //la funcion fork va crear un nuevo proceso que va a ejecutar en principio el mismo codigo que estoy escribiendo, tendre 2 procesos corriendo el mismo codigo

    //como puedo saber si estoy en el proceso padre o proceso hijo?
    if(pid){//pid != 0
        printf("Father PID is %d and SON PID is %d\n",getpid(),pid);
    }else{//pid = 0
        printf("Soy el hijo mi PID es: %d", getpid());
    }

    while (1)
    {
        /* code */
    }
    
    return 0;
}


