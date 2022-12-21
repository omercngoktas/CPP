#include "Doku.h"

/* aldığı hücre objesini doku'ya ekler */
void Doku::setDokuDegerleri(Hucre *yeniHucre) { hucreler.push_back(yeniHucre); }

/* orta değeri return eden fonksiyon */
int Doku::getOrtaDeger() { return ortaDokuDegeri; }

/*
    doku'nun içerisinde bulunan hucre vectorunu radix ile küçükten 
    büyüğe sıralayarak ortada bulunan değeri ortaDokuDegeri'ne atar
*/
void Doku::setOrtaDeger() {
    std::vector <int> hucreDegerleri;
    for(int i = 0; i < hucreler.size(); i++) {
        hucreDegerleri.push_back(hucreler[i]->getHucreDegeri());
    }
    Radix radix;
    radix.radixSort(hucreDegerleri);
    ortaDokuDegeri =  hucreDegerleri[hucreDegerleri.size() / 2];
}

Doku::Doku() {

}

Doku::~Doku() {
    
}