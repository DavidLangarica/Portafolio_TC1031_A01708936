// =================================================================
//
// File: funciones.h
// Autores: David René Langarica Hernández - A01708936, Sebastian Flores Lemus - A01709229
// Description: This file contains the functions searchPrefix which will call a 3 character code of the ship, and sortRegister which sorts the ships with the desired Prefix by month. Both functions are called in main.cpp.
//
// Copyright (c) 2020 by Tecnologico de Monterrey.
// All Rights Reserved. May be reproduced for any non-commercial
// purpose.
// =================================================================

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// =================================================================
// Performs the SearchPrefix function.
//
// @param str, every string in file input starting in line 2.
// @param term, the prefix or code we want to filter from the list.
// complexity: O(1) since we do not have any loops, nor recursion, the time complexity will be linear. Which is optimal in terms of time and memory.
// =================================================================

int SearchPrefix(string str, string term)
{
    int index;
    index = str.rfind(term);
    return index;
}

// =================================================================
// Performs the sortRegister algorithm.
//
// @param regsitro, a vector with the elements that include the desired key or prefix type string which will be sorted by the month.
// complexity: O(n) since we have while loops that are not nested.
// =================================================================

vector<string> sortRegister(vector<string> registro){

// =================================================================
// Sort: Predetermined function that sorts our vector.
//
// @param regsitro.begin, the beginning of the vector<string> registro, starting point.
// @param regsitro.end, the end of the vector<string> registro, ending point.
  // @param string a, string b, are the elements being compared between each other.
// complexity: Best Case – O(N log N) when applied to a range of N elements
// Average Case – O(N log N) when applied to a range of N elements
// Worst-Case – O(N log N) when applied to a range of N elements
// =================================================================
  
    sort(registro.begin(), registro.end(), [](string a, string b){
      
      string point;
		  size_t position = 0;
		  string mark_delimiter = "-";

      // 
      vector<string> compare_a;
      vector<string> compare_b;
      
		  while ((position = a.find(mark_delimiter)) != string::npos) {
			  point = a.substr(0, position);
			  compare_a.push_back(point);
			  a.erase(0, position + mark_delimiter.length());
		  }
		  compare_a.push_back(a);
      
		  while ((position = b.find(mark_delimiter)) != string::npos) {
			  point = b.substr(0, position);
			  compare_b.push_back(point);
			  b.erase(0, position + mark_delimiter.length());
		  }
      
		  compare_b.push_back(b);
		  return pair<string, string>(compare_a[1], compare_a[0]) < 
		  pair<string, string>(compare_b[1], compare_b[0]); 
    });
  
    return registro;
}