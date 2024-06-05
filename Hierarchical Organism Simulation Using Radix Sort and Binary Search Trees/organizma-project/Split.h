#ifndef SPLIT_H
#define SPLIT_H
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <cstddef>
#include <algorithm>

class Split {
    private:
        std::string textToSplit;

    public:
        Split(std::string);
        ~Split();
        std::vector <int> splitTextBySpace();
};

#endif