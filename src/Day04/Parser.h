//
// Created by marek on 26.12.21.
//

#ifndef ADVENTOFCODE2021_PARSER_H
#define ADVENTOFCODE2021_PARSER_H


#include <fstream>
#include "ParsedInput.h"

class Parser {
    public:
        ParsedInput parse(std::string &inputFile);
};


#endif //ADVENTOFCODE2021_PARSER_H
