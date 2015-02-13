/*Jaime Delgado Linares */
#include <iostream>
#include <string>
#include "listadeclientes.h"
using namespace std;

//Implementacion funciones listadeclientes
bool listaClientesLlena(tListaClientes &listaClientes){
	bool llena = false;
	if(listaClientes.listaclientes == NULL){
		llena = true;
	}
	return llena;
}
bool buscarCliente(tListaClientes &listaClientes, string nif, int &posicion){
	bool encontrado = false;
	int ini=1, fin=listaClientes.contador, resultado=0;
	if(buscaNif(listaClientes, nif, resultado, ini, fin)){
		encontrado=true;
	}
	posicion=resultado;
	return encontrado;
}
void insertarCliente(tCliente cliente, tListaClientes &lista){
	int pos=0;
	if(existeCliente(cliente, lista)){
		//La peli ya esta en la lista
	}else if(listaClientesLlena(lista)){
		// No Hay suficiente memoria
	}else if(lista.contador==lista.capacidad){// si no tienes espacio en el array dinamico
		//Amplio array dinamico con la formula de la practica
		if(ampliarClientesPtr(lista)){
		}
		buscarCliente(lista, cliente.nif, pos);
		for(int j=lista.contador; j>pos; j--){ //Desde el ultimo hasta i
			lista.listaclientes[j]=lista.listaclientes[j-1];
		}
		lista.listaclientes[pos] = cliente;
		lista.contador++;
	}else{// Tengo suficiente espacio en el array dinamico para introducirlo
		buscarCliente(lista, cliente.nif, pos);
		for(int j=lista.contador; j>pos; j--){ //Desde el ultimo hasta i
			lista.listaclientes[j]=lista.listaclientes[j-1];
		}
		lista.listaclientes[pos] = cliente;
		lista.contador++;
	}
}
void bajaCliente(string nif, tListaClientes &listaClientes){
	int pos=0;
	if(buscarCliente(listaClientes, nif, pos)){
		for(int i=pos+1; i<listaClientes.contador; i++){
			listaClientes.listaclientes[i-1]=listaClientes.listaclientes[i];
		}
		listaClientes.contador--;

	}else{
		// No existe ese cliente
	}
}
bool existeCliente(tCliente cliente, tListaClientes lista){
	int pos=0;
	bool existe=false;
	if(buscarCliente(lista, cliente.nif, pos)){
		existe=true;
	}
	return existe;
}

// VERSION 2.0
bool buscaNif(tListaClientes lista, string nif, int &pos, int ini, int fin){
	int mitad = (ini+fin)/2; //codigo anterior
	pos=mitad;

	if(lista.listaclientes[mitad-1].nif == nif){ //Caso base 1
		return true;

	}else if(ini>fin){ //Caso base 2
		return false;
	}

	if(nif < lista.listaclientes[mitad-1].nif){
		return buscaNif(lista, nif, pos, ini, mitad-1); //Llamada recursiva 

	}else{
		return buscaNif(lista, nif, pos, mitad+1, fin); //Llamada recursiva 

	}
}

void crearClientesPtr(tListaClientes &lista, int numero) {
  lista.contador = 0;
  lista.capacidad = numero;
  lista.listaclientes = new tCliente[lista.capacidad];
}
bool ampliarClientesPtr(tListaClientes &lista) {
  bool ok = true;
  clientePtr aux = lista.listaclientes;
  lista.capacidad = (lista.capacidad * 3) / 2 + 1;
  lista.listaclientes = new tCliente[lista.capacidad];
  if (lista.listaclientes == NULL) { // No queda suficiente memoria
    ok = false;
	lista.listaclientes = aux;
  }
  else {
	  for (int i = 0; i < lista.contador; i++)
		lista.listaclientes[i] = aux[i];
    delete [] aux;
  }
  return ok;
}
void destruirClientesPtr(tListaClientes lista) {
	delete [] lista.listaclientes;
}
