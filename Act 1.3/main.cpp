// =================================================================
//
// File: main.cpp
// Autores: David René Langarica Hernández - A01708936, Sebastian Flores Lemus - A01709229
// Date: 09/11/2022
//
// =================================================================
#include <iostream>
#include <fstream>
#include <vector>
#include "funciones.h"
#include <string>

using std::cin;
using std::endl;
using std::vector;
using std::ifstream;
using std::ofstream;

int main(int argc, char* argv[]) {

  // variables 
  // nelements siendo la cantidad de elementos
  // prefix siendo el UBI
  int nelements, i, j, existe;
  string line, prefix;

  // creamos vector que almacena los datos llamado 'registro'
  // creamos vector que almacena los datos ordenados 'resultado'
  vector<string> registro, resultado;

  // lectura de archivo al igual que creacion de otro
  ifstream archivo1(argv[1]); 
  ofstream archivo2(argv[2]);

  // se leen nelements numero de datos y prefix 'UBI' desde el archivo 'input'
  archivo1 >> nelements >> prefix;

  do{
     getline(archivo1, line);

    if(archivo1.good()){
      existe = SearchPrefix(line, prefix);

      if(existe >= 0){
        registro.push_back(line);
      }
    }
    i++;
  } while (i < nelements);

  resultado = sortRegister(registro);

  for (j = 0; j < resultado.size(); j++){
    archivo2 << resultado[j] << endl;
  }

  archivo1.close();
  archivo2.close();

  return 0;

}
