//
// Created by marek on 26.12.21.
//
#include <iostream>

#include <string>
#include "Solver.h"
#include "ParsedInput.h"
#include <fstream>

int Solver::solve(ParsedInput &parsedInput) {
    int result = 0;

    for (int i = 0; i < parsedInput.getNumbers().size(); i++) {
        int currentNumber = parsedInput.getNumbers()[i];
        parsedInput.markNumber(currentNumber);

        try {
            BingoField winningField = parsedInput.getFieldWithBingo();
            int sumOfUnmarked = winningField.getSumOfUnmarked();
            result = sumOfUnmarked * currentNumber;
            break;

        } catch (std::domain_error& e) {
            continue;
        }
    }

    return result;
}
