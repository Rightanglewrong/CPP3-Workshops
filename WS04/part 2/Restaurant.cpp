/*
Workshop 4 Part 2
Name: Benny Yang
Student ID: 112654223
Email: byang68@myseneca.ca
Date: June 10st, 2023
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*/

#include <iostream>
#include "Restaurant.h"

namespace sdds
{
    int Restaurant::CALL_CNT = 0;

    // Constructor
    Restaurant::Restaurant(const Reservation *reservations[], size_t cnt)
    {
        m_numRes = cnt;
        m_reservations = new Reservation *[cnt];
        for (size_t i = 0; i < cnt; i++)
        {
            m_reservations[i] = new Reservation(*reservations[i]);
        }
    }

    // Copy Cons & ass
    Restaurant::Restaurant(const Restaurant &other)
    {
        *this = other;
    }

    Restaurant &Restaurant::operator=(const Restaurant &other)
    {
        if (this != &other)
        {
            if (m_reservations != nullptr)
            {
                for (size_t i = 0; i < m_numRes; ++i)
                {
                    if (m_reservations[i] != nullptr)
                    {
                        delete m_reservations[i];
                    }
                }
                delete[] m_reservations;
                m_reservations = nullptr;
            }

            if (other.m_reservations != nullptr)
            {
                m_numRes = other.m_numRes;
                m_reservations = new Reservation *[m_numRes];
                for (size_t i = 0; i < m_numRes; ++i)
                {
                    m_reservations[i] = new Reservation;
                    *(m_reservations[i]) = *(other.m_reservations[i]);
                }
            }
        }
        return *this;
    }

    // Move Cons & Ass
    Restaurant::Restaurant(Restaurant &&other)
    {
        *this = std::move(other);
    }

    Restaurant &Restaurant::operator=(Restaurant &&other)
    {
        if (this != &other)
        {
            if (m_reservations != nullptr)
            {
                for (size_t i = 0; i < m_numRes; ++i)
                {
                    if (m_reservations[i] != nullptr)
                    {
                        delete m_reservations[i];
                    }
                }
                delete[] m_reservations;
                m_reservations = nullptr;
            }
            if (other.m_reservations != nullptr)
            {
                m_reservations = other.m_reservations;
                m_numRes = other.m_numRes;

                other.m_reservations = nullptr;
                other.m_numRes = 0;
            }
        }
        return *this;
    }

    // Query
    size_t Restaurant::size() const
    {
        return m_numRes;
    }

    // Overloaded Op
    std::ostream &operator<<(std::ostream &os, const Restaurant &restaurant)
    {
        os << "--------------------------" << std::endl;
        os << "Fancy Restaurant (" << ++Restaurant::CALL_CNT << ")" << std::endl;
        os << "--------------------------" << std::endl;

        if (restaurant.m_numRes != 0)
        {
            for (size_t i = 0; i < restaurant.m_numRes; i++)
            {
                os << *(restaurant.m_reservations[i]);
            }
        }
        else
        {
            os << "This restaurant is empty!" << std::endl;
        }
        os << "--------------------------" << std::endl;

        return os;
    }

    // Destructor
    Restaurant::~Restaurant()
    {
        for (size_t i = 0; i < m_numRes; i++)
        {
            delete m_reservations[i];
        }
        delete[] m_reservations;
    }
}