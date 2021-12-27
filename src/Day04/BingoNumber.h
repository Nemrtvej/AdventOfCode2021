//
// Created by marek on 27.12.21.
//

#ifndef ADVENTOFCODE2021_BINGONUMBER_H
#define ADVENTOFCODE2021_BINGONUMBER_H


class BingoNumber {
    public:
    BingoNumber(): BingoNumber(0) {};

    BingoNumber(int number);
        void mark();
        bool isMarked();
        int getNumber();
        BingoNumber copy();
    private:
        int number;
        bool marked;
};


#endif //ADVENTOFCODE2021_BINGONUMBER_H
