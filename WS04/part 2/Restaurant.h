/*
Workshop 4 Part 2
Name: Benny Yang
Student ID: 112654223
Email: byang68@myseneca.ca
Date: June 10st, 2023
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_RESTAURANT_H
#define SDDS_RESTAURANT_H

#include <iostream>
#include "Reservation.h"

namespace sdds
{

    class Restaurant
    {
        Reservation **m_reservations{};
        size_t m_numRes{};
        static int CALL_CNT;

    public:
        // constructor
        Restaurant(){};
        Restaurant(const Reservation *reservations[], size_t cnt);

        // Copy cons & ass
        Restaurant(const Restaurant& other);
        Restaurant& operator=(const Restaurant& other);
        
        // Move Cons & ass
        Restaurant(Restaurant&& other);
        Restaurant& operator=(Restaurant&& other);


        // Destructor
        ~Restaurant();

        // Query
        size_t size() const;

        // Overloaded op
        friend std::ostream &operator<<(std::ostream &os, const Restaurant &restaurant);
    };

}

#endif