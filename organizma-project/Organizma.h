#ifndef ORGANIZMA_H
#define ORGANIZMA_H
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <cstddef>
#include <algorithm>
#include "Sistem.h"

class Organizma {
    private:
        std::vector <Sistem *> sistemler;

    public:
        void setSistemler(Sistem *yeniSistem);
        int getSizeOfOrganizma(Organizma organizma) { return organizma.sistemler.size(); }
        std::vector <Sistem *> getSistemler() { return sistemler; }
};

#endif