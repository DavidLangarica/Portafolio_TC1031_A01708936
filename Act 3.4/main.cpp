// =================================================================
//
// File: main.cpp
// Author: David Langarica | Sebastian Flores
// Date: 18 Noviembre 2022
//
// =================================================================
#include <iostream>
#include <fstream>
#include <string>
#include "heap.h"

using namespace std;

int main(int argc, char *argv[]) {

  ifstream archivo1(argv[1]); 
  ofstream archivo2(argv[2]);

  int n_elementos, temp_suma;
  int suma = 0;
  vector<int> elementos_lista;
  string num_list;
  
  archivo1 >> n_elementos;

  elementos_lista.resize(n_elementos);

  Heap<int> heap(n_elementos);

  for(int j = 0; j < n_elementos; j++){
    archivo1 >> elementos_lista[j];
    heap.add(elementos_lista[j]);
  }

  while(heap.length() != 1){
    temp_suma = heap.remove() + heap.remove();
    heap.add(temp_suma); 
    suma += temp_suma - 1;
  }

  archivo2 << suma; 

  archivo1.close();
  archivo2.close();

  return 0;
}
