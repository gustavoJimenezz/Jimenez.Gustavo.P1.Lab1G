#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "estructuraPiloto.h"

int cargarDescripcionPiloto( ePiloto listaPilotos[], int tamPilotos, int idPiloto, char nombrePiloto[])
{
    int todoOk = 0;
    int flag = 1;
    if (listaPilotos != NULL && tamPilotos > 0)
    {
        todoOk = 1;
        for (int i = 0; i < tamPilotos; i++)
        {
            if (listaPilotos[i].id == idPiloto)
            {
                strcpy(nombrePiloto, listaPilotos[i].nombre);
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
