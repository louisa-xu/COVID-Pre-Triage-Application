/*
==================================================
Final Project Milestone 5
==================================================
Module : CovidPatient
Filename : CovidPatient.cpp
Version 1.0
Author	Louisa Xu
Date: 2021-08-02

I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
--------------------------------------------------------------------
*/


#include <iostream>
#include "CovidPatient.h"
using namespace std;

namespace sdds {
   int nextCovidTicket = 1;

   CovidPatient::CovidPatient() : Patient(nextCovidTicket)
   {
	   nextCovidTicket++;
   }
	  
   char  CovidPatient::type()const
   {
	   return 'C';
   }

   std::istream& CovidPatient::csvRead(std::istream& istr)
   {
	   Patient::csvRead(istr);
	   istr.ignore();
	   nextCovidTicket = number() + 1;
	   return istr;
   }

   std::ostream& CovidPatient::write(std::ostream& ostr) const
   {
	   if (fileIO())
	   {
		   Patient::csvWrite(ostr);
	   }
	   else
	   {
		   ostr << "COVID TEST" << endl;
		   Patient::write(ostr) << endl;
	   }

	   return ostr;
   }

   std::istream& CovidPatient::read(std::istream& istr)
   {
	   if (fileIO())
	   {
		   csvRead(istr);
	   }
	   else
	   {
		   Patient::read(istr);
	   }

	   return istr;
   }

}