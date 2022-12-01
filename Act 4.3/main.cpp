// =================================================================
//
// File: main.cpp
// Autores: David René Langarica Hernández - A01708936, Sebastian Flores Lemus - A01709229
// Date: 2/12/2022
//
// =================================================================
#include <iostream>
#include <fstream>
#include <vector>
#include "ugraph.h"

using namespace std;

void output(ofstream &archivo2, int numero_cases, int puertos_faltantes, string puerto_nombre, int mnp_inicial){
  archivo2 << "Case " << numero_cases << ": " <<  puertos_faltantes
  << " ports not reachable from port "  << puerto_nombre << " with MNP = "
  << mnp_inicial << "." << "\n";
}

int main(int argc, char* argv[]) {

  // creamos archivo de input y output
  ifstream archivo1(argv[1]); 
  ofstream archivo2(argv[2]);

  // creamos variables 
  int puertos_faltantes, numero_cases = 1, numero_conexiones, numero_consultas, mnp_inicial;
  string puerto_nombre, puerto1, puerto2;

  // leemos el numero de conexiones que haremos en el grafo
  archivo1 >> numero_conexiones;
  
  UListGraph<string> grafo(numero_conexiones);
  
   for(int i = 0; i < numero_conexiones; i++){
    archivo1 >> puerto1 >> puerto2;
    grafo.addEdge(puerto1, puerto2);
    grafo.addEdge(puerto2, puerto1);
   }
  
  // leemos numero de consultas de puertos
  archivo1 >> numero_consultas;

  // se leen e imprimen datos
  for(int i = 0; i < numero_consultas; i++){
    archivo1 >> puerto_nombre >> mnp_inicial;
    int cont = 0;
    bfs(puerto_nombre, &grafo, cont, mnp_inicial);
    output(archivo2, i+1, cont, puerto_nombre, mnp_inicial);
  }
  
  archivo1.close();
  archivo2.close();
  
	return 0;
}
