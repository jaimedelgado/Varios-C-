/*Jaime Delgado Linares DNI:50242452X*/
#include <iostream>
#include <string>
#include "clientes.h"
using namespace std;

//Implementacion funciones clientes
tCliente leerCliente(){
	tCliente cliente;
	string nif, nombre, apellidos;
	do{
		cout << "Introduzca nif: ";
		cin.sync();
		getline(cin,nif);
	}while(!nifCorrecto(nif));
	int size=nif.size();
	for(int i=0; i<size; i++){
		cliente.nif[i]=nif.at(i);
	}
	cliente.nif[size]=0;
	cout << endl << "Introduzca nombre: " ;
	getline(cin,nombre);
	size=nombre.size();
	for(int i=0; i<size; i++){
		cliente.nombre[i]=nombre.at(i);
	}
	cliente.nombre[size]=0;
	cout << endl << "Introduzca los apellidos: ";
	getline(cin,apellidos);
	size=apellidos.size();
	for(int i=0; i<size; i++){
		cliente.apellidos[i]=apellidos.at(i);
	}
	cliente.apellidos[size]=0;
	cout << endl << "Introduzca su genero favorito: " << endl;
	cliente.generoFavorito = leerGenero();
	cliente.contador=0;
	return cliente;
}
void mostrarCliente(tCliente cliente, bool mostrarDetalles, tListaPelis listacompleta){
	int pos=0;
	cout << "           Nombre: " << cliente.nombre << " " << cliente.apellidos << endl;
	cout << "              NIF: " << cliente.nif << endl; /*<< cliente.nif.numero << cliente.nif.letra << endl;*/
	cout << "  Genero favorito: "; escribirGenero(cliente.generoFavorito); cout << endl;
	if(mostrarDetalles == false){
		cout << "Pelis descargadas: " << cliente.contador << endl;
	}else{
		cout << "Pelis descargadas: " << endl;
		for(int i=0; i<cliente.contador; i++){
			if(buscarPelicula(listacompleta, cliente.peliculasVisionadas[i].codigo, pos)){
				cout << listacompleta.lista[pos].titulo << " - ";
				escribirGenero(listacompleta.lista[pos].genero) ; cout << " - ";
				if(cliente.peliculasVisionadas[i].opinion){
					cout << "SI ";
				}else{
					cout << "NO ";
				}
				cout << "le ha gustado." << endl;
			}
		}
	}
}
void editarCliente(tCliente &cliente){
	string c; 
	int size;
	string nombre, apellidos;
	cout << "El nombre es: " << cliente.nombre << endl;
	cout << "Nuevo nombre (INTRO para no modificar): " << endl;
	cin.sync();
	getline(cin, nombre);
	if(nombre != ""){
		size = nombre.size();
		for(int i=0; i<size; i++){
			cliente.nombre[i]=nombre.at(i);
		}
		cliente.nombre[size]=0;
	}
	cin.sync();
	cout << "Los apellidos son: " << cliente.apellidos << endl;
	cout << "Nuevos apellidos (INTRO para no modificar): " << endl;
	cin.sync();
	getline(cin, apellidos);
	if(apellidos != ""){
		size = apellidos.size();
		for(int i=0; i<size; i++){
			cliente.apellidos[i]=apellidos.at(i);
		}
		cliente.apellidos[size]=0;
	}
	cin.sync();
	cout << "Su genero favorito es: " ; escribirGenero(cliente.generoFavorito);
	cout << endl << "Quieres cambiarlo (s para cambiar, INTRO para continuar): " << endl;
	getline(cin,c);
	while(c!="s"&&c!="S"&&c!=""){
		cin >> c;
	}
	if(c == "s" || c == "S"){
		cout << "Introduzca el genero de la pelicula: " << endl;
		cliente.generoFavorito = leerGenero();
	}
	cin.sync();
}
void altaVisionado(tCliente &cliente, tPeliculasVisionadas peliculasvisionadas){
	int i=0;
	if(cliente.contador==0){
		cliente.peliculasVisionadas[cliente.contador] = peliculasvisionadas;
		cliente.contador++;
	}else{
		//buscar posicion en la lista de peliculasVisionadas que ocupa la peli segun el codigo
		while(i!=cliente.contador&&(i!=cliente.contador&&cliente.peliculasVisionadas[i].codigo < peliculasvisionadas.codigo)){
			i++;
		}
		for(int j=cliente.contador; j>i; j--){ //Desde el ultimo hasta i
			cliente.peliculasVisionadas[j]=cliente.peliculasVisionadas[j-1];
		}
		cliente.peliculasVisionadas[i] = peliculasvisionadas;
		cliente.contador++;
	}

}
void datosVisionado(tCliente cliente, int codigo, int &visiones, int &gusta){
	int i=0;
	visiones = 0;
	gusta = 0;
	while(cliente.contador!=i){ //Recorro todas las pelis visionadas del cliente
		if(cliente.peliculasVisionadas[i].codigo == codigo){
			visiones++;
			if(cliente.peliculasVisionadas[i].opinion){
				gusta++;
			}
		}
		i++;
	}
}
bool nifCorrecto(string nif){
	bool ok=true;
	if(nif.size()!=9){
		ok=false;
	}else{
		for(int i=0; i<9; i++){
			if(i==8){
				if(isdigit(nif.at(i))){
					ok=false;
				}
			}else{
				if(isalpha(nif.at(i))){
					ok=false;
				}
			}
		}
	}
	return ok;
}