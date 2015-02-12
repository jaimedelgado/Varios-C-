//Jaime Delgado Linares

//Implementacion del algoritmo cíclico de las coordenadas

#include <iostream>
#include <cmath>
using namespace std;
#define pi 3.14159265

 
double branin(double x, double y);
double coordenadas(double &x, double &y, double precision, int maxIter);
void coordenadas();

int main(){
	coordenadas();
	return 0;
}

double branin(double x, double y){
	double a1 = 1 - 2*y + 0.05 * sin(4*pi*y) - x;
	double a2 = y - 0.5 * sin(2*pi*x);
	return pow(a1,2.0) + pow(a2, 2.0);
}

double coordenadas(double &x, double &y, double precision, int maxIter){
	double delta = 9, n=0;
	do{   
		double fxy = branin(x,y);
		if(branin(x+delta, y) < fxy ){
			x = x+delta;
		}else if(branin(x-delta, y)< fxy){
			x = x-delta;
		}else if(branin(x, y+delta)< fxy){
			y = y+delta;
		}else if(branin(x, y-delta)< fxy){
			x= x+delta;
		}else{
			
		}
		n++;
	}while((abs(branin(x,y))>precision)&&(n<maxIter));
	return branin(x,y);
}

void coordenadas(){
	double a, b, precision, sol;
	int maxIter;
	
	cout<< "Introduzca la coordenada x:  ";
	cin>>a;
	
	cout<<endl<< "Introduzca la coordenada y:  ";
	cin>>b;
	
	cout<<endl<< "Introduzca la precision:  ";
	cin>>precision;
	
	cout<<endl<< "Introduzca el maximo numero de iteraciones:  ";
	cin>>maxIter;
	
	sol = coordenadas(a,b,precision,maxIter);
	cout<<endl<< "Solucion: f(" << a << "," << b << ") = " <<  sol <<endl;
}