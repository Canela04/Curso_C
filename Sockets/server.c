/*
    Structuras que permiten manejas la informacion entre comunicacion
    socket: crear sockets
    bind: asociar socket a puerto
    listen: pedirle al sistema operativo que el puerto tiene una conexion abierta para escuchar
    acccept: las peticiones se guardan en una cola y esta estructura toma la primera y le da conexion
    send: envia informacion del lado del servidor
    recv: del lado del cliente recibe informacion
    shutdown: cerrar comunicacion
*/
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char const *argv[])
{
    //Argumento: el puerto en el que queremos que este escuchando
    if(argc > 1){
        //Numero de:
        int server_socket, client_socket, longitud_cliente, puerto;
        
        //Crear el puerto de la convercion del primer argumento
        puerto = atoi(argv[1]);
        
        //variables de estructuras
        struct sockaddr_in server;
        struct sockaddr_in client;

        //Definir variables del servidor
        //configurar el tipo de protocolo a utilizar
        server.sin_family = AF_INET;//constatnte de las librerias
        server.sin_port = htons(puerto);//se crea el puerto
        server.sin_addr.s_addr = INADDR_ANY;//direccion de quien se puede conectar a este servidor
        bzero( &(server.sin_zero), 8);//rellena un string con ceros (el 8 son las posiciones que deben ser 0)

        //Crear el socket del servidor y despues ponerlo en modo escucha
        //parametros de funcion socket:(familia de protocolo, protocolo especifico, se configure lo demas por default(0))
        if( ( server_socket = socket ( AF_INET, SOCK_STREAM, 0) ) == -1){
            perror( "No pude abrir el socket\n" );
            return -1;
        }
        
        //conectar socket a puerto
        //bind(socket, puntero a structu de tipo socktaddres, guardar en la variable server, tamaño de structura)
        if ( bind( server_socket, (struct sockaddr *) &server, sizeof(struct sockaddr)) == -1){
            printf( "No pude abrir el puerto %s\n", argv[1] );
            return -2;
            //si esto ocurre posiblemente el puerto ya esta abierto en otra aplicacion
        }

        //listen(ssocket, tamaño de la cola[cuanto clientes pueden ser atendidos en forma simultanea])
        if (listen(server_socket, 5) == -1){
            printf( "No pude ponerme en modo escucha\n");
            return -3;
        }

        longitud_cliente = sizeof( struct sockaddr_in);
        //intentando recibir a nuestro primer cliente
        printf("Esperando clientes..\n");
        if( (client_socket = accept(server_socket, (struct sockaddr *) &client, 
        &longitud_cliente)) == -1){/*decirle al sistema oiperativo que nos de la 
        informacion del primer cliente que esta esperando ser atendido*/
            printf("No pudimos aceptar una conexión\n");
            return -4;
        }

        char str[INET_ADDRSTRLEN];//se copia la direccion del cliente que ingreso
        //(protocolo, direccion a transformar, buffer que se crea, como se debe interpretar la direccion[tamaño maximo del buffer])
        inet_ntop(AF_INET, &(client.sin_addr), str, INET_ADDRSTRLEN);/*
         funcion que transforma una structura direccion en un string que se pueda mostrar*/
        printf("Se conecto un cliente desde %s:%d. Lo saludo\n", str, client.sin_port );
        send(client_socket, "Bienvenido a mi servidor.\n", 26, 0);
        /*26 es el tamaño de lo que estamos enviando, 0 serie de banderas o modificadores dan informacion a la comunicacion*/
        printf("Saludo enviado!\n");
        //cerrar socket que estamos utilizando
        //2 modo de cierre completo, nadie envia ni recibe
        shutdown(client_socket, 2);
        shutdown(server_socket, 2);
    }else{
        printf("Porfavor, indique el puerto\n" );
        return -5;
    }
    //dos sockets se abren en el lado del servidor
    return 0;
}
