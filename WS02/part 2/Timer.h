/*
Workshop 2 Part 2
Name: Benny Yang
Student ID: 112654223
Email: byang68@myseneca.ca
Date: May 27th, 2023
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_TIMER_H
#define SDDS_TIMER_H

#include <iostream>
#include <chrono>

namespace sdds
{

    class Timer
    {
        // std::chrono::steady_clock::time_point startTime;
        std::chrono::time_point<std::chrono::steady_clock> startTime;
        std::chrono::time_point<std::chrono::steady_clock> stopTime;
    public:
        // Modifiers
        void start();
        long long stop();
    };

}

#endif