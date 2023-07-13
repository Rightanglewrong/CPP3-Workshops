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
#include "Utilities.h"
#include "Car.h"
#include "Racecar.h"
namespace sdds
{
    Vehicle *createInstance(std::istream &in)
    {
        char tag;
        Vehicle *temp{};
        in >> tag;
        if (in.good())
        {
            if (tag == 'c' || tag == 'C')
            {
                temp = new Car(in);
                return temp;
            }
            else if (tag == 'r' || tag == 'R')
            {
                temp = new Racecar(in);
                return temp;
            }
            else
            {
                throw std::invalid_argument("Unknown vehicle type in the record");
            }
        }
        return nullptr;
    }
}