/*
Workshop 2 Part 2
Name: Benny Yang
Student ID: 112654223
Email: byang68@myseneca.ca
Date: May 27th, 2023
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*/

#include <iostream>
#include "Timer.h"

using namespace std;
namespace sdds {
    void Timer::start()
    {
        startTime = chrono::steady_clock::now();
    }
    long long Timer::stop() {
        stopTime = chrono::steady_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stopTime - startTime);
		return duration.count();
    }
}