/*
Workshop 4 Part 1
Name: Benny Yang
Student ID: 112654223
Email: byang68@myseneca.ca
Date: June 9st, 2023
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include "Reservation.h"

namespace sdds
{
    // Constructor
    Reservation::Reservation(const std::string &res)
    {
        std::string id;
        size_t colon = res.find(':');   // part of string library to find position of ':'
        if (colon != std::string::npos) // this the what it returns if it fails
        {
            // Extracting ID
            id = res.substr(0, colon);
            trim(id);
            std::strncpy(m_reservationId, id.c_str(), sizeof(m_reservationId) - 1);
            m_reservationId[sizeof(m_reservationId) - 1] = '\0';

            // Extracting comma seperated data
            std::string attributes = res.substr(colon + 1); // new string without ID
            size_t commaSpt;
            int i = 0;
            while (i < 5) // 4 commas seperated data to get total
            {
                commaSpt = attributes.find(',');
                std::string attribute = attributes.substr(0, commaSpt);
                trim(attribute);
                if (i == 0)
                {
                    m_name = attribute;
                }
                else if (i == 1)
                {
                    m_email = attribute;
                }
                else if (i == 2)
                {
                    m_numPpl = std::stoi(attribute);
                }
                else if (i == 3)
                {
                    m_day = std::stoi(attribute);
                }
                attributes.erase(0, commaSpt + 1);
                i++;
            }
            m_hour = std::stoi(attributes);
        }
    }

    // Modifier
    void Reservation::update(int day, int time) // No validation included
    {
        m_day = day;
        m_hour = time;
    }

    void Reservation::trim(std::string &str) const
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

    std::ostream &operator<<(std::ostream &os, const Reservation &res)
    {
        std::string meal;
        if (res.m_hour >= 6 && res.m_hour <= 9)
        {
            meal = "Breakfast";
        }
        else if (res.m_hour >= 11 && res.m_hour <= 15)
        {
            meal = "Lunch";
        }
        else if (res.m_hour >= 17 && res.m_hour <= 21)
        {
            meal = "Dinner";
        }
        else
        {
            meal = "Drinks";
        }
        os << "Reservation ";
        os << std::right << std::setw(10) << res.m_reservationId << ": "
           << std::setw(20) << res.m_name << "  "
           << std::left << std::setw(20) << '<' + res.m_email + '>' << "    " << meal
           << " on day " << res.m_day << " @ " << res.m_hour << ":00 for "
           << res.m_numPpl << ' ' << (res.m_numPpl == 1 ? "person." : "people.") << std::endl;
        return os;
    }
}