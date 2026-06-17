#include <iostream>
#include <string>
#include "Parser.hpp"
#include "Equation.hpp"
#include "Solver.hpp"

int main(int argc, char **argv)
{
    std::string input;

    if(argc == 2)
        input = argv[1];
    else if (argc == 1)
        std::getline(std::cin, input);
    else
    {
        std::cerr << "Usage: ./computor \"equation\"" << std::endl;
        return 1;
    }

    try
    {
        Parser parser;
        Equation eq = parser.parse(input);
        eq.print();

        Solver solver;
        solver.solve(eq);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
