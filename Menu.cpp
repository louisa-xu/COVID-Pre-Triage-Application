/*
==================================================
Final Project Milestone 5
==================================================
Module : UITLS
Filename : utils.cpp
Version 1.0
Author	Louisa Xu
Date: 2021-08-02

I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
--------------------------------------------------------------------
*/


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Menu.h"
#include "utils.h"
#include "IOAble.h"

using namespace std;

namespace sdds
{
    void Menu::setEmpty()
    {
        m_text = nullptr;
        m_noOfSel = 0;
    }


    void Menu::display()const
    {
        cout << m_text << endl;
        cout << "0- Exit" << endl;
    }


    Menu::Menu(const char* MenuContent, int NoOfSelections)
    {
        setEmpty();

        if (MenuContent)
        {
            m_text = new char[strlen(MenuContent) + 1];
            strcpy(m_text, MenuContent);
        }
       
        m_noOfSel = NoOfSelections;

    }


    Menu:: ~Menu()
    {
        delete[] m_text;
        m_text = nullptr;
    }


    Menu::Menu(const Menu& M)
    {
        m_text = new char[strlen(M.m_text) + 1];
        strcpy(m_text, M.m_text);
        m_noOfSel = M.m_noOfSel;
    }

    int& Menu::operator>>(int& Selection)
    {
        display();
        Selection = getInt(0, m_noOfSel, "> ", "Invalid option ");

        return Selection;
    }


}