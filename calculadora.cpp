//Jaime Delgado Linares 

#include <iostream>
#include <cmath>
using namespace std;

//Declaracion de funciones
int menu();//Programa principal
void calculadora();//Realiza la opcion 1: Calculadora
double comprobarPrimerOperando(double &operando1); //Comprueba si el primer caracter que metes es un operando o c(Cancelacion) o x(salir)
void operacionesCalculadora(); //Realiza todas las operaciones
double suma(double &operando1); // suma
double resta(double &operando1); //resta
double multiplicacion(double &operando1);//multiplicacion
double division(double &operando1);//division
double exponencial(double &operando1);//exponencial
double raiz(double &operando1);//raiz
double factorial(double &operando1);//factorial
void configuracion(); //Realiza la opcion 2: Configuracion	
char tecsuma(char &tsuma);// configura la tecla suma
char tecresta(char &tresta);// configura la tecla resta
char tecmultiplicacion(char &tmultiplicacion);// configura la tecla multiplicacion
char tecdivision(char &tdivision);// configura la tecla division
char tecexponencial(char &texponencial);// configura la tecla exponencial
char tecraiz(char &traiz);// configura la tecla raiz
char tecfactorial(char &tfactorial);// configura la tecla factorial
char tecc(char &tc);// configura la tecla c(cancelacion)
char tecx(char &tx);// configura la tecla x(salir)

//Programa principal
int main(){
	int opcion=0;
	opcion = menu();
	switch(opcion){
	case 1: //Calculadora
		calculadora();
		break;
	case 2: //Configuracion
		configuracion();
		break;
	case 3: //Calculadora. Modo fracciones
		break;
	case 4: //Terminar
		break;
	default: //Opcion no disponible
		cin.sync();
		cout << "Opcion no disponible" << endl << endl;
		main();
		break;
	}
	return 0;
}

//Implementacion de las funciones
int menu(){
	int opcion=0;
	do{
	cout << endl;
	cout << "         CALCULADORA " << endl;
	cout << "-------------------------------" << endl;
	cout << "1.-Calculadora" << endl;
	cout << "2.-Configuracion" << endl;
	cout << "3.-Calculadora: Modo fracciones" << endl;
	cout << "4.-Terminar" << endl;
	cout << "-------------------------------" << endl;
	cin >> opcion;
	return opcion;
	}while(opcion != 4);
}
void calculadora(){
	
	cin.sync();
	cout << endl;
	cout << "1.-Calculadora" << endl;
	cout << "Introduzca operaciones:" << endl;
	operacionesCalculadora();
}
double comprobarPrimerOperando(double &operando1){
	char tx='x', tc='c', d;
	do{ //Compruebo que el primer numero es un operando y no una letra
		cin.sync();
		d = cin.peek();
		if(!isdigit(d)){ // si no es un numero
			if(d == tx){ // si introduces una x limpia el buffer y sale del bucle
				cin.sync();
				main(); 
			}else if(d == tc){ // si introduces una c pone 0
				cin.sync();
				cout << "0" << endl;
			}else{ //cualquier letra que no reconozca
				cout << endl << "Error" << endl << "Introduzca operaciones:" << endl;
				d = tc; // para que vuelva a iniciar el bucle
			}
		}else{ 
			cin>>operando1;
		}
	}while(d == tc);
	return operando1;
}

void operacionesCalculadora(){
	char operador, tsuma='+', tresta='-', tmultiplicacion='*', tdivision='/', traiz='r', televado='^', tfactorial='!', tc='c', tx='x';
	double operando1=0.0, operando2, aux, fact;
	int entero;	
	comprobarPrimerOperando(operando1);
	do{
		cin.get(operador);
		do{
			if(operador == tc){ // cancelacion (c)
				cin.sync();
				operando1=0;		
			}else if( operador == tsuma ){// suma
				suma(operando1);
			}else if( operador == tresta ){ //resta
				resta(operando1);
			}else if( operador == tmultiplicacion){ //multiplicacion
				multiplicacion(operando1);
			}else if( operador == tdivision ){ //division
				division(operando1);
			}else if( operador == televado ){ //exponencial
				exponencial(operando1);
			}else if(operador == traiz){ //raiz cuadrada
				raiz(operando1);
			}else if(operador == tfactorial){ //factorial
				factorial(operando1);
			}else if(operador == tx){ // salir (x)
				main();
			}else if(operador == '\n'){
			}else{
				cout << "ERROR (Vuelva a introducir)" << endl;
				cin.sync();
				cout << operando1; // si el operando esta mal vuelve a poner 
				//el numero que había antes y te deja volver a operar
			}
			cin.get(operador);
						
		}while(operador != '\n');
		cout << operando1;
		
	}while( operador!= tx );
}
double suma(double &operando1){
	double operando2;
	cin >> operando2;
	operando1 = operando1 + operando2;
	return operando1;
}
double resta(double &operando1){
	double operando2;
	cin >> operando2;
	operando1 = operando1 - operando2;
	return operando1;
}
double multiplicacion(double &operando1){
	double operando2;
	cin >> operando2;
	operando1 = operando1 * operando2;
	return operando1;
}
double division(double &operando1){
	double operando2;
	cin >> operando2;
	operando1 = operando1 / operando2;
	return operando1;
}
double exponencial(double &operando1){
	int entero;
	double operando2, aux=1.0, fact;
	cin >> operando2;
	entero = operando2;
	if(entero != operando2){ //comprobar exponente entero
		cout << "Error. El exponente tiene que ser entero." << endl;
	}else{
		if(operando2>0){
			for(int i=0;i< operando2;i++){
			aux=aux*operando1;
			}
			operando1=aux;
			aux=1;
		}else if(operando2=0){
			operando1=1;
		}else{
			fact = operando2*-1;
			for(int i=0;i< fact;i++){
			aux=aux*fact;
			}
			operando1=1/aux;
		}
		return operando1;
	}
}
double raiz(double &operando1){
	operando1= sqrt(operando1);
	return operando1;
}
double factorial(double &operando1){
	int entero;
	double aux=1.0;
	entero= operando1;
	if(entero!=operando1){
		cout << "Error. Tiene que ser un numero entero" << endl;
	}else{
		if(operando1<0){
		cout << "ERROR (numero negativo)" << endl;
		}else if(operando1 == 0){
				operando1=0;
		}else{
				for(int i=1; i<=operando1;i++){
				aux=aux*i;
				}
			operando1=aux;
			aux=1;
		}
	}
	return operando1;
}
void configuracion(){
	char tsuma='+', tresta='-', tmultiplicacion='*', tdivision='/', traiz='r', televado='^', tfactorial='!', tc='c', tx='x';
	tecsuma(tsuma);
	tecresta(tresta);
	tecmultiplicacion(tmultiplicacion);
	tecdivision(tdivision);
	tecraiz(traiz);
	tecexponencial(televado);
	tecfactorial(tfactorial);
	tecc(tc);
	tecx(tx);
	main();
	//Fin codigo configuracion
}
char tecsuma(char &tsuma){
	char cambio;
	cin.sync();
	cout << "Introduzca la tecla para la operacion SUMA:" ;
	cin.get(cambio);
	if(cambio == '\n'){
		//tsuma se queda como estaba
	}else{
		tsuma = cambio;
	}
	return tsuma;
}
char tecresta(char &tresta){
	char cambio;
	cin.sync();
	cout << "Introduzca la tecla para la operacion RESTA:" ;
	cin.get(cambio);
	if(cambio == '\n'){
		//tresta se queda como estaba
	}else{
		tresta = cambio;
	}
	return tresta;
}
char tecmultiplicacion( char &tmultiplicacion){
	char cambio;
	cin.sync();
	cout << "Introduzca la tecla para la operacion MULTIPLICACION:" ;
	cin.get(cambio);
	if(cambio == '\n'){
		//tmultiplicacion se queda como estaba
	}else{
		tmultiplicacion = cambio;
	}
	return tmultiplicacion;
}
char tecdivision(char &tdivision){
	char cambio;
	cin.sync();
	cout << "Introduzca la tecla para la operacion DIVISION:" ;
	cin.get(cambio);
	if(cambio == '\n'){
		//tdivision se queda como estaba
	}else{
		tdivision= cambio;
	}
	return tdivision;
}
char tecexponencial(char &televado){
	char cambio;
	cin.sync();
	cout << "Introduzca la tecla para la operacion EXPONENCIAL:" ;
	cin.get(cambio);
	if(cambio == '\n'){
		//televado se queda como estaba
	}else{
		televado = cambio;
	}
	return televado;
}
char tecraiz(char &traiz){
	char cambio;
	cin.sync();
	cout << "Introduzca la tecla para la operacion RAIZ:" ;
	cin.get(cambio);
	if(cambio == '\n'){
		//traiz se queda como estaba
	}else{
		traiz = cambio;
	}
	return traiz;
}
char tecfactorial(char &tfactorial){
	char cambio;
	cin.sync();
	cout << "Introduzca la tecla para la operacion FACTORIAL:" ;
	cin.get(cambio);
	if(cambio == '\n'){
		//tfactorial se queda como estaba
	}else{
		tfactorial = cambio;
	}
	return tfactorial;
}
char tecc(char &tc){
	char cambio;
	cin.sync();
	cout << "Introduzca la tecla para la operacion c(CANCELACION):" ;
	cin.get(cambio);
	if(cambio == '\n'){
		//tc se queda como estaba
	}else{
		tc = cambio;
	}
	return tc;
}
char tecx(char &tx){
	char cambio;
	cin.sync();
	cout << "Introduzca la tecla para la operacion x(SALIR):" ;
	cin.get(cambio);
	if(cambio == '\n'){
		//tx se queda como estaba
	}else{
		tx = cambio;
	}
	return tx;
}
