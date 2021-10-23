#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "funcionesValidacion.h"

int peticionEnteroPositivo(int* numEntero, char texto[], int intentos)
{
    int retorno = 0;
    int numAux;
    int esNum;

    if (texto != NULL && intentos > 0)
    {
        printf("%s", texto);
        esNum = scanf("%d", &numAux);
        fflush(stdin);

        while(numAux <= 0 || esNum != 1)
        {
            printf("Error, solo numeros positivos intentos %d\n", intentos);
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
            *numEntero = numAux;
            retorno = 1;
        }
    }
    return retorno;
}
