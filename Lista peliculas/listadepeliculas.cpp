/*Jaime Delgado Linares DNI:50242452X*/
#include <iostream>
#include <string>
#include "listadepeliculas.h"
using namespace std;

//Implementacion funciones listadepeliculas enunciado
bool listaPeliculasLlena(tListaPelis lista){
	bool llena=false;
	if(lista.lista == NULL){
		llena = true;
	}
	return llena;
}
bool buscarPelicula(tListaPelis listapelis, int codigo, int &posicion){
	bool encontrado = false;
	int ini=1, fin=listapelis.contador, resultado=0;
	if(buscaPeli(listapelis, codigo, resultado, ini, fin)){
		encontrado=true;
	}
	posicion=resultado;
	return encontrado;
}
void insertarPelicula(tPelicula pelicula, tListaPelis &lista){
	int pos=0;
	if(existePeli(pelicula, lista)){
		//La peli ya esta en la lista
	}else if(listaPeliculasLlena(lista)){
		// No Hay suficiente memoria
	}else if(lista.contador==lista.capacidad){// si no tienes espacio en el array dinamico
		//Amplio array dinamico con la formula de la practica
		if(ampliarPelisPtr(lista)){
		}
		buscarPelicula(lista, pelicula.codigo, pos);
		for(int j=lista.contador; j>pos; j--){ //Desde el ultimo hasta i
			lista.lista[j]=lista.lista[j-1];
		}
		lista.lista[pos] = pelicula;
		lista.contador++;
	}else{// Tengo suficiente espacio en el array dinamico para introducirla
		buscarPelicula(lista, pelicula.codigo, pos);
		for(int j=lista.contador; j>pos; j--){ //Desde el ultimo hasta i
			lista.lista[j]=lista.lista[j-1];
		}
		lista.lista[pos] = pelicula;
		lista.contador++;
	}
}
void bajaPelicula(int codigo, tListaPelis &lista){
	int pos=0;
	if(buscarPelicula(lista, codigo, pos)){
		lista.lista[pos].disponible = false;
	}else{
		// No se ha encontrado ese cliente
	}
}
bool existePeli(tPelicula pelicula, tListaPelis &lista){
	int pos=0;
	bool existe=false;
	if(buscarPelicula(lista, pelicula.codigo, pos)){
		existe=true;
	}
	return existe;
}

// VERSION 2.0
bool buscaPeli(tListaPelis lista, int codigo, int &pos, int ini, int fin){
	int mitad = (ini+fin)/2; //codigo anterior
	pos=mitad;

	if(lista.lista[mitad-1].codigo == codigo){ //Caso base 1
		return true;

	}else if(ini>fin){ //Caso base 2
		return false;
	}

	if(codigo < lista.lista[mitad-1].codigo){
		return buscaPeli(lista, codigo, pos, ini, mitad-1); //Llamada recursiva 

	}else{
		return buscaPeli(lista, codigo, pos, mitad+1, fin); //Llamada recursiva 

	}
}

void crearPelisPtr(tListaPelis &lista, int numero) {
  lista.contador = 0;
  lista.capacidad = numero;
  lista.lista = new tPelicula[lista.capacidad];
}
bool ampliarPelisPtr(tListaPelis &lista) {
  bool ok = true;
  peliPtr aux = lista.lista;
  lista.capacidad = (lista.capacidad * 3) / 2 + 1;
  lista.lista = new tPelicula[lista.capacidad];
  if (lista.lista == NULL) { // No queda suficiente memoria
    ok = false;
	lista.lista = aux;
  }
  else {
	  for (int i = 0; i < lista.contador; i++)
		lista.lista[i] = aux[i];
    delete [] aux;
  }
  return ok;
}
void destruirPelisPtr(tListaPelis lista) {
	delete [] lista.lista;
}