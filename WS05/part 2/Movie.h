/*
Workshop 5 Part 2
Name: Benny Yang
Student ID: 112654223
Email: byang68@myseneca.ca
Date: June 17st, 2023
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_MOVIE_H
#define SDDS_MOVIE_H

namespace sdds
{
    class Movie
    {
        std::string m_mTitle{};
        std::size_t m_releaseYear{};
        std::string m_mDescription{};

        void trim(std::string &str) const;

    public:
        // Constructors
        Movie(){};
        Movie(const std::string &strMovie);

        // Query
        const std::string &title() const;

        // Friend
        friend std::ostream &operator<<(std::ostream &os, const Movie &m);

        // Template
        template <typename T>
        void fixSpelling(T &spellChecker)
        {
            spellChecker(m_mTitle);
            spellChecker(m_mDescription);
        }
    };

}

#endif