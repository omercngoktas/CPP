#include "../include/Yigin.h"

Yigin::Yigin() : sayilar(nullptr), son_index(-1) {}

Yigin::~Yigin() {
    delete[] sayilar;
}

void Yigin::push(int item) {
    int* yeni_sayilar = new int[son_index + 2];
    for (int i = 0; i <= son_index; i++) {
        yeni_sayilar[i] = sayilar[i];
    }
    yeni_sayilar[son_index + 1] = item;

    delete[] sayilar;
    sayilar = yeni_sayilar;
    son_index++;
}

void Yigin::pop() {
    if (!empty()) {
        son_index--;
    }
}

int Yigin::top() const {
    if (!empty()) {
        return sayilar[son_index];
    }
    return -1;
}

bool Yigin::empty() const {
    return son_index == -1;
}

YiginListesi::YiginListesi() : bas(nullptr), son(nullptr) {}

YiginListesi::~YiginListesi() {
    Dugum* suanki_dugum = bas;
    while (suanki_dugum) {
        Dugum* sonraki = suanki_dugum->sonraki;
        delete suanki_dugum->yigin;
        delete suanki_dugum;
        suanki_dugum = sonraki;
    }
}

void YiginListesi::yiginEkle(Yigin* s) {
    Dugum* yeniDugum = new Dugum(s);

    if (!bas) {
        bas = yeniDugum;
        son = yeniDugum;
    } else {
        son->sonraki = yeniDugum;
        son = yeniDugum;
    }
}

void YiginListesi::yiginlariKaldir() {
    Dugum* suanki_dugum = bas;
    while (suanki_dugum) {
        Dugum* sonraki = suanki_dugum->sonraki;
        delete suanki_dugum->yigin;
        delete suanki_dugum;
        suanki_dugum = sonraki;
    }
    bas = nullptr;
    son = nullptr;
}

Yigin* YiginListesi::getYigin(int index) const {
    if (index < 0) {
        return nullptr;
    }

    Dugum* suanki_dugum = bas;
    int count = 0;

    while (suanki_dugum) {
        if (count == index) {
            return suanki_dugum->yigin;
        }

        suanki_dugum = suanki_dugum->sonraki;
        count++;
    }

    return nullptr;
}