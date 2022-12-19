#include "Doku.h"

void Doku::setDokuDegerleri(Hucre *yeniHucre) { hucreler.push_back(yeniHucre); }

int Doku::getOrtaDeger() { return ortaDokuDegeri; }

void Doku::setOrtaDeger() {
    std::vector <int> hucreDegerleri;
    for(int i = 0; i < hucreler.size(); i++) {
        hucreDegerleri.push_back(hucreler[i]->getHucreDegeri());
    }
    Radix radix;
    radix.radixSort(hucreDegerleri);
    ortaDokuDegeri =  hucreDegerleri[hucreDegerleri.size() / 2];
    // std::ofstream outfile("cikti.txt", std::ios::app);
    // outfile << ortaDokuDegeri << "\n";
    // outfile.close();
}

Doku::Doku() {

}

Doku::~Doku() {
    
}