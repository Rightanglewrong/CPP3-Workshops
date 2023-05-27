/*
Workshop 1
Name: Benny Yang
Student ID: 112654223
Email: byang68@myseneca.ca
Date: May 16th, 2023
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_CARADS_H
#define SDDS_CARADS_H

extern double g_taxrate;
extern double g_discount;

namespace sdds {

    class Cars
    {
    private:
        char m_brand[11]{};
        char m_model[16]{};
        int m_year{};
        double m_price{};
        char m_status{};
        bool m_onPromo{};

    public:
        Cars();
        void read(std::istream& is); // Modifier
        void display(bool reset) const;
        char getStatus() const;
    };
    void listArgs(int argc, char* argv[]);

}

#endif