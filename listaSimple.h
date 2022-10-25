#ifndef LISTASIMPLE_H_INCLUDED
#define LISTASIMPLE_H_INCLUDED
#include "estructuras.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct nodoCancion{
	stCancion dato;
	struct nodoCancion * siguiente;
}nodoCancion;

///prototipados

nodoCancion*inicLista();
nodoCancion*crearNodo(stCancion cancion);
nodoCancion*agregarOrdenado(nodoCancion*lista,nodoCancion*nuevoNodo);
nodoCancion*borrarCancion(nodoCancion*lista,char tituloCancion [100]);
stCancion cargaCancion(int* idActual);
void mostrarNodo(nodoCancion*nodoAmostrar);
void mostraLista(nodoCancion*lista);
void mostrarCancion(stCancion cancion);
nodoCancion*buscarCancion(nodoCancion*lista,char titulo[50]);
void reproduciorCancion(nodoCancion*lista,char titulo[50]);
nodoCancion*buscarPorGenero(nodoCancion*lista,char genero[50]);
void reproducirPorId(nodoCancion*lista,int idCancion);
nodoCancion*buscarPorId(nodoCancion*lista,int idCancion);

#endif // LISTASIMPLE_H_INCLUDED
