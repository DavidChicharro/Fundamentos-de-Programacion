#include <iostream>
using namespace std;

int main(){
	/*
	En primer lugar, ejecutamos y entendemos el siguiente c�digo:
	*/
   
	int  orden_caracter_cero;
	char caracter_cero;

	// El orden del car�cter 0 es 48
	
   caracter_cero = 48;                   // Almacena 48
	caracter_cero = '0';                  // Almacena 48
	
	orden_caracter_cero = 48;             // Almacena 48
	orden_caracter_cero = '0';            // Almacena 48
	orden_caracter_cero = caracter_cero;  // Almacena 48

	cout << "\nEl orden del car�cter " << caracter_cero << " es: "
        << orden_caracter_cero;
}
