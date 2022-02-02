#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int number; //supongoamos la lista es de numeros
    struct Node * next;//Estructura autoreferenciada

} NODE;

//Funcion para crear un nuevo nodo
NODE * createNode ( int number )
{
    //La funcion va a devolver un puntero al nodo que se va a crear
    NODE * newNode;

    newNode = malloc( sizeof(NODE) );
    //Asignacion de propiedades

    newNode->next = NULL;//Esto es importante por que define que el siguiente de este nodo siempre sera nulo

    newNode->number = number;//Asignar el dato que realmente nos interesa
    
    return newNode;//La funcion devuelve el puntero al nuevo nodo creado
}

int main(int argc, char const *argv[])
{
    //Crear el puntero del inicio, en null para marcar el nodo inicial
    NODE *start = NULL, *current, *next;
    //Curren es un puntero auxiliar para saber que se esta trabajando el nodo actual

    char goOn;//bandera de continuacion

    int listSize = 0, number;//tamano de la lista y numero a asignar



    do{
        printf("La lista contiene %d nodos. Ingrese el siguiente numero (0 para salir)\n", listSize);
        scanf("%d", &number);
        if ( number ){
            if( !start ){//Si start esta vacio se crea el primer noodo

                start = createNode( number );
                listSize++;

            }else{//En caso contrario ya hay nodos creados

                current = start;//Para saber que es el inicio de la lista
                while(current -> next){//Mientras current tenga algo en su siguiente
                    current = current->next;//current sea el siguiente, esto hace que se avance en los nodos

                }//Cuando esto termina quiere decir que ya no hay nada en siguiente
                current->next = createNode( number );//ahora el siguiente va a ser el nodo a crearse, de esta forma queda encadenado
                listSize++;
            }
            goOn = 1;
        }else{
            goOn = 0;
        }
    }while(goOn);

    current = start;
    printf("La lista contiene los numeros: \n");
    while(current){
        printf("%d", current->number);
        printf(current -> next ? ", ": "\n" );
        current = current->next;
    }

    current = start;
    while(current){
        next = current->next;
        free( current );
        current = next;
    }

    return 0;
}
