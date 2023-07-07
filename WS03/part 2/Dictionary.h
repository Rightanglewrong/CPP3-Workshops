/*
Workshop 3 Part 2
Name: Benny Yang
Student ID: 112654223
Email: byang68@myseneca.ca
Date: June 3st, 2023
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_DICTIONARY_H
#define SDDS_DICTIONARY_H
#include <iostream>

namespace sdds
{

    class Dictionary
    {
        std::string m_term{};
        std::string m_definition{};

    public:
        const std::string &getTerm() const { return m_term; }
        const std::string &getDefinition() const { return m_definition; }
        Dictionary(const std::string &term, const std::string &definition) : m_term{term}, m_definition{definition} {}

        // Self added
        Dictionary(){};
        bool operator==(const Dictionary &rhs) const;
        bool operator!=(const Dictionary& other) const;
    };
    std::ostream &operator<<(std::ostream &os, const Dictionary &d);
}

#endif