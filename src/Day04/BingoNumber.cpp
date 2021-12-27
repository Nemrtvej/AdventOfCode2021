//
// Created by marek on 27.12.21.
//

#include "BingoNumber.h"

BingoNumber::BingoNumber(int number) {
    this->number = number;
    this->marked = false;
}

void BingoNumber::mark() {
    this->marked = true;
}

bool BingoNumber::isMarked() {
    return this->marked;
}

int BingoNumber::getNumber() {
    return this->number;
}

BingoNumber BingoNumber::copy() {
    auto result = BingoNumber(this->getNumber());
    if (this->isMarked()) {
        result.mark();
    }

    return result;
}
