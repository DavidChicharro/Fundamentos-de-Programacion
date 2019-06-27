/*
Alumno: David Carrasco Chicharro
D.N.I.: 15520228-N
Grado en Ingeniería Informática
Asignatura: Fundamentos de la Programación
Curso: 1º 	Grupo: C		Subgrupo: C1
Profesor Teoría: Juan Carlos Cubero
Proferosa Prácticas: María del Carmen Pegalajar

Sesión
Ejercicio 21 - Promedio en una clase (Examen Febrero 2015) 

Programa que calcula en una matriz cuadrada, en su triángulo superior,
el valor promedio de los números y los que se encuentran a su derecha.

*/

#include <iostream>
using namespace std;


class SecuenciaReales{
private:
   static const int TAMANIO = 50;
   double vector_privado[TAMANIO];
   int total_utilizados;
   
public:
   SecuenciaReales()
      :total_utilizados(0)
   {
   }

   int TotalUtilizados(){
      return total_utilizados;
   }

   void  Aniade(double nuevo){
      if (total_utilizados < TAMANIO){
      	vector_privado[total_utilizados] = nuevo;
         total_utilizados++;
      }
   }

   double Elemento(int indice){
      return vector_privado[indice];
   }

   void Modifica(int indice_componente, double nuevo){
      if (indice_componente >= 0  &&  indice_componente < total_utilizados)
         vector_privado[indice_componente] = nuevo;
   }

   void EliminaTodos(){
      total_utilizados = 0;
   }

   int PrimeraOcurrenciaEntre(int pos_izda, int pos_dcha, double buscado){
      int i = pos_izda;
      bool encontrado = false;

      while (i <= pos_dcha  &&  !encontrado)
         if (vector_privado[i] == buscado)
            encontrado = true;
         else
            i++;

      if (encontrado)
         return i;
      else
         return -1;
   }

   int PrimeraOcurrencia (double buscado){
      return PrimeraOcurrenciaEntre(0, total_utilizados - 1, buscado);
   }

   void Ordena_por_Insercion(){
      int izda, i;
      int a_desplazar;

      for (izda = 1; izda < total_utilizados; izda++){
         a_desplazar = vector_privado[izda];

         for (i = izda; i>0 && a_desplazar < vector_privado[i-1]; i--)
            vector_privado[i] = vector_privado[i-1];

         vector_privado[i] = a_desplazar;
      }
   }
};


class TablaCuadradaReales{
private:
   static const int MAX_FILAS_COLUMNAS = 40;
   double matriz_privada[MAX_FILAS_COLUMNAS][MAX_FILAS_COLUMNAS];
   const int util_fil_col = 0;
   int indice_ultima_fila_aniadida = -1;
   
   void AsignaFila (SecuenciaReales fila, int indice_fila){
      for (int i=0; i < util_fil_col; i++)
         matriz_privada[indice_fila][i] = fila.Elemento(i);
   }
   
public:
   TablaCuadradaReales(SecuenciaReales primera_fila)
      :util_fil_col(primera_fila.TotalUtilizados())
   {
      AniadeFila(primera_fila);
      indice_ultima_fila_aniadida = 0;
   }

	TablaCuadradaReales(int numero_columnas)
      :util_fil_col(numero_columnas)
   {
   }
   
   double Elemento (int fil, int col){
      return matriz_privada[fil][col];
   }

   int NumeroFilas_y_Columnas(){
      return util_fil_col;
   }
   
   bool EsCuadrada(){
      return util_fil_col == indice_ultima_fila_aniadida + 1;
   }

   void AniadeFila(SecuenciaReales nueva_fila){
      if (indice_ultima_fila_aniadida < MAX_FILAS_COLUMNAS){
         if (nueva_fila.TotalUtilizados() == util_fil_col){
            indice_ultima_fila_aniadida++;
            AsignaFila(nueva_fila, indice_ultima_fila_aniadida);
         }
      }
   }
   
   SecuenciaReales Fila(int indice_fila){
      SecuenciaReales fila;
      
      for (int i=0; i < util_fil_col; i++){
         fila.Aniade(matriz_privada[indice_fila][i]);
      }
      return fila;
   }
   
   TablaCuadradaReales Promedio(){
		TablaCuadradaReales promedio(4);
		double suma;
      
	   for (int i = 0; i < util_fil_col; i++){
	      promedio.matriz_privada[i][i] = matriz_privada[i][i];
	      suma = 0;
	      
	      for (int j = util_fil_col - 1 ; j > i ; j--){
	         suma           = suma + matriz_privada[i][j];
	         promedio.matriz_privada[i][j] = suma / (util_fil_col - j);
	         promedio.matriz_privada[j][i] = promedio.matriz_privada[i][j];
	      }
	   }
	   return promedio;
      
   }
};


int main(){
   int util_filas_original, util_filas_promedio;
   double valor;
   SecuenciaReales fila;

   // No etiquetamos las entradas porque suponemos que leemos de un fichero
   // Supondremos que util_filas > 0

   cin >> util_filas_original;
   
   TablaCuadradaReales tabla(util_filas_original);

   for (int i = 0; i < util_filas_original; i++){
      for (int j = 0; j < util_filas_original; j++){
         cin >> valor;
         fila.Aniade(valor);
      }
      
      tabla.AniadeFila(fila);
      fila.EliminaTodos();
   }

   if (tabla.EsCuadrada()){
      TablaCuadradaReales promedio(tabla.Promedio());
      
      util_filas_promedio = promedio.NumeroFilas_y_Columnas();
   
      cout << "\n\n";
      cout << "Matriz promedio:\n";

      for (int i = 0; i < util_filas_promedio; i++){
         cout << "\n";

         for (int j = 0; j < util_filas_promedio; j++)
            cout << promedio.Elemento(i,j) << '\t';
      }
   }
}
