/*
Workshop 3 Part 2
Name: Benny Yang
Student ID: 112654223
Email: byang68@myseneca.ca
Date: June 3st, 2023
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
#include "Dictionary.h"

namespace sdds
{
    bool Dictionary::operator==(const Dictionary &rhs) const
    {
        return m_term == rhs.m_term && m_definition == rhs.m_definition;
    }

    bool Dictionary::operator!=(const Dictionary& rhs) const
    {
        return !(*this == rhs);
    }

    std::ostream &operator<<(std::ostream &os, const Dictionary &d)
    {
        os << std::setw(20) << std::right << d.getTerm();
        os << std::left << ": " << d.getDefinition();
        return os;
    }
}