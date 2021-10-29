/*
==================================================
Final Project Milestone 5
==================================================
Module : TriagePatient
Filename : TriagePatient.h
Version 1.0
Author	Louisa Xu
Date: 2021-08-02

I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
--------------------------------------------------------------------
*/


#ifndef SDDS_TRIAGEPATIENT_H_
#define SDDS_TRIAGEPATIENT_H_
#include "Patient.h"

namespace sdds
{

	class TriagePatient : public Patient
	{
		char* m_symptoms;

	public:
		TriagePatient();
		~TriagePatient();
		char type()const;
		std::ostream& csvWrite(std::ostream& ostr)const;
		std::istream& csvRead(std::istream& istr);
		std::ostream& write(std::ostream& ostr)const;
		std::istream& read(std::istream& istr);
	};

}
#endif // !SDDS_TRIAGEPATIENT_H


