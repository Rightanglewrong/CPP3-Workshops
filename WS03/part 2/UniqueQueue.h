/*
Workshop 3 Part 2
Name: Benny Yang
Student ID: 112654223
Email: byang68@myseneca.ca
Date: June 3st, 2023
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_UNIQUEQUEUE_H
#define SDDS_UNIQUEQUEUE_H

#include <iostream>
#include <cmath>
#include "Queue.h"
#include "Dictionary.h"

namespace sdds
{
    template <typename T>
    class UniqueQueue : public Queue<T, 100>
    {
    public:
        bool push(const T &item)
        {
            for (size_t i = 0; i < 100; ++i)
            {
                if (this->operator[](i) == item)
                {
                    return false;
                }
            }
            return Queue<T, 100>::push(item);
        }
    };

    template <>
    bool UniqueQueue<double>::push(const double &item)
    {
        for (size_t i = 0; i < 100; ++i)
        {
            if (std::fabs(item - this->operator[](i)) <= 0.005)
            {
                return false;
            }
        }
        return Queue<double, 100>::push(item);
    }
}

#endif