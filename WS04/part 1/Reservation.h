/*
Workshop 4 Part 1
Name: Benny Yang
Student ID: 112654223
Email: byang68@myseneca.ca
Date: June 9st, 2023
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_RESERVATION_H
#define SDDS_RESERVATION_H

#include <iostream>

namespace sdds
{
    class Reservation
    {
    private:
        char m_reservationId[20]{};
        std::string m_name{};
        std::string m_email{};
        int m_numPpl{};
        int m_day{};
        int m_hour{};

        void trim(std::string &str) const;

    public:
        // Constructors
        Reservation(){};
        Reservation(const std::string &res);

        // Modifier
        void update(int day, int time);

        // overloaded op
        friend std::ostream &operator<<(std::ostream &os, const Reservation &res);
    };

}

#endif