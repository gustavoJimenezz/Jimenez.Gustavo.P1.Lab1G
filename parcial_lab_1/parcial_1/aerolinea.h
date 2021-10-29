#ifndef AEROLINEA_H_INCLUDED
#define AEROLINEA_H_INCLUDED
typedef struct
{
    int id;
    char descripcion[20];

} eAerolineas;


/** \brief Muestra datos de un array de eAvion.
 *
 * \param listAerolineas[] eAerolineas
 * \param tam int
 * \return int Devuelve (0) si Error [Longitud no válida o puntero NULL o sin
             espacio libre] - (1) si está bien
 *
 */
int mostrarAerolineas( eAerolineas listAerolineas[], int tam);

/** \brief Revisa que el ID que se pasa por paramtro se encuentra en el array listaAerolineas.
 *
 * \param id int
 * \param listaAerolineas[] eAerolineas
 * \param tam int
 * \return int Devuelve (0) si Error [Longitud no válida o puntero NULL o sin
             espacio libre] - (1) si está bien
 *
 */
int validarIdAerolinea(int id, eAerolineas listaAerolineas[], int tam);

/** \brief Muestra, pide y valida ID de una estructura eAerolineas.
 *
 * \param numId int*
 * \param listaAerolineas[] eAerolineas
 * \param tamAero int
 * \param texto[] char
 * \param intentos int
 * \return int Devuelve (0) si Error [Longitud no válida o puntero NULL o sin
             espacio libre] - (1) si está bien
 *
 */
int peticionIdAerolineas(int* numId, eAerolineas listaAerolineas[], int tamAero, char texto[], int intentos);

/** \brief Pasa descripcion de la estructura eAerolineas a las variables pasados por parametro.
 *
 * \param listaAerolineas[] eAerolineas
 * \param tam int
 * \param idAero int
 * \param descripcion[] char
 * \return int Devuelve (0) si Error [Longitud no válida o puntero NULL o sin
             espacio libre] - (1) si está bien
 *
 */
int cargarDescripcionAerolineas( eAerolineas listaAerolineas[], int tam, int idAero, char descripcion[]);

#endif // AEROLINEA_H_INCLUDED
