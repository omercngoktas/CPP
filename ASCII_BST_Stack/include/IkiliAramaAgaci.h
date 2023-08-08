#ifndef IKILIARAMAAGACI_H
#define IKILIARAMAAGACI_H

#include <iostream>

using namespace std;

class AgacDugumu {
    public:
        int sayi;
        AgacDugumu* sol;
        AgacDugumu* sag;
        AgacDugumu(int sayi) : sayi(sayi), sol(nullptr), sag(nullptr) {};
};

class IkiliAramaAgaci {
    private:
        AgacDugumu* kok_dugum;
        AgacDugumu* ekle(AgacDugumu* dugum, int sayi);
        int agacUzunlugu(AgacDugumu* dugum);
        int degerlerToplami(AgacDugumu* dugum);
        void postorderTraversal(AgacDugumu* dugum);

    public:
        IkiliAramaAgaci();
        void ekle(int sayi);
        void goruntule();
        int agacUzunlugu();
        int degerlerToplami();
        void postorderTraversal();
};

class IkiliAramaAgaciListesi {
    private:
        class Dugum {
            public:
                IkiliAramaAgaci* tree;
                Dugum* next;
                Dugum(IkiliAramaAgaci* t) : tree(t), next(nullptr) {}
        };
        Dugum* bas;
        Dugum* son;

    public:
        IkiliAramaAgaciListesi();
        ~IkiliAramaAgaciListesi();
        void agacEkle(IkiliAramaAgaci* yeni_agac);
        IkiliAramaAgaci* indexleAgacBul(int index) const;
};

#endif
