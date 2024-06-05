#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <cstddef>
#include <algorithm>
#include "Doku.h"
#include <math.h>
using namespace std;

class IkiliAramaAgaci {
    private:
        struct dugum;
        dugum* kokOrgan;
        dugum* dokuEkle(Doku*, dugum*);
        dugum* BSTSil(dugum*);
        int checkIfBSTBalancedByAVL(dugum*);

    public:
        IkiliAramaAgaci();
        ~IkiliAramaAgaci();
        void dokuEkle(Doku*);
        int checkBalance() { return checkIfBSTBalancedByAVL(kokOrgan); }
        int getkokOrganValue();
};

#endif