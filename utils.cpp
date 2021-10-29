/*
==================================================
Final Project Milestone 5
==================================================
Module : UITLS
Filename : utils.cpp
Version 1.0
Author	Louisa Xu
Date: 2021-08-02

I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
--------------------------------------------------------------------
*/


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>
#include "utils.h"

using namespace std;
namespace sdds {
   bool debug = true;  // made global in utils.h
   int getTime() {  
      int mins = -1;
      if (debug) {
         Time t(0);
         cout << "Enter current time: ";
         do {
            cin.clear();
            cin >> t;   // needs extraction operator overloaded for Time
            if (!cin) {
               cout << "Invlid time, try agian (HH:MM): ";
               cin.clear();
            }
            else {
               mins = int(t);
            }
            cin.ignore(1000, '\n');
         } while (mins < 0);
      }
      else {
         time_t t = time(NULL);
         tm lt = *localtime(&t);
         mins = lt.tm_hour * 60 + lt.tm_min;
      }
      return mins;
   }


   int getInt(const char* prompt)
   {
       int num;
       bool valid = false;

       if (prompt)
       {
           cout << prompt;
       }

       do
       {
           cin >> num;
 
           if (cin.fail())
           {
               cin.clear();
               cin.ignore(10000, '\n');
               cout << "Bad integer value, try again: ";
           }
           else if (cin.get() != '\n')
           {
               cin.ignore(10000, '\n');
               cout << "Enter only an integer, try again: ";
           }
           else
           {
               valid = true;
           }

       } while (!valid);
      
       return num;
   }


   int getInt(int min, int max, const char* prompt, const char* errorMessage, bool showRangeAtError)
   {
       int num;
       bool valid = false;
       
       if (prompt)
       {
           cout << prompt;
       }

       do
       {
           num = getInt();

           if (num < min || num > max)
           {
               if (errorMessage)
               {
                   if (showRangeAtError)
                   {
                       cout << errorMessage << "[" << min << " <= value <= " << max << "]: ";
                   }
                   else
                   {
                       cout << errorMessage;
                   }
               }
           }
           else
           {
               valid = true;
           }

       } while (!valid);

       return num;
   }



   char* getcstr(const char* prompt, std::istream& istr, char delimiter)
   {
       char* cstring = nullptr;
       string str;

       if (prompt)
       {
           cout << prompt;
       }

       if (getline(istr, str, delimiter))
       {
           cstring = new char[str.length() + 1];
           strcpy(cstring, str.c_str());
       }

       return cstring;
   }

}