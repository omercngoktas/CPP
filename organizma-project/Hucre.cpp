#include "Hucre.h"

/* aldığı int değeri hucreDegeri'ne eşitler */
void Hucre::setHucreDegeri(int yeniHucreDegeri) { hucreDegeri = yeniHucreDegeri; }

/*  */
Hucre::Hucre() {
    int random = rand();
    // std::cout << "Hucre " << random << " degeriyle olusturuldu." << std::endl;
    hucreDegeri = random; 
}

Hucre::~Hucre() {
    // std::cout << "Hucre yok edildi" << std::endl;
}