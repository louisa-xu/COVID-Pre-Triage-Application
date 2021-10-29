/*
==================================================
Final Project Milestone 5
==================================================
Module : Patient
Filename : Patient.cpp
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
#include "Patient.h"
#include "Ticket.h"
#include "utils.h"

using namespace std;

namespace sdds
{
	Patient::Patient(int ticketNum, bool flag) : m_ticket(ticketNum)
	{
		m_name = nullptr;
		m_ohipNum = 0;
		csv = flag;
	}

	Patient::~Patient()
	{
		delete[] m_name;
	}

	bool Patient::fileIO()const
	{
		return csv;
	}

	void Patient::fileIO(bool flag)
	{
		csv = flag;
	}

	bool Patient::operator==(char ch)const
	{
		return type() == ch;
	}

	bool Patient::operator==(const Patient& P)const
	{
		return type() == P.type();
	}


	void Patient::setArrivalTime()
	{
		m_ticket.resetTime();
	}


	Patient::operator Time()const
	{
		return Time(m_ticket);

	}


	int Patient::number()const
	{
		return m_ticket.number();

	}

	std::ostream& Patient::csvWrite(std::ostream& ostr) const
	{
		ostr << type() << "," << m_name << "," << m_ohipNum << "," ;
		m_ticket.csvWrite(ostr);
		return ostr;
	}

	std::istream& Patient::csvRead(std::istream& istr)
	{
		string name;
		delete[] m_name;
		m_name = nullptr;

		if (getline(istr, name, ','))
		{
			m_name = new char[name.length() + 1];
			strcpy(m_name, name.c_str());
		}
		istr >> m_ohipNum;
		istr.ignore();
		m_ticket.csvRead(istr);
		return istr;
	}

	std::ostream& Patient::write(std::ostream& ostr) const
	{
		char name[26];
		strncpy(name, m_name, 25);
		name[25] = '\0';
		m_ticket.write(ostr) << endl;
		ostr << name << ", OHIP: " << m_ohipNum;
		return ostr;
	}

	std::istream& Patient::read(std::istream& istr)
	{
		string name;
		delete[] m_name;
		m_name = nullptr;

		cout << "Name: ";
		getline(istr, name, '\n');

		m_name = new char[name.length() + 1];
		strcpy(m_name, name.c_str());

		cout << "OHIP: ";
		m_ohipNum = getInt(100000000, 999999999, nullptr, "Invalid OHIP Number, ", true);

		return istr;
	}

	




}