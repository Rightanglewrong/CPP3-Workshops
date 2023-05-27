/*
Workshop 1 Part 2
Name: Benny Yang
Student ID: 112654223
Email: byang68@myseneca.ca
Date: May 19th, 2023
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_CARADS_H
#define SDDS_CARADS_H

extern double g_taxrate;
extern double g_discount;

namespace sdds
{

    class Cars
    {
    private:
        char *m_brand{}; // Changing to cstring of any length
        char m_model[16]{};
        int m_year{};
        double m_price{};
        char m_status{};
        bool m_onPromo{};

    public:
        // Constructors
        Cars();
        Cars(const Cars &other);
        Cars &operator=(const Cars &other);
        ~Cars();

        void read(std::istream &is); // Modifier
        void display(bool reset) const;
        char getStatus() const;

        operator bool() const;
    };
    void listArgs(int argc, char *argv[]);

    std::istream &operator>>(std::istream &is, Cars &car);
    void operator>>(const Cars &car1, Cars &car2);

}

#endif