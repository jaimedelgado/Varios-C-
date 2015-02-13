/*Jaime Delgado Linares */
#include <iostream>
#include <string>
#include "peliculas.h"
using namespace std;

//Implementacion funciones peliculas
tPelicula leerPelicula(){
	int codigo, duracion;
	double precio;
	string titulo;
	bool disponible = false;
	tPelicula pelicula;
	tGenero genero;
	cout << "Introduzca el codigo de la pelicula: " << endl;
	cin >> codigo;
	cout << "Introduzca el titulo de la pelicula: " << endl;
	cin.sync();
	getline(cin,titulo);
	cin.sync();
	cout << "Introduzca el genero de la pelicula: " << endl;
	genero = leerGenero();
	cout << "Introduzca la duracion de la pelicula: " << endl;
	cin >> duracion;
	cout << "Introduzca el precio de la pelicula: " << endl;
	cin >> precio;
	pelicula.codigo = codigo;
	int letras=titulo.size();
	for(int i=0; i<letras; i++){
		pelicula.titulo[i] = titulo.at(i);
	}
	pelicula.titulo[letras]=0;
	pelicula.duracion = duracion;
	pelicula.genero = genero;
	pelicula.precio = precio;
	pelicula.disponible = true;
	return pelicula;
}
void mostrarPelicula(tPelicula pelicula){
	cout << "Pelicula #";
	cout << pelicula.codigo << endl;
	cout << "Titulo: ";
	cout << pelicula.titulo << endl;
	cout << "Genero: ";
	escribirGenero(pelicula.genero); cout << endl;
	cout << "Duracion: ";
	cout << pelicula.duracion << endl;
	cout << "Alquiler: ";
	cout << pelicula.precio << endl;
	cout << "Activa: ";
	if(pelicula.disponible){
		cout << "Si" << endl;
	}else{
		cout << "No" << endl;
	}
}
void editarPelicula(tPelicula &pelicula){
	char c; 
	string titulo, b;
	cout << "Introduzca el codigo de una pelicula: " << endl;
	cin >> pelicula.codigo;
	cout << "Se titula: " << pelicula.titulo << endl;
	cout << "Introduzca el titulo (INTRO para no modificar): " << endl;
	getline(cin, titulo); //COJO SALTO
	getline(cin, titulo);
	if(titulo != ""){
		int letras=titulo.size();
		for(int i=0; i<letras; i++){
			pelicula.titulo[i] = titulo.at(i);
		}
	}
	cout << "El genero es: " ; escribirGenero(pelicula.genero);
	cout << endl << "Quieres cambiarlo (s para cambiar, INTRO para continuar): " << endl;
	cin >> b;
	while(b!="s"&&b!="S"&&b!=""){
		cin >> b;
	}
	if(b == "s" || b == "S"){
		cout << "Introduzca el genero de la pelicula: " << endl;
		pelicula.genero = leerGenero();
	}
	cout << "La pelicula dura " << pelicula.duracion << " minutos" << endl;
	cout << "Introduzca la duracion (INTRO para no modificar): " << endl;
	cin.sync();
	c = cin.peek();
	if(isdigit(c)){
		cin >> pelicula.duracion;
	}
	cout << "La pelicula cuesta " << pelicula.precio << " euros" << endl;
	cout << "Introduzca el precio (INTRO para no modificar): " << endl;
	cin.sync();
	c = cin.peek();
	if(isdigit(c)){
		cin >> pelicula.precio;
	}
	cin.sync();
	cout << "Se ha modificado correctamente, sus nuevos valores son:" << endl;
	mostrarPelicula(pelicula);
}

