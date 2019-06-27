

//////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programaci�n
// ETS Inform�tica y Telecomunicaciones
// Universidad de Granada
// Departamento de Ciencias de la Computaci�n e Inteligencia Artificial
// Autor: Juan Carlos Cubero
//
//////////////////////////////////////////////////////////////////////////

/*
Dada una secuencia de caracteres que contiene un mensaje cifrado, se pide definir un m�todo para construir otra
secuencia nueva con el mensaje descifrado. La forma de descifrado consiste en coger la primera y �ltima letra de
cada palabra. Las palabras est�n separadas por uno o m�s espacios en blanco o el final de la secuencia. Si la �ltima
palabra no tiene espacios en blanco a su derecha, se coge s�lo el primer car�cter.
*/

   // Entrada:    Hidr�geno limpia   #
   // Salida: Hola

   // Entrada: Hidr�geno limpia#
   // Salida: Hol

   // Entrada: Hidr�geno#
   // Salida: H

   // Entrada: Hidr�geno    #
   // Salida: Ho

   // Entrada: H #
   // Salida: H

   // Entrada: H#
   // Salida: H

#include <iostream>
using namespace std;

   /*
   Vamos a resolver este problema de dos formas alternativas:
   
   1. Utilizando un bucle principal que va avanzando la posici�n actual 
      y con un bool detectamos si estamos al inicio de una palabra
      
      while (actual != ultimo)
         procesa la componente actual
   
   2. Con varios bucles consecutivos que van avanzando 
      para detectar el inicio y final de una palabra  
      y todos ellos dentro de un bucle principal que controla que 
      no nos salgamos de la secuencia.
      
      while (actual != ultimo)
         while (i < ultimo
            ...
         while (j < ultimo)
            ...
         while (k < ultimo)
            ...

   La primera soluci�n quedar� m�s elegante (no siempre tiene por qu� ser as�)
   */
      
int main(){
   const char TERMINADOR = '#';
   char caracter;
   const int TAMANIO                 =  100;
   char texto[TAMANIO];
   char descodificada[TAMANIO];
   int utilizados_texto;
   int utilizados_descodificada;
   
   int i, siguiente;
   bool anterior_es_blanco;
   
   //////////////////////////////////////////////////////////////////
   // Lectura de los datos:

   cout << "Cadena codificada."
        << "\nIntroduzca caracteres con terminador " << TERMINADOR << "\n";

   utilizados_texto = 0;
   caracter = cin.get();

   while (caracter != TERMINADOR && utilizados_texto < TAMANIO){
      texto[utilizados_texto] = caracter;
      utilizados_texto++;
      caracter = cin.get();
   }

   //////////////////////////////////////////////////////////////////
   /*
   Versi�n en la que nos fijamos en la componente actual y con un bool
   detectamos si estamos al inicio de una palabra:

   Algoritmo. Descodificar palabra:

      Recorremos todos los caracteres
         Si el car�cter actual NO es blanco,
         lo a�ado cuando se verifica alguna de estas condiciones:
            a) Est� en el inicio de la palabra
            b) La siguiente sea blanco 
   */
   
   utilizados_descodificada = 0;
   i = 0;
   anterior_es_blanco = true;

   while (i < utilizados_texto){
      siguiente = i+1;

      if (texto[i] != ' '){
         if (anterior_es_blanco ||
            (siguiente < utilizados_texto && texto[siguiente] == ' ')){
               
            descodificada[utilizados_descodificada] = texto[i];
            utilizados_descodificada++;
         }

         anterior_es_blanco = false;
      }
      else
         anterior_es_blanco = true;

      i = siguiente;
   }
   
   
   
   
   // En la siguiente versi�n s�lo comparamos con blanco una �nica vez.
   /*
   utilizados_descodificada = 0;
   anterior_es_blanco = true;
   bool actual_es_blanco;
   int posicion_a_aniadir;
   bool hay_que_aniadir;
   
   for (int i = 0; i < utilizados_texto; i++){
      actual_es_blanco = texto[i] == ' ';
      
      hay_que_aniadir = actual_es_blanco && !anterior_es_blanco;
      
      if (hay_que_aniadir)
         posicion_a_aniadir = i - 1;
      else{
         hay_que_aniadir = !actual_es_blanco && anterior_es_blanco;
         
         if (hay_que_aniadir)
            posicion_a_aniadir = i;
      }
      
      if (hay_que_aniadir){
         descodificada[utilizados_descodificada] = texto[posicion_a_aniadir];
         utilizados_descodificada++;
      }

      anterior_es_blanco = actual_es_blanco;
   }
   
   
   /////////////////////////////////////////////////////////////////////
   
   /*
   Versi�n en la que se va recorriendo el vector
   con varios bucles consecutivos:

   Recorremos todos los caracteres
      Nos saltamos todos los blancos y
      a�adimos el primer car�cter que no sea blanco

      Nos saltamos todos los que no sean blanco
      para situarnos al final de la palabra
      y a�adimos el �ltimo car�cter.

   Esta versi�n es bastante menos elegante que la anterior.
   */
   
   /*
   int j;

   i = 0;

   while (i < utilizados_texto){
      j = i;

      while (j < utilizados_texto && texto[j] == ' ')
         j++;

      if (j < utilizados_texto){
         descodificada[utilizados_descodificada] = texto[j];
         utilizados_descodificada ++;
      }

      while (j < utilizados_texto && texto[j] != ' ')
         j++;

      if (i + 1 != j && j < utilizados_texto){         // i+1 != j necesario para palabras de un �nico car�cter
         descodificada[utilizados_descodificada] = texto[j-1];
         utilizados_descodificada ++;
      }

      i = j;
   }
   */
   
   cout << "\nCadena descodificada:\n" << "<";
   
   for (int i = 0; i < utilizados_descodificada; i++)
      cout << descodificada[i];

   cout << ">";
}



