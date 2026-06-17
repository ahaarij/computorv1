#include "Parser.hpp"
#include <regex>
#include <stdexcept>


void    Parser::parseSide(const std::string &side, Equation &eq, double sign)
{
    std::string s;
    for (char c : side)
        if (c != ' ')
            s += c;

    // for matching stuff like 5*X^0 or +4*X^1 or -9.3*X^2
    std::regex term_re("([+-]?[0-9]*\\.?[0-9]+)\\*[Xx]\\^([0-9]+)");

    auto begin = std::sregex_iterator(s.begin(), s.end(), term_re);
    auto end = std::sregex_iterator();

    for (auto it = begin; it != end; ++it)
    {
        double  coeff = std::stod((*it)[1].str());
        int     exp = std::stoi((*it)[2].str());
        eq.addTerm(exp, sign * coeff);
    }
}


Equation Parser::parse(const std::string &input)
{
    Equation eq;

    size_t eq_pos = input.find('=');
    if(eq_pos == std::string::npos)
        throw std::invalid_argument("No '=' found in equation");

    std::string lhs = input.substr(0, eq_pos);
    std::string rhs = input.substr(eq_pos + 1);

    parseSide(lhs, eq, 1.0); // left side u can add as is.
    parseSide(rhs, eq, -1.0); // right you negate to move to left.

    return eq;
}

//the regex matches a number like 5 or +4 or -9.3 | ([+-]?[0-9]*\.?[0-9]+)
// matches literal '*X^' | \*[Xx]\^
// matches exponent | ([0-9]+)
// so after stripping space you get a result like "-4*X^1"
