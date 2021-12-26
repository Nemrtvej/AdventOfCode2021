//
// Created by marek on 26.12.21.
//

#ifndef ADVENTOFCODE2021_BINGOFIELD_H
#define ADVENTOFCODE2021_BINGOFIELD_H


class BingoField {
    public:
        BingoField(const BingoField &other);
        BingoField(int size);
        BingoField copy();
        void setNumber(int rowIndex, int colIndex, int value);
        int getNumber(int rowIndex, int colIndex);
        void dump();
        ~BingoField();
    private:
        int size;
        int** values;
};


#endif //ADVENTOFCODE2021_BINGOFIELD_H
