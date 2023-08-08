#ifndef YIGIN_H
#define YIGIN_H

#include <iostream>

using namespace std;

class Yigin {
    private:
        int* sayilar;
        int son_index;

    public:
        Yigin();
        ~Yigin();
        void push(int item);
        void pop();
        int top() const;
        bool empty() const;
};

class YiginListesi {
    private:
        class Dugum {
        public:
            Yigin* yigin;
            Dugum* sonraki;

            Dugum(Yigin* s) : yigin(s), sonraki(nullptr) {}
        };

        Dugum* bas;
        Dugum* son;

    public:
        YiginListesi();
        ~YiginListesi();
        void yiginEkle(Yigin* s);
        void yiginlariKaldir();
        Yigin* getYigin(int index) const;
};

#endif