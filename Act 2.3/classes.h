// =================================================================
//
// File: classes.h
// Autores: David René Langarica Hernández - A01708936, Sebastian Flores Lemus - A01709229
// Description: 
//
// Copyright (c) 2022 by Tecnologico de Monterrey.
// All Rights Reserved. May be reproduced for any non-commercial
// purpose.
// =================================================================

#ifndef SHIPREG_H
#define SHIPREG_H

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

using std::cin;
using std::vector;
using std::ifstream;
using std::ofstream;
using std::string;

// Usamos clases para romper el string y usar sus componentes a lo largo de la actividad

/* clase ShipReg tiene tiene los atributos de mes, puerto y ubicacion de cada barco
 Sus metodos son getters que se usan a lo largo del programa 
*/

class ShipReg{
	private:
		int month;
		string entryp;
		string ubi;

	public:
		ShipReg(){};
		ShipReg(int,string,string);

    //getters
		int getMonth(){
			return month;
		};

		string getEntryp(){
			return entryp;
		};

		string getUBI(){
			return ubi;
		};
};

// Constructor de clase ShipReg(int, string, string)

ShipReg::ShipReg(int month_, string encryp_, string ubi_)
{
	month = month_;
	entryp = encryp_;
	ubi = ubi_;
}

/*
 clase month tiene como atributos Mctr, Rctr y dos vectores, separamos los datos basado en el puerto de entrada de cada barco, por esa razon usamos dos vectores de registro diferentes.
En metodos usamos getters ademas de funciones para agregar elementos a los registros, para formato entre otros.
*/


class Month{
	private:
		int num;
    // contadores por puerto
		int Mctr = 0;
		int Rctr = 0;

  //vectores de registro

		vector<ShipReg> sregsM;
		vector<ShipReg> sregsR;

	public:
		Month(int);

    // funcion para sumar al contador de 'M' o 'R' cuando aplique
		void sumCtr(int bdef){
			if (bdef == 0){
				Mctr += 1;
			}
			else if (bdef == 1){
				Rctr += 1;
			}
		};

    // getters
		int getMctr(){
			return Mctr;
		};

		int getRctr(){
			return Rctr;
		};

    // Agregamos elementos al vector de registro (R o M)

		void addSregM(ShipReg sreg_){
			sregsM.push_back(sreg_);
		};

		void addSregR(ShipReg sreg_){
			sregsR.push_back(sreg_);
		};

    // getters

		string getUBIM(int pos){
			return sregsM[pos].getUBI();
		};

		string getUBIR(int pos){
			return sregsR[pos].getUBI();
		};

		int getSregSizeM(){
			return sregsM.size();
		};

		int getSregSizeR(){
			return sregsR.size();
		};

    // formato para imprimir los resultados

		void output(ofstream& out_file){

      // imprime solo si hay mas de una ocurrencia en M
			if(getMctr() > 0){
				out_file << "M " << getMctr() << ": ";

				for (int m = 0; m < getSregSizeM(); m++)
				{
          // imrprimimos en archivo externo
					out_file << getUBIM(m) << " ";
				};

				out_file << '\n';
			}

      // imprime solo si hay mas de una ocurrencia en R
			if(getRctr() > 0){
				out_file << "R " << getRctr() << ": ";

				for (int f = 0; f < getSregSizeR(); f++)
				{
          // imrprimimos en archivo externo
					out_file << getUBIR(f) << " ";
				};

				out_file << '\n';
			}
		};

    // calcula el número de registros para cada puerto y los almacena en un subvector de 'M' o 'R'
		void ports(vector<ShipReg> sreg_vec){
			for (int j = 0; j < sreg_vec.size(); j++){
				
				if (sreg_vec[j].getMonth() == num){

					if (sreg_vec[j].getEntryp() == "M"){
						// Sumar uno al contador de M
						sumCtr(0);
						// Agregar el registro al mes
						addSregM(sreg_vec[j]);
					}
					else if (sreg_vec[j].getEntryp() == "R"){
						sumCtr(1);
						addSregR(sreg_vec[j]);
					}
				}
			}
		};
};

          
// constructor de clase Month

Month::Month(int num_)
{
	num = num_;
};

#endif
