#include "Organ.h"

Organ::Organ() {}

Organ::~Organ() {}

/*
    mutasyona uğramış Organ objesini alır. organda bulunan
    doku vectorunu ve BST'yi sıfırlar, aldığı mutasyon
    geçirmiş organdaki değerleri bu organa ekler.
*/
void Organ::mutasyonGecir(Organ* mutasyonluOrgan) {
    BST = new IkiliAramaAgaci();
    std::vector <Doku*> mutasyonluDokular;
    for(int i = 0; i < mutasyonluOrgan->getDokular().size(); i++) {
        mutasyonluDokular.push_back(mutasyonluOrgan->getDokular()[i]);
        BST->dokuEkle(mutasyonluOrgan->getDokular()[i]);
    }
}

/*
    aldığı doku objesini organ'da bulunan doku
    vectorune push'lar ve BST (binary search tree)'ye ekler
*/
void Organ::setOrgan(Doku* yeniDoku) {
    dokular.push_back(yeniDoku);
    BST->dokuEkle(yeniDoku);
}
