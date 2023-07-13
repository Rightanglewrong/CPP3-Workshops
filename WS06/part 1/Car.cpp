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
#include <string>
#include <iomanip>
#include "Car.h"

namespace sdds
{
    // COnstructor
    Car::Car(std::istream &in)
    {
        std::string tag;
        getline(in, tag, ',');
        getline(in, m_maker, ',');
        trim(m_maker);
        in >> m_condition;
        if (m_condition == ' ' || m_condition == ',')
        {
            m_condition = 'n';
        }
        else if (m_condition != 'n' && m_condition != 'u' && m_condition != 'b')
        {
            throw std::runtime_error("Invalid record!");
        }
        else
        {
            in.ignore(1000, ',');
        }
        in >> m_topSpeed;
        if (in.fail())
        {
            in.clear();
            throw std::runtime_error("Invalid record!");
        }
    }

    // QUeries
    std::string Car::condition() const
    {
        std::string condition = "";
        if (m_condition == 'n')
        {
            condition = "new";
        }
        else if (m_condition == 'u')
        {
            condition = "used";
        }
        else if (m_condition == 'b')
        {
            condition = "broken";
        }
        return condition;
    }

    double Car::topSpeed() const
    {
        return m_topSpeed;
    }
    void Car::display(std::ostream &out) const
    {
        out << "| " << std::right << std::setw(10) << m_maker << " | "
            << std::left << std::setw(6) << condition() << " | "
            << std::setw(6) << std::fixed << std::setprecision(2) << topSpeed() << " |";
    }

    void Car::trim(std::string &str) // Taken from my last workshop
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
}