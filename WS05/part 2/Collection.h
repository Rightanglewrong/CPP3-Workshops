/*
Workshop 5 Part 2
Name: Benny Yang
Student ID: 112654223
Email: byang68@myseneca.ca
Date: June 17st, 2023
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H
#include <iostream>
#include <string>

namespace sdds
{
    template <typename T>
    class Collection
    {
        std::string m_cName{};
        T *m_items{};
        std::size_t m_size{};
        void (*m_observer)(const Collection<T> &, const T &){};

    public:
        // Constructors
        Collection(){};
        Collection(const std::string &name) : m_cName(name){};

        // Copy con & ass disabled
        Collection(const Collection &) = delete;
        Collection &operator=(const Collection &) = delete;

        // Destructor
        ~Collection() { delete[] m_items; }

        // Query
        const std::string &name() const { return m_cName; }
        size_t size() const { return m_size; }

        void setObserver(void (*observer)(const Collection<T> &, const T &))
        {
            m_observer = observer;
        }

        // Overloaded Ops
        Collection<T> &operator+=(const T &item)
        {
            bool dupe = false;
            for (size_t i = 0; i < m_size && !dupe; i++)
            {
                if (m_items[i].title() == item.title())
                {
                    dupe = true;
                }
            }
            if (!dupe)
            {
                T *temp = new T[m_size + 1];
                for (size_t i = 0; i < m_size; i++)
                {
                    temp[i] = m_items[i];
                }
                temp[m_size++] = item;
                delete[] m_items;
                m_items = temp;
                if (m_observer)
                {
                    m_observer(*this, item);
                }
                // delete[] temp;
            }
            return *this;
        }

        T &operator[](size_t idx) const
        {
            if (idx < 0 || idx >= m_size)
            {
                throw std::out_of_range("Bad index " + std::to_string(idx) + ". Collection has " + std::to_string(m_size) + " items.");
            }
            return m_items[idx];
        }

        T *operator[](const std::string &title) const
        {
            for (size_t i = 0; i < m_size; i++)
            {
                if (m_items[i].title() == title)
                {
                    return &m_items[i];
                }
            }
            return nullptr;
        }
    };
    template <typename T>
    std::ostream &operator<<(std::ostream &os, const Collection<T> &c)
    {
        for (size_t i = 0; i < c.size(); i++)
        {
            os << c[i];
        }
        return os;
    }
}

#endif