#include <iostream>
#include "Solver.h"
#include "Parser.h"

int main() {
    std::string input = "/home/marek/Work/personal/AdventOfCode2021/src/Day04/input/First/input1.txt";

    Parser parser;
    ParsedInput parsedInput = parser.parse(input);
    parsedInput.dump();

    // Solver solver;

    // std::cout << solver.solve(parsedInput) << std::endl;

    return 0;
}
