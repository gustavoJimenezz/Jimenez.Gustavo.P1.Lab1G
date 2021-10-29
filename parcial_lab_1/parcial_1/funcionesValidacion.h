#ifndef FUNCIONESVALIDACION_H_INCLUDED
#define FUNCIONESVALIDACION_H_INCLUDED

/** \brief
 *
 * \param numEntero int*
 * \param texto[] char
 * \param intentos int
 * \return int Devuelve (0) si Error [Longitud no válida o puntero NULL o sin
             espacio libre] - (1) si está bien
 *
 */
int peticionEnteroPositivo(int* numEntero, char texto[], int intentos);

/** \brief
 *
 * \param numDia int*
 * \param numMEs int*
 * \param numAnio int*
 * \param texto[] char
 * \param intentos int
 * \return int Devuelve (0) si Error [Longitud no válida o puntero NULL o sin
             espacio libre] - (1) si está bien
 *
 */
int peticionFecha(int* numDia, int* numMEs, int* numAnio, char texto[], int intentos);

#endif // FUNCIONESVALIDACION_H_INCLUDED
