#include "Sistem.h"

Sistem::Sistem() {}

Sistem::~Sistem() {}

/* aldığı Organ objesini sistemde bulunan vectore ekler */
void Sistem::setOrganlar(Organ *yeniOrgan) { organlar.push_back(yeniOrgan); }

