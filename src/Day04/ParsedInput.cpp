//
// Created by marek on 26.12.21.
//

#include <iostream>
#include "ParsedInput.h"
using namespace std;


void ParsedInput::addNumber(int number) {
    inputNumbers.push_back(number);
}

void ParsedInput::addField(BingoField bingoField) {
    bingoFields.push_back(bingoField);
}

void ParsedInput::markNumber(int number) {
    for (int i = 0; i < this->bingoFields.size(); i++) {
        this->bingoFields[i].markNumber(number);
    }
}

BingoField ParsedInput::getFieldWithBingo() {
    for (int i = 0; i < this->bingoFields.size(); i++) {
        if (this->bingoFields[i].hasBingo()) {
            return this->bingoFields[i];
        }
    }

    throw std::domain_error("No field with bingo found.");
}

ParsedInput::~ParsedInput() {
}

void ParsedInput::dump() {
    std::cout << "Input numbers are:" << std::endl;

    for (int i = 0; i < this->inputNumbers.size(); i++) {
        std::cout << this->inputNumbers[i] << " ";
    }
    std::cout << std::endl << std::endl;

    std::cout << "Matrices are:" << std::endl;

    for (int i = 0; i < this->bingoFields.size(); i++) {
        this->bingoFields[i].dump();
    }
}

vector<int> ParsedInput::getNumbers() {
    return this->inputNumbers;
}
