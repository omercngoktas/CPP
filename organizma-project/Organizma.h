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
        Organizma();
        ~Organizma();
        void setSistemler(Sistem *yeniSistem);
        int getSizeOfOrganizma() { return sistemler.size(); }
        std::vector <Sistem *> getSistemler() { return sistemler; }
};

#endif