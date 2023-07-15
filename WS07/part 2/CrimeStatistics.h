/*
Workshop 7 Part 2
Name: Benny Yang
Student ID: 112654223
Email: byang68@myseneca.ca
Date: July 14th, 2023
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_CRIMESTATISTICS_H
#define SDDS_CRIMESTATISTICS_H
#include <iostream>
#include <string>
#include <vector>
#include <list>

namespace sdds
{
    struct Crime
    {
        std::string s_province{};
        std::string s_district{};
        std::string s_crime{};
        int s_numCases;
        int s_year;
        int m_resolved;
    };

    class CrimeStatistics
    {
    private:
        std::vector<Crime> crimes;

    public:
        CrimeStatistics(const std::string &fileName);
        void trim(std::string &str);
        void display(std::ostream &out) const;

        void sort(const std::string &field);
        void cleanList();
        bool inCollection(const std::string &crime) const;
        std::list<Crime> getListForProvince(const std::string &province) const;
    };
    std::ostream &operator<<(std::ostream &out, const Crime &theCrime);
}

#endif