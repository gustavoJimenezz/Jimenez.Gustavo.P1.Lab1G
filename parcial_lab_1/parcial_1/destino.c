#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "destino.h"

int mostrarDestinos( eDestino listaDestino[], int tam)
{
    int todoOk = 0;
    if (listaDestino != NULL && tam > 0 )
    {
        printf("\n              *** Destinos ***      \n");
        printf("________________________________________________\n\n");
        printf("     Id            Descripcion            Precio\n");
        printf("________________________________________________\n\n");
        for (int i = 0; i < tam; i++)
        {
            printf("  %5d       %16s       %11.3f $\n", listaDestino[i].id, listaDestino[i].descripcion, listaDestino[i].precio);
        }
        todoOk = 1;
    }
    printf("\n\n");
    return todoOk;
}

int peticionIdDestino(int* numId, eDestino listaDestinos[], int tamDest, char texto[], int intentos)
{
    int retorno = 0;
    int numAux;
    int esNum;

    if (listaDestinos != NULL && tamDest > 0 && texto != NULL && intentos > 0 && numId != NULL)
    {
        mostrarDestinos(listaDestinos, tamDest);

        printf("%s", texto);
        esNum = scanf("%d", &numAux);
        fflush(stdin);

        while(numAux <= 0 || esNum != 1 || !validarDestino(numAux, listaDestinos, tamDest))
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

int validarDestino(int id, eDestino listDestinos[], int tamDest)
{
    int esValido = 0;
    if (id > 0 && listDestinos != NULL && tamDest > 0)
    {
        for (int i = 0; i < tamDest; i++)
        {
            if (id == listDestinos[i].id)
            {
                esValido = 1;
                break;
            }
        }
    }
    return esValido;
}

int cargarDescripcionDestino(eDestino listaDestinos[], int tamDestino, int idDestino, char descripcion[], float* precio)
{
    int todoOk = 0;
    int flag = 1;
    if (listaDestinos != NULL && tamDestino > 0 && idDestino > 0 && descripcion != NULL)
    {
        todoOk = 1;
        for (int i = 0; i < tamDestino; i++)
        {
            if (listaDestinos[i].id == idDestino)
            {
                strcpy(descripcion, listaDestinos[i].descripcion);
                *precio = listaDestinos[i].precio;
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
