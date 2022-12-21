#include "Organizma.h"

Organizma::Organizma() {}
Organizma::~Organizma() {}

void Organizma::setSistemler(Sistem *yeniSistem) { sistemler.push_back(yeniSistem); }