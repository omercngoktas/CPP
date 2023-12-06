#ifndef YIGIN_H
#define YIGIN_H

#include <iostream>
using namespace std;

class YiginDugumu {
    private:

    public:
        int sayi;
        YiginDugumu* sonraki;
        YiginDugumu(int sayi, YiginDugumu* sonraki = nullptr);
};

class Yigin {
    private:
        YiginDugumu* yiginBasi;

    public:
        Yigin();
        ~Yigin();
        bool yiginBosMu();
        void ekle(const int sayi);
        void cikar();
        int getYiginBasi();
        void yiginiBosalt();
        void yiginiGoruntule();
};

#endif