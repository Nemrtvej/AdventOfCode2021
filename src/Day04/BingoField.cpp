//
// Created by marek on 26.12.21.
//

#include <iostream>
#include "BingoField.h"

BingoField::BingoField(int size) {
    this->size = size;
    this->values = new int*[size];
    for (int i = 0; i < size; i++) {
        this->values[i] = new int[size];
    }
}

BingoField::BingoField(const BingoField &other) {
    this->size = other.size;
    this->values = new int*[size];
    for (int rowIndex = 0; rowIndex < size; rowIndex++) {
        this->values[rowIndex] = new int[size];
        for (int colIndex = 0; colIndex < size; colIndex++) {
            this->values[rowIndex][colIndex] = other.values[rowIndex][colIndex];
        }
    }
}


BingoField BingoField::copy() {
    BingoField result = BingoField(this->size);

    for (int rowIndex = 0; rowIndex < size; rowIndex++) {
        for (int colIndex = 0; colIndex < size; colIndex++) {
            result.setNumber(rowIndex, colIndex, this->getNumber(rowIndex, colIndex));
        }
    }

    return result;
}

void BingoField::setNumber(int rowIndex, int colIndex, int value) {
    this->values[rowIndex][colIndex] = value;
}

int BingoField::getNumber(int rowIndex, int colIndex) {
    return this->values[rowIndex][colIndex];
}

BingoField::~BingoField() {
    for (int i = 0; i < this->size; i++) {
        delete [] this->values[i];
    }
    delete [] this->values;
}

void BingoField::dump() {
    for (int rowIndex = 0; rowIndex < this->size; rowIndex++ ) {
        std::cout << std::endl;
        for (int colIndex = 0; colIndex < this->size; colIndex++) {
            std::cout << this->getNumber(rowIndex, colIndex);
            std::cout << " ";
        }
    }
    std::cout << std::endl;
}
