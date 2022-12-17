#include "Doku.h"

void Doku::setDokuDegerleri(Hucre yeniHucre) { dokuDegeri = yeniHucre; }

Hucre getOrtadakiDoku(std::vector <Doku *> dokuDegerleri) {
    //  return dokuDegerleri[dokuDegerleri.size() / 2].getDokuDegerleri();
    return dokuDegerleri[dokuDegerleri.size() / 2]->getDokuDegerleri();
}

Doku::Doku() {

}

Doku::~Doku() {
    
}