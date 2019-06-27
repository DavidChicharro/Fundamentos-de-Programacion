/*
Indique si se produce un problema de precisión
o de desbordamiento en los siguientes ejemplos
y diga cuál sería el resultado final de las operaciones.

Para mostrar el contenido de una variable real con cout
hay que establecer el número de decimales a mostrar en
pantalla ejecutando cout.precision(numer_digitos); al
inicio del programa.
*/

#include <iostream>

using namespace std;

int main(){
	int chico, chico1, chico2;
	
	chico1 = 1234567;
	chico2 = 1234567;
	chico = chico1 * chico2; 					// 1.524.155.677.489
	
	cout << "a) " << chico << "\n\n";		// Se produce un desbordamiento
	
	
	
	long grande;
	
	chico1 = 1234567;
	chico2 = 1234567;
	grande = chico1 * chico2; 					// 1.524.155.677.489
	
	cout << "b) " << grande << "\n\n";		// Se produce un desbordamiento
	
	
	
	double real, real1, real2;
	
	real1 = 123.1;
	real2 = 124.2;
	real = real1 * real2; 						// 15289,02
	
	cout << "c) " << real << "\n\n";			// Se produce un problema de precision
	
	
	
	real1 = 123456789.1;
	real2 = 123456789.2;
	real = real1 * real2;						// 15.241.578.787.227.557,72
	
	cout << "d) " << real << "\n\n";			// Se produce un problema de precision
	
	
	
	double otro_real;
	real = 2.0e+34;
	otro_real = real + 1;
	otro_real = otro_real - real;				// 1
	
	cout << "e) " << otro_real << "\n\n"; 	// Se produce un error de precision
	
	
	
	real = 1.0e+300;
	otro_real = 1.0e+200;
	otro_real = otro_real * real;				// 1e+500
	
	cout << "f) " << otro_real << "\n\n"; 	// Se produce un error de precision
	
	
	
	float chicoo;
	double grandee;
	
	grandee = 2e+150;
	chicoo = grandee;								// 2e+150
	
	cout << "g) " << chicoo << "\n\n"; 		// Se produce un error de precision

	system ("pause");
}
