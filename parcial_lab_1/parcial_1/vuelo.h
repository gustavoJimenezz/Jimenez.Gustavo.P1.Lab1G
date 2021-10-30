#ifndef VUELO_H_INCLUDED
#define VUELO_H_INCLUDED

struct
{
    int dia;
    int mes;
    int anio;

} typedef eFecha;

typedef struct
{
    int id;
    int idAvion;
    int idDestino;
    eFecha fecha;
    int isEmpty;

} eVuelo;


/** \brief Cambia el valor de isEmpty del array a 0.
 *
 * \param lista[] eVuelo
 * \param tam int
 * \return int Devuelve (0) si Error [Longitud no válida o puntero NULL o sin
             espacio libre] - (1) si está bien
 *
 */
int inicializarVuelos(eVuelo lista[], int tam);

/** \brief  Busca la posicion de un id en el array.
 *
 * \param listaVuelos[] eVuelo
 * \param tamVuelos int
 * \return int Devuelve (-1) si no se encuentra el ID
            o numero de indice si se encuentra la posicion
 *
 */
int buscarLibreVuelo(eVuelo listaVuelos[], int tamVuelos);

/** \brief Pide datos (idAvion, idDestino) para cargar en la estructura eVuelo.
 *
 * \param listaVuelos[] eVuelo
 * \param tamVuelos int
 * \param listaAviones[] eAvion
 * \param tamAviones int
 * \param listaAerolineas[] eAerolineas
 * \param tamAero int
 * \param listaTipos[] eTipo
 * \param tamTipo int
 * \param listaDestinos[] eDestino
 * \param tamDest int
 * \param pId int*
 * \param intentos int
 * \return int  Devuelve (0) si Error [Longitud no válida o puntero NULL o sin
             espacio libre] - (1) si está bien
 *
 */
int altaVuelo(eVuelo listaVuelos[], int tamVuelos, eAvion listaAviones[], int tamAviones, eAerolineas listaAerolineas[], int tamAero, eTipo listaTipos[], int tamTipo, eDestino listaDestinos[], int tamDest, ePiloto listaPiloto[], int tamPilotosa, int* pId, int intentos);

/** \brief Muestra datos de la estuctura Avion.
 *
 * \param vuelo eVuelo
 * \param listaAviones[] eAvion
 * \param tamAviones int
 * \param listaAerolineas[] eAerolineas
 * \param tamAero int
 * \param listaDestino[] eDestino
 * \param tamDestino int
 * \param listaTipos[] eTipo
 * \param tamTipo int
 * \return void
 *
 */
void mostrarVuelo(eVuelo vuelo, eAvion listaAviones[], int tamAviones, eAerolineas listaAerolineas[], int tamAero, eDestino listaDestino[], int tamDestino, eTipo listaTipos[], int tamTipo);

/** \brief Muestra datos de un array de eAvion.
 *
 * \param listaVuelos[] eVuelo
 * \param tamVuelos int
 * \param listaAviones[] eAvion
 * \param tamAviones int
 * \param listaAerolineas[] eAerolineas
 * \param tamAero int
 * \param listaDestinos[] eDestino
 * \param tamDestino int
 * \param listaTipos[] eTipo
 * \param tamTipo int
 * \return int  Devuelve (0) si Error [Longitud no válida o puntero NULL o sin
             espacio libre] - (1) si está bien
 *
 */
int mostrarVuelos(eVuelo listaVuelos[], int tamVuelos, eAvion listaAviones[], int tamAviones, eAerolineas listaAerolineas[], int tamAero, eDestino listaDestinos[], int tamDestino, eTipo listaTipos[], int tamTipo);

#endif // VUELO_H_INCLUDED
