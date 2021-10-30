#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "hard.h"
#include "aerolinea.h"
#include "tipo.h"
#include "destino.h"
#include "avion.h"
#include "vuelo.h"
#include "funcionesValidacion.h"
#include "estructuraPiloto.h"

#define MAX_LENGTH_STRING 20
#define INTENTOS 3
#define TAM_AERO 5
#define TAM_TIPO 4
#define TAM_DEST 4
#define TAM 10

char menuPrincipal();
int main()
{

    int idAvion = 1000;
    int idVuelos = 1000;
    int alemenosUnAltaAvion = 1;
    int alemenosUnAltaVuelo = 1;
    int retornoBaja;
    int idIngresadoBaja;

    eAerolineas listaAerolineas[TAM_AERO] = {{1000,"Lan"}, {1001,"Iberia"}, {1002, "Norwegian"}, {1003, "American"}, {1004,"Austral"}};
    eTipo listaTipos[TAM_TIPO] = {{5000,"Jet"}, {5001,"Helice"}, {5002,"Planeador"}, {5003,"Carga"}};
    eDestino listaDestinos[TAM_DEST] = {{20000,"Calafate",22.250}, {20001,"Miami", 103.000}, {20002,"Madrid", 84.400}, {20003,"Amsterdam", 95.600}};
    ePiloto listaPilotos[TAM] = {{1000,"Julian",'m'},{1001,"Pedro",'m'},{1002,"Julia", 'f'},{1003,"Noelia",'f'},{1004,"Carlos",'f'},{1005,"Pepito",'f'}
    ,{1006,"Jose",'f'},{1007,"Adrian",'f'}};

    eAvion listaAviones[TAM] = {{1000,1001,5000,20,1000,1},
                                {1001,1002,5001,30,1001,1},
                                {1003,1003,5003,100,1002,1},
                                {1002,1004,5002,100,1003,1},
                                {1004,1003,5001,100,1004,1},
                                {1005,1002,5000,100,1005,1},
                                {1006,1001,5002,100,1006,1},
                                {1007,1000,5003,100,1007,1},
                                {1008,1004,5000,100,1008,1}};
    //inicializarAviones(listaAviones, TAM);

    eVuelo listaVuelos[TAM]; //= {{1000, 1000, 20000, {17,10,2020}, 1},{1001, 1001, 20001, {17,10,1995}, 1},{1001, 1002, 20002, {17,10,2015}, 1}};
    inicializarVuelos(listaVuelos, TAM);

    char seguir;

    do
    {
        system("cls");
        switch(menuPrincipal())
        {
        case 'a':
            if(altaAvion(listaAviones, TAM, listaAerolineas, TAM_AERO, listaTipos, TAM_TIPO, &idAvion, INTENTOS))
            {
                printf("No se pudo realizar el alta\n");
                printf("\n\n");
            }
            else
            {
                printf("Alta exitosa\n");
                printf("\n\n");
                alemenosUnAltaAvion = 1;
            }
            break;
        case 'b':
            if(alemenosUnAltaAvion == 1)
            {
                system("cls");
                printf("_____________________________________________________________\n\n");
                printf("       ************* Modificar datos **************          \n");
                printf("_____________________________________________________________\n");
                if(modificarAvion(listaAviones, TAM, listaAerolineas, TAM_AERO, listaTipos, TAM_TIPO, INTENTOS, listaPilotos, TAM))
                {
                    printf("No se pudo modificar\n");
                    printf("\n\n");
                }
                else
                {
                    printf("Cambios realizados con exito\n");
                    printf("\n\n");
                }
            }
            else
            {
                printf("Genere almenos un Alta de Avion\n");
                printf("\n\n");
            }
            break;
        case 'c':
            if(alemenosUnAltaAvion == 1)
            {
                system("cls");
                printf("_____________________________________________________________\n\n");
                printf("          ************* Baja de Avion *************          \n");
                printf("_____________________________________________________________\n\n");

                mostrarAviones(listaAviones, TAM, listaAerolineas, TAM_AERO, listaTipos, TAM_TIPO, listaPilotos, TAM);
                peticionEnteroPositivo(&idIngresadoBaja, "\nIngrese ID : ", INTENTOS);
                retornoBaja = bajaAvion(listaAviones, 10, idIngresadoBaja, listaAerolineas, TAM_AERO, listaTipos, TAM_TIPO, listaPilotos, TAM);
                if(retornoBaja == 0)
                {
                    printf("Baja de datos con exito\n");
                    printf("\n\n");
                }
                else
                {
                    printf("Problemas para realizar la Baja de datos\n");
                    printf("\n\n");
                }

            }
            else
            {
                printf("Genere almenos un Ata de Avion\n");
                printf("\n\n");
            }
            break;
        case 'd':
            if(alemenosUnAltaAvion == 1)
            {
                system("cls");
                if(!mostrarAviones(listaAviones, TAM, listaAerolineas, TAM_AERO, listaTipos, TAM_TIPO, listaPilotos, TAM))
                {
                    printf(" Problemas para mostrar los datos\n");
                    printf("\n\n");
                }
            }
            else
            {
                printf("Genere almenos un Alta de Avion\n");
                printf("\n\n");
            }
            break;
        case 'e':
            if(alemenosUnAltaAvion == 1)
            {
                system("cls");
                if(!mostrarAerolineas(listaAerolineas, TAM_AERO))
                {
                    printf(" Problemas para mostrar los datos\n");
                    printf("\n\n");
                }
            }
            else
            {
                printf("Genere almenos un Alta de Avion\n");
                printf("\n\n");
            }
            break;
        case 'f':
            if(alemenosUnAltaAvion == 1)
            {
                system("cls");
                if(!mostrarTipos(listaTipos, TAM_TIPO))
                {
                    printf(" Problemas para mostrar los datos\n");
                    printf("\n\n");
                }
            }
            else
            {
                printf("\n\nGenere almenos un Alta de Avion\n");
                printf("\n\n");
            }
            break;
        case 'g':
            if(alemenosUnAltaAvion == 1)
            {
                system("cls");
                if(!mostrarDestinos(listaDestinos, TAM_DEST))
                {
                    printf(" Problemas para mostrar los datos\n");
                    printf("\n\n");
                }
            }
            else
            {
                printf("\n\nGenere almenos un Alta de Avion\n");
                printf("\n\n");
            }
            break;
        case 'h':
            if(alemenosUnAltaAvion == 1)
            {
                system("cls");
                printf("_____________________________________________________________\n\n");
                printf("                 ******  Alta de datos   *****                \n");
                printf("_____________________________________________________________\n");
                if(altaVuelo(listaVuelos, 10, listaAviones, TAM, listaAerolineas, TAM_AERO, listaTipos, TAM_TIPO, listaDestinos, TAM_DEST, listaPilotos, TAM, &idVuelos, INTENTOS))
                {
                    printf("No se pudo realizar el alta\n");
                    printf("\n\n");
                }
                else
                {
                    printf("Alta exitosa\n");
                    alemenosUnAltaVuelo = 1;
                    printf("\n\n");
                }
            }
            else
            {
                printf("Genere almenos un Alta de Avion\n");
                printf("\n\n");
            }
            break;
        case 'i':
            if(alemenosUnAltaAvion == 1 && alemenosUnAltaVuelo == 1)
            {
                system("cls");
                mostrarVuelos(listaVuelos, TAM, listaAviones, TAM, listaAerolineas, TAM_AERO, listaDestinos, TAM_DEST, listaTipos, TAM_TIPO);
                printf("\n\n");
            }else
            {
                printf("Genere almenos un Alta de Vuelo\n");
                printf("\n\n");
            }
            break;
        case 'j':
            mostrarAvionPorAerolinea(listaAviones, TAM, listaAerolineas, TAM_AERO, listaTipos, TAM_TIPO, listaPilotos, TAM, INTENTOS);
            break;
        case 'k':
            mostrarAvionPorTipo(listaAviones, TAM, listaAerolineas, TAM_AERO, listaTipos, TAM_TIPO, listaPilotos, TAM, INTENTOS);
            break;
        case 'z':
            printf("Desea Salir? (si/s)(no/n) : ");
            fflush(stdin);
            scanf("%c", &seguir);
            seguir = tolower(seguir);
            printf("\n\n");
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
    printf("\n     *** MENU DE OPCIONES ***     \n");
    printf("__________________________________\n\n");
    printf("A. ALTA AVION\n");
    printf("B. MODIFICAR AVION\n");
    printf("C. BAJA AVION\n");
    printf("D. LISTAR AVIONES\n");
    printf("E. LISTAR AEROLINEAS\n");
    printf("F. LISTAR TIPOS\n");
    printf("G. LISTAR DESTINOS\n");
    printf("H. ALTA VUELO\n");
    printf("I. LISTAR VUELOS\n");
    printf("J. LISTAR AVIONES POR AEROLINEAS\n");
    printf("K. LISTAR AVIONES POR TIPO\n");
    printf("Z- Salir\n");
    printf("__________________________________\n\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%c", &opcion);
    opcion = tolower(opcion);
    return opcion;
}
