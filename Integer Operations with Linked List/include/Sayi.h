#ifndef SAYI_H
#define SAYI_H

#include "Basamak.h" // Basamak sınıfını dahil ettik.
#include <iostream>
#include <iomanip> 

class Sayi {
    private:
        Basamak* ilk;

    public:
        Sayi();
        ~Sayi();

        void ekleBasamak(int deger);
        int tamSayiDegeri();
        void adresleriYaz() const;
        void ekranaYaz() const;
        void tekBasamaklariBasaAl();
        void basamaklariTersle();
        void enBuyuguCikar();
};

#endif
