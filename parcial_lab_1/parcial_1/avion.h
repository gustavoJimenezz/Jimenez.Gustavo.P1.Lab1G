#include "estructuraPiloto.h"
#ifndef AVION_H_INCLUDED
#define AVION_H_INCLUDED

typedef struct
{
    int id;
    int idAerolinea;
    int idTipo;
    int capacidad;
    int ipPiloto;
    int isEmpty;

} eAvion;


/** \brief Buesca en la estructura un isEmpty de valor 0 que se considere libre.
 *
 * \param listaAvion[] eAvion
 * \param tam int
 * \return int numero entero posicion libre.
 *
 */
int buscarLibre(eAvion listaAvion[], int tam);

/** \brief  Pide datos (idAerolinea, idTipo, capacidad) para cargar en la estructura eAviones.
 *
 * \param listaAviones[] eAvion
 * \param tamAviones int
 * \param listaAerolineas[] eAerolineas
 * \param tamAero int
 * \param listaTipos[] eTipo
 * \param tamTipo int
 * \param pId int*
 * \param intentos int
 * \return int Devuelve (0) si Error [Longitud no válida o puntero NULL o sin
           espacio libre] - (1) si está bien
 *
 */
int altaAvion(eAvion listaAviones[], int tamAviones, eAerolineas listaAerolineas[], int tamAero, eTipo listaTipos[], int tamTipo, int* pId, int intentos);

/** \brief Solicita entero positivo menor de 300 mayor de 10;
 *
 * \param capacidad int*
 * \param texto[] char
 * \param intentos int
 * \return int Devuelve (0) si Error [Longitud no válida o puntero NULL o sin
            espacio libre] - (1) si está bien
 *
 */
int peticionCapacidad( int* capacidad , char texto[], int intentos);

/** \brief Muestra datos de la estuctura Avion.
 *
 * \param unAvion eAvion
 * \param listaAerolineas[] eAerolineas
 * \param tamAero int
 * \param listaTipos[] eTipo
 * \param tamTipo int
 * \return void
 *
 */
void mostrarAvion(eAvion unAvion, eAerolineas listaAerolineas[], int tamAero, eTipo listaTipos[], int tamTipo, ePiloto listaPiloto[], int tamPiloto);

/** \brief Muestra datos de un array de eAvion.
 *
 * \param listaAviones[] eAvion
 * \param tam int
 * \param listaAerolineas[] eAerolineas
 * \param tamAero int
 * \param listaTipos[] eTipo
 * \param tamTipo int
 * \return int Devuelve (0) si Error [Longitud no válida o puntero NULL o sin
             espacio libre] - (1) si está bien
 *
 */
int mostrarAviones(eAvion listaAviones[], int tam, eAerolineas listaAerolineas[], int tamAero, eTipo listaTipos[], int tamTipo, ePiloto listaPiloto[], int tamPiloto);

/** \brief Cambia el valor de isEmpty del array a 0.
 *
 * \param lista[] eAvion
 * \param tam int
 * \return int Devuelve (0) si Error [Longitud no válida o puntero NULL o sin
             espacio libre] - (1) si está bien
 *
 */
int inicializarAviones(eAvion lista[], int tam);


/** \brief Modifica los datos de una estructura eAvion.
 *
 * \param listaAviones[] eAvion
 * \param tam int
 * \param listaAerolineas[] eAerolineas
 * \param tamAero int
 * \param listaTipos[] eTipo
 * \param tamTipo int
 * \param intentos int
 * \return int Devuelve (0) si Error [Longitud no válida o puntero NULL o sin
             espacio libre] - (1) si está bien
 *
 */
int modificarAvion(eAvion listaAviones[], int tam, eAerolineas listaAerolineas[], int tamAero, eTipo listaTipos[], int tamTipo, int intentos, ePiloto listaPilotos[], int tamPilotos);

/** \brief Submenu con opciones.
 *
 * \return int valor de opciones seleccionado
 *
 */
int subMenuModificar();

/** \brief Busca la posicion de un id en el array.
 *
 * \param listaAviones[] eAvion
 * \param tam int
 * \param Id int
 * \return int Devuelve (-1) si no se encuentra el ID
            o numero de indice si se encuentra la posicion
 *
 */
int buscarAvionId(eAvion listaAviones[], int tam, int Id);

/** \brief Eliminar datos por Id (pone la bandera isEmpty en 1)
 *
 * \param listaAviones[] eAvion
 * \param tam int
 * \param id int
 * \param aerolineas[] eAerolineas
 * \param tamAero int
 * \param tipos[] eTipo
 * \param tamTipo int
 * \return int  Devuelve (0) si Error [Longitud no válida o puntero NULL o sin
             espacio libre] - (1) si está bie
 *
 */
int bajaAvion(eAvion listaAviones[], int tam, int id, eAerolineas aerolineas[], int tamAero, eTipo tipos[], int tamTipo, ePiloto listaPilotos[], int tamPilotos);

/** \brief Revisa que el ID que se pasa por paramtro se encuentra en el array listaAviones.
 *
 * \param id int
 * \param listaAviones[] eAvion
 * \param tamAvion int
 * \return int Devuelve (0) si Error [Longitud no válida o puntero NULL o sin
             espacio libre] - (1) si está bien
 *
 */
int validarIdAvion(int id, eAvion listaAviones[], int tamAvion);

/** \brief Muestra, pide y valida ID de una estructura eAvion.
 *
 * \param numId int*
 * \param listaAviones[] eAvion
 * \param tamAvion int
 * \param listaAerolineas[] eAerolineas
 * \param tamAero int
 * \param listaTipos[] eTipo
 * \param tamTipo int
 * \param texto[] char
 * \param intentos int
 * \return int Devuelve (0) si Error [Longitud no válida o puntero NULL o sin
             espacio libre] - (1) si está bien
 *
 */
int peticionIdAvion(int* numId, eAvion listaAviones[], int tamAvion, eAerolineas listaAerolineas[], int tamAero, eTipo listaTipos[], int tamTipo, ePiloto listaPilotos[], int tamPilotos, char texto[], int intentos);


/** \brief Pasa idAvion, idAerolineas y capacidad de la estructura eAvion a las variables pasados por parametro.
 *
 * \param listaAviones[] eAvion
 * \param tamAviones int
 * \param idAvion int
 * \param idAerolineas int*
 * \param idTipo int*
 * \param capacidad int*
 * \return int (0) si Error [Longitud no válida o puntero NULL o sin
             espacio libre] - (1) si está bien
 *
 */
int cargarDescripcionAvion( eAvion listaAviones[], int tamAviones, int idAvion, int* idAerolineas, int* idTipo, int* capacidad);

int mostrarAvionPorAerolinea(eAvion listaAviones[], int tamAviom, eAerolineas listaAerolineas[], int tamAero, eTipo listaTipos[], int tamTipos, ePiloto listaPilotos[], int tamPilotos, int intentos);

int mostrarAvionPorTipo(eAvion listaAviones[], int tamAviom, eAerolineas listaAerolineas[], int tamAero, eTipo listaTipos[], int tamTipos, ePiloto listaPilotos[], int tamPilotos, int intentos);


#endif // AVION_H_INCLUDED
