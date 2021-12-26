#include <string>
#include "ParsedInput.h"

#ifndef ADVENTOFCODE2021_SOLVER_H
#define ADVENTOFCODE2021_SOLVER_H

class Solver {
    public:
        int solve(ParsedInput &parsedInput);
    private:
        std::string inputFile;
};


#endif //ADVENTOFCODE2021_SOLVER_H
