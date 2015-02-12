//Jaime Delgado Linares

//Implementación del algoritmo de la bisección

#include <cmath>
#include <iostream>
using namespace std;
#define pi 3.14159265
 
double branin(double x);
void biseccion();
double biseccion ( double a, double b, double precision, int maxIter);
 
int main(){
	biseccion();
	return 0;
}
 
double branin(double x){
	double a1 = 1 - 2*x + 0.05 * sin(4*pi*x*x) - x;
	double a2 = x*x - 0.5 * sin(2*pi*x);
	return pow(a1,2.0) + pow(a2, 2.0);
}

double biseccion(double a, double b, double precision, int maxIter){
	double c,ai;
	int n=0;
 
	do{   
		ai=a;
		c=(a+b)/2;
		if(branin(a)*branin(c)<0){
			b=c;
		}else{
			a=c;
		}
		n++;
	}while((abs(branin(c))>precision)&&(n<maxIter));

	return c;
}
 
void biseccion(){
 
	double a, b, precision, raiz;
	int maxIter;
	
	cout<< "Introduzca el punto a:  ";
	cin>>a;
	
	cout<<endl<< "Introduzca el punto b:  ";
	cin>>b;
	
	cout<<endl<< "Introduzca la precision:  ";
	cin>>precision;
	
	cout<<endl<< "Introduzca el maximo numero de iteraciones:  ";
	cin>>maxIter;
	
	raiz = biseccion(a,b,precision,maxIter);
	cout<<endl<< "La raiz es: "<< raiz <<endl;
	
 
}