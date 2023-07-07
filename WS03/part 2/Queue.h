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
#include <cstring>
#include "Dictionary.h"

namespace sdds
{
    template <typename T, size_t CAPACITY>
    class Queue
    {
        T m_elements[CAPACITY]{};
        size_t m_count{};
        static T m_dummy;

    public:
        // Constructor & destructor
        Queue(){};
        virtual ~Queue(){};

        virtual bool push(const T &item)
        {
            bool result = false;
            if (m_count < CAPACITY)
            {
                m_elements[m_count] = item;
                m_count++;
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

        size_t size() const { return m_count; }

        void display(std::ostream &os = std::cout)
        {
            os << "----------------------" << std::endl;
            os << "| Dictionary Content |" << std::endl;
            os << "----------------------" << std::endl;
            for (size_t i = 0; i < m_count; ++i)
            {
                os << (m_elements == 0 ? m_dummy : m_elements[i]) << std::endl; // Remember the parenthesis lol, that ruined me for awhile
            }
            os << "----------------------" << std::endl;
        };

        T operator[](size_t index) const
        {
            return (index < m_count) ? m_elements[index] : m_dummy;
        }
    };
    // template <>
    // class Queue<Dictionary, 100u>
    // {
    //     Dictionary m_elements[100u];
    //     size_t m_count{0};
    //     Dictionary m_dummy{"Empty Term", "Empty Substitute"};
    // } Wish this worked lol

    // When dummy is for Dictionary with 100u
    template <>
    Dictionary Queue<Dictionary, 100u>::m_dummy = {"Empty Term", "Empty Substitute"};

    // Defining for dummy
    template <typename T, size_t CAPACITY>
    T Queue<T, CAPACITY>::m_dummy{};

}
#endif