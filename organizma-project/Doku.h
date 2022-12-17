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
        Hucre dokuDegeri;
        
    public:
        void setDokuDegerleri(Hucre hucre);
        Hucre getDokuDegerleri() { return dokuDegeri; }
        Doku();
        ~Doku();
};

Hucre getOrtadakiDoku(std::vector <Doku *> dokuDegerlerli);

#endif