/*
==================================================
Final Project Milestone 5
==================================================
Module : TriagePatient
Filename : TriagePatient.cpp
Version 1.0
Author	Louisa Xu
Date: 2021-08-02

I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
--------------------------------------------------------------------
*/



#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>
#include "TriagePatient.h"

using namespace std;

namespace sdds {
   int nextTriageTicket = 1;

   TriagePatient::TriagePatient(): Patient(nextTriageTicket)
   {
	   m_symptoms = nullptr;
	   nextTriageTicket++;
   }


   TriagePatient::~TriagePatient()
   {
	   delete[] m_symptoms;
   }


   char TriagePatient::type()const
   {
	   return 'T';
   }

   std::ostream& TriagePatient::csvWrite(std::ostream& ostr)const
   {
	   Patient::csvWrite(ostr);
	   ostr << "," << m_symptoms;
	   return ostr;
   }

   std::istream& TriagePatient::csvRead(std::istream& istr)
   {
	   string symptoms;

	   delete[] m_symptoms;
	   m_symptoms = nullptr;

	   Patient::csvRead(istr);
	   istr.ignore();
	   if (getline(istr, symptoms, '\n'))
	   {
		   m_symptoms = new char[symptoms.length() + 1];
		   strcpy(m_symptoms, symptoms.c_str());
	   }
	   nextTriageTicket = number() + 1;

	   return istr;
   }

   std::ostream& TriagePatient::write(std::ostream& ostr)const
   {
	   if (fileIO())
	   {
		   csvWrite(ostr);
	   }
	   else
	   {
		   ostr << "TRIAGE" << endl;
		   Patient::write(ostr) << endl;
		   ostr << "Symptoms: "<<  m_symptoms << endl;
	   }

	   return ostr;
   }


   std::istream& TriagePatient::read(std::istream& istr)
   {
	   string symptoms;

	   if (fileIO())
	   {
		   csvRead(istr);
	   }
	   else
	   {
		   delete[] m_symptoms;
		   m_symptoms = nullptr;

		   Patient::read(istr);
		   cout << "Symptoms: ";
		   if (getline(istr, symptoms, '\n'))
		   {
			   m_symptoms = new char[symptoms.length() + 1];
			   strcpy(m_symptoms, symptoms.c_str());
		   }
	   }

	   return istr;
   }

}