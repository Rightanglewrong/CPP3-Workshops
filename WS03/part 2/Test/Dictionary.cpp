#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
#include "Dictionary.h"

namespace sdds {
    bool Dictionary::operator==(const Dictionary& other) const
    {
        return m_term == other.m_term && m_definition == other.m_definition;
    }

    std::ostream& operator<<(std::ostream& os, const Dictionary& d) {
        os.width(20);
        os.fill(' ');
        os.setf(std::ios::right);
        os << d.getTerm();
        os.unsetf(std::ios::right);
        os << ": " << d.getDefinition();
        return os;
    }

}