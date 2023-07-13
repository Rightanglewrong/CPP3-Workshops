/*
Workshop 6 Part 2
Name: Benny Yang
Student ID: 112654223
Email: byang68@myseneca.ca
Date: July 9th, 2023
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_CAR_H
#define SDDS_CAR_H
#include <iostream>
#include "Vehicle.h"

namespace sdds
{
    class Car : public Vehicle
    {
        std::string m_maker{};
        char m_condition{};
        double m_topSpeed{};

    public:
        Car() = default;
        Car(std::istream &is);
        ~Car() = default;

        std::string condition() const;         // query
        double topSpeed() const;               // query
        void display(std::ostream &out) const; // query

        void trim(std::string &str);
    };

} // namespace sdds

#endif