#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "pilotos.h"

int cargarDescripcionPiloto(ePiloto listaPilotos[], int tamPiloto, int idPiloto, char descripcion[])
{
    int todoOk = 0;
    int flag = 1;
    if (listaPilotos != NULL && tamPiloto > 0 && idPiloto > 0 && descripcion != NULL)
    {
        todoOk = 1;
        for (int i = 0; i < tamPiloto; i++)
        {
            if (listaPilotos[i].id == idPiloto)
            {
                strcpy(descripcion, listaPilotos[i].nombre);
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
