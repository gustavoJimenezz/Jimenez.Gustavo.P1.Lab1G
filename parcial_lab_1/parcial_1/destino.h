#ifndef DESTINO_H_INCLUDED
#define DESTINO_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[25];
    float precio;

} eDestino;

/** \brief Muestra datos de un array de eDestino.
 *
 * \param listaDestino[] eDestino
 * \param tam int
 * \return int Devuelve (0) si Error [Longitud no válida o puntero NULL o sin
             espacio libre] - (1) si está bien
 *
 */
int mostrarDestinos( eDestino listaDestino[], int tam);

/** \brief Valida que el id existe en el array listadestinos.
 *
 * \param id int
 * \param listDestinos[] eDestino
 * \param tamDestino int
 * \return int Devuelve (0) si Error [Longitud no válida o puntero NULL o sin
             espacio libre] - (1) si está bien
 *
 */
int validarDestino(int id, eDestino listDestinos[], int tamDestino);

/** \brief Muestra, pide y valida ID de una estructura eDestino.
 *
 * \param numId int*
 * \param listaDestinos[] eDestino
 * \param tamDest int
 * \param texto[] char
 * \param intentos int
 * \return int Devuelve (0) si Error [Longitud no válida o puntero NULL o sin
             espacio libre] - (1) si está bien
 *
 */
int peticionIdDestino(int* numId, eDestino listaDestinos[], int tamDest, char texto[], int intentos);

/** \brief Pasa descripcion de la estructura eDestino a las variables pasados por parametro.
 *
 * \param listaDestinos[] eDestino
 * \param tamDestino int
 * \param idDestino int
 * \param descripcion[] char
 * \param precio float*
 * \return int (0) si Error [Longitud no válida o puntero NULL o sin
             espacio libre] - (1) si está bien
 *
 */
int cargarDescripcionDestino(eDestino listaDestinos[], int tamDestino, int idDestino, char descripcion[], float* precio);

#endif // DESTINO_H_INCLUDED
