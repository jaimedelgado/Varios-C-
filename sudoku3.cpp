//Jaime Delgado Linares

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

typedef struct{
	int enteros[9][9];
	bool booleanos[9][9];
	int solucion[9][9];
	int casillasVacias;
}tSudoku;

typedef struct{
	int contCandidatos;
	int numeros[9];
}tCandidatos;


//Prototipos
//PRIMEROS SUBPROGRAMAS///////////////////////////////////////////////////
int menu();
void inicializacion(tSudoku &sudoku, tCandidatos &candidatos);
void pideArchivos(string &tablero, string &solucion);
bool cargaValoresIniciales(tSudoku &sudoku,string tablero);
void cargaSolucion(tSudoku &sudoku, string solucion);
void dibujaTablero(tSudoku &sudoku);
//MAS SUBPROGRAMAS OPCION1////////////////////////////////////////////////
void filaColumna(int &fila, int &columna);
bool casillaVacia(tSudoku &sudoku,int fila, int columna);
void calculaCandidatos(tSudoku &sudoku, tCandidatos &candidatos, int fila, int columna);
bool estaEnFila(tSudoku &sudoku,int fila, int num);
bool estaEnColumna(tSudoku &sudoku,int columna, int num);
bool estaEnRegion(tSudoku &sudoku, int fila, int columna, int num);
void prueba(tSudoku &sudoku);
void opcion1(tSudoku &sudoku, tCandidatos &candidatos);
//MAS SUBPROGRAMAS OPCION2/////////////////////////////////////////////////
void numero(int &num);
bool casillaValorInicial(tSudoku &sudoku, int fila, int columna);
void coloca(int num, int fila, int columna, tSudoku &sudoku, tCandidatos &candidatos);
bool esCandidato(tSudoku &sudoku, tCandidatos &candidatos, int fila, int columna, int num);
void opcion2(tSudoku &sudoku, tCandidatos &candidatos);
//OPCION3//////////////////////////////////////////////////////////////////
void borrar(tSudoku &sudoku, int fila, int columna, int num);
void opcion3(tSudoku &sudoku, tCandidatos &candidatos);
//OPCION4//////////////////////////////////////////////////////////////////
bool errores(tSudoku &sudoku);
void opcion4(tSudoku &sudoku, tCandidatos &candidatos);
//OPCION5/////////////////////////////////////////////////////////////////
void opcion5(tSudoku &sudoku);
//OPCION6/////////////////////////////////////////////////////////////////
void completaUnCandidato(tSudoku &sudoku, tCandidatos &candidatos, int &casillasCompletadas);
void opcion6(tSudoku &sudoku, tCandidatos &candidatos);

//Cuerpo del programa principal
int main(){
	int opc;
	string tablero, solucion;
	tSudoku sudoku;
	tCandidatos candidatos;
	pideArchivos(tablero, solucion);
	inicializacion(sudoku, candidatos);
	if(cargaValoresIniciales(sudoku,tablero)){
		cargaSolucion(sudoku,solucion);
		do{
			cout << endl;
			dibujaTablero(sudoku);
			opc=menu();
			switch(opc){
			case 0: //SALIR
				break;
			case 1: //Ver posibles valores de una casilla
				opcion1(sudoku, candidatos);
				break;
			case 2: //
				opcion2(sudoku, candidatos);
				break;
			case 3: //
				opcion3(sudoku, candidatos);
				break;
			case 4: //
				opcion4(sudoku, candidatos);
				break;
			case 5: //
				opcion5(sudoku);
				break;
			case 6: //
				opcion6(sudoku, candidatos);
				break;
			}
		}while(opc!=0);
	}else{
		cout << "Error al cargar el sudoku" << endl;
	}
	return 0;
}


//Implementacion de las funciones
int menu(){
	int opcion;
	do{
		cout << "=====================================\n";
		cout << "           MENU\n";
		cout << "=====================================\n";
		cout << " 0 - SALIR \n";
		cout << " 1 - Ver posibles valores de casilla \n";
		cout << " 2 - Colocar un valor en una casilla \n";
		cout << " 3 - Borrar el valor de una casilla \n";
		cout << " 4 - Mostrar valores incorrectos \n";
		cout << " 5 - Reiniciar tablero \n";
		cout << " 6 - Completar casillas simples \n";
		cout << "=====================================\n";
		cout << "Eliga una opcion:";
		cin >> opcion;
		cout << "=====================================\n";
		if(opcion < 0 || opcion > 9){
			cout << "Opcion incorrecta" << endl;
		}
	}while(opcion < 0 || opcion > 9);
	return opcion;
}
void inicializacion(tSudoku &sudoku, tCandidatos &candidatos){
	for(int i=0; i<9; i++){
		for(int j=0; j<9; j++){
			sudoku.enteros[i][j]=0;
			sudoku.solucion[i][j]=0;
			sudoku.booleanos[i][j]=false;
			candidatos.numeros[j]=j+1;
		}
	}
	sudoku.casillasVacias=81;
	candidatos.contCandidatos=0;
}
void pideArchivos(string &tablero, string &solucion){
	cout << "Nombre del sudoku (intro-> archivo por defecto 'sudoku.txt'): \n";
	getline(cin,tablero);
	cout << "Nombre de la solucion (intro-> archivo por defecto 'solsdk1.txt'): \n";
	getline(cin,solucion);
}
bool cargaValoresIniciales(tSudoku &sudoku,string tablero){
	ifstream archivo;
	int fila, columna, valor;
	bool ok=false;
	if(tablero==""){
		archivo.open("sudoku1.txt");
	}else{
		archivo.open(tablero);
	}
	if(!archivo.is_open()){
		ok=false;
	}else{ // Cargamos valores iniciales
		do{
			archivo >> fila >> columna >> valor;
			if(fila == -1){
			}else if(fila<1||fila>9||columna<1||columna>9||valor<1||valor>9){
				return false;
			}else{
				sudoku.enteros[fila-1][columna-1]=valor;
				sudoku.booleanos[fila-1][columna-1]=true;
			}
		}while(fila!=-1);
		ok=true;
	}
	archivo.close();
	return ok;
}
void cargaSolucion(tSudoku &sudoku, string solucion){
	int num;
	ifstream sol;
	if(solucion==""){
		sol.open("solsdk1.txt");
	}else{
		sol.open(solucion);
	}
	do{
		for(int i=0; i<9; i++){
			for(int j=0; j<9; j++){
				sol >> num;
				sudoku.solucion[i][j]=num;
			}
		}
	}while(sol.eof());
	sol.close();
}
void dibujaTablero(tSudoku &sudoku){
	for(int i=0; i<9; i++){
		if(i%3==0){
			cout << "-------------------------" << endl;
		}
		for(int j=0; j<9; j++){
			if(j%3==0){
				cout << "| ";
			}
			if(sudoku.enteros[i][j]==0){
				cout << "  " ;
			}else{
				cout <<  sudoku.enteros[i][j] << " " ;
			}
		}
		cout << "|\n";
	}
	cout << "-------------------------" << endl;
}
////////////////////////////////////////////////////////////////
void filaColumna(int &fila, int &columna){
	do{
		cout << "Introduzca una fila [1-9]: " << endl;
		cin >> fila;
		if(fila<1||fila>9){
			cout << "Error. ";
		}
	}while(fila<1||fila>9);
	do{
		cout << "Introduzca una columna [1-9]: " << endl;
		cin >> columna;
		if(columna<1||columna>9){
			cout << "Error. ";
		}
	}while(columna<1||columna>9);
}
bool casillaVacia(tSudoku &sudoku,int fila, int columna){
	bool ok=false;
	if(sudoku.enteros[fila-1][columna-1]!=0){
		ok=false;
	}else{
		ok=true;
	}
	return ok;
}
void calculaCandidatos(tSudoku &sudoku, tCandidatos &candidatos, int fila, int columna){
	candidatos.contCandidatos=0;;
	for(int i=1; i<10; i++){
		if(!estaEnFila(sudoku,fila,i)&&!estaEnColumna(sudoku,columna,i)&&!estaEnRegion(sudoku,fila,columna,i)){
			candidatos.numeros[i-1]=i;
			candidatos.contCandidatos++;
		}else{
			candidatos.numeros[i-1]=0;
		}
	}
}
bool estaEnFila(tSudoku &sudoku,int fila, int num){
	for(int i=0; i<9; i++){
		if(sudoku.enteros[fila-1][i]==num){
			return true;
		}
	}
	return false;
}
bool estaEnColumna(tSudoku &sudoku,int columna, int num){
	for(int i=0; i<9; i++){
		if(sudoku.enteros[i][columna-1]==num){
			return true;
		}
	}
	return false;
}
bool estaEnRegion(tSudoku &sudoku, int fila, int columna, int num){
	int filaRegion=((fila-1)/3)*3, columnaRegion=((columna-1)/3)*3;
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			if(sudoku.enteros[filaRegion+i][columnaRegion+j] == num){
				return true;
			}
		}
	}
	return false;
}
void prueba(tSudoku &sudoku){
	int fila, columna, num;
	cout << "Introduce fila:" << endl;
	cin >> fila;
	cout << "Introduce columna:" << endl;
	cin >> columna;
	cout << "Introduce un numero: " << endl;
	cin >> num;
	if(estaEnFila(sudoku,fila, num)==true){
		cout << "ESTA EN FILA" << endl;
	}else{
		cout << "no esta en fila" << endl;
	}
	if(estaEnColumna(sudoku, columna, num)==true){
		cout << "ESTA EN COLUMNA" << endl;
	}else{
		cout << "no esta en columna" << endl;
	}
	if(estaEnRegion(sudoku, fila, columna, num)==true){
		cout << "ESTA EN REGION" << endl;
	}else{
		cout << "no esta en region" << endl;
	}
	cout << "Su valor es: " << sudoku.enteros[fila-1][columna-1] << endl;

}
void opcion1(tSudoku &sudoku, tCandidatos &candidatos){
	int fila, columna;
	filaColumna(fila, columna);
	if(!casillaVacia(sudoku,fila,columna)){
		cout << "CASILLA NO VACIA" << endl;
	}else{
		calculaCandidatos(sudoku,candidatos,fila,columna);
		cout << "Candidatos: ( ";
		for(int i=0; i<9; i++){
			if(candidatos.numeros[i]!=0){
				cout << candidatos.numeros[i] << " ";
			}
		}
		cout << ")" << endl ;
	}
}
////////////////////////////////////////////////////////////////////
void numero(int &num){
	do{
		cout << "Introduzca un numero [1-9]: " << endl;
		cin >> num;
		if(num<1||num>9){
			cout << "Error. ";
		}
	}while(num<1||num>9);
}
bool casillaValorInicial(tSudoku &sudoku, int fila, int columna){
	if(sudoku.booleanos[fila-1][columna-1]==false){
		return false;
	}else{
		return true;
	}
}
void coloca(int num, int fila, int columna, tSudoku &sudoku, tCandidatos &candidatos){
	if(casillaVacia(sudoku,fila,columna)&&esCandidato(sudoku,candidatos,fila,columna,num)){
		sudoku.enteros[fila-1][columna-1]=num;
		sudoku.casillasVacias--;
	}	
}
bool esCandidato(tSudoku &sudoku, tCandidatos &candidatos, int fila, int columna, int num){
	if(!estaEnFila(sudoku,fila,num)&&!estaEnColumna(sudoku,columna,num)&&!estaEnRegion(sudoku,fila,columna,num)){
		return true;
	}else{
		return false;
	}
}
void opcion2(tSudoku &sudoku, tCandidatos &candidatos){
	int fila, columna, num;
	filaColumna(fila, columna);
	numero(num);
	if(casillaVacia(sudoku, fila, columna==false)){
		if(sudoku.booleanos[fila-1][columna-1]==true){
			cout << "CASILLA NO MODIFICABLE" << endl;
		}else{
			cout << "CASILLA NO VACIA" << endl;
		}
	}else{
		if(!estaEnFila(sudoku,fila,num)&&!estaEnColumna(sudoku,columna,num)&&!estaEnRegion(sudoku,fila,columna,num)){
			coloca(num,fila,columna,sudoku,candidatos);
		}else{
			cout << "DIGITO NO VALIDO" << endl;
		}
	}
}
/////////////////////////////////////////////////////////////////////
void borrar(tSudoku &sudoku, int fila, int columna){
	if(casillaVacia(sudoku,fila,columna)){
		//cout << "CASILLA VACIA" << endl;
	}else{
		if(casillaValorInicial(sudoku,fila,columna)){
			//cout << "NO MODIFICABLE" << endl;
		}else{
			sudoku.enteros[fila-1][columna-1]=0;
			sudoku.casillasVacias++;
		}
	}
}
void opcion3(tSudoku &sudoku, tCandidatos &candidatos){
	int fila, columna;
	filaColumna(fila, columna);
	if(casillaVacia(sudoku,fila,columna)){
		cout << "CASILLA VACIA" << endl;
	}else{
		if(casillaValorInicial(sudoku,fila,columna)){
			cout << "NO MODIFICABLE" << endl;
		}else{
			sudoku.enteros[fila-1][columna-1]=0;
		}
	}
}
/////////////////////////////////////////////////////////////////////
bool errores(tSudoku &sudoku){
	for(int i=0; i<9; i++){
		for(int j=0; j<9; j++){
			if(sudoku.enteros[i][j]!=0 && (sudoku.enteros[i][j]!=sudoku.solucion[i][j]) ){
				return true;
			}
		}
	}
	return false;
}
void opcion4(tSudoku &sudoku, tCandidatos &candidatos){
	if(!errores(sudoku)){
		cout << "NO HAY ERRORES" << endl;
	}else{
		cout << "ERRORES:" << endl;
		for(int i=0; i<9; i++){
			for(int j=0; j<9; j++){
				if(sudoku.enteros[i][j]!=0 && (sudoku.enteros[i][j]!=sudoku.solucion[i][j]) ){
					cout << "[" << i+1 << "," << j+1 << "] (" << sudoku.enteros[i][j] << ")" << endl;
				}
			}
		}
	}
}
//////////////////////////////////////////////////////////////////////
void opcion5(tSudoku &sudoku){
	for(int i=0; i<9; i++){
		for(int j=0; j<9; j++){
			if(!casillaVacia(sudoku,i+1,j+1)&&!casillaValorInicial(sudoku,i+1,j+1)){
				borrar(sudoku, i+1, j+1);
			}
		}
	}
}
//////////////////////////////////////////////////////////////////////
void completaUnCandidato(tSudoku &sudoku, tCandidatos &candidatos, int &casillasCompletadas){
	casillasCompletadas=0;
	for(int i=0; i<9; i++){
		for(int j=0; j<9; j++){
			if(sudoku.enteros[i][j]==0){
				calculaCandidatos(sudoku, candidatos, i+1, j+1);
				if(candidatos.contCandidatos==1){
					for(int k=0; k<9; k++){
						if(candidatos.numeros[k]!=0){
							coloca(k+1, i+1, j+1, sudoku, candidatos);
							casillasCompletadas++;
							k=9;//Para que salga ya y se ahorre vueltas en el for
						}
					}
				}
			}
		}
	}
}
void opcion6(tSudoku &sudoku, tCandidatos &candidatos){
	int casillasCompletadas;
	completaUnCandidato(sudoku,candidatos, casillasCompletadas);
	cout << "Se han completado: " << casillasCompletadas << " casillas" << endl;
}