#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaSimple.h"

typedef struct fila
{
    struct nodoListaReproduccion* primero;
    struct nodoListaReproduccion* ultimo;

} fila ;

typedef struct nodoListaReproduccion
{
    int idCancion;
    struct nodoListaReproduccion* siguiente;
    struct nodoListaReproduccion* anterior;
} nodoListaReproduccion;

///prototipado
nodoListaReproduccion*inicListaRepro();
nodoListaReproduccion*crearNodoLista(int idCancion);
nodoListaReproduccion*agregarAlFinal(nodoListaReproduccion*lista,nodoListaReproduccion*nuevoNodo);
void mostrarNodoDoble(nodoListaReproduccion*aMostrar);
void mostrarListaRepro(nodoListaReproduccion*lista,nodoCancion*listaCanciones);
void inicFila(fila*Filin);
void agregarAFila(fila*filin,int idCancion);
int extraerFila(fila*filin);
int verPrimero(nodoListaReproduccion*primero);
nodoListaReproduccion*borrarPrimero(nodoListaReproduccion*lista);


#endif // FILA_H_INCLUDED
