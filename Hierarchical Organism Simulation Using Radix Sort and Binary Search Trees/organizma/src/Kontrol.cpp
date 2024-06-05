#include "Kontrol.h"

Kontrol::Kontrol(Organizma *mutasyonsuzOrganizma) { organizma = mutasyonsuzOrganizma; }

Kontrol::~Kontrol() {}

void Kontrol::mutasyonKontrolEt() {
    IkiliAramaAgaci* geciciBST;
    /* organizmada bulunan sistemlerin içerisindeyiz */
    for(int i = 0; i < organizma->getSistemler().size(); i++) {
        /* sistemin içerisinde bulunan organın içerisindeyiz */
        for(int j = 0; j < organizma->getSistemler()[i]->getOrganlar().size(); j++) {
            geciciBST = organizma->getSistemler()[i]->getOrganlar()[j]->getBST();
            /* if koşuluna girerse BST'nin kök değeri 50 ile kalansız bölünebilmektedir */
            if(geciciBST->getkokOrganValue() %50 == 0) {
                Organ* mutasyonluOrgan = new Organ();
                mutasyonluOrgan = mutasyonaUgrat(organizma->getSistemler()[i]->getOrganlar()[j]);
                organizma->getSistemler()[i]->getOrganlar()[j]->mutasyonGecir(mutasyonluOrgan);
            }
        }
    }
}

Organ* Kontrol::mutasyonaUgrat(Organ* mutasyonsuzOrgan) {
    vector <Doku*> mutasyonsuzDokular = mutasyonsuzOrgan->getDokular();
    Organ* mutasyonluOrgan = new Organ();
    
    for(int i = 0; i < mutasyonsuzDokular.size(); i++) {
        Doku* mutasyonluDoku = new Doku();
        for(int j = 0; j < mutasyonsuzDokular[i]->getDokuDegerleri().size(); j++) {
            int yeniDeger = mutasyonsuzDokular[i]->getDokuDegerleri()[j]->getHucreDegeri();
            if(yeniDeger %2 == 0) yeniDeger = yeniDeger / 2;
            Hucre* mutasyonluHucre = new Hucre();
            mutasyonluHucre->setHucreDegeri(yeniDeger);
            mutasyonluDoku->setDokuDegerleri(mutasyonluHucre);
            mutasyonluDoku->setOrtaDeger();
        }
        mutasyonluOrgan->setOrgan(mutasyonluDoku);
    }
    int balance = mutasyonluOrgan->getBST()->checkBalance();
    return mutasyonluOrgan;
}