/*Jaime Delgado Linares*/

/*En este archivo se encuentran las funciones encargadas de controlar las listas de peliculas.
NO DEVUELVEN NADA POR PANTALLA*/

#ifndef listadepeliculas_h
#define listadepeliculas_h 

#include "peliculas.h"
using namespace std;

//Estructuras listadepeliculas
const int maxpelis=1; //Numero maximo de peliculas que caben en la lista
const int num=10; //Capacidad inicial del array de pelis
typedef struct{
	int contador; // Cuenta las pelis que hay en la lista de pelis
	peliPtr lista; 
	int capacidad;
}tListaPelis; // LISTA PELIS

//PROTOTIPOS LISTADEPELICULAS 

//Recibe una lista de peliculas y devuelte true si la lista esta llena
bool listaPeliculasLlena(tListaPelis lista);
//Recibe una lista de peliculas, y un codigo.
//Devuelve true si se ha encontrado la peli en la lista y su posicion
//UTILIZA buscaPeli() QUE REALIZA LA BUSQUEDA RECURSIVAMENTE, la he metido dentro para no tener
//que cambiar las llamadas a esta funcion en la practica anterior
bool buscarPelicula(tListaPelis lista, int codigo, int &posicion);
//Recibe una pelicula, y una lista de peliculas e inserta la pelicula en la lista y la ordena por codigo
//Devuelve la lista actualizada
void insertarPelicula(tPelicula pelicula, tListaPelis &lista);
//Recibe un codigo y una lista de pelis. Busca la peli en la lista, y si esta, la marca como no disponible.
//Devuelve la lista actualizada
void bajaPelicula(int codigo, tListaPelis &lista);
//Recibe una peli y una lista de pelis y devuelve true si la peli ya esta en la lista (por codigo)
bool existePeli(tPelicula pelicula, tListaPelis &lista); //MEJORA PRACTICA ANTERIOR


/*              ++++ VERSION 2.0 ++++          */
//Recibe una lista de pelis, un codigo, el inicio, mitad y fin de la lista, y devuelve true si se ha
//encontrado la peli y su posicion (BUSQUEDA BINARIA RECURSIVA)
bool buscaPeli(tListaPelis lista, int codigo, int &pos, int ini, int fin);
//Recibe una lista de pelis e inicilializa el puntero. Crea un puntero a un array de lista.capacidad elem
void crearPelisPtr(tListaPelis &lista, int numero);
//Recibe una lista de pelis y si queda suficiente memoria, amplia la capacidad del array dinamico con ayuda de un puntero aux
bool ampliarPelisPtr(tListaPelis &lista);
//Destruye el puntero al array de las pelis cuando ya no lo use
void destruirPelisPtr(tListaPelis lista);

#endif
