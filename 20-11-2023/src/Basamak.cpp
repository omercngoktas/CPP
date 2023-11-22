#include "../include/Basamak.h"

Basamak::Basamak(int basamakDegeri) : basamakDegeri(basamakDegeri), sonraki(nullptr) {}

Basamak::~Basamak() {
    delete sonraki;
}