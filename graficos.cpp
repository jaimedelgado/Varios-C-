//Jaime Delgado Linares 1ºC Laboratorio4

#include <iostream>	 // consola de la libreria standard (STL)
#include <string>	 // cadenas de caracteres de la STL
#include <cstdlib>	 // numeros aleatorios
using namespace std; // prefijo de la STL
#include "ventanaGrafica.h"	// ventana grafica

//Funcion para el menu
int menu (){
	int opcion;
	cout << endl;
	cout << " -----------------------------------------------" <<endl
	     << " |                   MENU                      |" <<endl
	     << " -----------------------------------------------" <<endl
	     << " |                                             |" << endl
	     << " |  0.- Salir.                                 |" << endl
	     << " |  1.- Limpiar ventana.                       |" << endl
	     << " |  2.- Dibujar una linea.                     |" << endl
	     << " |  3.- Dibujar un cuadrado.                   |" << endl
         << " |  4.- Dibujar una poliespiral.               |" << endl
	     << " |  5.- Dibujar un poligono regular.           |" << endl
	     << " |  6.- Dibujar poligonos regulares anidados.  |" << endl
	     << " |  7.- Dibujar un triangulo de Sierpinsky.    |" << endl
	     << " |  8.- Dibujar una figura de dragon.          |" << endl
	     << " |                                             |" << endl
	     << " -----------------------------------------------" << endl<<endl;
	cout << "  Elige una opcion: " << endl;
	cin >> opcion; 
	return opcion; 
}
//Funciones para el caso 2: dibujar lineas
void leerDatos2(double &x, double &y, double &lon, double &ang) {
	cout << endl << "2.-Dibujar una linea" << endl;
	cout << " Coordenadas del punto inicial 2 reales en rango [-50.0, 50.0]: ";
	cin >> x >> y;
	do {
		cout << " Introduce la longitud de la linea: ";
		cin >> lon;
	} while (lon <= 0);
	cout << " Introduce el angulo (grados en el rango [0, 360]): ";
	cin >> ang;
	ang = ang*RPG;
}
void pintarLinea(double x, double  y, double lon, double ang){
	vgLine(x,y,x+(lon*cos(ang)), y+(lon*sin(ang)));
	cout<<"La linea empieza en el punto: ("<<x<< "," << y << ")" << endl <<
	"y termina en el punto: (" << x + (lon*cos(ang)) << "," << y + (lon*sin(ang)) << ")" << endl;
}

void dibujarLinea() {
	double Px, Py, lon, ang;
	leerDatos2(Px,Py,lon,ang);
	pintarLinea(Px,Py,lon,ang);
}
//Funciones para el caso 3: dibujar cuadrado
void leerDatos3(double &x, double &y, double &lon, double &ang) {
	cout << endl << "3.-Dibujar cuadrado."<< endl;
	cout << "Introduce las coordenadas del vertice inicial(x,y):"<<endl;
	cin >> x >> y;

	do {
		cout << "Introduce la longitud de su lado: ";
		cin >> lon;
	} while (lon <= 0);

	cout << " Introduce el angulo que forma con el eje(grados en el rango [0, 360]): ";
	cin >> ang;
	ang = ang*RPG;
}
void pintarCuadrado(double x, double y, double lon, double ang) {
	for (int i = 0; i < 4; i++ ) {
		vgLine(x, y, x + (lon * cos(ang)), y + (lon * sin(ang)));
		x = x+lon * cos(ang);
		y = y+lon * sin(ang);
		ang = ang+(PI/2.0);
		cout << "Vertice numero " << (i + 1) << ": (" << x << "," << y << ")" << endl;
	}
}
void dibujarCuadrado() {
	double x, y, angulo, longitud;
	leerDatos3(x,y,longitud,angulo);
	pintarCuadrado(x,y,longitud,angulo);
}
//Funciones para el caso 4: dibujar poliespiral
void leerDatos4(double &lad, double &incrAng, double &incrLado, double &numIter) {
	cout << endl << "4.-Dibujar poliespirales" << endl;
	do {
		cout << "Introduce la longitud de su lado: "<<endl;
		cin >> lad;
	} while (lad <= 0);
	do {
		cout << "Introduce el incremento del angulo: ";
		cin >> incrAng;
	} while (incrAng <= 0);
	incrAng = incrAng*RPG;
	do {
		cout << "Introduce el incremento del lado: ";
		cin >> incrLado;
	} while (incrLado <= 0);
	do {
		cout << "Introduce el numero de iteraciones: ";
		cin >> numIter;
	} while (numIter <= 0);
}
void pintarPoliespiral(double lad, double incrAng, double incrLado, double numIter) {
	double ang = 0, x = 0, y = 0;
	cout << "Vertice inicial: (0,0)" << endl;
	for (double i = 0; i < numIter; i++) {
		vgLine(x,y,x+lad*cos(ang),y+lad*sin(ang));
						
		x=x+(lad*cos(ang));
		y=y+(lad*sin(ang));
		ang=ang+incrAng;
		lad=lad+incrLado;

		cout << "Punto " << (i + 1) << ": " << x << "," << y << endl;
	}
}
void dibujarPoliespiral() {
	double incrAng, lado, incrLado, numIter;
	leerDatos4(lado,incrAng,incrLado,numIter);
	pintarPoliespiral(lado, incrAng, incrLado, numIter);
}
//Funciones para el caso 5: dibujar poligono regular
void leerDatos5(double &lad, double &lon) {
	cout<<endl<< "5.-Dibujar poligono regular"<<endl;
	do {
		cout << "Introduce el numero de lados del poligono: ";
		cin >> lad;
	} while (lad < 3);
	do {
		cout << "Introduce la longitud del lado del poligono: ";
		cin >> lon;
	} while (lon <= 0);
}
void calculosPoligReg(double numlados, double lon, double &rad, double &incrAng, double &angIni){
	incrAng = 360.0 / numlados;
	angIni =(270.0 - (incrAng / 2.0))*RPG;
	incrAng = incrAng*RPG;
	rad = lon/(2*sin(incrAng/2.0));
	
}
void pintarPoligRegular(double rad, double incrAng, double angIni) {
	int i = 1;
	for (double j = 0; j< 2*PI;j +=incrAng){
		cout << "Vertice numero " << i << ": (" << rad*cos(angIni+j) << "," << rad*sin(angIni+j) << ")" << endl;
		vgLine(rad*cos(angIni+j),rad*sin(angIni+j),rad*cos(angIni+j+incrAng),rad*sin(angIni+j+incrAng));
		i++;
	}
}
void dibujarPoligRegular() {
	double alfa, beta, radio, longitud, lados;
	leerDatos5(lados,longitud);
	calculosPoligReg(lados,longitud,radio,beta,alfa);
	pintarPoligRegular(radio, beta, alfa);
}
//Funciones para el caso 6: dibujar poligonos anidados
void leerDatos6(double &lad, int &numPoligonos) {
	do {
		cout << "Introduce la longitud del lado: ";
		cin >> lad;
	} while (lad <= 0);
	do {
		cout << "Introduce el numero de poligonos: ";
		cin >> numPoligonos;
	} while (numPoligonos <= 0);
}
void pintarPoligonosAnidados(double lad, int num) {
	double alfa, beta, radio, x, y;

	//Se obtiene el vertice inicial para que quede centrado el poligono mas grande
	beta = (360.0/double(num+2));
	alfa = (270.0-(beta/2.0))*RPG;
	beta = beta*RPG;
	radio = lad/(2*sin(beta/2.0));

	for (double i = 3; i <= (num+2); i++) {
		x = radio*cos(alfa);
		y = radio*sin(alfa);

			// Se pintan los vertices usando el angulo que forma respecto al anterior (2*PI/i) hasta dar la vuelta (2*PI)
			for (double j = 0; j < (2*PI); j += (2*PI/i)) {
				vgLine( x , y , x+lad*cos(j) , y+lad*sin(j) );
				x = x+lad*cos(j);
				y = y+lad*sin(j);
			}
	}
}
void dibujarPoligonosAnidados() {
	double lado;
	int numPolig;
	leerDatos6(lado, numPolig);
	pintarPoligonosAnidados(lado, numPolig);
}
//Funciones para el caso 7: triangulo de Sierpinski
int leerDato7() {
	cout << endl << "7.-Dibujar triangulo de Sierpinski."<<endl;
	int d;
	do {
		cout << "Introduce el numero de interaciones, mayor que 0: ";
		cin >> d;
	} while (d <= 0);
	return d;
}
void pintarTrianguloSierpinski(int d) {

	double r = rand() / double(RAND_MAX); //Puntos aleatorios
	double Px = -50 + (100*r);
	double Py = -50;

	//Hacer tantos puntos como iteraciones
	for (int i = 0; i < d; i++) {
		vgPoint(Px,Py);	//Pintar punto

		int j = rand() % 3;	
		//Hallar el punto medio del punto anterior para cada vertice
		switch (j) {
			case 0:
				Px = (-50.0 + Px) / 2.0;
				Py = (-50.0 + Py) / 2.0;
			break;

			case 1:
				Px = (50.0 + Px) / 2.0;
				Py = (-50.0 + Py) / 2.0;
			break;

			case 2:
				Px = Px / 2.0;
				Py = (50.0 + Py) / 2.0;
			break;
		}
	}
}
void dibujarTrianguloSierpinski() {
	int leerDato7();
	pintarTrianguloSierpinski(leerDato7());
}
//Funciones para el caso 8: dragón
void leerDatos8(int& numPuntos){
	cout<<endl<<"8.-Dibujar dragon"<<endl;
	cout << "Introduce el numero de iteraciones(mayor que 0):";
	cin >> numPuntos;
}
void calcularDragon (int numPuntos){
	double x1, y1, x2, y2, p;
	x1=0;
	y1=0;

	for (int i=0; i< numPuntos; i++){//Hacer tantos puntos como iteraciones

		p= rand() / double (RAND_MAX);//Puntos aleatorios

		if (p< 0.787473) {
			x2=0.824074* x1 + 0.281482* y1 - 0.882290;
			y2= -0.212346*x1 + 0.864198 * y1 - 0.110607;
		}else{
			x2= 0.088272 * x1 + 0.520988 * y1 + 0.785360;
			y2= -0.463889 * x1 - 0.377778*y1 + 8.095795;
		}
		x1=x2;
		y1=y2;
		vgPoint(8*x1-10,8*y1-35); // Pintar puntos

	}
}
void dibujarDragon (){
	int numPuntos;
	leerDatos8( numPuntos);
	calcularDragon (numPuntos);
}

//MAIN
int main(int argc, char *argv[]) {
	vgInit(true); //Inicia la ventana grafica y muestra ejes
	
	//Comienzo del codigo de la practica
	//
	
	srand(1);
	int opcion = 0;
	do{
		cin.sync(); // limpia el buffer de cin 
		opcion = menu(); //Se encarga de todo el menu y devuelve la opcion
		switch (opcion) {
			case 0: //Salir
				break; 
			case 1: // Limpiar la ventana
				vgClear(); 
				break; 
			case 2: // Dibujar lineas
				dibujarLinea(); 
				break; 
			case 3: // Dibujar cuadrados
				dibujarCuadrado();
				break;
			case 4: // Dibujar poliespirales
				dibujarPoliespiral();
				break;			
			case 5: // Dibujar poligonos regulares 
				dibujarPoligRegular();
				break;
			case 6: // Dibujar poligonos anidados
				dibujarPoligonosAnidados(); 
				break;
			case 7: // Dibujar triangulo de Sierpinski
				dibujarTrianguloSierpinski(); 
				break;
			case 8: //Dibujar dragon
				dibujarDragon();
				break;
			//Si la opción no está entre 0 y 8 se comunica que no existe esa opcion 
			default: cout << "No existe esa opcion" << endl;
		}
		
	}while (opcion!= 0);
	
	//Fin del codigo de la practica
	//
	vgEnd();
	return 0;
}


