#include "Doku.h"

/* aldığı hücre objesini doku'ya ekler */
void Doku::setDokuDegerleri(Hucre* yeniHucre) { hucreler.push_back(yeniHucre); }

/* orta değeri return eden fonksiyon */
int Doku::getOrtaDeger() { return ortaDokuDegeri; }

/*
    doku'nun içerisinde bulunan hucre vectorunu radix ile küçükten 
    büyüğe sıralayarak ortada bulunan değeri ortaDokuDegeri'ne atar
*/
void Doku::setOrtaDeger() {
    int sirasizHucreler[hucreler.size()];

    for(int i = 0; i < hucreler.size(); i++) { sirasizHucreler[i] = hucreler[i]->getHucreDegeri(); }
    Radix* radix = new Radix(sirasizHucreler, hucreler.size());
    int* siraliHucreler = radix->Sort();
    ortaDokuDegeri = siraliHucreler[hucreler.size() / 2];
}

Doku::Doku() {

}

Doku::~Doku() {
    
}