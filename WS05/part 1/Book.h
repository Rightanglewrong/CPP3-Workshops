/*
Workshop 5 Part 1
Name: Benny Yang
Student ID: 112654223
Email: byang68@myseneca.ca
Date: June 16st, 2023
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H

#include <iostream>

namespace sdds
{
    class Book
    {
    private:
        std::string m_author{};
        std::string m_title{};
        std::string m_country{};
        size_t m_pubYear{};
        double m_price{};
        std::string m_description{};

        void trim(std::string &str) const;

    public:
        // COnstructors
        Book();
        Book(const std::string &str);
        // Queries
        const std::string &title() const;
        const std::string &country() const;
        const size_t &year() const;

        // Modable Query
        double &price();

        // Helper
        friend std::ostream &operator<<(std::ostream &os, const Book &book);
    };
}

#endif