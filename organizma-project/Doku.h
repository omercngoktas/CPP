#ifndef DOKU_H
#define DOKU_H
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <cstddef>
#include <algorithm>
#include "Hucre.h"

class Doku {
    private:
        std::vector <int> dokuDegerleri;
        
    public:
        void setDokuDegerleri(Hucre hucre);
        std::vector <int> getDokuDegerleri() { return dokuDegerleri; }
};

#endif