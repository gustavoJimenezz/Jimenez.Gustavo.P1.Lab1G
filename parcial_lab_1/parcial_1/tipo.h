#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED

typedef struct
{
    int id; // pk
    char descripcion[20];
    int isEmpty; //1 esta vacio, 0 esta lleno
} eTipo;

int mostrarTipos( eTipo listTipos[], int tam);

int validarIdTipo( int idTipo, eTipo tipos[], int tam );

int peticionIdTipo(int* numId, eTipo tipos[], int tamTipo, char texto[], int intentos);

int cargarDescripcionTipo( eTipo tipos[], int tam, int idTipo, char descripcion[]);

#endif // TIPO_H_INCLUDED
