/*
Alumno: David Carrasco Chicharro
Grado en Ingeniería Informática
Asignatura: Fundamentos de la Programación
Curso: 1º 	Grupo: C		Subgrupo: C1
Profesor Teoría: Juan Carlos Cubero
Proferosa Prácticas: María del Carmen Pegalajar

Sesión
Ejercicio 11 - k Mayores que, dentro de una clase

El programa lee una secuencia de números reales para ordenar los k mayores que una referencia.
para ello pide dicha referencia y otro que será el número k. Finalmente imprimirá en pantalla
los valores mayores que k de manera ordenada.

*/

#include <iostream>
using namespace std;

class SecuenciaDoubles{
private:
   static const int TAMANIO = 50;
   double vector_privado[TAMANIO];
   int total_utilizados;
   
   void IntercambiaComponentes_en_Posiciones(int pos_izda, int pos_dcha){
      double intercambia;

      intercambia = vector_privado[pos_izda];
      vector_privado[pos_izda] = vector_privado[pos_dcha];
      vector_privado[pos_dcha] = intercambia;
   }
public:
   SecuenciaDoubles()
      :total_utilizados(0) {
   }
   
   int TotalUtilizados(){
      return total_utilizados;
   }
   
   int Capacidad(){
      return TAMANIO;
   }
   
   void Aniade(double nuevo){
      if (total_utilizados < TAMANIO){
         vector_privado[total_utilizados] = nuevo;
         total_utilizados++;
      }
   }
   
   void Modifica(int posicion, double nuevo){
      if (posicion >= 0 && posicion < total_utilizados)
         vector_privado[posicion] = nuevo;
   }

   double Elemento(int indice){
      return vector_privado[indice];
   }
   
   string ToString(){
      // Si el número de caracteres en memoria es muy grande,
      // es mucho más eficiente reservar memoria previamente
      // y usar push_back

      string cadena;

      cadena.reserve(total_utilizados);

      for (int i=0; i < total_utilizados; i++){
         cadena.append(to_string(vector_privado[i]));
         cadena.append(" ");
         //cadena = cadena + to_string(vector_privado[i])  <- Evitarlo. Muy ineficiente para tamaños grandes;
      }
      
      return cadena;
   }

   /////////////////////////////////////////////////////////////
   // Búsquedas
   
   // Precond: 0 <= izda <= dcha < total_utilizados
   int PosicionMinimoEntre(int izda, int dcha){
      int posicion_minimo = -1;
      double minimo;

      minimo = vector_privado[izda];
      posicion_minimo = izda;

      for (int i = izda+1 ; i <= dcha ; i++)
         if (vector_privado[i] < minimo){
            minimo = vector_privado[i];
            posicion_minimo = i;
         }

      return posicion_minimo;
   }
   
   int PosicionMinimo(){
      return PosicionMinimoEntre(0, total_utilizados - 1);
   }
   
   int BusquedaBinaria (double buscado){
      int izda, dcha, centro;
      bool encontrado = false;

      izda = 0;
      dcha = total_utilizados - 1;
      centro = (izda + dcha) / 2;

      while (izda <= dcha  &&  !encontrado){
         if (vector_privado[centro] == buscado)
            encontrado = true;
         else if (buscado < vector_privado[centro])
            dcha = centro - 1;
         else
            izda = centro + 1;

         centro = (izda + dcha) / 2;
      }

      if (encontrado)
         return centro;
      else
         return -1;
   }
   
   /////////////////////////////////////////////////////////////
   // Algoritmos de ordenación
   
   void Ordena_por_Seleccion(){
      int pos_min;

      for (int izda = 0 ; izda < total_utilizados ; izda++){
         pos_min = PosicionMinimoEntre(izda, total_utilizados - 1);
         IntercambiaComponentes_en_Posiciones(izda, pos_min);
      }
   }
   
   void Ordena_por_Insercion(){
      int izda, i;
      double a_desplazar;

      for (izda=1; izda < total_utilizados; izda++){
         a_desplazar = vector_privado[izda];

         for (i=izda; i > 0 && a_desplazar < vector_privado[i-1]; i--)
            vector_privado[i] = vector_privado[i-1];

         vector_privado[i] = a_desplazar;
      }
   }

   SecuenciaDoubles MayoresQue(double referencia, int k){
   	SecuenciaDoubles mayores_que;
   	
   	for (int i = 0 ; i < total_utilizados ; i++)
   		if (vector_privado[i] > referencia && mayores_que.total_utilizados < k){
   			mayores_que.Aniade(vector_privado[i]);
   			mayores_que.Ordena_por_Insercion();
   		}
   			
   	return mayores_que;   	
   }
};

class LectorSecuenciaDoubles{
private:
   double terminador;
   
public:
   LectorSecuenciaDoubles(double real_terminador)
      :terminador(real_terminador)
   {
   }
   
   SecuenciaDoubles Lee(){
      SecuenciaDoubles a_leer;
      int total_introducidos;  // Esta variable es para contar los introducidos
                               // y que no nos pasemos de la capacidad de la secuencia.
      int capacidad_secuencia;
      double real;

      total_introducidos = 0;
      capacidad_secuencia = a_leer.Capacidad();
      cin >> real;

      while (real != terminador && total_introducidos < capacidad_secuencia){
         a_leer.Aniade(real);
         total_introducidos++;
         cin >> real;
      }

      return a_leer;
   }
};

int main(){
   const double TERMINADOR = -1.0;
   LectorSecuenciaDoubles lector_secuencias(TERMINADOR);
   SecuenciaDoubles secuencia, mayores_que;
   double referencia;
   int k;

   secuencia = lector_secuencias.Lee();
   
   cout << "Indique la referencia k: ";
   cin >> referencia;
	cout << "Indique cuantos valores mayores que " << referencia << " desea: ";
	cin >> k;
	
   mayores_que = secuencia.MayoresQue(referencia, k);
   
	cout << "\n" << mayores_que.ToString();

	system ("pause");
}
