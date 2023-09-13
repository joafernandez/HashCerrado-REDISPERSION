
#include "hash.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"


tipohash creartablahash( int capacidad ){
    tipohash *aux= malloc(sizeof (tipohash));    //pido memoria para mi tabla de tipohash es una SOLA!
    aux->capacidad=capacidad;                //le doy cap
    aux->tamanio=0;                         //todavia no tienen nada
    aux->tabla= malloc(sizeof(char *)*capacidad);//ahora pido memoria para la capacidad(punteros) a char*

    for (int i = 0; i < capacidad; i++) {
        aux->tabla[i] = NULL; // Inicializar cada elemento con NULL
    }
    return * aux;

}
int calcularhash(tipohash *tabla, char *nombre) {
    int suma = 0;                        //[J][U][A][N] recorremos vector
    int i;
    for (i = 0; nombre[i] != '\0'; i++) {
        suma += nombre[i];                   //sumamos lo q hay en cada cubito
    }
    return suma % tabla->capacidad;  // Devolver el índice calculado, aplicando el "MODULO" para asegurarse de estar dentro del rango de la tabla
    //o sea la posicion donde deberia ir esa palabra en la tabla
}

int completa(tipohash *tabla) {
    return tabla->tamanio == tabla->capacidad;
}

void agregar(tipohash *tabla, char *nombre){
    if (completa(tabla)){                            //preguntosi esta completa la tabla
        printf("no se puede agregar\n");
        return;}

    else{                                             //calculo la pos , si esa pos esta vacia agrego sino redisp
        int posicion= calcularhash(tabla,nombre);   //llamo a hash
        if  (tabla->tabla[posicion]==NULL){
            tabla->tabla[posicion]=nombre;
            tabla->tamanio++;
        }
        else {
            redispersion(tabla, nombre,posicion); //tabla, el nombre, la posicion ocupada
        }
    }

}

void redispersion(tipohash *tabla,char *nombre,int posicion) {

    int i = posicion + 1; // Recorro de la posicion hacia abajo

    while (i < tabla->capacidad && tabla->tabla[i] != NULL) {
        i++;
    }

    if (i == tabla->capacidad) { // Si llego al final de la tabla ,
        i = 0;                  // vuelvo al principio par recorrer

        while (i < posicion && tabla->tabla[i] != NULL) {
            i++;
        }
    }

}


//EXISTE RECORRIENDO TODA LA TABLA/xq no hay un afuncion eliminar q me diga si un elemento se elimino y fue redisperso
int existe(tipohash *tabla,char *nombre ) {  //recorremos la tabla completa xq el nombre pudo haber sido reubicado
    int i = 0;

    while (i < tabla->capacidad &&  //no se termine la tabla
           (tabla->tabla[i] != NULL &&
            strcmp(tabla->tabla[i], nombre) != 0)) {


        i++;
    }
    return i < tabla->capacidad; //si i finalmente es menor a la capacidad, significa que salio del ciclo
    // y encontro el valor asique es verdadero y retorna 1, si es falso retorna 0

}


void imprimir(tipohash *tabla) {

    printf("Tabla de hashing:\n");
    for (int i = 0; i < tabla->capacidad; ++i) {
        printf("%d -> %s\n", i, tabla->tabla[i]);
    }

}