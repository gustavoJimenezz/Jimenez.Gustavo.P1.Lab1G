#ifndef ESTRUCTURAPILOTO_H_INCLUDED
#define ESTRUCTURAPILOTO_H_INCLUDED



typedef struct
{
    int id;
    char nombre[30];
    char sexo;

} ePiloto;

int cargarDescripcionPiloto( ePiloto listaPilotos[], int tamPilotos, int id, char nombrePiloto[]);

#endif // ESTRUCTURAPILOTO_H_INCLUDED
