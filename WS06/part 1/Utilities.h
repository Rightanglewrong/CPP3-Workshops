/*
Workshop 6 Part 1
Name: Benny Yang
Student ID: 112654223
Email: byang68@myseneca.ca
Date: July 8th, 2023
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H
#include <iostream>

#include "Vehicle.h"
namespace sdds
{
    Vehicle* createInstance(std::istream& in);
}

#endif