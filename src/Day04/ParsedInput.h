//
// Created by marek on 26.12.21.
//

#include <vector>
#include "BingoField.h"

using namespace std;

#ifndef ADVENTOFCODE2021_PARSEDINPUT_H
#define ADVENTOFCODE2021_PARSEDINPUT_H


class ParsedInput {
    public:
        ~ParsedInput();
        void dump();
        void addNumber(int number);
        void addField(BingoField bingoField);
    private:
        vector<int> inputNumbers;
        vector<BingoField> bingoFields;
};


#endif //ADVENTOFCODE2021_PARSEDINPUT_H
