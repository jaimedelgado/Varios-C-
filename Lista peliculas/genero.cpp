/*Jaime Delgado Linares */
#include <iostream>
#include "genero.h"
using namespace std;

//Implementacion funciones genero

//Pide un género al usuario y devuelve una variable de tipo tGenero con el género leído
tGenero leerGenero(){
	tGenero genero;
	int num;
	cout << "(1) - Ciencia ficcion " << endl;
	cout << "(2) - Fantasia " << endl;
	cout << "(3) - Comedia " << endl;
	cout << "(4) - Terror " << endl;
	cout << "(5) - Drama " << endl;
	cout << "(6) - Comedia romantica" << endl;
	do{
		cin.sync();
		do{ //Por si lo introduces fuera del intervalo (1-6)
		cin >> num;
		genero = switchgenero(num-1);
		}while(num<1 || num>6);
		if(num<1 || num>6){
			cout << "Vuelva a introducir: " << endl;
		}
	}while(num<1 || num>6);
	return genero;
}
//Dada una variable de tipo tGenero, escribe el nombre del género en la consola
void escribirGenero(tGenero &genero){
	switch(genero){
	case 0:
			cout << "Ciencia-ficcion";
			break;
		case 1:
			cout << "Fantasia";
			break;
		case 2:
			cout << "Comedia";
			break;
		case 3:
			cout << "Terror";
			break;
		case 4:
			cout << "Drama";
			break;
		case 5:
			cout << "Comedia-romantica";
			break;
	}
}
//switch
tGenero switchgenero(int gen){
	tGenero genero;
	switch(gen){
		case 0:
			genero = cienciaficcion;
			break;
		case 1:
			genero = fantasia;
			break;
		case 2:
			genero = comedia;
			break;
		case 3:
			genero = terror;
			break;
		case 4:
			genero = drama;
			break;
		case 5:
			genero = comediaromantica;
			break;
		default:
			genero = terror; //Inicializo la variable genero a cualquier genero
			break;
	}
	return genero;
}

