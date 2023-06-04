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
#include <fstream>
#include <iomanip>
#include "TennisLog.h"

using namespace std;
namespace sdds
{
    // Constructors
    TennisLog::TennisLog()
    {
        m_matches = nullptr;
        m_count = 0;
    };

    TennisLog::TennisLog(std::string fileName)
    {
        ifstream file(fileName);
        if (file.is_open())
        {
            string skipIt; // The first line we are skipping will get put in here
            string line;
            string matchIdStr;
            getline(file, skipIt);
            while (getline(file, line)) // Getting count of lines
            {
                if (!line.empty())
                    m_count++;
            }
            m_matches = new TennisMatch[m_count];

            file.clear();
            file.seekg(0, ios::beg); // Have to reset file before I read the data
            getline(file, skipIt);

            for (size_t i = 0; i < m_count; ++i)
            {
                getline(file, m_matches[i].s_TournamentId, ',');
                getline(file, m_matches[i].s_TournamentName, ',');
                getline(file, matchIdStr, ',');
                m_matches[i].s_matchId = stoi(matchIdStr);
                getline(file, m_matches[i].s_Winner, ',');
                getline(file, m_matches[i].s_Loser);
            }

            file.close();
        }
        else
        {
            cout << "didnt work" << endl;
        }
    }

    // Copy Constructor & ass
    TennisLog::TennisLog(const TennisLog &other)
    {
        m_matches = nullptr;
        *this = other;
    }

    TennisLog &TennisLog::operator=(const TennisLog &other)
    {
        if (this != &other)
        {
            delete[] m_matches;
            m_count = other.m_count;
            m_matches = new TennisMatch[m_count + 1];
            for (size_t i = 0; i < m_count; ++i)
            {
                m_matches[i] = other.m_matches[i];
            }
        }
        return *this;
    }

    // Move Constructor & ass
    TennisLog::TennisLog(TennisLog &&other)
    {
        *this = std::move(other);
    }

    TennisLog &TennisLog::operator=(TennisLog &&other)
    {
        if (this != &other)
        {
            delete[] m_matches;
            if (other.m_matches != nullptr)
            {
                m_count = other.m_count;
                m_matches = other.m_matches;

                other.m_count = 0;
                other.m_matches = nullptr;
            }
            else
            {
                m_matches = nullptr;
                m_count = 0;
            }
        }
        return *this;
    }

    // Destructor
    TennisLog::~TennisLog()
    {
        delete[] m_matches;
    }

    // Query
    TennisLog TennisLog::findMatches(std::string playerName) const
    {
        TennisLog results;
        for (size_t i = 0; i < m_count; i++)
        {
            if (m_matches[i].s_Winner == playerName || m_matches[i].s_Loser == playerName)
            {
                results.addMatch(m_matches[i]);
            }
        }
        return results;
    }

    // Modifier
    void TennisLog::addMatch(const TennisMatch &match)
    {
        TennisMatch *tempArr = new TennisMatch[m_count + 1];

        for (size_t i = 0; i < m_count; i++) // copies over to temp
        {
            tempArr[i] = m_matches[i];
        }
        tempArr[m_count] = match;

        delete[] m_matches;
        m_matches = tempArr;
        m_count++;
    }

    // Operators
    TennisMatch TennisLog::operator[](size_t match) const
    {
        return (match < m_count) ? m_matches[match] : TennisMatch{}; // returning empty TennisMatch if fails here
    }

    TennisLog::operator size_t()
    {
        return m_count;
    }

    ostream &operator<<(ostream &os, const TennisMatch &match)
    {
        if (match.s_matchId == 0)
        {
            os << "Empty Match";
        }
        else
        {
            os << setfill('.') << setw(20) << right << "Tourney ID"
               << " : " << left << setw(30) << match.s_TournamentId << endl;
            os << setfill('.') << setw(20) << right << "Match ID"
               << " : " << left << setw(30) << match.s_matchId << endl;
            os << setfill('.') << setw(20) << right << "Tourney"
               << " : " << left << setw(30) << match.s_TournamentName << endl;
            os << setfill('.') << setw(20) << right << "Winner"
               << " : " << left << setw(30) << match.s_Winner << endl;
            os << setfill('.') << setw(20) << right << "Loser"
               << " : " << left << setw(30) << match.s_Loser << endl;
        }
        return os;
    }
}