#ifndef RADIX_SORT_H
#define RADIX_SORT_H
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cstddef>
#include <algorithm>
#include "Hucre.h"

class Radix {
    private:
        std::vector <int> hucreDegerleri;
    
    public:
        void setHucreDegerleri();
        std::vector <int> getHucreDegerleri() {};
};

void radix_sort(std::vector <int> &hucreDegerleri);
std::vector<int> splitBySpace(std::string text);

#endif