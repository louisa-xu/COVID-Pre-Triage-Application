/*
==================================================
Final Project Milestone 5
==================================================
Module : Time
Filename : time.cpp
Version 1.0
Author	Louisa Xu
Date: 2021-08-02

I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
--------------------------------------------------------------------
*/



#include <iomanip>
#include "Time.h"
#include "utils.h"
using namespace std;
namespace sdds {

    Time& Time::setToNow()
    {
        m_min = getTime();

        return *this;
    }


    Time::Time(unsigned int min)
    {
        m_min = min;
    }


    std::ostream& Time::write(std::ostream& ostr) const
    {
        int hour, min;
        hour = int(m_min / 60);
        min = m_min % 60;

        if (hour < 10)
        {
            ostr.width(2);
            ostr.fill('0');
        }
        ostr << hour << ":" << setw(2) << setfill('0') << min;

        return ostr;
    }


    std::istream& Time::read(std::istream& istr)
    {
        int hour = 0, min = 0;
        char ch = 0;

        istr >> hour >> ch >> min;
        
        if (cin.fail() || hour < 0 || ch != ':' || min < 0)
        {
            istr.setstate(ios::failbit);
        }
        else
        {
            m_min = hour * 60 + min;
        }

        return istr;
    }


    Time& Time::operator-=(const Time& D)
    {
        int factor;

        if (m_min >= D.m_min)
        {
            m_min -= D.m_min;
        }
        else
        {
            factor = int((D.m_min - m_min) / 60 / 24);
            m_min = m_min + (factor + 1) * 24 * 60 - D.m_min;
        }

        return *this;
    }


    Time Time::operator-(const Time& D)const
    {
        Time T;
        int factor;

        if (m_min >= D.m_min)
        {
            T.m_min = m_min - D.m_min;
        }
        else
        {
            factor = int((D.m_min - m_min) / 60 / 24);
            T.m_min = m_min + (factor + 1) * 24 * 60 - D.m_min;
        }

        return T;
    }


    Time& Time::operator+=(const Time& D)
    {
        m_min += D.m_min;

        return *this;
    }


    Time Time::operator+(const Time& D)const
    {
        Time T;

        T.m_min = m_min + D.m_min;

        return T;
    }


    Time& Time::operator=(unsigned int val)
    {
        m_min = val;

        return *this;
    }


    Time& Time::operator *= (unsigned int val)
    {
        m_min *= val;

        return *this;
    }


    Time& Time::operator /= (unsigned int val)
    {
        m_min /= val;

        return *this;
    }


    Time Time::operator *(unsigned int val)const
    {
        Time T;

        T.m_min = m_min * val;

        return T;
    }


    Time Time::operator /(unsigned int val)const
    {
        Time T;

        T.m_min = m_min / val;

        return T;
    }


    Time::operator unsigned int()const
    {
        return m_min;
    }


    Time::operator int()const
    {
        return int(m_min);

    }


    std::ostream& operator<<(std::ostream& ostr, const Time& D)
    {
        D.write(ostr);

        return ostr;
    }


    std::istream& operator>>(std::istream& istr, Time& D)
    {
        D.read(istr);

        return istr;

    }



}