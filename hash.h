//
// Created by joana on 12/9/2023.
//

#ifndef HASHCERRADO_REDISPERSION_HASH_H
#define HASHCERRADO_REDISPERSION_HASH_H

#endif //HASHCERRADO_REDISPERSION_HASH_H


#include "stdio.h"

typedef struct tipohash {
    int capacidad;
    int tamanio;
    char ** tabla;
}tipohash;

tipohash  creartablahash( int capacidad );
int calcularhash(tipohash *tabla, char *nombre);
int completa( tipohash *tabla);
void agregar(tipohash *tabla, char *nombre);
int existe(tipohash *tabla,char *nombre );
//la posicion es la de colision
void redispersion(tipohash *tabla,char *nombre,int posicion);
void imprimir(tipohash *tabla);


