#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "tipo.h"
#include "aerolinea.h"

int mostrarTipos( eTipo listTipos[], int tam)
{
    int todoOk = 0;
    if (listTipos != NULL && tam > 0 )
    {
        printf("\n    *** Tipo de Aviones ***      \n");
        printf("______________________________\n\n");
        printf("     Id            Descripcion\n");
        printf("______________________________\n\n");
        for (int i = 0; i < tam; i++)
        {
            printf("  %5d       %16s\n", listTipos[i].id, listTipos[i].descripcion);
        }
        todoOk = 1;
    }
    printf("\n\n");
    return todoOk;
}

int validarIdTipo( int idTipo, eTipo tipos[], int tam )
{
    int esValido = 0;
    if (idTipo > 0 && tipos != NULL && tam > 0)
    {
        for (int i = 0; i < tam; i++)
        {
            if (idTipo == tipos[i].id)
            {
                esValido = 1;
                break;
            }
        }
    }
    return esValido;
}

int peticionIdTipo(int* numId, eTipo tipos[], int tamTipo, char texto[], int intentos)
{
    int retorno = 0;
    int numAux;
    int esNum;

    if (tipos != NULL && texto != NULL && intentos > 0 && numId != NULL)
    {
        mostrarTipos(tipos, tamTipo);

        printf("%s", texto);
        esNum = scanf("%d", &numAux);
        fflush(stdin);

        while(numAux <= 0 || esNum != 1 || !validarIdTipo(numAux, tipos, tamTipo))
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

int cargarDescripcionTipo( eTipo tipos[], int tam, int idTipo, char descripcion[] )
{
    int todoOk = 0;
    int flag = 1;
    if (tipos != NULL && tam > 0 && descripcion != NULL)
    {
        todoOk = 1;
        for (int i = 0; i < tam; i++)
        {
            if (tipos[i].id == idTipo)
            {
                strcpy(descripcion, tipos[i].descripcion);
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            todoOk = -1; // no habia localidad con el id que le pasaron
        }
    }
    return todoOk;
}
