#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[20];

} eTipo;

/** \brief Muestra datos de un array de eTipos.
 *
 * \param listTipos[] eTipo
 * \param tam int
 * \return int Devuelve (0) si Error [Longitud no válida o puntero NULL o sin
             espacio libre] - (1) si está bien
 *
 */
int mostrarTipos( eTipo listTipos[], int tam);

/** \brief Revisa que el ID que se pasa por paramtro se encuentra en el array tipos.
 *
 * \param idTipo int
 * \param tipos[] eTipo
 * \param tam int
 * \return int Devuelve (0) si Error [Longitud no válida o puntero NULL o sin
             espacio libre] - (1) si está bien
 *
 */
int validarIdTipo( int idTipo, eTipo tipos[], int tam );

/** \brief  Muestra, pide y valida ID de una estructura eTipo.
 *
 * \param numId int*
 * \param tipos[] eTipo
 * \param tamTipo int
 * \param texto[] char
 * \param intentos int
 * \return int Devuelve (0) si Error [Longitud no válida o puntero NULL o sin
             espacio libre] - (1) si está bien
 *
 */
int peticionIdTipo(int* numId, eTipo tipos[], int tamTipo, char texto[], int intentos);

/** \brief Pasa descripcion de la estructura eAvion a la variables pasados por parametro.
 *
 * \param tipos[] eTipo
 * \param tam int
 * \param idTipo int
 * \param descripcion[] char
 * \return int Devuelve (0) si Error [Longitud no válida o puntero NULL o sin
             espacio libre] - (1) si está bien
 *
 */
int cargarDescripcionTipo( eTipo tipos[], int tam, int idTipo, char descripcion[]);

#endif // TIPO_H_INCLUDED
