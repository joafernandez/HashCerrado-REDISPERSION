#include "hash.h"
#include <stdio.h>

int main() {

    tipohash tabla = creartablahash(5);// Creo tabla con cap de 5 nombres

    // Agregar 5 nombres
    agregar(&tabla, "Ana");
    agregar(&tabla, "Elena");
    agregar(&tabla, "Pablo");
    agregar(&tabla, "Sara");
    agregar(&tabla, "Jorge");

    agregar(&tabla, "Marta");   // ACA ME ESTOY PASANDO DE LA CAPACIDAD ,
    // ENTONCES la funcion agregar me va a decir "no se puede agregar"


    if (completa(&tabla)) {
        printf("tabla completa\n");
    } else {
        printf("hay lugar en la tabla\n");
    }

    if(existe(&tabla,"Pablo")){
        printf(" el nombre existe");
    }
    else{
        printf(" el nombre NO  existe");
    }
    imprimir(&tabla);



    return 0;
}



