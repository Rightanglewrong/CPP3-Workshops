/*
Workshop 2 Part 2
Name: Benny Yang
Student ID: 112654223
Email: byang68@myseneca.ca
Date: May 27th, 2023
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_TENNISLOG_H
#define SDDS_TENNISLOG_H

#include <iostream>
#include <string>

namespace sdds
{
    struct TennisMatch
    {
        std::string s_TournamentId{};
        std::string s_TournamentName{};
        size_t s_matchId{};
        std::string s_Winner{};
        std::string s_Loser{};
    };

    class TennisLog
    {
        TennisMatch *m_matches{};
        size_t m_count{};

    public:
        // Constructors
        TennisLog();
        TennisLog(std::string fileName);
        
        // Copy Constructor, Copy ass
        TennisLog(const TennisLog& other);
        TennisLog& operator=(const TennisLog& other);

        // Move Constructor, Move ass
        TennisLog(TennisLog&& other);
        TennisLog& operator=(TennisLog&& other);

        // Destructor
        ~TennisLog();

        // Query
        TennisLog findMatches(std::string playerName) const;

        // Modifier
        void addMatch(const TennisMatch &match);

        // Overloaded Operators
        TennisMatch operator[](size_t) const;
        operator size_t();
    };

    std::ostream &operator<<(std::ostream &os, const TennisMatch &match);

}

#endif