//
// Created by marek on 26.12.21.
//

#include <iostream>
#include "BingoField.h"
#include "BingoNumber.h"

BingoField::BingoField(int size) {
    this->size = size;
    this->values = new BingoNumber[size * size];
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
    this->values[this->getIndex(rowIndex, colIndex)] = BingoNumber(value);
}

bool BingoField::isMarked(int rowindex, int colIndex) {
    return this->values[this->getIndex(rowindex, colIndex)].isMarked();
}

int BingoField::getNumber(int rowIndex, int colIndex) {
    return this->values[this->getIndex(rowIndex, colIndex)].getNumber();
}

int BingoField::getIndex(int rowIndex, int colIndex) const {
    return (rowIndex * this->size) + colIndex;
}

BingoField::~BingoField() {
    // delete [] this->values;
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

void BingoField::markNumber(int number) {
    for (int i = 0; i < this->size * this->size; i++) {
        if (this->values[i].getNumber() == number) {
            this->values[i].mark();
        }
    }
}

bool BingoField::hasBingo() {
    bool result = false;

    for (int rowIndex = 0; rowIndex < this->size; rowIndex++) {
        result = result || this->isBingoInRow(rowIndex);
    }

    for (int colIndex = 0; colIndex < this->size; colIndex++) {
        result = result || this->isBingoInColumn(colIndex);
    }

    return result;
}

bool BingoField::isBingoInRow(int row) {
    bool result = true;
    for (int columnIndex = 0; columnIndex < this->size; columnIndex++) {
        result = result && this->isMarked(row, columnIndex);
    }

    return result;
}

bool BingoField::isBingoInColumn(int col) {
    bool result = true;
    for (int rowIndex = 0; rowIndex < this->size; rowIndex++) {
        result = result && this->isMarked(rowIndex, col);
    }

    return result;
}

int BingoField::getSumOfUnmarked() {
    int result = 0;
    for (int i = 0; i < this->size * this->size; i++) {
        if (!this->values[i].isMarked()) {
            result = result + this->values[i].getNumber();
        }
    }

    return result;
}
