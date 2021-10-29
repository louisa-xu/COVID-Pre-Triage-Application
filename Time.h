/*
==================================================
Final Project Milestone 5
==================================================
Module : Time
Filename : time.h
Version 1.0
Author	Louisa Xu
Date: 2021-08-02

I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
--------------------------------------------------------------------
*/

#ifndef SDDS_TIME_H_
#define SDDS_TIME_H_
#include <iostream>
namespace sdds {
   class Time {
      unsigned int m_min;
   public:
      Time& setToNow();
      Time(unsigned int min = 0);
      std::ostream& write(std::ostream& ostr) const;
      std::istream& read(std::istream& istr);

      Time& operator-=(const Time& D);
      Time operator-(const Time& D)const;
      Time& operator+=(const Time& D);
      Time operator+(const Time& D)const;

      Time& operator=(unsigned int val);
      Time& operator *= (unsigned int val);
      Time& operator /= (unsigned int val);
      Time operator *(unsigned int val)const;
      Time operator /(unsigned int val)const;

      operator unsigned int()const;
      operator int()const;
   };
   std::ostream& operator<<(std::ostream& ostr, const Time& D);
   std::istream& operator>>(std::istream& istr, Time& D);
}

#endif // !SDDS_TIME_H_

