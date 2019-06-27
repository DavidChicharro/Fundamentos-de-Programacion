/*
EJERCICIO OPCIONAL
Triles: intercambiar variables
Programa que simule un juego inspirado en el de los triles.
Suponemos que hay dos cajas (izquierda y derecha). Dentro
de cada caja hay una cantidad de dinero y el objetivo es
intercambiar las cantidades que hay dentro.
	- Debe leer desde teclado dos variables caja_izda y caja_dcha.
	- A continuación debe intercambiar sus valores y, finalmente
	  mostrarlos en pantalla.
	  
Observe que se desea intercambiar el contenido de las variables,
de forma que caja_izquierda pasa a contener lo que tenía caja_derecha
y viceversa. El siguiente códigono es válido ya que simplemente engaña
al usuario pero las cajas no se quedanmodificadas:

	cout << "La caja izquierda vale " << caja_dcha << "\n";
	cout << "La caja derecha vale " << caja_izda;
*/

/*
Una posible solución sería crear una caja imaginaria 'caja_virtual' donde
depositar el valor de una de las cajas (1) mientras que la caja 2 da su
valor a la 1, y luego la 2 adquiere el valor de la imaginaria, de la siguiente manera:
*/

#include <iostream>

using namespace std;

int main(){
	double caja_izquierda, caja_derecha, caja_virtual;

	cout << "Introduzca un valor en la caja izquierda ";
	cin >> caja_izquierda;
	cout << "Introduzca un valor en la caja derecha ";
	cin >> caja_derecha;
	
	caja_virtual = caja_izquierda;
	caja_izquierda = caja_derecha;	
	caja_derecha = caja_virtual;		
	
	cout << "\nCaja izquierda: " << caja_izquierda;
	cout << "\nCaja derecha: " << caja_derecha << "\n\n";
	
	system ("pause");
}


/*
El siguiente código no funciona porque las dos variables adquieren el mismo valor:

	caja_izda = caja_dcha;
	caja_dcha = caja_izda;
*/
