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

#define MAX_CARACTER_AEROLINEAS 20
#define INTENTOS 3
#define TAM 5
#define TAM_2 6
#define TAM_TIPO 4



char menuPrincipal();
int main()
{

    int idAvion = 1000;
    int almenosUnEmpleado = 1;
    int retornoBaja;
    int idIngresadoBaja;

    eAerolineas listaAerolineas[TAM] = {{1000,"Lan",0}, {1001,"Iberia",0}, {1002, "Norwegian",0}, {1003, "American",0}, {1004,"Austral",0}};
    eTipo listaTipos[TAM_TIPO] = {{5000,"Jet",0}, {5001,"Helice",0}, {5002,"Planeador",0}, {50003,"Carga",0}};
    //eDestino listaDestinos[TAM_2] = {{20000,"Calafate", 22250}, {20001,"Miami", 103000}, {20002,"Madrid", 84400}, {20003,"Amsterdam", 95600}};


    eAvion listaAviones[TAM];// = {{1000, 1001, 5000, 20},{1001,1003,5001,30},{1002,1004,50002,40},{1003,1003,50003,100}};
    inicializarAviones(listaAviones, TAM);

    char seguir;

    do
    {
        system("cls");
        switch(menuPrincipal())
        {
        case 'a':
            if(altaAvion(listaAviones, TAM, listaAerolineas, TAM, listaTipos, TAM, &idAvion, MAX_CARACTER_AEROLINEAS, INTENTOS))
            {
                almenosUnEmpleado = 1;
                printf("No se pudo realizar el alta\n");
            }
            else
            {
                printf("Alta exitosa\n");
            }
            break;
        case 'b':
            if(almenosUnEmpleado == 1)
            {
                    system("cls");
                    printf("_____________________________________________________________\n\n");
                    printf("       ************* Modificar datos **************          \n");
                    printf("_____________________________________________________________\n");
                        if(modificarAvion(listaAviones, TAM, listaAerolineas, TAM, listaTipos, TAM_TIPO, MAX_CARACTER_AEROLINEAS, INTENTOS))
                        {
                            printf("No se pudo modificar\n");
                        }
                        else
                        {
                            printf("Cambios realizados con exito\n");
                        }
            }
            else
            {
                printf("\n\nGenere almenos un Alta de empleado\n\n");
            }
            break;
        case 'c':
            if(almenosUnEmpleado == 1)
            {
                    system("cls");
                    printf("_____________________________________________________________\n\n");
                    printf("       ************* Baja de empleado *************          \n");
                    printf("_____________________________________________________________\n\n");
                    mostrarAviones(listaAviones, TAM, listaAerolineas, TAM, listaTipos, TAM_TIPO);
                    peticionEnteroPositivo(&idIngresadoBaja, "Ingrese ID : ", INTENTOS);
                    retornoBaja = bajaAvion(listaAviones, TAM, idIngresadoBaja, listaAerolineas, TAM, listaTipos, TAM_TIPO);
                    if(retornoBaja == 0)
                    {
                        printf("\n\nBaja de empleado con exito\n\n");
                    }
                    else
                    {
                        printf("\n\nProblemas para realizar la Baja de empleado\n\n");
                    }

            }else
            {
                printf("\n\nGenere almenos un Alta de empleado\n\n");
            }
            break;
        case 'd':
            if(almenosUnEmpleado == 1)
            {
                if(!mostrarAviones(listaAviones, TAM, listaAerolineas, TAM, listaTipos, TAM_TIPO))
                {
                    printf(" Problemas para mostrar los datos\n\n");
                }
              }else
            {
                printf("\n\nGenere almenos un Alta de empleado\n\n");
            }
            break;
        case 'e':
            if(almenosUnEmpleado == 1)
            {
                if(!mostrarAerolineas(listaAerolineas, TAM))
                {
                    printf(" Problemas para mostrar los datos\n\n");
                }
              }else
            {
                printf("\n\nGenere almenos un Alta de empleado\n\n");
            }
            break;
        case 'f':
            if(almenosUnEmpleado == 1)
            {
                if(!mostrarTipos(listaTipos, TAM))
                {
                    printf(" Problemas para mostrar los datos\n\n");
                }
              }else
            {
                printf("\n\nGenere almenos un Alta de empleado\n\n");
            }
            break;
        case 'z':
            printf("Desea Salir? (si/s)(no/n) : ");
            fflush(stdin);
            scanf("%c", &seguir);
            seguir = tolower(seguir);
            break;
        default:
            break;
        }
        system("pause");

    }
    while(seguir != 's');
    return 0;
}
char menuPrincipal()
{
    char opcion;
    system("cls");
    printf("     *** MENU DE OPCIONES ***\n");
    printf("A. ALTA AVION\n");
    printf("B. MODIFICAR AVION\n");
    printf("C. BAJA AVION\n");
    printf("D. LISTAR AVIONES\n");
    printf("E. LISTAR AEROLINEAS\n");
    printf("F. LISTAR TIPOS\n");
    printf("Z- Salir\n\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%c", &opcion);
    opcion = tolower(opcion);
    return opcion;
}
