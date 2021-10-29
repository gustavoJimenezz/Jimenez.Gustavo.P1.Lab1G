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


int altaAvion(eAvion listaAviones[], int tamAviones, eAerolineas listaAerolineas[], int tamAero, eTipo listaTipos[], int tamTipo, int* pId, int intentos)
{
    int todoOk = 0;
    int indice;
    eAvion auxAvion;
    if (listaAviones != NULL && tamAviones > 0 && listaAerolineas != NULL && tamAero >= 0 && listaTipos != NULL && tamTipo >= 0 && intentos >= 0)
    {
        system("cls");
        printf("______________________________\n");
        printf("                              \n");
        printf(" *****  Alta de datos   ***** \n");
        printf("______________________________\n\n");

        indice = buscarLibre(listaAviones, tamAviones);
        if (indice == -1)
        {
            printf("\n\nError, sistema esta lleno\n\n");
        }
        else
        {
            auxAvion.id = *pId;
            (*pId)++;
            if(!peticionIdAerolineas(&auxAvion.idAerolinea, listaAerolineas, tamAero, "Ingrese ID de la Aerolinea : ", intentos))
            {
                todoOk = 1;
            }
            printf("\n\n");
            if(todoOk == 0 && !peticionIdTipo(&auxAvion.idTipo, listaTipos, tamTipo, "Ingrese ID del tipo de avion : ", intentos))
            {
                todoOk = 1;
            }
            printf("\n\n");
            if(todoOk == 0 && !peticionCapacidad(&auxAvion.capacidad, "Ingrese capacidad (entre 10 y 300) : ", intentos))
            {
                todoOk = 1;
            }
            printf("\n\n");
            if( todoOk == 0)
            {
                auxAvion.isEmpty = 1;
                listaAviones[indice] = auxAvion;
            }
        }
    }
    printf("\n\n");
    return todoOk;
}

int buscarLibre(eAvion listaAvion[], int tam)
{
    int indice = -1;
    for (int i = 0; i < tam; i++)
    {
        if (!listaAvion[i].isEmpty)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int peticionCapacidad( int* capacidad , char texto[], int intentos)
{
    int retorno = 0;
    int numAux;
    int esNum;
    if (capacidad != NULL && texto != NULL)
    {
        printf("%s", texto);
        esNum = scanf("%d", &numAux);
        fflush(stdin);
        while(numAux <= 0 || esNum != 1 || (numAux < 10 || numAux > 300))
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
            *capacidad = numAux;
            retorno = 1;
        }

    }
    return retorno;
}

void mostrarAvion(eAvion unAvion, eAerolineas listaAerolineas[], int tamAero, eTipo listaTipos[], int tamTipo)
{
    char descripcionAero[20];
    char descripcionTipo[20];

    if ( cargarDescripcionAerolineas( listaAerolineas, tamAero, unAvion.idAerolinea, descripcionAero) == 1 &&
         cargarDescripcionTipo(listaTipos, tamTipo, unAvion.idTipo, descripcionTipo) == 1)
    {
        printf("  %6d     %14s      %8s     %14d\n",
               unAvion.id,
               descripcionAero,
               descripcionTipo,
               unAvion.capacidad);
    }

}

int mostrarAviones(eAvion listaAviones[], int tam, eAerolineas listaAerolineas[], int tamAero, eTipo listaTipos[], int tamTipo)
{
    int todoOk = 0;
    int flag = 1;
    if (listaAviones != NULL && tam > 0 && listaAerolineas != NULL && tamAero > 0 && listaTipos != NULL && tamTipo > 0)
    {

        printf("\n                    *** Lista Aviones ***      \n");
        printf("_____________________________________________________________\n\n");
        printf("      ID          Aerolinea          Tipo          Capacidad\n");
        printf("_____________________________________________________________\n\n");
        for (int i = 0; i < tam; i++)
        {
            if (listaAviones[i].isEmpty == 1)
            {
                mostrarAvion(listaAviones[i], listaAerolineas, tamAero, listaTipos, tamTipo);
                flag = 0;
            }
        }
        if (flag)
        {
            printf("No hay datos para mostrar.\n");

        }
        todoOk = 1;
    }
    printf("\n\n");
    return todoOk;
}

int modificarAvion(eAvion listaAviones[], int tam, eAerolineas listaAerolineas[], int tamAero, eTipo listaTipos[], int tamTipo, int intentos)
{
    int error = 1;
    int opcionSalir = 0;
    int idIngresado = 0;
    int indice;
    char confirma;
    char seguir;
    eAvion auxAvion;

    if(listaAviones != NULL && tam > 0 && listaAerolineas != NULL && tamAero > 0 && listaTipos != NULL && tamTipo > 0 && intentos > 0)
    {
        mostrarAviones(listaAviones, tam, listaAerolineas, tamAero, listaTipos, tamTipo);
        peticionEnteroPositivo(&idIngresado, "\nIngrese ID : ", intentos);
        indice = buscarAvionId(listaAviones, tam, idIngresado);
        if(indice == -1)
        {
            printf("\nError, ID inexistente\n\n");
        }
        else
        {
            auxAvion = listaAviones[indice];
            do
            {
                system("cls");
                printf("_________________________________________________________________\n\n");
                printf("          ************* Modificar datos **************           \n");
                printf("_________________________________________________________________\n");
                printf("_________________________________________________________________\n\n");
                printf("      ID          Aerolinea          Tipo          Capacidad\n");
                printf("_________________________________________________________________\n");
                printf("_________________________________________________________________\n");
                mostrarAvion(auxAvion, listaAerolineas, tamAero, listaTipos, tamTipo);
                printf("_________________________________________________________________\n\n");

                switch(subMenuModificar())
                {
                case 1:
                    peticionIdTipo(&auxAvion.idTipo, listaTipos, tamTipo, "Ingrese ID : ", intentos);
                  break;
                case 2:
                    peticionCapacidad(&auxAvion.capacidad, "Ingrese capacidad (entre 10 y 300) : ", intentos);
                    break;
                default:
                    opcionSalir = 1;
                    break;
                }
                if(opcionSalir != 1)
                {
                    printf("\nDesea seguir modificando? (si/s)(no/n) : ");
                    fflush(stdin);
                    scanf("%c", &seguir);
                }
            }
            while(seguir == 's' && opcionSalir != 1);
            system("cls");
            printf("\nConfirma modificacion? (si/s)(no/n) : ");
            fflush(stdin);
            scanf("%c", &confirma);
            if(confirma== 's')
            {
                error= 0;
                listaAviones[indice] = auxAvion;
            }
        }
    }
    return error;
}
int subMenuModificar()
{
    int opcion;
    printf("\n1. tipo\n");
    printf("\n2. capacidad\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);
    printf("\n\n");
    return opcion;
}

int buscarAvionId(eAvion listaAviones[], int tam, int Id)
{
    int indice = -1;
    for (int i = 0; i < tam; i++)
    {
        if (listaAviones[i].id == Id && listaAviones[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int inicializarAviones(eAvion listaAviones[], int tam)
{
    int todoOk = 0;
    if (listaAviones != NULL && tam > 0)
    {
        todoOk = 1;
        for (int i = 0; i < tam; i++)
        {
            listaAviones[i].isEmpty = 0;
        }
    }
    return todoOk;
}


int bajaAvion(eAvion listaAviones[], int tam, int id, eAerolineas aerolineas[], int tamAero, eTipo tipos[], int tamTipo)
{
    int error = 1;
    int indice;
    char confirma;

    if(listaAviones != NULL && tam > 0 && aerolineas != NULL && tamAero > 0 && tipos != NULL && tamTipo > 0 )
    {
        indice = buscarAvionId(listaAviones, tam, id);
        if(indice == -1)
        {
            printf("\n\nID inexistente\n\n");
        }
        else
        {
            system("cls");
            printf("_____________________________________________________________\n\n");
            printf("             ************* Baja Avion *************           \n");
            printf("_____________________________________________________________\n");
            printf("_____________________________________________________________\n\n");
            printf("      ID          Aerolinea          Tipo          Capacidad\n");
            printf("_____________________________________________________________\n\n");
            printf("_____________________________________________________________\n\n");
            mostrarAvion(listaAviones[indice], aerolineas, tamAero, tipos, tamTipo);

            printf("\nconfirma borrado (si/s): ");
            fflush(stdin);
            scanf("%c", &confirma);
            if(confirma == 's')
            {
                listaAviones[indice].isEmpty = 0;
                error= 0;
            }
        }
    }
    return error;
}

int validarIdAvion(int id, eAvion listaAviones[], int tamAvion)
{
    int esValido = 0;
    if (id > 0 && listaAviones != NULL && tamAvion > 0)
    {
        for (int i = 0; i < tamAvion; i++)
        {
            if (id == listaAviones[i].id)
            {
                esValido = 1;
                break;
            }
        }
    }
    return esValido;
}

int peticionIdAvion(int* numId, eAvion listaAviones[], int tamAvion, eAerolineas listaAerolineas[], int tamAero, eTipo listaTipos[], int tamTipo, char texto[], int intentos)
{
    int retorno = 0;
    int numAux;
    int esNum;

    if (listaAviones != NULL && texto != NULL && intentos > 0 && numId != NULL)
    {
        mostrarAviones(listaAviones, tamAvion, listaAerolineas, tamAero, listaTipos, tamTipo);

        printf("%s", texto);
        esNum = scanf("%d", &numAux);
        fflush(stdin);

        while(numAux <= 0 || esNum != 1 || !validarIdAvion(numAux, listaAviones, tamAvion))
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

int cargarDescripcionAvion( eAvion listaAviones[], int tamAviones, int id, int* idAerolineas, int* idTipo, int* capacidad)
{
    int todoOk = 0;
    int flag = 1;
    if (listaAviones != NULL && tamAviones > 0 )
    {
        todoOk = 1;
        for (int i = 0; i < tamAviones; i++)
        {
            if (listaAviones[i].id == id)
            {
                *idAerolineas = listaAviones[i].idAerolinea;
                *idTipo = listaAviones[i].idTipo;
                *capacidad = listaAviones[i].capacidad;
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


