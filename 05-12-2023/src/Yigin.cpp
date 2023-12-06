#include "../include/Yigin.h"

YiginDugumu::YiginDugumu(int sayi, YiginDugumu* sonraki) {
    this->sayi = sayi;
    this->sonraki = sonraki;
}

Yigin::Yigin() {
    yiginBasi = nullptr;
}

Yigin::~Yigin() {
    yiginiBosalt();
}

void Yigin::ekle(int sayi) {
    yiginBasi = new YiginDugumu(sayi, yiginBasi);
}

void Yigin::cikar() {
    if(yiginBosMu()) {
        cout <<  "Yigin bos\n";
        return;
    }
    YiginDugumu* silinecekDugum = yiginBasi;
    // Yığında sadece bir düğüm varsa
    if (yiginBasi->sonraki == nullptr) {
        delete silinecekDugum;
        yiginBasi = nullptr;  // Yığın boşaldı, başı null olmalı
    } else {
        yiginBasi = yiginBasi->sonraki;
        delete silinecekDugum;
    }
}

int Yigin::getYiginBasi() {
    if(yiginBosMu()) {
        cout <<  "Yigin bos\n";
        return -1;
    } else {
        return yiginBasi->sayi;
    }
}

void Yigin::yiginiBosalt() {
    while(!yiginBosMu()) {
        cikar();
    }
}

bool Yigin::yiginBosMu() {
    if(yiginBasi == nullptr) {
        return true;
    } else {
        return false;
    }
}

void Yigin::yiginiGoruntule() {
    if(yiginBasi == nullptr) {
        cout <<  "Yigin bos\n";
        return;
    } else {
        YiginDugumu* geciciDugum = yiginBasi;
        
        cout << "Yigin: ";
        while(geciciDugum) {
            cout << geciciDugum->sayi << " ";
            geciciDugum = geciciDugum->sonraki;
        }
        cout << endl;
    }
}