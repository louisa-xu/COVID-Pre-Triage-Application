/*
==================================================
Final Project Milestone 5
==================================================
Module : IOAble
Filename : IOAble.cpp
Version 1.0
Author	Louisa Xu
Date: 2021-08-02

I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
--------------------------------------------------------------------
*/


#include <iostream>
#include "utils.h"
#include "IOAble.h"



namespace sdds
{
	IOAble::~IOAble()
	{ }


	std::ostream& operator << (std::ostream& ostr, const IOAble& O)
	{
		O.write(ostr);
		return ostr;
	}

	std::istream& operator >> (std::istream& istr, IOAble& I)
	{
		I.read(istr);
		return istr;
	}


}