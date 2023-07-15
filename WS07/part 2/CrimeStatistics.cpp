/*
Workshop 7 Part 2
Name: Benny Yang
Student ID: 112654223
Email: byang68@myseneca.ca
Date: July 14th, 2023
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
#include <list>
#include <algorithm>

#include "CrimeStatistics.h"

namespace sdds
{
    CrimeStatistics::CrimeStatistics(const std::string &fileName)
    {
        std::ifstream file(fileName);
        if (!file.is_open())
        {
            throw std::runtime_error("Failed to open file");
        }

        std::string line;
        while (std::getline(file, line))
        {
            Crime crime;
            crime.s_province = line.substr(0, 25);
            crime.s_district = line.substr(25, 25);
            crime.s_crime = line.substr(50, 25);
            crime.s_year = std::stoi(line.substr(75, 5));
            crime.s_numCases = std::stoi(line.substr(80, 5));
            crime.m_resolved = std::stoi(line.substr(85, 5));

            // Trim leading and trailing spaces
            trim(crime.s_province);
            trim(crime.s_district);
            trim(crime.s_crime);

            crimes.push_back(crime);
        }
    }

    void CrimeStatistics::trim(std::string &str) // Taken from my last workshop
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

    void CrimeStatistics::display(std::ostream &out) const
    {
        int totalCases = 0;
        int totalResolved = 0;
        std::for_each(
            crimes.begin(), crimes.end(), [&](const Crime &crime)
            { 
                out << crime << std::endl; 
                totalCases += crime.s_numCases;
                totalResolved += crime.m_resolved; });

        out << std::right << "Total cases: " << totalCases << std::endl;
        out << std::right << "Total resolved: " << totalResolved << std::endl;
    }

    std::ostream &operator<<(std::ostream &out, const Crime &theCrime)
    {
        out << "| " << std::left << std::setw(21) << theCrime.s_province
            << " | " << std::left << std::setw(15) << theCrime.s_district
            << " | " << std::left << std::setw(20) << theCrime.s_crime
            << " | " << std::right << std::setw(6) << theCrime.s_year
            << " | " << std::right << std::setw(4) << theCrime.s_numCases
            << " | " << std::right << std::setw(3) << theCrime.m_resolved
            << " |";
        return out;
    }

    void CrimeStatistics::sort(const std::string &field)
    {
        if (field == "Province")
        {
            std::sort(crimes.begin(), crimes.end(), [](const Crime &a, const Crime &b)
                      { return a.s_province < b.s_province; });
        }
        else if (field == "Crime")
        {
            std::sort(crimes.begin(), crimes.end(), [](const Crime &a, const Crime &b)
                      { return a.s_crime < b.s_crime; });
        }
        else if (field == "Cases")
        {
            std::sort(crimes.begin(), crimes.end(), [](const Crime &a, const Crime &b)
                      { return a.s_numCases < b.s_numCases; });
        }
        else if (field == "Resolved")
        {
            std::sort(crimes.begin(), crimes.end(), [](const Crime &a, const Crime &b)
                      { return a.m_resolved < b.m_resolved; });
        }
    }

    void CrimeStatistics::cleanList()
    {
        crimes.erase(std::remove_if(crimes.begin(), crimes.end(), [](const Crime &crime)
                                    { return crime.s_crime == "[None]"; }),
                     crimes.end());
    }

    bool CrimeStatistics::inCollection(const std::string &crime) const
    {
        return std::any_of(crimes.begin(), crimes.end(), [=](const Crime &c)
                           { return c.s_crime == crime; });
    }

    std::list<Crime> CrimeStatistics::getListForProvince(const std::string &province) const
    {
        std::list<Crime> provinceCrimes;
        std::copy_if(crimes.begin(), crimes.end(), std::back_inserter(provinceCrimes), [&](const Crime &crime)
                     { return crime.s_province == province; });
        return provinceCrimes;
    }

}