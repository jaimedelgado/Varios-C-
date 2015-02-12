/*Jaime Delgado Linares DNI:50242452X*/

/*En este archivo se encuentran las funciones encargadas de controlar las listas de clientes.
NO DEVUELVEN NADA POR PANTALLA*/

#ifndef listadeclientes_h
#define listadeclientes_h 

#include "clientes.h"
using namespace std;

//Estructuras listadeclientes
const int maxclientes=1; //Numero maximo de clientes que caben en una lista
const int num1=10; //Capacidad inicial del array de clientes
typedef struct{
	int contador; //Numero de clientes que hay en la lista
	clientePtr listaclientes; 
	int capacidad;
}tListaClientes; // LISTA DE CLIENTES

//Prototipos funciones listadeclientes
//Recibe una lista de clientes y devuelve true si la lista esta llena
bool listaClientesLlena(tListaClientes &listaClientes);
//Recibe una lista de clientes y un nif y devuelve la posicion donde se encuentra
//el nif en el array de la lista de clientes y true si se ha encontrado
//UTILIZA buscaNif() QUE REALIZA LA BUSQUEDA RECURSIVAMENTE, la he metido dentro para no tener
//que cambiar las llamadas a esta funcion en la practica anterior
bool buscarCliente(tListaClientes &listaClientes,string nif, int &posicion);
//Recibe un cliente y una lista, e introduce el cliente en la lista. Devuelve la lista actualizada
void insertarCliente(tCliente cliente, tListaClientes &lista);
//Recibe un nif y una listaClientes y elimina al cliente completamente. Devuelve la lista actualizada
void bajaCliente(string nif, tListaClientes &listaClientes);
//Recibe un cliente y una lista y devuelve true si el cliente ya existe en la lista (comprobando nif)
bool existeCliente(tCliente cliente, tListaClientes lista); //MEJORA PRACTICA ANTERIOR


/*              ++++ VERSION 2.0 ++++          */
//Recibe una lista de clientes, un nif, el inicio, mitad y fin de la lista, y devuelve true si se ha
//encontrado el cliente y su posicion (BUSQUEDA BINARIA RECURSIVA)
bool buscaNif(tListaClientes lista, string nif, int &pos, int ini, int fin);
//Recibe una lista de clientes e inicilializa el puntero. Crea un puntero a un array de lista.capacidad elem
void crearClientesPtr(tListaClientes &lista, int numero);
//Recibe una lista de clientes y si queda suficiente memoria, amplia la capacidad del array dinamico con ayuda de un puntero aux
bool ampliarClientesPtr(tListaClientes &lista);
//Destruye el puntero al array de los clientes cuando ya no lo use
void destruirClientesPtr(tListaClientes lista);

#endif