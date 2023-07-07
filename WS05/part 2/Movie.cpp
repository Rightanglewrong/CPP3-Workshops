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
#include <string>
#include <iomanip>
#include "Movie.h"

using namespace sdds;
namespace sdds
{
    // Constructor
    Movie::Movie(const std::string &strMovie)
    {
        std::string movieInfo = strMovie;
        size_t start = 0;
        size_t comma = movieInfo.find(',');
        for (size_t i = 0; i < 2 && comma != std::string::npos; ++i)
        {
            std::string attr = movieInfo.substr(start, comma - start);
            trim(attr);
            if (i == 0)
            {
                m_mTitle = attr;
            }
            else if (i == 1)
            {
                m_releaseYear = std::stoi(attr);
            }
            start = comma + 1;
            comma = movieInfo.find(',', start);
        }
        std::string description = movieInfo.substr(start);
        trim(description);
        m_mDescription = description;
    }

    void Movie::trim(std::string &str) const // Taken from my last workshop
    {
        // Trim leading whitespaces
        size_t start = 0;
        while (start < str.length() && std::isspace(str[start]))
        {
            start++;
        }
        str = str.substr(start);

        // Trim trailing whitespaces
        size_t end = str.length() - 1;
        while (end > 0 && std::isspace(str[end]))
        {
            end--;
        }
        str = str.substr(0, end + 1);
    }
    // QUery
    const std::string &Movie::title() const
    {
        return m_mTitle;
    }

    // FRIEND
    std::ostream &operator<<(std::ostream &os, const Movie &m)
    {
        os << std::right << std::setw(40) << m.m_mTitle << " | ";
        os << std::setw(4) << m.m_releaseYear << " | ";
        os << std::left << m.m_mDescription << std::endl;
        return os;
    }

}