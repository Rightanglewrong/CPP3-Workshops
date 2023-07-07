/*
Workshop 4 Part 2
Name: Benny Yang
Student ID: 112654223
Email: byang68@myseneca.ca
Date: June 10st, 2023
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_CONFIRMATIONSENDER_H
#define SDDS_CONFIRMATIONSENDER_H

#include "Reservation.h"

namespace sdds
{
    class ConfirmationSender
    {
    private:
        const Reservation **m_resConS{};
        size_t m_confirmationNum{0};

    public:
        // Constuctor
        ConfirmationSender(){};

        // Cpy C&A
        ConfirmationSender(const ConfirmationSender &other);
        ConfirmationSender &operator=(const ConfirmationSender &other);

        // Move C&A
        ConfirmationSender(ConfirmationSender &&other);
        ConfirmationSender &operator=(ConfirmationSender &&other);

        // Destructor
        ~ConfirmationSender();

        ConfirmationSender &operator+=(const Reservation &res);
        ConfirmationSender &operator-=(const Reservation &res);

        friend std::ostream &operator<<(std::ostream &os, const ConfirmationSender &sender);
    };

}

#endif