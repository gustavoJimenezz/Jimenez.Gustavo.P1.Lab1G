#ifndef PILOTOS_H_INCLUDED
#define PILOTOS_H_INCLUDED

typedef struct
{
    int id;
    char nombre[30];
    char sexo;

}ePiloto;

int cargarDescripcionPiloto(ePiloto listaPilotos[], int tamPiloto, int idPiloto, char descripcion[]);

#endif // PILOTOS_H_INCLUDED
