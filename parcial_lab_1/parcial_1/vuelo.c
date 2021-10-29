#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "aerolinea.h"
#include "tipo.h"
#include "destino.h"
#include "avion.h"
#include "vuelo.h"
#include "funcionesValidacion.h"

int altaVuelo(eVuelo listaVuelos[], int tamVuelos, eAvion listaAviones[], int tamAviones, eAerolineas listaAerolineas[], int tamAero, eTipo listaTipos[], int tamTipo, eDestino listaDestinos[], int tamDest, int* pId, int intentos)
{
    int todoOk = 0;
    int indice;
    eVuelo auxVuelo;
    if (listaVuelos != NULL && tamVuelos > 0 && listaAviones != NULL && tamAviones > 0 && listaAerolineas != NULL && tamAero >= 0 && listaTipos != NULL && tamTipo >= 0 && intentos >= 0)
    {
        indice = buscarLibreVuelo(listaVuelos, tamVuelos);
        if (indice == -1)
        {
            printf("\n\nError, sistema esta lleno\n\n");
        }
        else
        {
            auxVuelo.id = *pId;
            (*pId)++;
            if(!peticionIdAvion(&auxVuelo.idAvion, listaAviones, tamAviones, listaAerolineas, tamAero, listaTipos, tamTipo,"Ingrese ID : ", intentos))
            {
                todoOk = 1;
            }
            printf("\n\n");
            if(todoOk == 0 && !peticionIdDestino(&auxVuelo.idDestino, listaDestinos, tamDest, "Ingrese ID : ", intentos))
            {
                todoOk = 1;
            }

            printf("\n\n");
            if(todoOk == 0 && !peticionFecha(&auxVuelo.fecha.dia, &auxVuelo.fecha.mes, &auxVuelo.fecha.anio, "Ingrese Fecha dd/mm/aaaa : ", intentos))
            {
                todoOk = 1;
            }

            if( todoOk == 0)
            {
                auxVuelo.isEmpty = 1;
                listaVuelos[indice] = auxVuelo;
            }
        }
    }
    printf("\n\n");
    return todoOk;
}

int inicializarVuelos(eVuelo lista[], int tam)
{
    int todoOk = 0;
    if (lista != NULL && tam > 0)
    {
        todoOk = 1;
        for (int i = 0; i < tam; i++)
        {
            lista[i].isEmpty = 0;
        }
    }
    return todoOk;
}


int buscarLibreVuelo(eVuelo listaVuelos[], int tamVuelos)
{
    int indice = -1;
    for (int i = 0; i < tamVuelos; i++)
    {
        if (listaVuelos[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

void mostrarVuelo(eVuelo vuelo, eAvion listaAviones[], int tamAviones, eAerolineas listaAerolineas[], int tamAero, eDestino listaDestino[], int tamDestino, eTipo listaTipos[], int tamTipo)
{
    char descripcionAero[20];
    char descripcionTipo[20];
    int capacidad;

    char descripcionDestino[20];
    float precioDestino;

    int idAerolineas;
    int idTipo;

    if (cargarDescripcionAvion(listaAviones, tamAviones, vuelo.idAvion, &idAerolineas, &idTipo, &capacidad) == 1 &&
        cargarDescripcionAerolineas(listaAerolineas, tamAero, idAerolineas, descripcionAero) == 1 &&
        cargarDescripcionTipo(listaTipos, tamTipo, idTipo, descripcionTipo) == 1 &&
        cargarDescripcionDestino(listaDestino, tamDestino, vuelo.idDestino, descripcionDestino, &precioDestino))
    {
        printf("  %6d %18s %13s %18d %20s %15.3f $%6d/%2d/%4d\n",
               vuelo.id,
               descripcionAero,
               descripcionTipo,
               capacidad,
               descripcionDestino,
               precioDestino,
               vuelo.fecha.dia,
               vuelo.fecha.mes,
               vuelo.fecha.anio);
    }

}

int mostrarVuelos(eVuelo listaVuelos[], int tamVuelos, eAvion listaAviones[], int tamAviones, eAerolineas listaAerolineas[], int tamAero, eDestino listaDestinos[], int tamDestino, eTipo listaTipos[], int tamTipo)
{
    int todoOk = 0;
    int flag = 1;
    if (listaAviones != NULL && listaAerolineas != NULL && tamAero > 0 && listaTipos != NULL && tamTipo > 0)
    {
        printf("\n                                            ***** Lista Vuelos *****                                            \n");
        printf("________________________________________________________________________________________________________________\n\n");
        printf("      ID          Aerolinea          Tipo          Capacidad          Descripcion          Precio          Fecha\n");
        printf("_________________________________________________________________________________________________________________\n\n");
        for (int i = 0; i < tamVuelos; i++)
        {
            if (listaVuelos[i].isEmpty == 1)
            {
                mostrarVuelo(listaVuelos[i], listaAviones, tamAviones, listaAerolineas, tamAero, listaDestinos, tamDestino, listaTipos, tamTipo);
                flag = 0;
            }
        }
        if(flag)
        {
            printf("No hay datos para mostrar.\n");

        }
        todoOk = 1;
    }
    printf("\n\n");
    return todoOk;
}


