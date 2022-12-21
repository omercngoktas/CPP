#ifndef HUCRE_H
#define HUCRE_H
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <cstddef>
#include <algorithm>

class Hucre {
    private:
        int hucreDegeri;

    public:
        Hucre();
        ~Hucre();
        void setHucreDegeri(int yeniHucreDegeri);
        int getHucreDegeri() { return hucreDegeri; }
};

#endif