/*
Workshop 6 Part 1
Name: Benny Yang
Student ID: 112654223
Email: byang68@myseneca.ca
Date: July 8th, 2023
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*/
#include <iostream>
#include "Utilities.h"
#include "Car.h"
namespace sdds
{
    Vehicle* createInstance(std::istream& in) {
        char tag;
        Vehicle* temp{};
        in >> tag;
        if (in.good())
        {
            if (tag == 'c' || tag == 'C') {
               temp =  new Car(in);
               return temp;
            }
        }
        return nullptr;
	}
}