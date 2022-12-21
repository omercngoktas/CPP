#ifndef ORGAN_H
#define ORGAN_H
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <cstddef>
#include <algorithm>
#include "IkiliAramaAgaci.h"

class Organ {
    private:
        IkiliAramaAgaci* BST = new IkiliAramaAgaci();
        std::vector <Doku*> dokular;

    public:
        Organ();
        ~Organ();
        void setOrgan(Doku*);
        void mutasyonGecir(Organ*);
        IkiliAramaAgaci* getBST() { return BST; }
        std::vector <Doku*> getDokular() { return dokular; }
};

#endif