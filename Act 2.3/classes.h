// =================================================================
//
// File: classes.h
// Autores: David René Langarica Hernández - A01708936, Sebastian Flores Lemus - A01709229
// Description: Archivo de clases empleadas para el funcionamiento del programa
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

class ShipReg{
	private:
		int month;
		string entryp;
		string ubi;

	public:
		ShipReg(){};
		ShipReg(int,string,string);

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

ShipReg::ShipReg(int month_, string encryp_, string ubi_)
{
	month = month_;
	entryp = encryp_;
	ubi = ubi_;
}

class Month{
	private:
		int num;
		int Mctr = 0;
		int Rctr = 0;
		vector<ShipReg> sregsM;
		vector<ShipReg> sregsR;

	public:
		Month(int);

		void sumCtr(int bdef){
			if (bdef == 0){
				Mctr += 1;
			}
			else if (bdef == 1){
				Rctr += 1;
			}
		};

		int getMctr(){
			return Mctr;
		};

		int getRctr(){
			return Rctr;
		};

		void addSregM(ShipReg sreg_){
			sregsM.push_back(sreg_);
		};

		void addSregR(ShipReg sreg_){
			sregsR.push_back(sreg_);
		};

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

		void output(ofstream& out_file){

			if(getMctr() > 0){
				out_file << "M " << getMctr() << ": ";

				for (int m = 0; m < getSregSizeM(); m++)
				{
					out_file << getUBIM(m) << " ";
				};

				out_file << '\n';
			}

			if(getRctr() > 0){
				out_file << "R " << getRctr() << ": ";

				for (int f = 0; f < getSregSizeR(); f++)
				{
					out_file << getUBIR(f) << " ";
				};

				out_file << '\n';
			}
		};

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

Month::Month(int num_)
{
	num = num_;
};

#endif