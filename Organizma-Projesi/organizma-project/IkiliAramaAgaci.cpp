#include "IkiliAramaAgaci.h"

struct IkiliAramaAgaci::dugum {
        Doku* doku = new Doku();
        int ortaDokuDegeri;
        dugum* sol;
        dugum* sag;
};

IkiliAramaAgaci::IkiliAramaAgaci() { kokOrgan = NULL; }

IkiliAramaAgaci::~IkiliAramaAgaci() { kokOrgan = BSTSil(kokOrgan); }

IkiliAramaAgaci::dugum* IkiliAramaAgaci::BSTSil(IkiliAramaAgaci::dugum* silinecekDugum) {
    if(silinecekDugum == NULL) { return NULL; } 
    else {
        BSTSil(silinecekDugum->sol);
        BSTSil(silinecekDugum->sag);
        delete silinecekDugum;
    }
    return NULL;
}

IkiliAramaAgaci::dugum* IkiliAramaAgaci::dokuEkle(Doku* doku, IkiliAramaAgaci::dugum* yeniDugum) {
    if(yeniDugum == NULL) {
        yeniDugum = new dugum;
        yeniDugum->doku = doku;
        yeniDugum->ortaDokuDegeri = doku->getOrtaDeger();
        yeniDugum->sol = yeniDugum->sag = NULL;
    }

    else if(doku->getOrtaDeger() < yeniDugum->ortaDokuDegeri) { yeniDugum->sol = dokuEkle(doku, yeniDugum->sol); }
    else if(doku->getOrtaDeger() > yeniDugum->ortaDokuDegeri) { yeniDugum->sag = dokuEkle(doku, yeniDugum->sag); }
    else if(doku->getOrtaDeger() == yeniDugum->ortaDokuDegeri) { yeniDugum->sol = dokuEkle(doku, yeniDugum->sol); }
    return yeniDugum;
}

void IkiliAramaAgaci::dokuEkle(Doku* doku) { kokOrgan = dokuEkle(doku, kokOrgan); }

int IkiliAramaAgaci::checkIfBSTBalancedByAVL(dugum* kokOrgan) {
    if(kokOrgan == NULL) return 0;
    int soldugumBF = checkIfBSTBalancedByAVL(kokOrgan->sol);
    if(soldugumBF == -1) return -1;
    int sagdugumBF = checkIfBSTBalancedByAVL(kokOrgan->sag);
    if(sagdugumBF == -1) return -1;
    if(abs(soldugumBF - sagdugumBF) > 1) return -1;
    else return max(soldugumBF, sagdugumBF) + 1;
}

int IkiliAramaAgaci::getkokOrganValue() { return kokOrgan->doku->getOrtaDeger(); }