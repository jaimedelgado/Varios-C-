/*Jaime Delgado Linares */

/*En este archivo se encuentran las funciones encargadas de modificar y crear peliculas*/

#ifndef peliculas_h
#define peliculas_h 

#include "genero.h"
using namespace std;

//Estructuras peliculas
typedef char tTitulo[80];

typedef struct{
	int codigo;
	tTitulo titulo;
	tGenero genero;
	int duracion;
	double precio;
	bool disponible;
}tPelicula; //PELICULA

typedef tPelicula *peliPtr; //Puntero a una tPelicula

const int SIZEPELI=sizeof(tPelicula); //Tam de una tPelicula

//Prototipos funciones para gestionar peliculas
//No recibe nada. Pide al usuario los datos necesarios para la ficha de una pelicula y devuelve
//una variable tPelicula debidamente actualizada
tPelicula leerPelicula();
//Recibe una pelicula y muestra sus datos por pantalla
void mostrarPelicula(tPelicula pelicula);
//Recibe una pelicula y ofrece al usuario la posibilidad de editar el titulo,genero,duracion y precio
void editarPelicula(tPelicula &pelicula);

#endif
