#include "Equation.hpp"

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

    bool first = true;
    bool allZero = true;

    for(auto &p : coeffs)
    {
        if(p.second == 0.0)
            continue;
        allZero = false;

        if(!first)
        //finish when back getting late
    }
}