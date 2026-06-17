#pragma once
#include "Equation.hpp"

class Solver
{
    public:
        void solve(const Equation &eq);
    private:
        double my_sqrt(double n);
        void solveDegree0(double c0);
        void solveDegree1(double c0, double c1);
        void solveDegree2(double c0, double c1, double c2);
};
