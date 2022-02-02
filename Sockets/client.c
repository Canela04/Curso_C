#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char const *argv[])
{
    //Argumentos: Direccion ip y puerto a conectar
    if(argc > 2){
        const char *ip;
        int client_socket, numbytes, puerto;
        char buff[100];
        puerto = atoi( argv[2]);
        ip=argv[1];

        struct sockaddr_in server;//informacion del servidor a conectar
        //convertir argumento en una direccion ip como utilizar
        if(inet_pton(AF_INET,argv[1], &server.sin_addr )<=0){
            printf("La ip %s no es valida\n", ip);
            return -1;
        }
        printf("Abriendo el socket\n");

        if((client_socket = socket( AF_INET, SOCK_STREAM, 0 ) )== -1 ){
            perror("No pude abrir el socket\n");
            return -2;
        }

        server.sin_family = AF_INET;//familia protocolos de internet
        server.sin_port = htons(puerto);//conectaremos al puerto del dato resultante recibido
        bzero( &(server.sin_zero), 8);

        //intentando la conexion
        printf("Conectando a %s:%s\n", argv[1], argv[2]);
        //comprobar si la conexion se pudo realizar
        if( connect(client_socket, (struct sockaddr *)&server, sizeof(struct sockaddr))== -1){
            perror("no pude conectarme al servidor");
            return -3;
        }

        printf("Recibiendo...\n");
        //verificar si hay algo para recibir
        if((numbytes = recv(client_socket, buff, 100, 0))==-1){
            printf("Error en la lectura\n");
            return -4;
        }
        buff[numbytes]='\0';//agregar la contra barra 0 al buffer que nos dio

        printf("El servidor envio el mensaje '%s'\n", buff);
        shutdown(client_socket, 2);

    }else{
        printf("Porfavor, indique ip del servidor y puerto\n" );
        return -5;
    }
    
    return 0;
}
