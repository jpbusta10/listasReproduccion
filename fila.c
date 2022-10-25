#include "fila.h"

nodoListaReproduccion*inicListaRepro()
{
    return NULL;
}




nodoListaReproduccion*crearNodoLista(int idCancion) ///nodo para lista de reproduccion
{
    nodoListaReproduccion*nuevoNodo=(nodoListaReproduccion*)malloc(sizeof(nodoListaReproduccion));
    nuevoNodo->idCancion=idCancion;
    nuevoNodo->siguiente=NULL;
    nuevoNodo->anterior=NULL;

    return nuevoNodo;
}

nodoListaReproduccion*agregarAlFinal(nodoListaReproduccion*lista,nodoListaReproduccion*nuevoNodo)
{
    if(lista==NULL)
    {
        lista=nuevoNodo;
    }
    else
    {

        nodoListaReproduccion*seguidora=lista;
        while(seguidora->siguiente!=NULL)
        {
            seguidora=seguidora->siguiente;
        }
        seguidora->siguiente=nuevoNodo;
        nuevoNodo->anterior=seguidora;

    }
    return lista;
}

void mostrarNodoDoble(nodoListaReproduccion*aMostrar)
{
    printf("id: %i\n",aMostrar->idCancion);

}
void mostrarListaRepro(nodoListaReproduccion*lista,nodoCancion*listaCanciones)
{
    nodoListaReproduccion*seguidora=lista;
    nodoCancion*buscado;
    while(seguidora!=NULL)
    {
        buscado=buscarPorId(listaCanciones,seguidora->idCancion);
        mostrarNodo(buscado);
        seguidora=seguidora->siguiente;
    }
}
void inicFila(fila*Filin)
{
    Filin->primero=inicListaRepro();
    Filin->ultimo=inicListaRepro();
}

void agregarAFila(fila*filin,int idCancion)
{
    nodoListaReproduccion*nuevoNodo=crearNodoLista(idCancion);
    if(filin->primero==NULL)
    {
        filin->primero=nuevoNodo;
        filin->ultimo=nuevoNodo;
    }
    else
    {
        filin->primero=agregarAlFinal(filin->primero,nuevoNodo);
        filin->ultimo=nuevoNodo;
    }
}
int extraerFila(fila*filin)
{
    int resp=-1;
    if(filin->primero!=NULL)
    {
        resp=verPrimero(filin->primero);
        printf("%i id en extraer \n",resp);
        filin->primero=borrarPrimero(filin->primero);
        if(filin->primero==NULL)
        {
            printf("entra en segundo if\n");
            filin->ultimo=inicListaRepro();
        }
    }
    return resp;
}
int verPrimero(nodoListaReproduccion*primero)
{
    int resp=-1;
    if(primero!=NULL)
    {
        resp=primero->idCancion;
    }
    return resp;
}
nodoListaReproduccion*borrarPrimero(nodoListaReproduccion*lista)
{
    nodoListaReproduccion*aborrar=lista;
    if(lista!=NULL)
    {
        lista=lista->siguiente;
        printf("siguiente en borrar%i\n",lista->idCancion);
        if(lista==NULL)
        {
            lista->anterior=NULL;
        }
        free(aborrar);
    }
    return lista;
}
