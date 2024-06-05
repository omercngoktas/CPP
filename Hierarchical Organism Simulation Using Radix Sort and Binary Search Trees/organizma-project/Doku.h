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
#include "Radix.h"

class Doku {
    private:
        std::vector <Hucre*> hucreler;
        int ortaDokuDegeri;
        
    public:
        Doku();
        ~Doku();
        void setDokuDegerleri(Hucre*);
        std::vector <Hucre*> getDokuDegerleri() { return hucreler; }
        void setOrtaDeger();
        int getOrtaDeger();
};

#endif