#ifndef ESTRUCTURAS_H_INCLUDED
#define ESTRUCTURAS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
typedef struct stCancion
{
    int duracion;
    char artista[50];
    int cantidadReproducciones;
    char genero[50];
    char titulo[50];
    int idCancion;
    char albmun[50];
} stCancion;


#endif // ESTRUCTURAS_H_INCLUDED
