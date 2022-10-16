// =================================================================
//
// File: main.cpp
// Autores: David René Langarica Hernández - A01708936, Sebastian Flores Lemus - A01709229
// Date: 16/10/2022
//
// =================================================================
#include <iostream>
#include <fstream>
#include <vector>
#include "classes.h"
#include <string>

int main(int argc, char* argv[]) {

  // lectura de archivo al igual que creacion de otro
  ifstream archivo1(argv[1]); 
  ofstream archivo2(argv[2]);

  int nelements;
  string date, hour, entryp, ubi, prefix, prefixdata;
  int day, month, year;

  // se leen nelements numero de datos y prefix 'UBI' desde el archivo 'input'
  archivo1 >> nelements >> prefix;

  // crear el vector de objetos para los registros
  vector<ShipReg> sregists;

  // crear objetos para contadores de M o R en cada mes
  vector<Month> monthctr;

  for (int k = 1; k < 13; k++){
    monthctr.push_back(Month(k));
  };

  // crear arreglo de string de meses
  string month_string[12] = {"jan","feb","mar","apr","may","jun","jul","aug","sep","oct","nov","dec"};

  // se ajusta el tamaño del vector al del número de elementos
  sregists.resize(nelements);

  for (int i = 0; i < sregists.size(); i++){
    // leer cada línea del archivo y obtener los datos necesarios para armar el objeto
    archivo1 >> date >> hour >> entryp >> ubi;

    // dividir la fecha y convertir el mes en un int para agregar a ShipReg
    month = stoi(date.substr(3, 2));

    // Dividir el ubi para obtener el prefijo del registro
    prefixdata = ubi.substr(0, 3);

    //Si el prefijo coincide, se guarda en el vector mediante un push back
    if(prefixdata == prefix){
      sregists.push_back(ShipReg(month,entryp,ubi));
    }
  };

  //Output
  for (int h = 0; h < 12 ; h++){
    // calcula el número de registros para cada puerto y los almacena en un subvector de 'M' o 'R'
    monthctr[h].ports(sregists);

    // escribe en el archivo con el formato esperado
    archivo2 << month_string[h] << '\n';
    monthctr[h].output(archivo2);
  };

  archivo1.close();
  archivo2.close();

  return 0;
}
