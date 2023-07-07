/*
Workshop 5 Part 2
Name: Benny Yang
Student ID: 112654223
Email: byang68@myseneca.ca
Date: June 17st, 2023
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_SPELLCHECKER_H
#define SDDS_SPELLCHECKER_H

#include <iostream>

namespace sdds
{
    class SpellChecker // functor
    {
    private:
        std::string m_badWords[6]{};
        std::string m_goodWords[6]{};
        size_t m_count[6]{};

    public:
        SpellChecker(const char *filename);
        void operator()(std::string &text);
        void showStatistics(std::ostream &out) const;
    };
}

#endif