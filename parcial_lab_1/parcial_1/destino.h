#ifndef DESTINO_H_INCLUDED
#define DESTINO_H_INCLUDED
typedef struct
{
    int id; // pk
    char descripcion[25];
    int precio;
    int isEmpty; //1 esta vacio, 0 esta lleno
} eDestino;


#endif // DESTINO_H_INCLUDED
