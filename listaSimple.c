#include "listaSimple.h"

nodoCancion*inicLista()
{
    return NULL;
}

nodoCancion*crearNodo(stCancion cancion)
{
    nodoCancion*nuevoNodo=(nodoCancion*)malloc(sizeof(nodoCancion));
    nuevoNodo->dato=cancion;
    nuevoNodo->siguiente=NULL;
    return nuevoNodo;
}
nodoCancion*agregarOrdenado(nodoCancion*lista,nodoCancion*nuevoNodo)
{
    if(lista==NULL)
    {
        lista=nuevoNodo;
    }
    else if(lista->dato.duracion>=nuevoNodo->dato.duracion)
    {
        nuevoNodo->siguiente=lista;
        lista=nuevoNodo;
    }
    else
    {
        nodoCancion*seguidora=lista;
        nodoCancion*anterior=lista;

        while((seguidora!=NULL)&&(seguidora->dato.duracion<nuevoNodo->dato.duracion))
        {
            anterior=seguidora;
            seguidora=seguidora->siguiente;
        }
        anterior->siguiente=nuevoNodo;
        nuevoNodo->siguiente=seguidora;
    }
    return lista;
}
nodoCancion*borrarCancion(nodoCancion*lista,char tituloCancion [100])
{
    nodoCancion*aBorrar;
    if(lista!=NULL)
    {
        if(strcmp(lista->dato.titulo,tituloCancion)==0)
        {
            aBorrar=lista;
            lista=lista->siguiente;
            free(aBorrar);
        }
        else
        {
            nodoCancion*seguidora=lista;
            nodoCancion*anterior=seguidora;
            while((seguidora!=NULL)&&(strcmp(seguidora->dato.titulo,tituloCancion)!=0))
            {
                anterior=seguidora;
                seguidora=seguidora->siguiente;
            }
            if(seguidora!=NULL)
            {
                printf("se borra %s\n",seguidora->dato.titulo);
                anterior->siguiente=seguidora->siguiente;
                free(seguidora);
            }
        }
    }
    return lista;
}
stCancion cargaCancion(int* idActual)//pido el id anterior por parametro
{
    (*idActual)++;
    stCancion nuevaCancion;
    printf("ingrese el titulo de la cancion\n");
    fflush(stdin);
    gets(nuevaCancion.titulo);
    printf("ingrese el artista\n");
    fflush(stdin);
    gets(nuevaCancion.artista);
    printf("ingrese el albun\n");
    fflush(stdin);
    gets(nuevaCancion.albmun);
    printf("ingrese la duracion de la cancion\n");
    scanf("%i",&nuevaCancion.duracion);
    printf("ingrese el genero de la cancion\n");
    fflush(stdin);
    gets(nuevaCancion.genero);
    nuevaCancion.idCancion=(*idActual);
    nuevaCancion.cantidadReproducciones=0;

    return nuevaCancion;
}
void mostrarNodo(nodoCancion*nodoAmostrar)
{
    printf("TITULO: %s\n",nodoAmostrar->dato.titulo);
    printf("ARTISTA: %s \n",nodoAmostrar->dato.artista);
    printf("ALBMUN: %s \n",nodoAmostrar->dato.albmun);
    printf("DURACION: %i\n",nodoAmostrar->dato.duracion);
    printf("GENERO: %S\n",nodoAmostrar->dato.genero);
    printf("CANT REPRODUCCIONES: %i\n",nodoAmostrar->dato.cantidadReproducciones);
    printf("id cancion: %i\n",nodoAmostrar->dato.idCancion);
}
void mostraLista(nodoCancion*lista)
{
    nodoCancion*seguidora=lista;
    while (seguidora!=NULL)
    {
        printf("\n\n");
        mostrarNodo(seguidora);
        seguidora=seguidora->siguiente;
    }
}
void mostrarCancion(stCancion cancion)
{
    printf("%s\n",cancion.albmun);
    printf("%s\n",cancion.artista);
    printf("%i\n",cancion.cantidadReproducciones);
    printf("%i\n",cancion.duracion);
    printf("%s\n",cancion.genero);
    printf("%i\n",cancion.idCancion);
    printf("%s\n",cancion.titulo);
}
nodoCancion*buscarCancion(nodoCancion*lista,char titulo[50])
{
    nodoCancion*buscado=NULL;
    if(lista!=NULL)
    {
        if(strcmp(lista->dato.titulo,titulo)==0)
        {
            buscado=lista;
        }
        else
        {
            nodoCancion*seguidora=lista;
            while((seguidora!=NULL)&&(strcmpi(seguidora->dato.titulo,titulo)!=0))
            {
                seguidora=seguidora->siguiente;
            }
            if(seguidora!=NULL)
            {
                buscado=seguidora;
            }
        }
    }
    return buscado;
}
void reproduciorCancion(nodoCancion*lista,char titulo[50])
{
    nodoCancion*buscado;
    buscado=buscarCancion(lista,titulo);
    buscado->dato.cantidadReproducciones++;
}
void reproducirPorId(nodoCancion*lista,int idCancion)
{
    nodoCancion*buscado;
    buscado=buscarPorId(lista,idCancion);
    buscado->dato.cantidadReproducciones++;
}
nodoCancion*buscarPorId(nodoCancion*lista,int idCancion)
{
    nodoCancion*seguidora=lista;
    nodoCancion*buscado;
    while((seguidora!=NULL)&&(seguidora->dato.idCancion!=idCancion))
    {
        seguidora=seguidora->siguiente;
    }
    if(seguidora!=NULL)
    {
        buscado=seguidora;
    }
    return buscado;
}
nodoCancion*buscarPorGenero(nodoCancion*lista,char genero[50])
{
    nodoCancion*seguidora=lista;
    nodoCancion*nuevoNodo;
    nodoCancion*enGenero=inicLista();///creo una lista para guardar las canciones de ese genero
    if(lista!=NULL)
    {
        while(seguidora!=NULL)
        {

            if(strcmpi(seguidora->dato.genero,genero)==0)///veo si se cumple la condicion y lo agrego a la lista
            {
                nuevoNodo=crearNodo(seguidora->dato);
                enGenero=agregarOrdenado(enGenero,nuevoNodo);
            }

            seguidora=seguidora->siguiente;

        }
    }
    return enGenero;
}
nodoCancion*buscarPorAlbumn(nodoCancion*lista,char albmun[50])
{
    nodoCancion*seguidora=lista;
    nodoCancion*nuevoNodo;
    nodoCancion*enAlbmun=inicLista();///creo una lista para guardar las canciones de ese albunm
    if(lista!=NULL)
    {
        while(seguidora!=NULL)
        {

            if(strcmpi(seguidora->dato.albmun,albmun)==0)///veo si se cumple la condicion y lo agrego a la lista

            {
                nuevoNodo=crearNodo(seguidora->dato);
                enAlbmun=agregarOrdenado(enAlbmun,nuevoNodo);
            }

            seguidora=seguidora->siguiente;

        }
    }
    return enAlbmun;
}

void persistenciaCanciones(nodoCancion*lista)
{
    FILE*fp;
    fp=fopen("canciones.bin","wb");
    if(fp!=NULL)
    {
        nodoCancion*seguidora=lista;
        while(seguidora!=NULL)
        {
            fwrite(&seguidora->dato,sizeof(stCancion),1,fp);
            seguidora=seguidora->siguiente;
        }
    }
    fclose(fp);

}
nodoCancion*despersistenciaCanciones(int*idCanciones)
{
    nodoCancion*lista=inicLista();
    stCancion nuevaCancion;
    nodoCancion*nuevoNodo;
    FILE*fp;
    fp=fopen("canciones.bin","rb");
    if(fp!=NULL)
    {
        while(fread(&nuevaCancion,sizeof(stCancion),1,fp)>0)
        {
            nuevoNodo=crearNodo(nuevaCancion);
            lista=agregarOrdenado(lista,nuevoNodo);
            (*idCanciones)++;
        }

    }
    fclose(fp);
    return lista;
}
