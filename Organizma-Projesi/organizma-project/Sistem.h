#ifndef SISTEM_H
#define SISTEM_H
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <cstddef>
#include <algorithm>

#include "Organ.h"

class Sistem {
    private:
        vector <Organ*> organlar;

    public:
        Sistem();
        ~Sistem();
        void setOrganlar(Organ*);
        std::vector <Organ*> getOrganlar() { return organlar; }
        int getSizeOfOrganlar() { return organlar.size(); }
};

#endif