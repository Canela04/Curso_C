#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int number;
	struct Node * next;
} NODE;

NODE * createNode( int number )
{
	NODE * newNode;

	newNode = malloc( sizeof(NODE) );
	newNode->next = NULL;
	newNode->number = number;

	return newNode;
}

//cree una funcion para imprimir la lista enlazada
void imprimirLista(NODE * start){
    
    NODE * current = start;
    while (current) {
		printf( "%d", current->number );
		printf( current->next ? ", " : "\n" );
		current = current->next;
	}
}//imprimr

//funcion eliminar nodo
NODE * eliminarNodo(NODE * start, int number){
    NODE * current = start;//asignar valores para empezar a recorrer
    NODE * next, *previus;//nodos auxiliares que nos serviran para reacomodar la lista

    while (current) {//Comienza el recorrido de la lista para buscar el numero pedido
		if(current->number==number){//Se encuentra el numero solicitado
            if (current==start)//Caso 3 del desafio
            {
                next = start->next;//el nodo next sera a donde apunta next del primer nodo
                free(start);//se borra el inicio
                current=next;//el nodo actual para el recorrido de la lista es igual a next
                start=current;//el inicio(start) queda declarado como el nodo actual del recorrido
            }else{// Caso 2 del desafio
                previus->next = current->next;//el nodo anterior apuntara al next del nodo actual del recorrido
                free(current);// se elimina el nodo solicitado
                current=previus;//el nodo actual para a ser el nodo previo pero apuntando al nodo siguiente que le corresponde
            }  
		}//Caso 1 del desafio, si no se cumplen las condicion la lista se recorre normalmente
		previus = current;//aqui se guarda el nodo anterior, necesario para el caso 2 del desafio
    	current = current->next;// se recorre
	}
	return start;
}//eliminar nodo

void liberarMemoria(NODE * start){
	NODE * next,* current = start;
	while(current){
        next = current->next;
        free( current );
        current = next;
    }

}//Liberar memoria

int main( int argc, const char * arg[] )
{
	NODE * start = NULL, * current, *next;
	char goOn;
	int listSize = 0, number;

	do {
		printf( "La lista contiene %d nodos. Ingrese el siguiente numero (0 para finalizar)\n", listSize );
		scanf("%d", &number );
		if ( number ) {
			if ( !start ) {
				start = createNode( number );
				listSize++;
			} else {
				current = start;
				while ( current->next ) {
					current = current->next;
				}
				current->next = createNode( number );
				listSize++;
			}
			goOn = 1;
		} else {
			goOn = 0;
		}
	} while ( goOn );

	printf( "La lista contiene los numeros: \n" );
    imprimirLista(start);

    printf("Ingresa el numero a eliminar:\n");
    scanf("%d", &number);

    start=eliminarNodo(start,number);
    imprimirLista(start);

	liberarMemoria(start);
    
	return 0;
}