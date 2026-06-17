#include "Solver.hpp"
#include <iostream>

double Solver::my_sqrt(double n)
{
    if(n == 0) return 0;
    double x = n;
    for (int i = 0; i < 100000; i++)
        x = (x + n / x) / 2.0;
    return x;
}

void    Solver::solveDegree0(double c0)
{
    if(c0 == 0.0)
        std::cout << "Any real number is a solution." << std::endl;
    else
        std::cout << "No solution." << std::endl;
}

void    Solver::solveDegree1(double c0, double c1)
{
    std::cout << "The solution is:" << std::endl;
    std::cout << -c0 / c1 << std::endl;
}

void    Solver::solveDegree2(double c0, double c1, double c2)
{
    double D = c1 * c1 - 4 * c2 * c0;

    if (D > 0)
    {
        double sol1 = (-c1 + my_sqrt(D)) / (2 * c2);
        double sol2 = (-c1 - my_sqrt(D)) / (2 * c2);
        std::cout << "Discriminant is strictly positive, the two solutions are:" << std::endl;
        if (sol1 >= sol2)
        {
            std::cout << sol1 << std::endl;
            std::cout << sol2 << std::endl;
        }
        else
        {
            std::cout << sol2 << std::endl;
            std::cout << sol1 << std::endl;
        }
    }
    else if (D == 0)
    {
        std::cout << "Discriminant is zero, the solution is:" << std::endl;
        std::cout << -c1 / (2 * c2) << std::endl;
    }
    else // d < 0. complex solutions X = (-c1 ± i*sqrt(-D)) / (2*c2) 
    {   
        double realPart = -c1 / (2 * c2);
        double imagPart = my_sqrt(-D) / (2 * c2);
        std::cout << "Discriminant is strictly negative, the two complex solutions are:" << std::endl;
        std::cout << realPart << " + " << imagPart << "i" << std::endl;
        std::cout << realPart << " - " << imagPart << "i" << std::endl;
    }
}

void Solver::solve(const Equation &eq)
{
    int deg = eq.degree();
    std::cout << "Polynomial degree: " << deg << std::endl;

    double c0 = eq.coeffs.count(0) ? eq.coeffs.at(0) : 0.0;
    double c1 = eq.coeffs.count(1) ? eq.coeffs.at(1) : 0.0;
    double c2 = eq.coeffs.count(2) ? eq.coeffs.at(2) : 0.0;

    if (deg > 2)
        std::cout << "The polynomial degree is strictly greater than 2, I can't solve." << std::endl;
    else if (deg == 2)
        solveDegree2(c0, c1, c2);
    else if (deg == 1)
        solveDegree1(c0, c1);
    else
        solveDegree0(c0);
}


// .count() before .at() cuz coeffs[key] would insert a zero entry if the key doesnt exist hence corrupting the map, .count[key] checks it safely and then .at() reads it
