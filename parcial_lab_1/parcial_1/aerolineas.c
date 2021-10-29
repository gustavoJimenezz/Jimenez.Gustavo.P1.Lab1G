#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "aerolinea.h"

int mostrarAerolineas( eAerolineas listAerolineas[], int tam)
{
    int todoOk = 0;
    if (listAerolineas != NULL && tam > 0 )
    {
        printf("\n      *** Aerolineas ***      \n");
        printf("______________________________\n\n");
        printf("     ID            Descripcion\n");
        printf("______________________________\n\n");
        for (int i = 0; i < tam; i++)
        {
            printf("  %5d       %16s\n", listAerolineas[i].id, listAerolineas[i].descripcion);
        }
        todoOk = 1;
    }
    printf("\n\n");
    return todoOk;
}

int validarIdAerolinea(int id, eAerolineas listaAerolineas[], int tam)
{
    int esValido = 0;
    if (id> 0 && listaAerolineas != NULL && tam > 0)
    {
        for (int i = 0; i < tam; i++)
        {
            if (id == listaAerolineas[i].id)
            {
                esValido = 1;
                break;
            }
        }
    }
    return esValido;
}

int peticionIdAerolineas(int* numId, eAerolineas listaAerolineas[], int tamAero, char texto[], int intentos)
{
    int retorno = 0;
    int numAux;
    int esNum;

    if (listaAerolineas != NULL && texto != NULL && intentos > 0 && numId != NULL)
    {
        mostrarAerolineas(listaAerolineas, tamAero);

        printf("%s", texto);
        esNum = scanf("%d", &numAux);
        fflush(stdin);

        while(numAux <= 0 || esNum != 1 || !validarIdAerolinea(numAux, listaAerolineas, tamAero))
        {
            printf("Error, ID invalido intentos %d\n", intentos);
            printf("%s", texto);
            esNum = scanf("%d", &numAux);
            fflush(stdin);
            intentos--;
            if( intentos == 0)
            {
                break;
            }
        }
        if(intentos != 0)
        {
            *numId = numAux;
            retorno = 1;
        }
    }
    return retorno;
}


int cargarDescripcionAerolineas( eAerolineas listaAerolineas[], int tam, int idAero, char descripcion[])
{
    int todoOk = 0;
    int flag = 1;
    if (listaAerolineas != NULL && tam > 0 && descripcion != NULL)
    {
        todoOk = 1;
        for (int i = 0; i < tam; i++)
        {
            if (listaAerolineas[i].id == idAero)
            {
                strcpy(descripcion, listaAerolineas[i].descripcion);
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            todoOk = -1;
        }
    }
    return todoOk;
}
