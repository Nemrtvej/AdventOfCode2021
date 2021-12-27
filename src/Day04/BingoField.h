//
// Created by marek on 26.12.21.
//

#ifndef ADVENTOFCODE2021_BINGOFIELD_H
#define ADVENTOFCODE2021_BINGOFIELD_H


#include <array>
#include <vector>
#include "BingoNumber.h"

class BingoField {
    public:
        explicit BingoField(int size);
        BingoField copy();
        void setNumber(int rowIndex, int colIndex, int value);
        int getNumber(int rowIndex, int colIndex);
        void dump();
        void markNumber(int number);
        ~BingoField();
        bool hasBingo();

    int getSumOfUnmarked();

private:
        int size;
        BingoNumber* values;
        int getIndex(int rowIndex, int colIndex) const;
        bool isMarked(int rowindex, int colIndex);
        bool isBingoInColumn(int col);
        bool isBingoInRow(int row);
};


#endif //ADVENTOFCODE2021_BINGOFIELD_H
