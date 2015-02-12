/*Jaime Delgado Linares DNI:50242452X*/

/*En este archivo se encuentran las funciones encargadas de modificar los generos*/

#ifndef genero_h
#define genero_h

//Estructuras genero
typedef enum{
	cienciaficcion, fantasia, comedia, terror, drama, comediaromantica 
}tGenero; //GENERO

//Prorotipos funciones genero
//Pide un genero al usuario y devuelve una variable tGenero con el genero leido
tGenero leerGenero();
//Dada una variable tGenero escribe su nombre en consola
void escribirGenero(tGenero &genero);
//Recibe un entero y realiza el switch para escribir el genero
tGenero switchgenero(int gen);

#endif