#ifndef AVLTREE_H
#define AVLTREE_H

#include <iostream>
#include <cmath>
using namespace std;

class Dugum {
    public:
        int sayi;
        int yukseklik;
        Dugum* sol;
        Dugum* sag;
        Dugum(int sayi);
};

class AvlTree {
    private:
        
    
    public:
        Dugum* kok;
        AvlTree();
        Dugum* sayiEkle(Dugum* kok, int sayi);
        int getYukseklik(Dugum* dugum);
        int getDenge(Dugum* dugum);
        Dugum* sagaDondur(Dugum* dugum);
        Dugum* solaDondur(Dugum* dugum);
        Dugum* agaciDengele(Dugum* dugum);
        void agaciGoster(Dugum* kok, int seviye);
        void agaciTemizle(Dugum* dugum);
};

#endif