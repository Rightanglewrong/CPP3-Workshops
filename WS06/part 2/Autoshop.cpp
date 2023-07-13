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
#include "Autoshop.h"

namespace sdds
{
    Autoshop &Autoshop::operator+=(Vehicle *theVehicle)
    {
        m_vehicles.push_back(theVehicle);
        return *this;
    }

    void Autoshop::display(std::ostream& out) const {
		out << "--------------------------------" << std::endl;
		out << "| Cars in the autoshop!        |" << std::endl;
		out << "--------------------------------" << std::endl;
		for (const auto vehicle : m_vehicles)
		{
			vehicle->display(out);
			out << std::endl;
		}
		out << "--------------------------------" << std::endl;
	}

    Autoshop::~Autoshop() {
		for (const auto vehicle : m_vehicles)
		{
			delete vehicle;
		}
	}


}