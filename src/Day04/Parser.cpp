//
// Created by marek on 26.12.21.
//

#include "Parser.h"
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;


// for string delimiter
vector<string> split(string line, string delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    string token;
    vector<string> res;

    while ((pos_end = line.find (delimiter, pos_start)) != string::npos) {
        token = line.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back (token);
    }

    res.push_back (line.substr (pos_start));
    return res;
}

ParsedInput Parser::parse(string &inputFile) {

    ifstream input(inputFile);
    string line;

    if (!input.is_open()) {
        throw invalid_argument("Input file not available.");
    }

    ParsedInput parsedInput;

    getline(input, line);

    vector<string> parsedNumbers = split(line, ",");
    for (int i = 0; i < parsedNumbers.size(); i++) {
        if (parsedNumbers[i].length() == 0) {
            continue;
        }
        parsedInput.addNumber(stoi(parsedNumbers[i]));
    }

    BingoField* bingoField;
    const int matrixSize = 5;
    int currentRow = 0;
    int currentCol = 0;
    vector<string> parsedNumbersInLine;

    while (true) {
        getline(input, line);
        if (input.eof()) {
            if (currentRow > 0) {
                parsedInput.addField(bingoField->copy());
            }
            break;
        }

        if (line.length() == 0 ) {
            if (currentRow > 0) {
                parsedInput.addField(bingoField->copy());
            }
            bingoField = new BingoField(matrixSize);
            currentRow = 0;
            continue;
        }

        split(line, " ").swap(parsedNumbersInLine);
        currentCol = 0;
        for (int i = 0; i < parsedNumbersInLine.size(); i++) {
            string currentNumberString = parsedNumbersInLine[i];

            if (currentNumberString.length() == 0) {
                continue;
            }
            int currentNumber = stoi(currentNumberString);
            bingoField->setNumber(currentRow, currentCol++, currentNumber);
        }
        currentRow++;
    }

    input.close();

    return parsedInput;
}
