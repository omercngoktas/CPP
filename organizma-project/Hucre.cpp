#include "Hucre.h"

void Hucre::setHucreDegeri(int yeniHucreDegeri) { hucreDegeri = yeniHucreDegeri; }

Hucre getOrtadakiHucre(std::vector <Hucre> hucreListesi) {
    return hucreListesi[hucreListesi.size()/2];
}

Hucre::Hucre() {
    int random = rand();
    // std::cout << "Hucre " << random << " degeriyle olusturuldu." << std::endl;
    hucreDegeri = random; 
}

Hucre::~Hucre() {
    // std::cout << "Hucre yok edildi" << std::endl;
}