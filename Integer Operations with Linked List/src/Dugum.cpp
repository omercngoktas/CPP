#include "../include/Dugum.h"

Dugum::Dugum(Sayi* sayi) : sayi(sayi), sonraki(nullptr) {}

Dugum::~Dugum() {
    delete sayi;
}