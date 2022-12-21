#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H
#include <vector>
#include "Doku.h"
#include <math.h>

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