#pragma once
#include <map>

class Equation
{
    public:
    std::map<int, double> coeffs;

    void    addTerm(int exponent, double coeffecient);
    int degree() const;
    void print() const;
};

// addterm(exp, coeff) adds to coeffs[exp]
// degree returns highest exponent w non 0 coeffecient
// print prints the reduced form line