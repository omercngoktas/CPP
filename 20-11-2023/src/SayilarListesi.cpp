#include "../include/SayilarListesi.h"

SayilarListesi::SayilarListesi() : ilk(nullptr), son(nullptr) {}

SayilarListesi::~SayilarListesi() {
    delete ilk;
    delete son;
}

using namespace std;

void SayilarListesi::sayiEkle(Sayi* yeniSayi) {
    Dugum* yeniDugum = new Dugum(yeniSayi);
    if(!ilk) {
        ilk = yeniDugum;
        son = yeniDugum;
    } else {
        son->sonraki = yeniDugum;
        son = son->sonraki;
    }
}

void SayilarListesi::ekranaYaz() {
    Dugum* temp = ilk;
    int sayi, adresUzunlugu, sayiUzunlugu;

    while(temp) {
        ostringstream oss;
        oss << hex << setw(16) << setfill('0') << reinterpret_cast<uintptr_t>(temp);
        string addressStr = oss.str();
        sayi = temp->sayi->tamSayiDegeri();
        adresUzunlugu = addressStr.length();
        sayiUzunlugu = to_string(sayi).length();
        // ilk satiri yazdirma
        cout << string(adresUzunlugu + 2, '#') << "   ";
        // kac adet basamak varsa ona gore 7 adet * karakteri bastirilir
        for (int i = 0; i < sayiUzunlugu; ++i) {
            cout << string(7, '*');
            if (i < sayiUzunlugu - 1) {
                cout << ' ';
            }
        }
        cout << endl;
        // listenin adresini yazdirma
        cout << '#' << setw(adresUzunlugu) << addressStr << '#' << "  ";
        // basamaklarin adreslerini yazdirma
        temp->sayi->adresleriYaz();
        // en ortadaki ara çizgileri bastirma
        cout << "#" << string(adresUzunlugu, '-') << "#" << "   ";
        for (int i = 0; i < sayiUzunlugu; ++i) {
            cout << string(7, '*');
            if (i < sayiUzunlugu - 1) {
                cout << ' ';
            }
        }
        cout << endl;
        

        // ana sayiyi bastirma
        cout << "#" << string(adresUzunlugu - sayiUzunlugu, ' ') << sayi << '#' << "  ";
        temp->sayi->ekranaYaz();        
        // en alt satiri yazdirma
        cout << string(adresUzunlugu + 2, '#') << "   ";
        // kac adet basamak varsa ona gore 7 adet * karakteri bastirilir
        for (int i = 0; i < sayiUzunlugu; ++i) {
            cout << string(7, '*');
            if (i < sayiUzunlugu - 1) {
                cout << ' ';
            }
        }
        cout << endl << endl;
        temp = temp->sonraki;
    }
}

void SayilarListesi::tekleriBasaAl() {
    Dugum* temp = ilk;
    while(temp) {
        temp->sayi->tekBasamaklariBasaAl();
        temp = temp->sonraki;
    }
}

void SayilarListesi::basamaklariTersle() {
    Dugum* temp = ilk;
    while(temp) {
        temp->sayi->basamaklariTersle();
        temp = temp->sonraki;
    }
}

void SayilarListesi::enBuyuguCikar() {
    if (ilk == nullptr) {
        // Eğer liste boşsa bir şey yapmaya gerek yok.
        return;
    }

    Dugum* enBuyukDugum = nullptr;
    Dugum* simdikiDugum = ilk;

    while (simdikiDugum) {
        if (enBuyukDugum == nullptr || simdikiDugum->sayi->tamSayiDegeri() > enBuyukDugum->sayi->tamSayiDegeri()) {
            enBuyukDugum = simdikiDugum;
        }
        simdikiDugum = simdikiDugum->sonraki;
    }

    simdikiDugum = ilk;
    if(simdikiDugum == enBuyukDugum) {
        ilk = ilk->sonraki;
        delete enBuyukDugum;
        return;
    }
    while (simdikiDugum) {
        if(simdikiDugum->sonraki == enBuyukDugum) {
            simdikiDugum->sonraki = simdikiDugum->sonraki->sonraki;
        }
        simdikiDugum = simdikiDugum->sonraki;
    }
    delete enBuyukDugum;
}


