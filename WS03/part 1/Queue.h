/*
Workshop 3 Part 1
Name: Benny Yang
Student ID: 112654223
Email: byang68@myseneca.ca
Date: June 1st, 2023
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_QUEUE_H
#define SDDS_QUEUE_H

#include <iostream>
#include <iomanip>
#include "Dictionary.h"

namespace sdds
{
    template <typename T, size_t CAPACITY>
    class Queue
    {
        T m_elements[CAPACITY]{};
        size_t m_count{0};

    public:
        Queue(){};

        bool push(const T &item)
        {
            bool result = false;
            if (m_count < CAPACITY)
            {
                m_elements[m_count++] = item;
                result = true;
            }
            return result;
        }

        T pop()
        {
            T temp = m_elements[0];
            for (size_t i = 1; i < m_count; ++i)
            {
                m_elements[i - 1] = m_elements[i];
            }
            --m_count;
            return temp;
        }

        size_t size() const
        {
            return m_count;
        }

        void display(std::ostream &os = std::cout)
        {
            os << std::setfill('-') << std::setw(22) << "" << std::endl;
            os << "| Dictionary Content |" << std::endl;
            os << std::setw(22) << "" << std::endl
               << std::setfill(' ');
            for (size_t i = 0; i < m_count; ++i)
            {
                os << m_elements[i] << std::endl;
            }
            os << std::setfill('-') << std::setw(22) << "" << std::endl
               << std::setfill(' ');
        }

        T operator[](size_t index) const
        {
            return (index < m_count) ? m_elements[index] : T{};
        }
    };

    template<>
    class Queue<Dictionary, 100u>
    {
        
    }

}

#endif