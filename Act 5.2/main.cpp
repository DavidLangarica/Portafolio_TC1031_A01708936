// =================================================================
//
// File: main.cpp
// Autores: David René Langarica Hernández - A01708936, Sebastian Flores Lemus - A01709229
// Date: 01/12/2022
//
// =================================================================
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int main(int argc, char* argv[]) {

  // creamos archivo de input y output
  ifstream archivo1(argv[1]); 
  ofstream archivo2(argv[2]);

  // usamos unordered_map para hacer el hash
	unordered_map<string, int> hash;

  // palabras diccionario es el numero a buscar
  // descripcion_puestos es el segundo numero leido del archivo
  // valor_dolares es el numero que se suma al total
  int palabras_diccionario, descripciones_puestos, valor_dolares;
  
  // palabra es la key antes del valor
  // descripcion_puesto son los parrafos que seran leidos
  string palabra, descripcion_puesto;

  // lectura de datos del archivo input
	archivo1 >> palabras_diccionario >> descripciones_puestos;

  // leemos e insertamos los datos al hash con 'insert'
	for (int i = 0; i < palabras_diccionario; i++)
	{
		archivo1 >> descripcion_puesto >> valor_dolares;

    // andimos key, value al map
    hash.insert(make_pair(descripcion_puesto,valor_dolares));
	}

   while (descripciones_puestos--){
		int suma_total = 0;

		while (archivo1 >> descripcion_puesto){
      // rompemos la lectura cuando encontramos un cambio de parrafo, en este caso separado por un punto
  		if (descripcion_puesto == ".")
  		break;

      // hacemos la suma
  		suma_total += hash[descripcion_puesto];
  	}

     // imprimimos resultado al archivo output
  	archivo2 << suma_total << endl;
    }

  archivo1.close();
  archivo2.close();
  
	return 0;
}

