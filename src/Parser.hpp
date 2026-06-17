#pragma once
#include "Equation.hpp"
#include <string>

class Parser
{
    public:
        Equation parse(const std::string &input);
    private:
        void parseSide(const std::string &side, Equation &eq, double sign);
};
