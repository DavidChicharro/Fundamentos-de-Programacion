#include <iostream>
#include <cmath>
using namespace std;

double Cuadrado(double entrada){
   return entrada*entrada;
}

double Hipotenusa(double un_lado, double otro_lado){
   return sqrt(Cuadrado(un_lado) + Cuadrado(otro_lado));
}

void ImprimeAsteriscos (int num_asteriscos){
   for (int i = 1 ; i <= num_asteriscos ; i++)
      cout << "*";
}

void ImprimeLineas (int num_lineas, int num_asteriscos){
   for (int i = 1; i <= num_lineas ; i++){
      cout << "\n";
      ImprimeAsteriscos(num_asteriscos);
   }
}

void Presentacion(string mensaje, int tope_lineas, int num_asteriscos){
   ImprimeLineas (tope_lineas, num_asteriscos);
   cout << "\n" << mensaje;
   ImprimeLineas (tope_lineas, num_asteriscos);
}

int main(){
   double lado1, lado2, hipotenusa;

   Presentacion("Programa básico de Trigonometría", 3, 32);

   cout << "\n\nIntroduzca los lados del triángulo rectángulo:\n";
   cin >> lado1;
   cin >> lado2;

   hipotenusa = Hipotenusa(lado1,lado2);

   cout << "\nLa hipotenusa vale " << hipotenusa;
}
