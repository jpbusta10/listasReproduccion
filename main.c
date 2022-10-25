#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaSimple.h"
#include "estructuras.h"
#include <stdbool.h>
#include "fila.h"
int main()
{
    nodoCancion*lista;
    nodoCancion*listaAux;
    nodoListaReproduccion*nuevoNodoLista;///nodo doble auxiliar
    nodoListaReproduccion*listaRep=inicListaRepro(); ///lista de reproduccion nodo doble
    listaAux=inicLista();
    bool seguir=true;
    bool seguir2=true;

    int idActual=0;
    int option=0;
    char continuar;
    char auxString[50];

    lista=inicLista();
    stCancion nuevaCancion;
    nodoCancion*nuevoNodo;
    fila listaDeReproduccion;
    inicFila(&listaDeReproduccion);
    while (seguir)
    {
        printf("1.agregar cancion por duracion\n");
        printf("2.borrar cancion\n");
        printf("3.mostrar lista\n");
        printf("4.reproducir una cancion\n");
        printf("5.buscar una cancion\n");
        printf("6.Buscar por genero\n");
        printf("7.Buscar por album\n");
        printf("8.lista de reproduccion\n");
        printf("9. archivo canciones\n");
        scanf("%i",&option);

        switch(option)
        {
        case 1:

            do
            {
                nuevaCancion=cargaCancion(&idActual);
                nuevoNodo=crearNodo(nuevaCancion);
                mostrarNodo(nuevoNodo);
                lista=agregarOrdenado(lista,nuevoNodo);
                printf("desea agregar otra cancion?\n");
                fflush(stdin);
                scanf("%c",&continuar);

            }
            while(continuar=='s'||continuar=='S');
            system("pause");
            system("cls");
            break;
        case 2:
            printf("ingrese el nombre de la cancion que desea borrar:\n");
            fflush(stdin);
            gets(auxString);
            lista=borrarCancion(lista,auxString);
            system("pause");
            system("cls");
            break;
        case 3:
            mostraLista(lista);
            system("pause");
            system("cls");
            break;
        case 4:
            printf("que cancion desea reproducir?\n");
            fflush(stdin);
            gets(auxString);
            reproduciorCancion(lista,auxString);
            system("pause");
            system("cls");
            break;
        case 5:
            printf("ingrese el titulo que desea buscar: \n");
            fflush(stdin);
            gets(auxString);
            nuevoNodo=buscarCancion(lista,auxString);///utilizo nuevoNodo como un auxiliar
            if(nuevoNodo!=NULL)
            {
                printf("la cancancion buscada es:\n");
                mostrarNodo(nuevoNodo);
            }
            else
            {
                printf("no se encontro la cancion");
            }
            system("pause");
            system("cls");
            break;
        case 6:
            listaAux=inicLista();
            printf("ingrese el genero que desea buscar\n");
            fflush(stdin);
            gets(auxString);
            listaAux=buscarPorGenero(lista,auxString);
            mostraLista(listaAux);
            listaAux=inicLista();
            system("pause");
            system("cls");
            break;
        case 7:
            listaAux=inicLista();
            printf("que album desea buscar?\n");
            fflush(stdin);
            gets(auxString);
            listaAux=buscarPorAlbumn(lista,auxString);
            mostraLista(listaAux);
            system("pause");
            system("cls");
            break;
        case 8:
            seguir2=true;

            while (seguir2)
            {
                system ("cls");
                option=0;
                int idReproducido=0;
                int i=0;
                printf("seleccione la opcion deseada:\n");
                printf("1.agregar una cancion\n");
                printf("2.eliminar una cancion\n");
                printf("3.estadisticas de la playlist\n");
                printf("4.reproducir lista\n");
                printf("5.ver lista\n");
                printf("6.volver al menu inicial\n");
                scanf("%i",&option);
                switch(option)
                {
                case 1:
                    mostraLista(lista);
                    printf("que cancion desea agregar\n");
                    scanf("%s",&auxString);
                    nuevoNodo=buscarCancion(lista,auxString);
                    agregarAFila(&listaDeReproduccion,nuevoNodo->dato.idCancion);
                    system("pause");
                    system("cls");
                    break;
                case 4:
                    while(listaDeReproduccion.primero!=NULL)
                    {

                    idReproducido=extraerFila(&listaDeReproduccion);

                    if(idReproducido>0)
                    {
                        nuevoNodo=buscarPorId(lista,idReproducido);
                        reproducirPorId(lista,idReproducido);
                    }

                    }
                    printf("FINALIZO LA LIASTA\n");
                    system("pause");
                    system("cls");
                    break;

                case 5:
                    mostrarListaRepro(&listaDeReproduccion.primero,lista);
                    system("pause");
                    system("cls");
                    break;
                case 6:
                    seguir2=false;
                    system("pause");
                    system("cls");
                    break;




                }
            }
            break;
        case 9:
            option=0;
            printf("1.persistir canciones\n");
            printf("2.despesistir canciones\n");
            scanf("%i",&option);

            switch(option)
            {
            case 1:
                persistenciaCanciones(lista);
                printf("canciones persistidos\n");
                system("pause");
                system("cls");
                break;
            case 2:
                lista=despersistenciaCanciones(&idActual);
                printf("canciones despersistidad\n");
                system("pause");
                system("cls");
                break;

            }
            system("pause");
            system("cls");
            break;




        }
    }


    return 0;
}
