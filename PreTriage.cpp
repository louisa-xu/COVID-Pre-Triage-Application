/*
==================================================
Final Project Milestone 5
==================================================
Module : PreTriage
Filename : PreTriage.cpp
Version 1.0
Author	Louisa Xu
Date: 2021-08-02

I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
--------------------------------------------------------------------
*/

#define _CRT_SECURE_NO_WARNINGS
#include "PreTriage.h"
#include <iostream>
#include <fstream>
#include <cstring>


using namespace std;

namespace sdds
{
	PreTriage::PreTriage(const char* dataFilename) : m_averCovidWait(15), m_averTriageWait(5), m_appMenu("General Hospital Pre-Triage Application\n1- Register\n2- Admit", 2),
		m_pMenu("Select Type of Admittance:\n1- Covid Test\n2- Triage", 2)
	{
		if (dataFilename)
		{
			delete[] m_dataFilename;
			m_dataFilename = nullptr;
			m_dataFilename = new char[strlen(dataFilename) + 1];
			strcpy(m_dataFilename, dataFilename);
		}
		load();
	}


	PreTriage::~PreTriage()
	{
		ofstream fout(m_dataFilename);

		if (fout.is_open())
		{
			cout << "Saving Average Wait Times," << endl;
			cout << "   COVID Test: " << m_averCovidWait << endl;
			cout << "   Triage: " << m_averTriageWait << endl;
			fout << m_averCovidWait << "," << m_averTriageWait << endl;
			cout << "Saving m_lineup..." << endl;

			for (int i = 0; i < m_lineupSize; i++)
			{
				m_lineup[i]->fileIO(true);
				m_lineup[i]->write(fout) << endl;
				cout << (i + 1) << "- ";
				m_lineup[i]->write(cout) << endl;
				delete m_lineup[i];
			}

		}

		delete[] m_dataFilename;

		cout << "done!" << endl;
		fout.close();
	}


	const Time PreTriage::getWaitTime(const Patient& p)const
	{
		int i;
		unsigned int count = 0;
		Time waitTime;

		for (i = 0; i < m_lineupSize; i++)
		{
			if (m_lineup[i]->type() == p.type())
			{
				count++;
			}

		}

		if (p.type() == 'C')
		{
			waitTime = count * (unsigned int)(m_averCovidWait);
		}
		else if (p.type() == 'T')
		{
			waitTime = count * (unsigned int)(m_averCovidWait);
		}

		return Time(waitTime);
	}


	void PreTriage::setAverageWaitTime(const Patient& p)
	{
		if (p.type() == 'C')
		{
			m_averCovidWait = ((getTime() - (unsigned int)(Time(p))) + (unsigned int)(m_averCovidWait) * (p.number() - 1)) / p.number();
		}
		else if (p.type() == 'T')
		{
			m_averTriageWait = ((getTime() - (unsigned int)(Time(p))) + (unsigned int)(m_averTriageWait) * (p.number() - 1)) / p.number();
		}

	}


	void PreTriage::removePatientFromLineup(int index)
	{
		removeDynamicElement(m_lineup, index, m_lineupSize);
	}


	int PreTriage::indexOfFirstInLine(char type) const
	{
		int match = -1;
		bool found = false;

		for (int i = 0; !found && i < m_lineupSize; i++)
		{
			if (m_lineup[i]->type() == type)
			{
				match = i;
				found = true;
			}
		}

		return match;
	}

	void PreTriage::load()
	{
		Patient* p = nullptr;
		int i = 0;
		char ch;

		cout << "Loading data..." << endl;
		ifstream fin(m_dataFilename);

		if (fin.is_open())
		{
			fin >> m_averCovidWait;
			fin.ignore();
			fin >> m_averTriageWait;
			fin.ignore();

			while (i < maxNoOfPatients && fin >> ch)
			{
				fin.ignore();
				if (ch == 'C')
				{
					p = new CovidPatient();
				}
				else if (ch == 'T')
				{
					p = new TriagePatient();
				}

				if (p)
				{
					p->fileIO(true);
					p->csvRead(fin);
					p->fileIO(false);
					m_lineup[i] = p;
					m_lineupSize++;
				}

				i++;
			}

			if (!fin.eof())
			{
				cout << "Warning: number of records exceeded 100" << endl;
				cout << m_lineupSize << " Records imported..." << endl << endl;
			}
			else if (m_lineupSize == 0)
			{
				cout << "No data or bad data file!" << endl << endl;
			}
			else
			{
				cout << m_lineupSize << " Records imported..." << endl << endl;
			}

		}
		else
		{
			cout << "File cannot be opened." << endl;
		}
	}



	void PreTriage::reg()
	{
		int selection = -1;

		if (m_lineupSize >= 100)
		{
			cout << "Line up full!" << endl;
		}
		else
		{
			m_pMenu >> selection;

			switch (selection)
			{
			case 0:
				break;

			case 1:
				m_lineup[m_lineupSize] = new CovidPatient();
				break;

			case 2:
				m_lineup[m_lineupSize] = new TriagePatient();
				break;
			}

			if (m_lineup[m_lineupSize])
			{
				m_lineup[m_lineupSize]->setArrivalTime();
				cout << "Please enter patient information: " << endl;
				m_lineup[m_lineupSize]->fileIO(false);
				m_lineup[m_lineupSize]->read(std::cin);
				cout << "\n******************************************" << endl;
				m_lineup[m_lineupSize]->write(cout);
				cout << "Estimated Wait Time: " << getWaitTime(*m_lineup[m_lineupSize]) << endl;
				cout << "******************************************" << endl << endl;
				m_lineupSize++;
			}
		}
	}


	void PreTriage::admit()
	{
		int selection = -1, found = -1;
		char type = 0;

		m_pMenu >> selection;

		switch (selection)
		{
		case 0:
			break;

		case 1:
			type = 'C';
			break;

		case 2:
			type = 'T';
			break;
		}

		found = indexOfFirstInLine(type);

		if (found != -1)
		{
			cout << "\n******************************************" << endl;
			m_lineup[found]->fileIO(false);
			cout << "Calling for ";
			m_lineup[found]->write(cout);
			cout << "******************************************" << endl << endl;
			setAverageWaitTime(*m_lineup[found]);
			removePatientFromLineup(found);
		}

	}


	void PreTriage::run(void)
	{
		int selection = -1;

		do
		{
			m_appMenu >> selection;

			switch (selection)
			{
			case 0:
				break;

			case 1:
				reg();
				break;

			case 2:
				admit();
				break;
			}
		} while (selection != 0);

	}






}