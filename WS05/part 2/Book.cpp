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

#include "Book.h"
namespace sdds
{
    // Def Constructor
    Book::Book(){};

    // Custom Constructor
    Book::Book(const std::string &str)
    {
        std::string bookInfo = str;
        size_t start = 0;
        size_t comma = bookInfo.find(',');
        for (size_t i = 0; i < 5 && comma != std::string::npos; ++i)
        {
            std::string attr = bookInfo.substr(start, comma - start);
            trim(attr);

            if (i == 0)
            {
                m_author = attr;
            }
            else if (i == 1)
            {
                m_title = attr;
            }
            else if (i == 2)
            {
                m_country = attr;
            }
            else if (i == 3)
            {
                m_price = std::stod(attr);
            }
            else if (i == 4)
            {
                m_pubYear = std::stoi(attr);
            }
            start = comma + 1;
            comma = bookInfo.find(',', start);
        }
        std::string description = bookInfo.substr(start);
        trim(description);
        m_description = description;
    }

    void Book::trim(std::string &str) const // Taken from my last workshop
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

    // Queries
    const std::string &Book::title() const
    {
        return m_title;
    }

    const std::string &Book::country() const
    {
        return m_country;
    }

    const size_t &Book::year() const
    {
        return m_pubYear;
    }

    // Modifier
    double &Book::price() // not const cause they said modable
    {
        return m_price;
    }

    std::ostream &operator<<(std::ostream &os, const Book &book)
    {
        os << std::right << std::setw(20) << book.m_author << " | ";
        os << std::setw(22) << book.m_title << " | ";
        os << std::setw(5) << book.m_country << " | ";
        os << std::setw(4) << book.m_pubYear << " | ";
        os << std::setw(6) << std::fixed << std::setprecision(2) << book.m_price << " | ";
        os << std::left << book.m_description << std::endl;
        return os;
    }

}