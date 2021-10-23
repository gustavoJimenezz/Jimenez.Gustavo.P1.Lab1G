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


int altaAvion(eAvion listaAvion[], int tam, eAerolineas listaAerolineas[], int tamAero,eTipo listaTipos[], int tamTipo, int* pId, int longLimCadena, int intentos)
{
    int todoOk = 0;
    int indice;
    eAvion auxAvion;
    if (listaAerolineas != NULL && tam > 0 && listaAerolineas != NULL && tamAero >= 0 && listaTipos != NULL && tamTipo >= 0 && longLimCadena >= 0 && intentos >= 0)
    {
        system("cls");
        printf(" _____________________________\n");
        printf("|                             |\n");
        printf("|******  Alta de datos   *****|\n");
        printf("|_____________________________|\n\n");
        indice = buscarLibre(listaAvion, tam);
        if (indice == -1)
        {
            printf("\n\nError, sistema esta lleno\n\n");
        }
        else
        {
            auxAvion.id = *pId;
            (*pId)++;
            if(!peticionIdAerolineas(&auxAvion.idAerolinea, listaAerolineas, tamAero, "Ingrese ID : ", intentos))
            {
                todoOk = 1;
            }
            printf("\n\n");
            if(todoOk == 0 && !peticionIdTipo(&auxAvion.idTipo, listaTipos, tamTipo, "Ingrese ID : ", intentos))
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
                auxAvion.isEmpty = 0;
                listaAvion[indice] = auxAvion;
            }
        }
    }
    return todoOk;
}

int buscarLibre(eAvion listaAvion[], int tam)
{
    int indice = -1;
    for (int i = 0; i < tam; i++)
    {
        if (listaAvion[i].isEmpty)
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



void mostrarAvion(eAvion unAvion, eAerolineas aerolineas[], int tamAero, eTipo tipos[], int tamTipo)
{
    char descripcionAero[20];
    char descripcionTipo[20];

    if ( cargarDescripcionAerolineas( aerolineas, tamAero, unAvion.idAerolinea, descripcionAero) == 1 &&
         cargarDescripcionTipo(tipos, tamTipo, unAvion.idTipo, descripcionTipo) == 1)
    {
        printf("%8d     %11s     %11s    %8d\n",
               unAvion.id,
               descripcionAero,
               descripcionTipo,
               unAvion.capacidad);
    }

}

int mostrarAviones(eAvion listaAviones[], int tam, eAerolineas aerolineas[], int tamAero, eTipo tipos[], int tamTipo)
{
    int todoOk = 0;
    int flag = 1;
    if (listaAviones != NULL && tam > 0 && aerolineas != NULL && tamAero > 0 && tipos != NULL && tamTipo > 0)
    {
        printf("_____________________________________________________________\n\n");
        printf("      ID          Aerolinea          Tipo          Capacidad\n");
        printf("_____________________________________________________________\n\n");
        for (int i = 0; i < tam; i++)
        {
            if (!listaAviones[i].isEmpty)
            {
                mostrarAvion(listaAviones[i], aerolineas, tamAero, tipos, tamTipo);
                flag = 0;
            }
        }
        if (flag)
        {
            printf("No hay personas para mostrar.\n");

        }
        todoOk = 1;
    }
    return todoOk;
}

int modificarAvion(eAvion listaAviones[], int tam, eAerolineas aerolineas[], int tamAero, eTipo tipos[], int tamTipo, int longLimCadena, int intentos)
{
    int error = 1;
    int opcionSalir = 0;
    int idIngresado = 0;
    int indice;
    char confirma;
    char seguir;
    eAvion auxAvion;

    if(listaAviones != NULL && tam > 0 && aerolineas != NULL && tamAero > 0 && tipos != NULL && tamTipo > 0 && longLimCadena > 0 && intentos > 0)
    {
        system("cls");
        printf("_____________________________________________________________\n\n");
        mostrarAviones(listaAviones, tam, aerolineas, tamAero, tipos, tamTipo);
        printf("_____________________________________________________________\n\n");

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
                printf("_____________________________________________________________\n\n");
                printf("       ************* Modificar datos **************          \n");
                printf("_____________________________________________________________\n");
                printf("_____________________________________________________________\n\n");
                printf("      ID          Aerolinea          Tipo          Capacidad\n");
                printf("_____________________________________________________________\n\n");
                printf("_____________________________________________________________\n\n");
                mostrarAvion(auxAvion, aerolineas, tamAero, tipos, tamTipo);
                printf("_____________________________________________________________\n\n");

                switch(subMenuModificar())
                {
                case 1:
                    peticionIdTipo(&auxAvion.idTipo, tipos, tamTipo, "Ingrese ID : ", intentos);
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
        if (listaAviones[i].id == Id && listaAviones[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int inicializarAviones(eAvion lista[], int tam)
{
    int todoOk = 0;
    if (lista != NULL && tam > 0)
    {
        todoOk = 1;
        for (int i = 0; i < tam; i++)
        {
            lista[i].isEmpty = 1;
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
            printf("\n\nNo existe esa persona con ese ID\n\n");
        }
        else
        {
            system("cls");
            printf(" _______________________________________________________________\n");
            printf("                                                                \n");
            printf("          ************* Baja Avion*************          \n");
            printf("________________________________________________________________|\n\n");
            printf("      ID          Aerolinea          Tipo          Capacidad\n");
            printf("________________________________________________________________|\n");
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




