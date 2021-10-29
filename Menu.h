/*
==================================================
Final Project Milestone 5
==================================================
Module : Menu
Filename : Menu.cpp
Version 1.0
Author	Louisa Xu
Date: 2021-08-02

I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
--------------------------------------------------------------------
*/


#ifndef SDDS_MENU_H_
#define SDDS_MENU_H_
#include <iostream>
namespace sdds
{

    class Menu
    {
        char* m_text; 
        int m_noOfSel; 
        void setEmpty();
        void display()const;

    public:
        Menu(const char* MenuContent, int NoOfSelections);
        Menu(const Menu& M);
        Menu& operator=(const Menu& M) = delete;
        virtual ~Menu();
        int& operator>>(int& Selection);
    };


}


#endif 