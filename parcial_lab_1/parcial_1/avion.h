#ifndef AVION_H_INCLUDED
#define AVION_H_INCLUDED
typedef struct
{
    int id; // pk
    int idAerolinea;
    int idTipo;
    int capacidad;
    int isEmpty; //1 esta vacio, 0 esta lleno

} eAvion;


int buscarLibre(eAvion listaAvion[], int tam);

int altaAvion(eAvion listaAvion[], int tam, eAerolineas listaAerolineas[], int tamAero,eTipo listaTipo[], int tamTipo, int* pId, int longLimCadena, int intentos);

int peticionCapacidad( int* capacidad , char texto[], int intentos);

void mostrarAvion(eAvion unAvion, eAerolineas aerolineas[], int tamAero, eTipo tipos[], int tamTipo);

int inicializarAviones(eAvion lista[], int tam);

int mostrarAviones(eAvion listaAviones[], int tam, eAerolineas aerolineas[], int tamAero, eTipo tipos[], int tamTipo);

int modificarAvion(eAvion listaAviones[], int tam, eAerolineas aerolineas[], int tamAero, eTipo tipos[], int tamTipo, int longLimCadena, int intentos);

int subMenuModificar();

int buscarAvionId(eAvion listaAviones[], int tam, int Id);

int bajaAvion(eAvion listaAviones[], int tam, int id, eAerolineas aerolineas[], int tamAero, eTipo tipos[], int tamTipo);



#endif // AVION_H_INCLUDED
