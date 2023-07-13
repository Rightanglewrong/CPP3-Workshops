/*
Workshop 6 Part 2
Name: Benny Yang
Student ID: 112654223
Email: byang68@myseneca.ca
Date: July 9th, 2023
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*/
#include <iostream>
#include <sstream>
#include <iomanip>

#include "Racecar.h"

namespace sdds
{
    Racecar::Racecar(std::istream &in) : Car(in)
    {
        in.ignore(1000, ',');
        in >> m_booster;
    }

    void Racecar::display(std::ostream &out) const
    {
        Car::display(out);
        out << "*";
    }

    double Racecar::topSpeed() const
    {
        return Car::topSpeed() * (1 + m_booster);
    }
}