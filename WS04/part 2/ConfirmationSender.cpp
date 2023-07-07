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

#include "ConfirmationSender.h"

namespace sdds
{
    // Copy Const & ass
    ConfirmationSender::ConfirmationSender(const ConfirmationSender &other)
    {
        *this = other;
    }
    ConfirmationSender &ConfirmationSender::operator=(const ConfirmationSender &other)
    {
        if (this != &other)
        {
            if (m_resConS != nullptr)
            {
                delete[] m_resConS;
                m_resConS = nullptr;
            }
            if (other.m_resConS != nullptr)
            {
                m_resConS = new const Reservation *[other.m_confirmationNum];
                m_confirmationNum = other.m_confirmationNum;
                for (size_t i = 0; i < m_confirmationNum; ++i)
                {
                    m_resConS[i] = other.m_resConS[i];
                }
            }
        }
        return *this;
    }

    // Move C&A
    ConfirmationSender::ConfirmationSender(ConfirmationSender &&other)
    {
        *this = std::move(other);
    }

    ConfirmationSender &ConfirmationSender::operator=(ConfirmationSender &&other)
    {
        if (this != &other)
        {
            if (m_resConS != nullptr)
            {
                delete[] m_resConS;
                m_resConS = nullptr;
            }
            if (other.m_resConS != nullptr)
            {
                m_resConS = other.m_resConS;
                m_confirmationNum = other.m_confirmationNum;
                other.m_resConS = nullptr;
                other.m_confirmationNum = 0;
            }
        }
        return *this;
    }

    // Deconstructor
    ConfirmationSender::~ConfirmationSender()
    {
        if (m_resConS != nullptr)
        {
            delete[] m_resConS;
        }
    }

    // Overloaded Ops
    ConfirmationSender &ConfirmationSender::operator+=(const Reservation &res)
    {
        bool check = true;
        for (size_t i = 0; i < m_confirmationNum; ++i) // checks for duplicate
        {
            if (m_resConS[i] == &res)
            {
                check = false;
                break;
            }
        }

        if (check == true)
        {
            const Reservation **temp = m_resConS;
            m_resConS = new const Reservation *[m_confirmationNum + 1];
            if (temp != nullptr)
            {
                for (size_t i = 0; i < m_confirmationNum; ++i)
                {
                    m_resConS[i] = temp[i];
                }
                delete[] temp;
            }
            m_resConS[m_confirmationNum++] = &res;
        }
        return *this;
    }

    ConfirmationSender &ConfirmationSender::operator-=(const Reservation &res)
    {
        bool found = false;
        int resizer = 0;
        for (size_t i = 0; i < m_confirmationNum && found == false; i++) // Searching for res
        {
            if (m_resConS[i] == &res)
            {
                m_resConS[i] = nullptr; // Set the pointer to nullptr
                // Resizing the array to remove nullptr entries
                const Reservation **temp = m_resConS;
                m_resConS = new const Reservation *[m_confirmationNum - 1];
                for (size_t j = 0; j < m_confirmationNum; j++) // scanning for empty slots and not adding them to new temp Reservations
                {
                    if (temp[j] != nullptr)
                    {
                        m_resConS[j - resizer] = temp[j];
                    }
                    else
                    {
                        resizer = 1;
                    }
                }
                delete[] temp;
                --m_confirmationNum;
                found = true;
            }
        }
        return *this;
    }

    std::ostream &operator<<(std::ostream &os, const ConfirmationSender &sender)
    {
        os << "--------------------------" << std::endl;
        os << "Confirmations to Send" << std::endl;
        os << "--------------------------" << std::endl;

        if (sender.m_confirmationNum == 0)
        {
            os << "There are no confirmations to send!" << std::endl;
        }
        else
        {
            for (size_t i = 0; i < sender.m_confirmationNum; i++)
            {
                os << *(sender.m_resConS[i]);
            }
        }

        os << "--------------------------" << std::endl;
        return os;
    }

} // namespace sdds
