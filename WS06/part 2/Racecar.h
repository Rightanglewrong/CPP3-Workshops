/*
Workshop 6 Part 2
Name: Benny Yang
Student ID: 112654223
Email: byang68@myseneca.ca
Date: July 9th, 2023
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_RACECAR_H
#define SDDS_RACECAR_H
#include <iostream>

#include "Car.h"
namespace sdds
{
    class Racecar : public Car
    {
        double m_booster{};
    public:
        Racecar(std::istream &in);
        void display(std::ostream &out) const;
        double topSpeed() const;
    };
}

#endif