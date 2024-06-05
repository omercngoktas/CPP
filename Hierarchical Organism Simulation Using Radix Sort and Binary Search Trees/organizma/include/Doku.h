#ifndef DOKU_H
#define DOKU_H
#include <vector>
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