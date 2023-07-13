/*
Workshop 6 Part 2
Name: Benny Yang
Student ID: 112654223
Email: byang68@myseneca.ca
Date: July 9th, 2023
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_AUTOSHOP_H
#define SDDS_AUTOSHOP_H

#include <iostream>
#include <vector>
#include <list>

#include "Vehicle.h"

namespace sdds
{
    class Autoshop
    {
        std::vector<Vehicle *> m_vehicles{};

    public:
        Autoshop &operator+=(Vehicle *theVehicle);

        void display(std::ostream &out) const;
        ~Autoshop();

        template <typename T>
        void select(T test, std::list<const Vehicle *> &vehicles)
        {
            for (const auto &vehicle : m_vehicles)
            {
                if (test(vehicle))
                {
                    vehicles.push_back(vehicle);
                }
            }
        }
    };
}
#endif