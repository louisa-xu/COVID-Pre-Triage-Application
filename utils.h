/*
==================================================
Final Project Milestone 5
==================================================
Module : UITLS
Filename : utils.h
Version 1.0
Author	Louisa Xu
Date: 2021-08-02

I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
--------------------------------------------------------------------
*/

#ifndef SDDS_UTILS_H_
#define SDDS_UTILS_H_
#include <iostream>
#include "Time.h"

namespace sdds {
   extern bool debug; // making sdds::debug variable global to all the files
                      // which include: "utils.h"

   int getTime(); // returns the time of day in minutes

   int getInt(const char* prompt = nullptr);   // User entry prompt
   int getInt(int min, int max, const char* prompt = nullptr, const char* errorMessage = nullptr, bool showRangeAtError = true);
   char* getcstr( const char* prompt = nullptr, std::istream& istr = std::cin, char delimiter = '\n');

   template <typename type>
   void removeDynamicElement(type* array[], int index, int& size)
   {
       delete array[index];
       for (int j = index; j < size; j++)
       {
           array[j] = array[j + 1];
       }
       size--;
   }
   
}
#endif // !SDDS_UTILS_H_

