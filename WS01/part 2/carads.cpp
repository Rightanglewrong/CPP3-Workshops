/*
Workshop 1 Part 2
Name: Benny Yang
Student ID: 112654223
Email: byang68@myseneca.ca
Date: May 18th, 2023
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <string>

#include "carads.h"
using namespace std;

double g_taxrate;
double g_discount;

namespace sdds
{
    // Constructors
    Cars::Cars()
    {
        m_brand = nullptr; // changed to set brand to nullptr
        m_model[0] = '\0';
        m_year = 0;
        m_price = 0.0;
        m_status = '\0';
        m_onPromo = false;
    }

    // Created to implement rule of 3
    Cars::Cars(const Cars &other)
    {
        m_brand = nullptr;
        *this = other;
    }

    Cars &Cars::operator=(const Cars &other)
    {
        if (this != &other)
        {
            delete[] m_brand;
            m_brand = nullptr;
            if (other.m_brand != nullptr)
            {
                m_brand = new char[strlen(other.m_brand) + 1];
                strcpy(m_brand, other.m_brand);
            }
            strcpy(m_model, other.m_model);
            m_year = other.m_year;
            m_price = other.m_price;
            m_status = other.m_status;
            m_onPromo = other.m_onPromo;
        }

        return *this;
    }

    Cars::~Cars()
    {
        delete[] m_brand;
        m_brand = nullptr;
    }

    // read edited to match m_brand change
    void Cars::read(std::istream &is)
    {
        if (is.good())
        {
            char isSale;
            string brand;
            is >> m_status;
            is.ignore();
            getline(is, brand,',');
            delete [] m_brand;
            m_brand = new char[brand.length() + 1];
            strcpy(m_brand, brand.c_str());
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

    Cars::operator bool() const
    {
        return m_status == 'N';
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

    std::istream &operator>>(std::istream &is, Cars &car)
    {
        car.read(is);
        return is;
    }

    void operator>>(const Cars &car1, Cars &car2)
    {
        car2 = car1;
    }
}