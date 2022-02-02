#ifndef __MY_LIB_H//se utiliza para preguntar si ya esta definido algun simbolo
#define __MY_LIB_H
void hello(const char * name);//Firma de la funcion o declaracion de la funcion
#endif
/*
    De esta manera evito que la funcion se defina dos veces
    ya que __MY_LIB_H se va a definir la primera vez que se incluya este archivo,
    es lo que permite tener muchos archivos y en todos esos archivos incluir la misma biblioteca
    no voy a tener problema por que solo va a valer la primera definicion y asi no se preocupa como el compilador maneja los archivos
*/
