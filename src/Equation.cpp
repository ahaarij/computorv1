#include "Equation.hpp"
#include <iostream>

void    Equation::addTerm(int exp, double coeff)
{
    coeffs[exp] += coeff;
}

int     Equation::degree() const // 
{
    int deg = 0;
    for (auto &p : coeffs) // iterates over all entries in da map
        if (p.second != 0.0) // if coeff is not 0, then it updates degree to that exponentt
            deg = p.first;
    return deg; // deg holds highest exponent
}

void     Equation::print() const
{
    std::cout << "Reduced form: ";

    if (coeffs.empty())
    {
        std::cout << "0 * X^0 = 0" << std::endl;
        return;
    }

    bool first = true;
    for (auto &p : coeffs)
    {
        if (!first)
        {
            if (p.second >= 0)
                std::cout << " + ";
            else
                std::cout << " - ";
        }
        double val = (first || p.second >= 0) ? p.second : -p.second;
        std::cout << val << " * X^" << p.first;
        first = false;
    }
    std::cout << " = 0" << std::endl;
}

// prints ALL terms in the map, including zeros cuz subj expects 0 * X^2 to appear if it was in the input
// for signs, first term prints as-is (including negative), terms after print + or - then absolute value
