#ifndef BASAMAK_H
#define BASAMAK_H

// Sayi class'i friend olarak gosterileceginden taniminin yapilmasi gerekiyor
class Sayi;
#include <iostream>

class Basamak {
    private:
        int basamakDegeri;
        Basamak* sonraki;

    public:
        Basamak(int basamakDegeri);
        ~Basamak();
        // Sayi class'ini friend olarak gosteriyoruz, bu sayede Sayi class'ından buradaki degerlere erisebilecegiz
        friend class Sayi;
};

#endif