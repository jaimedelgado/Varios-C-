/*Jaime Delgado Linares */

/*En este archivo se encuentran las funciones encargadas de modificar y crear clientes*/

#ifndef clientes_h
#define clientes_h 

#include "genero.h"
#include "listadepeliculas.h"

//Estructuras
const int N=40;

typedef struct{
	int codigo; //Codigo de la peli
	bool opinion; //Si le ha gustado al cliente o no
}tPeliculasVisionadas; //DATOS DE UN VISIONADO

typedef char tCadena[80];
typedef struct{
	tCadena nif; 
	tCadena nombre;
	tCadena apellidos;
	tGenero generoFavorito;
	tPeliculasVisionadas peliculasVisionadas[N]; // array de las pelis que ha visto el cliente
	int contador; // Cuenta las pelis que ha visto el cliente
}tCliente; // CLIENTE

typedef tCliente *clientePtr; //Puntero a un tCliente

const int SIZECLIENTE=sizeof(tCliente);

//Prototipos
//Lee los datos de un cliente, inicializa su lista de visionados como una lista vacía y devuelve
//como salida una estructura tCliente debidamente creada. Comprueba que su nif este correcto
tCliente leerCliente();
//Recibe un cliente, un booleano y una lista de pelis. Si el booleano es false muestra los datos
//del cliente, y si es true muestra al detalle sys peliculas visionadas
void mostrarCliente(tCliente cliente, bool mostrarDetalles, tListaPelis listacompleta);
//Recibe un cliente y ofrece al usuario editar el nombre, los apellidos y el genero favorito
void editarCliente(tCliente &cliente);
//Recibe un cliente y los datos de un visionado, y devuelve el cliente actualizado
void altaVisionado(tCliente &cliente, tPeliculasVisionadas peliculasvisionadas);
//Recibe un cliente y un codigo y devuelve el numero de veces que el cliente ha visto una pelicula y cuantas veces le gstó
void datosVisionado(tCliente cliente, int codigo, int &visiones, int &gusta);
//Recibe un nif y devuelve si el nif esta correcto (8digitos y una letra alfinal)
bool nifCorrecto(string nif);

#endif
