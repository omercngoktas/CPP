#ifndef SAYILARLISTESI_H
#define SAYILARLISTESI_H

#include "Dugum.h"
#include <cstdint>
#include <sstream>


class SayilarListesi {
    private:
        Dugum* ilk;
        Dugum* son;

    public:
        SayilarListesi();
        ~SayilarListesi();
        void sayiEkle(Sayi* yeniSayi);
        void ekranaYaz();
        void tekleriBasaAl();
        void basamaklariTersle();
        void enBuyuguCikar();
};

#endif