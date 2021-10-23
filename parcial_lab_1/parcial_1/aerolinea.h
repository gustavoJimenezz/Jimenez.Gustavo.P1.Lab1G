#ifndef AEROLINEA_H_INCLUDED
#define AEROLINEA_H_INCLUDED
typedef struct
{
    int id; // pk
    char descripcion[20];
    int isEmpty; //1 esta vacio, 0 esta lleno
} eAerolineas;


int mostrarAerolineas( eAerolineas listAerolineas[], int tam);

int validarIdAerolinea(int id, eAerolineas aerolineas[], int tam);

int peticionIdAerolineas(int* numId, eAerolineas aerolineas[], int tamAero, char texto[], int intentos);

int cargarDescripcionAerolineas( eAerolineas aerolineas[], int tam, int idAero, char descripcion[] );


#endif // AEROLINEA_H_INCLUDED
