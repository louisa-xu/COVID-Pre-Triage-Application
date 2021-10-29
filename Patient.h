/*
==================================================
Final Project Milestone 5
==================================================
Module : Patient
Filename : Patient.h
Version 1.0
Author	Louisa Xu
Date: 2021-08-02

I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
--------------------------------------------------------------------
*/

#ifndef SDDS_PATIENT_H_
#define SDDS_PATIENT_H_
#include "IOAble.h"
#include "Ticket.h"

namespace sdds
{
    class Patient :public IOAble
    {
        char* m_name;
        int m_ohipNum;
        Ticket m_ticket;

    public:
        bool csv;
        Patient(int ticketNum = 0, bool csv = false);
        Patient(const Patient& P) = delete;
        Patient& operator=(const Patient& p) = delete;
        ~Patient();

        virtual char type()const = 0;
        bool fileIO()const;
        void fileIO(bool flag);
        bool operator==(char ch)const;
        bool operator==(const Patient& P)const;
        void setArrivalTime();
        operator Time()const;
        int number()const;
          
        std::ostream& csvWrite(std::ostream& ostr)const;
        std::istream& csvRead(std::istream& istr);
        std::ostream& write(std::ostream& ostr)const;
        std::istream& read(std::istream& istr);
    };
}







#endif