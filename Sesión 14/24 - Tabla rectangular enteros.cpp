/*
Alumno: David Carrasco Chicharro
Grado en Ingeniería Informática
Asignatura: Fundamentos de la Programación
Curso: 1º 	Grupo: C		Subgrupo: C1
Profesor Teoría: Juan Carlos Cubero
Proferosa Prácticas: María del Carmen Pegalajar

Sesión 14
Ejercicio 24 - Tabla rectangular de enteros

Programa que lee una tabla de enteros y dice si es simétrica o no.
Además calcula su traspuesta, y el producto de la tabla original por la traspuseta,
imprimiendo ambas en pantalla.

*/

#include <iostream>
#include <string>
using namespace std;


class SecuenciaEnteros{
private:
   static const int TAMANIO = 50;
   long vector_privado[TAMANIO];
   int total_utilizados;
   
   void IntercambiaComponentes_en_Posiciones(int pos_izda, int pos_dcha){
      long intercambia;

      intercambia = vector_privado[pos_izda];
      vector_privado[pos_izda] = vector_privado[pos_dcha];
      vector_privado[pos_dcha] = intercambia;
   }
public:
   SecuenciaEnteros()
      :total_utilizados(0)
	{
   }
   
   int TotalUtilizados(){
      return total_utilizados;
   }
   
   int Capacidad(){
      return TAMANIO;
   }
   
   void EliminaTodos(){
      total_utilizados = 0;
   }
   
   void Aniade(long nuevo){
      if (total_utilizados < TAMANIO){
         vector_privado[total_utilizados] = nuevo;
         total_utilizados++;
      }
   }
   
   void Modifica(int posicion, long nuevo){
      if (posicion >= 0 && posicion < total_utilizados)
         vector_privado[posicion] = nuevo;
   }

   long Elemento(int indice){
      return vector_privado[indice];
   }
};

class LectorSecuenciaEnteros{
private:
   long terminador;
   
public:
   LectorSecuenciaEnteros(long entero_terminador)
      :terminador(entero_terminador)
   {
   }
   
   SecuenciaEnteros Lee(int capacidad_secuencia){
      SecuenciaEnteros a_leer;
      int total_introducidos = 0;
      long entero;

      while (total_introducidos < capacidad_secuencia){
      	cin >> entero;
         a_leer.Aniade(entero);
         total_introducidos++;
      }

      return a_leer;
   }
};

class TablaRectangularEnteros{
private:
	static const int MAX_FIL = 100,
						  MAX_COL = 100;
	int matriz_privada[MAX_FIL][MAX_COL];
	int util_filas;
	int util_columnas;
   int indice_ultima_fila_aniadida = -1;
	
	void AsignaFila (SecuenciaEnteros fila, int indice_fila){
      for (int i = 0 ; i < util_filas; i++)
         matriz_privada[indice_fila][i] = fila.Elemento(i);
   }
	
public:
	TablaRectangularEnteros(int filas, int columnas)
		:util_filas(filas), util_columnas(columnas)
	{
	}
	
	int TotalUtilizadosFilas(){
		return util_filas;
	}
	
	int TotalUtilizadosColumnas(){
		return util_columnas;
	}
	
	int Pixel(int fila, int columna){
		return matriz_privada[fila][columna];
	}
   
   void AniadeFilas(SecuenciaEnteros secuencia){
   	int indice_secuencia = 0;
   	
   	if (indice_ultima_fila_aniadida < MAX_FIL)
   		for (int i = 0 ; i < util_filas ; i++){			
   			for (int j = 0 ; j < util_columnas ; j++){   				
   				matriz_privada[i][j] = secuencia.Elemento(indice_secuencia);
   				indice_secuencia++;
   			}
   			
   			indice_ultima_fila_aniadida++;
   		}   		
   }
   
   SecuenciaEnteros Fila(int indice_fila){
      SecuenciaEnteros fila;
      
      for (int i = 0 ; i < util_columnas ; i++){
         fila.Aniade(matriz_privada[indice_fila][i]);
      }
      
      return fila;
   }
   
   bool SonIguales (TablaRectangularEnteros otra_matriz){
   	bool son_iguales;
   	
   	for (int i = 0 ; i < util_filas ; i++){
   		son_iguales = true;
   		
   		for (int j = 0 ; j < util_columnas && son_iguales ; j++){
   			if (matriz_privada[i][j] == otra_matriz.matriz_privada[i][j])
   				son_iguales = true;
   			else
   				son_iguales = false;
   			}
   	}
   	
   	return son_iguales;
   }
   
   TablaRectangularEnteros Traspuesta(){
   	TablaRectangularEnteros traspuesta(util_columnas, util_filas);
   	
   	for (int i = 0 ; i < util_filas ; i++)
   		for (int j = 0 ; j < util_columnas ; j++)
   			traspuesta.matriz_privada[j][i] = matriz_privada[i][j];
   			
   	return traspuesta;
	}
	
	bool EsSimetrica(){
		bool es_simetrica;
		TablaRectangularEnteros traspuesta(Traspuesta());
		
		if (util_filas == util_columnas)
	   	for (int i = 0 ; i < util_filas ; i++){
	   		es_simetrica = true;
	   		
	   		for (int j = 0 ; j < util_columnas && es_simetrica; j++){
	   			if (matriz_privada[i][j] == traspuesta.matriz_privada[i][j])
	   				es_simetrica = true;
	   			else
	   				es_simetrica = false;
	   		}
	   	}
	   else
	   	es_simetrica = false;
   	
   	return es_simetrica;
   }
   
   TablaRectangularEnteros Producto(TablaRectangularEnteros matriz_2){
   	TablaRectangularEnteros producto(util_filas, matriz_2.util_columnas);
   	
	   for (int i = 0 ; i < util_columnas ; i++)
			for (int j = 0 ; j < matriz_2.util_columnas ; j++){
				producto.matriz_privada[i][j] = 0;
				for (int k = 0 ; k < util_columnas ; k++)
					producto.matriz_privada[i][j] = producto.matriz_privada[i][j] + matriz_privada[i][k] * matriz_2.matriz_privada[k][j];
			}
			
		return producto;
   }
};

int main(){
	int filas, columnas;
   const long TERMINADOR = -1;
   LectorSecuenciaEnteros lector_secuencias(TERMINADOR);
   SecuenciaEnteros secuencia;

	// Entrada de datos
	cout << "Establezca el numero de filas: ";
   cin >> filas;
   cout << "Establezca el numero de columnas: ";
   cin >> columnas;
   
   
   // Cómputos
   secuencia = lector_secuencias.Lee(filas*columnas);
  	TablaRectangularEnteros tabla(filas, columnas);
  	
  	tabla.AniadeFilas(secuencia);
  	
  	TablaRectangularEnteros traspuesta(tabla.Traspuesta());
 	TablaRectangularEnteros producto(tabla.Producto(traspuesta));
   		
   // Salida de resultados
   if (tabla.EsSimetrica())
   	cout << "\n\nLa tabla es simetrica.";
   else
   	cout << "\n\nLa tabla no es simetrica.";
   	
   cout << "\n\nTabla traspuesta: " << endl;
	for (int i = 0 ; i < traspuesta.TotalUtilizadosFilas() ; i++){
		for (int j = 0 ; j < traspuesta.TotalUtilizadosColumnas() ; j++)
			cout << traspuesta.Pixel(i, j) << "\t";
		cout << "\n";
		}
	
	cout << "\n\nProducto de la tabla original x traspuesta: " << endl;
	for (int i = 0 ; i < producto.TotalUtilizadosFilas() ; i++){
		for (int j = 0 ; j < producto.TotalUtilizadosColumnas() ; j++)
			cout << producto.Pixel(i, j) << "\t";
		cout << "\n";
		}
	
   system ("pause");
}
