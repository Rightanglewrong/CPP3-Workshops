/*
Workshop 1
Name: Benny Yang
Student ID: 112654223
Email: byang68@myseneca.ca
Date: May 16th, 2023
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*/

#include <iostream>
#include <fstream>
#include <iomanip>

#include "carads.h"
using namespace std;

double g_taxrate;
double g_discount;

namespace sdds
{
    Cars::Cars()
    {
        m_brand[0] = '\0';
        m_model[0] = '\0';
        m_year = 0;
        m_price = 0.0;
        m_status = '\0';
        m_onPromo = false;
    }

    void Cars::read(std::istream &is)
    {
        if (is.good())
        {
            char isSale;
            is >> m_status;
            is.ignore();
            is.getline(m_brand, 11, ',');
            is.getline(m_model, 16, ',');
            is >> m_year;
            is.ignore();
            is >> m_price;
            is.ignore();
            is >> isSale;
            if (isSale == 'Y')
            {
                m_onPromo = true;
            }
            else
            {
                m_onPromo = false;
            }
            is.ignore();
        }
    }

    void Cars::display(bool reset) const
    {
        static int counter = 1;
        if (reset)
        {
            counter = 1;
        }

        if (m_brand[0] == '\0')
        {
            cout << setw(2) << left << counter << ". No Car";
        }
        else
        {

            cout << setw(2) << left << counter << ". ";
            cout << setw(10) << m_brand << "| ";
            cout << setw(15) << m_model << "| ";
            cout << setw(4) << m_year << " |";
            cout << fixed << setw(12) << setprecision(2) << right << m_price * (1 + g_taxrate) << "|";
            if (m_onPromo)
            {
                cout << setw(12) << right << m_price * (1 + g_taxrate) * (1 - g_discount);
            }
            ++counter;
        }
        cout << endl;
    }

    char Cars::getStatus() const
    {
        return m_status;
    }

    void listArgs(int argc, char *argv[])
    {
        cout << "Command Line:" << endl;
        cout << "--------------------------" << endl;
        for (int i = 0; i < argc; i++)
        {
            cout << "  " << i + 1 << ": " << argv[i] << endl;
        }
        cout << "--------------------------\n"
             << endl;
    }
}