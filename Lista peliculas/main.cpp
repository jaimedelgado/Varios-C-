/*Jaime Delgado Linares*/

#include <iostream>
#include <fstream>
#include <string>
#include "listadeclientes.h"
#include "listadepeliculas.h"

using namespace std;

//PROTOTIPOS

//       ++VERSION2.0++

//Lee un archivo BINARIO de peliculas
//1-Si NO se encuentra el archivo crea una lista vacia de peliculas
//2-Si se encuentra el archivo crea una lista con las peliculas del archivo
tListaPelis leeArBinPelis();
//Lee un archivo BINARIO de clientes
//1-Si NO se encuentra el archivo crea una lista vacia de clientes
//2-Si se encuentra el archivo crea una lista con los clientes del archivo
tListaClientes leeArBinClientes();
//Escribe el archivo BINARIO de peliculas al terminar la ejecucion del programa.Recibe una lista de pelis.No devuelve nada
void escribeArBinPelis(tListaPelis lista);
//Escribe el archivo BINARIO de clientes al terminar la ejecucion del programa.Recibe una lista de clientes.No devuelve nada
void escribeArBinClientes(tListaClientes lista);


//Lee un archivo de peliculas
//1-Si NO se encuentra el archivo crea una lista vacia de peliculas
//2-Si se encuentra el archivo crea una lista con las peliculas del archivo
tListaPelis leeArchivoPelis();
//Lee un archivo de clientes
//1-Si NO se encuentra el archivo crea una lista vacia de clientes
//2-Si se encuentra el archivo crea una lista con los clientes del archivo
tListaClientes leeArchivoClientes();
//Recibe una lista de clientes y devuelve otra lista de clientes igual a la otra
//pero ordenada por apellidos
tListaClientes ordenarApellidos(tListaClientes lista);
//Escribe el archivo de peliculas al terminar la ejecucion del programa.Recibe una lista de clientes.No devuelve nada
void escribeArchivoPelis(tListaPelis lista);
//Escribe el archivo de clientes al terminar la ejecucion del programa.Recibe una lista de pelis.No devuelve nada
void escribeArchivoClientes(tListaClientes lista);

//MENU PRINCIPAL
//Menu principal. Devuelve la opcion elegida
int menuPrincipal();
//Lleva a cabo la opcion1 del menu principal. Recibe una lista de pelis y la devuelve actualizada
void opcion1principal(tListaPelis &listapelis);
//Lleva a cabo la opcion2 del menu principal. Recibe las listas de clientes y pelis y las actualiza
void opcion2principal(tListaClientes &listaclientes, tListaPelis &listapelis);
//Lleva a cabo la opcion2 del menu principal. Recibe las listas de clientes y pelis y las actualiza
void opcion3principal(tListaClientes &listaclientes, tListaPelis &listapelis);
//Lleva a cabo la opcion2 del menu principal. Recibe las listas de clientes y pelis y las actualiza
void opcion4principal(tListaClientes &listaclientes, tListaPelis &listapelis);

//MENU PELICULAS
//Menu peliculas. Devuelve la opcion elegida
int menuPeliculas();
//Lleva a cabo la opcion1 del menu peliculas. Recibe una lista de pelis y la devuelve actualizada
void opcion1peliculas(tListaPelis &listapelis);
//Lleva a cabo la opcion2 del menu peliculas. Recibe una lista de pelis y la devuelve actualizada
void opcion2peliculas(tListaPelis &listapelis);
//Lleva a cabo la opcion3 del menu peliculas. Recibe una lista de pelis y la devuelve actualizada
void opcion3peliculas(tListaPelis &listapelis);
//Lleva a cabo la opcion4 del menu peliculas. Recibe una lista de pelis y la devuelve actualizada
void opcion4peliculas(tListaPelis &listapelis);
//Lleva a cabo la opcion5 del menu peliculas. Recibe una lista de pelis y la devuelve actualizada
void opcion5peliculas(tListaPelis &listapelis);
//Recibe una lista de pelis y la devuelve ordenada por codigo
void ordenapelis (tListaPelis &listapelis);

//MENU CLIENTES
//Menu clientes. Devuelve la opcion elegida
int menuClientes();
//Lleva a cabo la opcion1 del menu clientes. Recibe una lista de clientes y la devuelve actualizada
void opcion1clientes(tListaClientes &listaclientes);
//Lleva a cabo la opcion2 del menu clientes. Recibe las listas de clientes y pelis y las actualiza
void opcion2clientes(tListaClientes &listaclientes, tListaPelis &listapelis);
//Lleva a cabo la opcion3 del menu clientes. Recibe las listas de clientes y pelis y las actualiza
void opcion3clientes(tListaClientes &listaclientes, tListaPelis &listapelis);
//Lleva a cabo la opcion4 del menu clientes. Recibe las listas de clientes y pelis y las actualiza
void opcion4clientes(tListaClientes &listaclientes, tListaPelis &listapelis);
//Lleva a cabo la opcion5 del menu clientes. Recibe una lista de clientes y la devuelve actualizada
void opcion5clientes(tListaClientes &listaclientes);

//OPCIONES MENU GESTION GENERAL
//Menu gestion. Devuelve la opcion elegida
int menuGestion();
//Lleva a cabo la opcion1 del menu gestion. Recibe las listas de clientes y pelis y las actualiza
void opcion1gestion(tListaClientes &listaclientes, tListaPelis &listapelis);
//Lleva a cabo la opcion2 del menu gestion. Recibe una lista de clientes y la actualiza
void opcion2gestion(tListaClientes &listaclientes);
//Lleva a cabo la opcion3 del menu gestion. Recibe las listas de clientes y pelis y las actualiza
void opcion3gestion(tListaClientes &listaclientes, tListaPelis &listapelis);

//Muestra el texto final y pide una tecla para terminar
void terminarPrograma();

//PROGRAMA PRINCIPAL
int main(){
	int opcion1;
	tListaPelis listapelis;
	tListaClientes listaclientes;
	/*listapelis = leeArchivoPelis();*/
	listapelis = leeArBinPelis();
	/*listaclientes = leeArchivoClientes();*/
	listaclientes = leeArBinClientes();
	do{
		opcion1 = menuPrincipal();
		switch(opcion1){
		case 1:
			opcion1principal(listapelis);
			break;
		case 2:
			opcion2principal(listaclientes, listapelis);
			break;
		case 3:
			opcion3principal(listaclientes, listapelis);
			break;
		case 4:
			opcion4principal(listaclientes, listapelis);
		default:
			break;
		}
		cout << endl;
	}while(opcion1!= 0);
	escribeArBinPelis(listapelis);
	escribeArBinClientes(listaclientes);
	destruirPelisPtr(listapelis);
	destruirClientesPtr(listaclientes);
	terminarPrograma();
	return 0;
}

//    ++VERSION 2.0++
tListaPelis leeArBinPelis(){
	tListaPelis lista;
	fstream archivo;
	archivo.open("pelis.dat", ios::in | ios::binary);
	if(archivo.is_open()){
		tPelicula peli;
		//Llevo el puntero del archivo al final
		archivo.seekg(0, ios::end);
		int pos=archivo.tellg();
		int numReg=pos/SIZEPELI;
		
		// Redondeo a la siguiente decena
		int tam=numReg/10; 
		tam++;
		tam=tam*10;
		// Creo array dinamico de ese tamaño
		crearPelisPtr(lista, tam);
		
		//Llevo el puntero del archivo al principio
		archivo.seekg(0, ios::beg);

		archivo.read( (char *) &peli, SIZEPELI);
		int cuantos = archivo.gcount();
		while (cuantos == SIZEPELI) {
			if(!listaPeliculasLlena(lista)){
				insertarPelicula(peli, lista);
			}
			archivo.read( (char *) &peli, SIZEPELI);
			cuantos = archivo.gcount();
		}
		cout << "Archivo de peliculas cargado con exito (" << lista.contador << " peliculas)" << endl;
		archivo.close();
	}else{
		//Creo array dinamico de 10 elem
		crearPelisPtr(lista, num);
		cout << "Se ha creado una lista de pelis vacia" << endl;
	}
	return lista;
}
tListaClientes leeArBinClientes(){
	tListaClientes lista;
	tCliente cliente;

	fstream archivo;
	archivo.open("clientes.dat", ios::in | ios::binary);
	if(archivo.is_open()){
		//Llevo el puntero del archivo al final
		archivo.seekg(0, ios::end);

		int pos=archivo.tellg();
		int numReg=pos/SIZECLIENTE;
		
		// Redondeo a la siguiente decena
		int tam=numReg/10; 
		tam++;
		tam=tam*10;
		// Creo array dinamico de ese tamaño
		crearClientesPtr(lista, tam);

		//Llevo el punteor del archivo al principio
		archivo.seekg(0, ios::beg);

		archivo.read( (char *) &cliente, SIZECLIENTE);
		int cuantos = archivo.gcount();
		while (cuantos == SIZECLIENTE) {
			if(!listaClientesLlena(lista)){
				insertarCliente(cliente, lista);
			}
			archivo.read( (char *) &cliente, SIZECLIENTE);
			cuantos = archivo.gcount();
		}
		cout << "Archivo de clientes cargado con exito (" << lista.contador << " clientes)" << endl << endl;
		archivo.close();
	}else{
		//Creo array dinamico de 10 elem
		crearClientesPtr(lista, num1);
		cout << "Se ha creado una lista de clientes vacia" << endl << endl;
	}
	return lista;
}
void escribeArBinPelis(tListaPelis lista){
	ofstream archivo;
	int i=0;
	archivo.open("pelis.dat", ios::out | ios::binary);
	while (i!=lista.contador) {
		archivo.write( (char *) &lista.lista[i], SIZEPELI);
		i++;
	}
	archivo.close();
	cout << "Archivo de peliculas guardado (" << lista.contador << " registros)" << endl;
}
void escribeArBinClientes(tListaClientes lista){
	ofstream archivo;
	int i=0;
	archivo.open("clientes.dat", ios::out | ios::binary);
	while (i!=lista.contador) {
		archivo.write( (char *) &lista.listaclientes[i], SIZECLIENTE);
		i++;
	}
	archivo.close();
	cout << "Archivo de clientes guardado (" << lista.contador << " registros)" << endl;
}
//  ++++++++++++++++++++

//Implementaciones
tListaPelis leeArchivoPelis(){
	tPelicula peli;
	tListaPelis lista;
	ifstream archivo;
	string titulo;
	int codigo, gen;
	char disponible;
	//Creo array dinamico de 10 elem
	crearPelisPtr(lista, num);
	archivo.open("pelis.txt");
	if(archivo.is_open()){
		cout << "Archivo de peliculas cargado con exito (" ;
		lista.contador = 0;
		do{
			archivo >> codigo;
			if(codigo!=-1){
				peli.codigo = codigo;
				cin.sync();
				getline(archivo,titulo); //Cojer salto de linea
				getline(archivo,titulo);
				int letras = titulo.size();
				for(int i=0; i<letras; i++){
					peli.titulo[i]=titulo.at(i);
				}
				peli.titulo[letras]=0;
				archivo >> gen >> peli.duracion >> peli.precio >> disponible;
				if(disponible=='S'){
					peli.disponible = true;
				}else{
					peli.disponible = false;
				}
				peli.genero = switchgenero(gen);
				if(!listaPeliculasLlena(lista)){
					insertarPelicula(peli, lista);
				}else{
					cout << "No se puede insertar la peli. Lista llena" << endl;
				}
			}
		}while(codigo != -1);
		cout << lista.contador << " peliculas)" << endl;
	}else{
		cout << "Se ha creado una lista de pelis vacia" << endl;
		lista.contador = 0;
	}
	
	return lista;
}
tListaClientes leeArchivoClientes(){
	tListaClientes lista;
	crearClientesPtr(lista, num1);
	tPeliculasVisionadas visionadas;
	tCliente cliente;
	ifstream archivo;
	char c;
	int genero, codigo=0, size;
	string opinion, nif, nombre, apellidos;
	archivo.open("clientes.txt");
	if(archivo.is_open()){
		cout << "Archivo de clientes cargado con exito (" ;
		lista.contador = 0; //Lista vacia de clientes
		do{
			cin.sync();
			cliente.contador = 0; //Lista vacia de pelis visionadas por el cliente 
			c = archivo.peek();
			if(isdigit(c)){
				archivo >> nif; 
				size = nif.size();
				for(int i=0; i<size; i++){
					cliente.nif[i]=nif.at(i);
				}
				cliente.nif[size]=0;
				getline(archivo, nombre); //COJER SALTO DE LINEA
				getline(archivo, nombre);
				size = nombre.size();
				for(int i=0; i<size; i++){
					cliente.nombre[i]=nombre.at(i);
				}
				cliente.nombre[size]=0;
				getline(archivo, apellidos);
				size = apellidos.size();
				for(int i=0; i<size; i++){
					cliente.apellidos[i]=apellidos.at(i);
				}
				cliente.apellidos[size]=0;
				archivo >> genero;
				cliente.generoFavorito = switchgenero(genero);
				do{
					archivo >> codigo;
					if(codigo!=-1){
						visionadas.codigo = codigo;
						getline(archivo, opinion);	
						getline(archivo, opinion);	
						if(opinion == "S"){
							visionadas.opinion = true;
						}else{
							visionadas.opinion = false;
						}
						altaVisionado(cliente, visionadas);
					}
				}while(codigo!=-1);
				if(listaClientesLlena(lista)){
					cout << "no se ha podido insertar el cliente. Lista llena" << endl << endl;
				}else{
					insertarCliente(cliente, lista);
				}
				getline(archivo, opinion);	//COJO SALTO
			}
		}while(c!='X');
		cout << lista.contador << " clientes)" << endl << endl;
	}else{
		cout << "Se ha creado una lista de clientes vacia" << endl << endl;
		lista.contador = 0; //Lista vacia de clientes
	}
	return lista;
}
tListaClientes ordenarApellidos(tListaClientes lista){
	tListaClientes ordenada;
	bool inter = true;
	int i=0;
	while((i < lista.contador-1) && inter){
		inter = false;
		for(int j=lista.contador-1; j>i; j--){
			if(*lista.listaclientes[j].apellidos<*lista.listaclientes[j-1].apellidos){
				tCliente tmp;
				tmp = lista.listaclientes[j];
				lista.listaclientes[j]=lista.listaclientes[j-1];
				lista.listaclientes[j-1]=tmp;
				inter = true;
			}
		}
		if(inter){
			i++;
		}
	}
	ordenada = lista;
	return ordenada;
}
void escribeArchivoPelis(tListaPelis lista){
	ofstream archivo;
	archivo.open("pelis.txt");
	int i=0;
	while(i!=lista.contador){
		archivo << lista.lista[i].codigo << endl;
		archivo << lista.lista[i].titulo << endl;
		archivo << lista.lista[i].genero << endl;
		archivo << lista.lista[i].duracion << endl;
		archivo << lista.lista[i].precio << endl;
		if(lista.lista[i].disponible){
			archivo << 'S' << endl;
		}else{
			archivo << 'N' << endl;
		}
		i++;
	}
	archivo << -1 << endl;
	archivo.close();
	cout << "Archivo de peliculas guardado (" << lista.contador << " registros)" << endl;
}
void escribeArchivoClientes(tListaClientes lista){
	ofstream archivo;
	archivo.open("clientes.txt");
	int i=0, j;
	while(i!=lista.contador){
		archivo << lista.listaclientes[i].nif << endl;
		archivo << lista.listaclientes[i].nombre << endl;
		archivo << lista.listaclientes[i].apellidos << endl;
		archivo << lista.listaclientes[i].generoFavorito << endl;
		j=0;
		while(j!=lista.listaclientes[i].contador){
			archivo << lista.listaclientes[i].peliculasVisionadas[j].codigo << endl;
			if(lista.listaclientes[i].peliculasVisionadas[j].opinion){
				archivo << 'S' << endl;
			}else{
				archivo << 'N' << endl;
			}
			j++;
		}
		archivo << -1 << endl;
		i++;
	}
	archivo << "X" << endl;
	archivo.close();
	cout << "Archivo de clientes guardado (" << lista.contador << " registros)" << endl;
}
//OPCIONES MENU PRINCIPAL
int menuPrincipal(){
	int opcion;
	cout << "-----------------------------------------" << endl;
	cout << "             MENU PRINCIPAL      " << endl;
	cout << "-----------------------------------------" << endl;
	cout << " 1 - Gestionar peliculas  " << endl;
	cout << " 2 - Gestionar clientes   " << endl;
	cout << " 3 - Gestion general      " << endl;
	cout << " 4 - Importar datos de archivos de texto      " << endl;
	cout << " 0 - Salir                " << endl;
	cout << "-----------------------------------------" << endl;
	cout << "Eliga una opcion: "; cin >> opcion;
	cout << "-----------------------------------------" << endl << endl;
	return opcion;
}
void opcion1principal(tListaPelis &listapelis){
	int opcion2;
	do{
		opcion2 = menuPeliculas();
		switch(opcion2){
		case 1:
			opcion1peliculas(listapelis);
			break;
		case 2:
			opcion2peliculas(listapelis);
			break;
		case 3:
			opcion3peliculas(listapelis);
			break;
		case 4:
			opcion4peliculas(listapelis);
			break;
		case 5:
			opcion5peliculas(listapelis);
			break;
		case 0: //salir
			break;
		default:
			cout << "Opcion no disponible" << endl << endl;
			break;
		}
	}while(opcion2!=0);
}
void opcion2principal(tListaClientes &listaclientes, tListaPelis &listapelis){
	int opcion2;
	do{
		opcion2 = menuClientes();
		switch(opcion2){
		case 1:
			opcion1clientes(listaclientes);
			break;
		case 2:
			opcion2clientes(listaclientes, listapelis);
			break;
		case 3:
			opcion3clientes(listaclientes, listapelis);
			break;
		case 4:
			opcion4clientes(listaclientes, listapelis);
			break;
		case 5:
			opcion5clientes(listaclientes);
			break;
		case 0: //salir
			break;
		default:
			cout << "Opcion no disponible" << endl << endl;
			break;
		}
	}while(opcion2!=0);
}
void opcion3principal(tListaClientes &listaclientes, tListaPelis &listapelis){
	int opcion3;
	do{
		opcion3 = menuGestion();
		switch(opcion3){
		case 1:
			opcion1gestion(listaclientes, listapelis);
			break;
		case 2:
			opcion2gestion(listaclientes);
			break;
		case 3:
			opcion3gestion(listaclientes, listapelis);
			break;
		case 0: //salir
			break;
		default:
			cout << "Opcion no disponible" << endl << endl;
			break;
		}
	}while(opcion3!=0);
}
void opcion4principal(tListaClientes &listaclientes, tListaPelis &listapelis){
	string tecla="F"; //Inicializo tecla
	cout << "*****************************" << endl;
	cout << "        ADVERTENCIA!!!       " << endl;
	cout << "*****************************" << endl;
	cout << "Esta operacion borrara todos los datos de las listas" << endl;
	cout << "Desea continuar con la operacion?(S/N): "; cin >> tecla;
	while(tecla!="s"&&tecla!="S"&&tecla!="n"&&tecla!="N"){
		cin >> tecla;
	}
	if(tecla=="s"||tecla=="S"){
		listapelis = leeArchivoPelis();
		listaclientes = leeArchivoClientes();
	}else{
		cout << "OPERACION CANCELADA" << endl << endl;
	}

}
//OPCIONES MENU PELICULAS
int menuPeliculas(){
	int opcion;
	cout << "-------------------------------------" << endl;
	cout << "         GESTIONAR PELICULAS         " << endl;
	cout << "-------------------------------------" << endl;
	cout << " 1 - Alta de pelicula                " << endl;
	cout << " 2 - Datos de pelicula               " << endl;
	cout << " 3 - Datos de todas las peliculas    " << endl;
	cout << " 4 - Edicion de peliculas            " << endl;
	cout << " 5 - Baja de pelicula                " << endl;
	cout << " 0 - Volver al menu anterior         " << endl;
	cout << "-------------------------------------" << endl;
	cout << "Eliga una opcion:" ; cin >> opcion;
	cout << "-------------------------------------" << endl<< endl;
	return opcion;
}
void opcion1peliculas(tListaPelis &listapelis){
	if(!listaPeliculasLlena(listapelis)){
		tPelicula pelicula;
		pelicula = leerPelicula();
		if(!existePeli(pelicula,listapelis)){
			insertarPelicula(pelicula, listapelis);
			cout << "Introducida con exito" << endl << endl;
		}else{
			cout << "La pelicula ya existe en la lista " << endl << endl;
		}
	}else{
		cout << "No se puede dar de alta una pelicula en esta lista " << endl;
	}
}
void opcion2peliculas(tListaPelis &listapelis){
	int codigo, pos=0;
	cout << "Dame el codigo de la pelicula que quieres mostrar: " ;
	cin >> codigo;
	if(buscarPelicula(listapelis, codigo, pos)){
		mostrarPelicula(listapelis.lista[pos]);
	}else{
		cout << "ERROR. Codigo no encontrado" << endl;
	}
}
void opcion3peliculas(tListaPelis &listapelis){
	string c;
	bool mostrar=false;
	cout << "(INTRO) para ver todas las peliculas" << endl;
	cout << "(Otra tecla) para ver solo las disponibles" << endl;
	cin.sync();
	getline(cin,c);
	if(c==""){
		cout << "---------------------------------" << endl;
		cout << "     LISTADO DE PELICULAS        " << endl;
		cout << "---------------------------------" << endl;
		for(int i=0; i<listapelis.contador; i++){
			mostrarPelicula(listapelis.lista[i]);
			cout << "---------------------------------" << endl;
		}
	}else{
		cout << "---------------------------------" << endl;
		cout << "     PELICULAS DISPONIBLES       " << endl;
		cout << "---------------------------------" << endl;
		for(int i=0; i<listapelis.contador; i++){
			if(listapelis.lista[i].disponible){
				mostrarPelicula(listapelis.lista[i]);
				cout << "---------------------------------" << endl;
			}
		}
	}
}
void opcion4peliculas(tListaPelis &listapelis){
	int codigo, pos=0;
	cout << "Dame el codigo de la pelicula que quieres editar: " ;
	cin >> codigo;
	if(buscarPelicula(listapelis, codigo, pos)){
		cout << "La pelicula es " << listapelis.lista[pos].titulo << ", desea editarla?(S/N):";
		string tecla="F";
		while(tecla!="s"&&tecla!="S"&&tecla!="n"&&tecla!="N"){
			getline(cin,tecla);
		}
		if(tecla=="s"||tecla=="S"){
			editarPelicula(listapelis.lista[pos]);
			ordenapelis(listapelis);
		}
	}else{
		cout << "ERROR. Codigo no encontrado" << endl;
	}
}
void opcion5peliculas(tListaPelis &listapelis){
	int codigo, pos=0;
	cout << "Dame el codigo de la pelicula que quieres dar de baja: " ;
	cin >> codigo;
	if(buscarPelicula(listapelis, codigo, pos)){
		bajaPelicula(codigo, listapelis);
		cout << "Pelicula borrada correctamente" << endl;
	}else{
		cout << "ERROR. Codigo no encontrado" << endl;
	}
}
void ordenapelis(tListaPelis &listapelis){
	bool inter = true;
	int i=0;
	while((i < listapelis.contador-1) && inter){
		inter = false;
		for(int j=listapelis.contador-1; j>i; j--){
			if(listapelis.lista[j].codigo < listapelis.lista[j-1].codigo){
				tPelicula tmp;
				tmp = listapelis.lista[j];
				listapelis.lista[j]=listapelis.lista[j-1];
				listapelis.lista[j-1]=tmp;
				inter = true;
			}
		}
		if(inter){
			i++;
		}
	}
}
//OPCIONES MENU CLIENTES
int menuClientes(){
	int opcion;
	cout << "-------------------------------------" << endl;
	cout << "         GESTIONAR CLIENTES          " << endl;
	cout << "-------------------------------------" << endl;
	cout << " 1 - Nuevo cliente                   " << endl;
	cout << " 2 - Datos de cliente                " << endl;
	cout << " 3 - Datos de todos los clientes     " << endl;
	cout << " 4 - Editar cliente                  " << endl;
	cout << " 5 - Bajar cliente                   " << endl;
	cout << " 0 - Volver al menu anterior         " << endl;
	cout << "-------------------------------------" << endl;
	cout << "Eliga una opcion: " ;	cin >> opcion;
	cout << "-------------------------------------" << endl<<endl;
	return opcion;
}
void opcion1clientes(tListaClientes &listaclientes){
	if(!listaClientesLlena(listaclientes)){
		tCliente cliente;
		cliente = leerCliente();
		if(!existeCliente(cliente, listaclientes)){
			insertarCliente(cliente, listaclientes);
			cout << "Cliente introducido con exito" << endl << endl;
		}else{
			cout << "El cliente ya existe en la lista" << endl << endl;
		}
	}else{
		cout << "No se puede dar de alta un cliente en esta lista " << endl;
	}
}
void opcion2clientes(tListaClientes &listaclientes, tListaPelis &listapelis){
	string nif;
	int pos=0;
	cout << "Dame el NIF del cliente que quieres mostrar: " ;
	cin >> nif;
	if(buscarCliente(listaclientes, nif, pos)){
		mostrarCliente(listaclientes.listaclientes[pos],true,listapelis);
	}else{
		cout << "ERROR. Codigo no encontrado" << endl;
	}
}
void opcion3clientes(tListaClientes &listaclientes, tListaPelis &listapelis){
	cout << "-----------------------------------------" << endl;
	cout << "         LISTADO DE CLIENTES             " << endl;
	cout << "-----------------------------------------" << endl;
	for(int i=0; i<listaclientes.contador; i++){
		mostrarCliente(listaclientes.listaclientes[i],false, listapelis);
		cout << "-----------------------------------------" << endl;
	}
}
void opcion4clientes(tListaClientes &listaclientes, tListaPelis &listapelis){
	string nif;
	int pos=0;
	cout << "Dame el NIF del cliente que quieres modificar: " ;
	cin >> nif;
	if(buscarCliente(listaclientes, nif, pos)){
		editarCliente(listaclientes.listaclientes[pos]);
		cout << "Edicion completada, nuevos valores: " << endl;
		mostrarCliente(listaclientes.listaclientes[pos], true, listapelis);
	}
}
void opcion5clientes(tListaClientes &listaclientes){
	string nif;
	int pos=0;
	cout << "Dame el NIF del cliente que quieres dar de baja: " ;
	cin >> nif;
	if(buscarCliente(listaclientes, nif, pos)){
		cout << "Quieres dar de baja a " << listaclientes.listaclientes[pos].nombre << " " << listaclientes.listaclientes[pos].apellidos << " ?(S/N):";
		string tecla="F";
		while(tecla!="s"&&tecla!="S"&&tecla!="n"&&tecla!="N"){
			getline(cin,tecla);
		}
		if(tecla=="s"||tecla=="S"){
			bajaCliente(nif, listaclientes);
			cout << "Se ha dado de baja correctamente" << endl;
		}
	}else{
		cout << " ERROR, NIF no encontrado " << endl;
	}
}
//OPCIONES MENU GESTION GENERAL
int menuGestion(){
	int opcion;
	cout << "-------------------------------------" << endl;
	cout << "          GESTION GENERAL            " << endl;
	cout << "-------------------------------------" << endl;
	cout << " 1 - Nuevo visionado                 " << endl;
	cout << " 2 - Exportar lista de clientes      " << endl;
	cout << " 3 - Estadisticas de peliculas       " << endl;
	cout << " 0 - Volver al menu anterior         " << endl;
	cout << "-------------------------------------" << endl;
	cout << "Eliga una opcion:  " ;	cin >> opcion;
	cout << "-------------------------------------" << endl << endl;
	return opcion;
}
void opcion1gestion(tListaClientes &listaclientes, tListaPelis &listapelis){
	tPeliculasVisionadas pelisvisionadas;
	int codigo, pos1=0, pos2=0;
	char gusta;
	string nif;
	cout << "Nuevo visionado..." << endl;
	cout << "Introduce el codigo de la pelicula:";
	cin >> codigo;
	if(buscarPelicula(listapelis, codigo, pos1)){
		cout << "Introduce el nif del usuario:";
		cin >> nif;
		if(buscarCliente(listaclientes, nif, pos2)){
			cout << "La pelicula es: " << listapelis.lista[pos1].titulo; cout << endl;
			cout << "El cliente es: " << listaclientes.listaclientes[pos2].nombre;
			cout << " " << listaclientes.listaclientes[pos2].apellidos; cout << endl;
			cout << "Le ha gustado(S/N)?: "; 
			do{
				cin >> gusta;
			}while(gusta!='s'&&gusta!='S'&&gusta!='n'&&gusta!='N');

			if(gusta=='s'||gusta=='S'){
				pelisvisionadas.opinion = true;
			}else{
				pelisvisionadas.opinion = false;
			}
			
			pelisvisionadas.codigo = codigo;
			altaVisionado(listaclientes.listaclientes[pos2], pelisvisionadas);
			cout << "Visionado registrado con exito" << endl << endl;
		}else{
			cout << "Error, cliente no encontrado" << endl;
		}
	}else{
		cout << "Error, pelicula no encontrada" << endl;
	}
}
void opcion2gestion(tListaClientes &listaclientes){
	tListaClientes ordenada;
	string texto;
	cout << "Escriba la ruta del archivo: "; 
	cin.sync();
	getline(cin, texto);
	ordenada = ordenarApellidos(listaclientes);
	ofstream archivo;
	archivo.open(texto);
	int i=0;
	while(i!=ordenada.contador){
		archivo << ordenada.listaclientes[i].apellidos << ", ";
		archivo << ordenada.listaclientes[i].nombre << " (";
		archivo << ordenada.listaclientes[i].nif << ")" << endl;
		archivo << "   Ha visto " << ordenada.listaclientes[i].contador << " peliculas." << endl << endl;
		i++;
	}
	cout << "Archivo exportado con exito" << endl << endl;
	archivo.close();
}
void opcion3gestion(tListaClientes &listaclientes, tListaPelis &listapelis){
	cout << "---------------------------------" << endl;
	cout << "    ESTADISTICAS DE VISIONADOS   " << endl;
	cout << "---------------------------------" << endl;
	int i=0;
	while(i!=listapelis.contador){
		int visiones=0, gusta=0, porcentaje=0,j=0;
		double  auxvisiones=0,auxgusta=0;
		while(j!=listaclientes.contador){ // calculo cuantas veces se ha visto y cuantas veces ha gustado
			datosVisionado(listaclientes.listaclientes[j],listapelis.lista[i].codigo,visiones,gusta);
			auxvisiones = auxvisiones + visiones;
			auxgusta= auxgusta + gusta;
			j++;
		}
		if(auxgusta==0){
			porcentaje=0;
		}else{
			porcentaje = (auxgusta/auxvisiones)*100;
		}
		cout << "Titulo:    " << listapelis.lista[i].titulo; cout << endl;
		cout << "Visionados: " << auxvisiones << " veces" << endl;
		cout << "Ha gustado: " << auxgusta << " veces" << endl;
		cout << "Valoracion: " << porcentaje << "%" << endl;
		cout << "---------------------------------" << endl;
		i++;
	}
	
}


void terminarPrograma(){
	string tecla;
	cout << "Gracias, adios!" << endl;
	cout << "Presione una tecla para continuar...";
	cin.sync();
	getline(cin,tecla);
}
