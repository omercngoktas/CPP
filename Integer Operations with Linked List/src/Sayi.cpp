#include "../include/Sayi.h"

Sayi::Sayi() : ilk(nullptr) {}

Sayi::~Sayi() {
    delete ilk;
}

using namespace std;

// yeni gelen basamak degerinin linkedlistte bulunan dugume eklenmesi
void Sayi::ekleBasamak(int yeniBasamakDegeri) {
    Basamak* yeniBasamak = new Basamak(yeniBasamakDegeri);
    yeniBasamak->sonraki = ilk;
    ilk = yeniBasamak;
}

int Sayi::tamSayiDegeri() {
    int result = 0;
    Basamak* temp = ilk;
    while (temp != nullptr) {
        result = result * 10 + temp->basamakDegeri;
        temp = temp->sonraki;
    }
    return result;
}

void Sayi::ekranaYaz() const {
    Basamak* temp = ilk;
    while (temp) {
        cout << " *   " << temp->basamakDegeri << " *";
        temp = temp->sonraki;
    }
    cout << endl;
}

void Sayi::adresleriYaz() const {
    Basamak* temp = ilk;

    while (temp) {
        // Son üç basamağın adreslerini bastırma
        uintptr_t adres = reinterpret_cast<uintptr_t>(temp);
        cout << " * " << hex << setw(3) << setfill('0') << (adres % 0x1000) << " *";
        temp = temp->sonraki;
    }
    cout << dec << endl;  // dec ile ondalık sistemde bastır
}

void Sayi::tekBasamaklariBasaAl() {
    if (ilk == nullptr || ilk->sonraki == nullptr) {
        // Eğer liste boşsa ya da başlangıç düğümü boşsa ya da tek bir düğüm varsa bir şey yapmaya gerek yok.
        return;
    }

    Basamak* simdikiDugum = ilk;
    Basamak* onceki = nullptr;

    while (simdikiDugum != nullptr) {
        if (simdikiDugum->basamakDegeri % 2 == 1) {
            // Tek sayıları uygun konuma taşıyalım
            if (onceki != nullptr && onceki->basamakDegeri % 2 == 0) {
                // Önceki düğüm çift sayı, bu durumda simdiki düğümü uygun konuma ekleyelim
                onceki->sonraki = simdikiDugum->sonraki;

                simdikiDugum->sonraki = nullptr;
                
                Basamak* temp = ilk;
                Basamak* oncekisi = nullptr;

                while (temp != nullptr && temp->basamakDegeri % 2 == 1) {
                    oncekisi = temp;
                    temp = temp->sonraki;
                }

                if (oncekisi != nullptr) {
                    oncekisi->sonraki = simdikiDugum;
                    simdikiDugum->sonraki = temp;
                } else {
                    simdikiDugum->sonraki = ilk;
                    ilk = simdikiDugum;
                }

                simdikiDugum = onceki->sonraki;
            } else {
                // Önceki düğüm yok veya önceki düğüm de tek sayı ise, sadece devam et
                onceki = simdikiDugum;
                simdikiDugum = simdikiDugum->sonraki;
            }
        } else {
            // Çift sayıları sadece devam ettir
            onceki = simdikiDugum;
            simdikiDugum = simdikiDugum->sonraki;
        }
    }
}

void Sayi::basamaklariTersle() {
    if (ilk == nullptr || ilk->sonraki == nullptr) {
        // Eğer liste boşsa ya da sadece bir düğüm varsa bir şey yapmaya gerek yok.
        return;
    }

    Basamak* onceki = nullptr;
    Basamak* simdikiDugum = ilk;
    Basamak* sonraki = nullptr;

    while (simdikiDugum != nullptr) {
        sonraki = simdikiDugum->sonraki;
        simdikiDugum->sonraki = onceki;

        onceki = simdikiDugum;
        simdikiDugum = sonraki;
    }

    ilk = onceki;
}

void Sayi::enBuyuguCikar() {
    if (ilk == nullptr || ilk->sonraki == nullptr) {
        // Eğer liste boşsa ya da sadece bir düğüm varsa bir şey yapmaya gerek yok.
        return;
    }

    Basamak* enBuyuk = nullptr;
    Basamak* onceki = nullptr;
    Basamak* simdikiDugum = ilk;

    while (simdikiDugum != nullptr) {
        if (enBuyuk == nullptr || simdikiDugum->basamakDegeri > enBuyuk->basamakDegeri) {
            enBuyuk = simdikiDugum;
            onceki = onceki;
        }
        simdikiDugum = simdikiDugum->sonraki;
    }

    if (enBuyuk != nullptr) {
        if (onceki != nullptr) {
            onceki->sonraki = enBuyuk->sonraki;
        } else {
            ilk = enBuyuk->sonraki;
        }

        delete enBuyuk;
    }
}