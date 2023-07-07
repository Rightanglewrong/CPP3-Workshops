/*
Workshop 5 Part 2
Name: Benny Yang
Student ID: 112654223
Email: byang68@myseneca.ca
Date: June 17st, 2023
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*/

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <iomanip>

#include "SpellChecker.h"

namespace sdds
{
    SpellChecker::SpellChecker(const char *filename)
    {
        std::ifstream file(filename);
        if (!file)
        {
            throw "Bad file name!";
        }

        std::string line;
        size_t index = 0;
        while (std::getline(file, line) && index < 6)
        {
            size_t delim = line.find(' ');
            std::string badWord = line.substr(0, delim);
            delim = line.find_last_of(' ');
            std::string goodWord = line.substr(delim + 1);

            m_badWords[index] = badWord;
            m_goodWords[index] = goodWord;
            ++index;
        }
        file.close();
    }

    void SpellChecker::operator()(std::string &text)
    {
        for (size_t i = 0; i < 6; i++)
        {
            size_t index = 0;
            index = text.find(m_badWords[i]);
            while (index != std::string::npos)
            {
                text.replace(index, m_badWords[i].length(), m_goodWords[i]);
                m_count[i]++;
                index = text.find(m_badWords[i], index + 1);
            }
        }
    }

    void SpellChecker::showStatistics(std::ostream &out) const
    {
        out << "Spellchecker Statistics" << std::endl;
        for (size_t i = 0; i < 6; ++i)
        {
            out << std::right << std::setw(15) << m_badWords[i] << ": " << m_count[i] << " replacements" << std::endl;
        }
    }
}