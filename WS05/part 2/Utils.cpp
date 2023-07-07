/*
Workshop 5 Part 2
Name: Benny Yang
Student ID: 112654223
Email: byang68@myseneca.ca
Date: June 17st, 2023
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*/
#include <iostream>
#include <string>

#include "Utils.h"
namespace sdds
{

    std::string trim(std::string &str) // Taken from my last workshop
    {
        // Trim leading whitespaces
        size_t start = 0;
        while (start < str.length() && std::isspace(str[start]))
        {
            start++;
        }
        str = str.substr(start);

        // Trim trailing whitespaces
        size_t end = str.length() - 1;
        while (end > 0 && std::isspace(str[end]))
        {
            end--;
        }
        str = str.substr(0, end + 1);
    }
}