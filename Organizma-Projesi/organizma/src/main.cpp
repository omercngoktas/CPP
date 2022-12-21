#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <cstddef>
#include <algorithm>
#include <memory>

#include "Radix.h"
#include "Hucre.h"
#include "IkiliAramaAgaci.h"
#include "Doku.h"
#include "Organ.h"
#include "Organizma.h"
#include "Sistem.h"
#include "Split.h"

using namespace std;

void dokulariOlustur(string txtDosyaAdi, vector <Doku *> &dokular) {
    ifstream VeriDosyasi;
    VeriDosyasi.open(txtDosyaAdi);
    if(!VeriDosyasi) {
        VeriDosyasi.close();
        VeriDosyasi.open("../Veri.txt");
    } if(!VeriDosyasi) {
        VeriDosyasi.close();
        VeriDosyasi.open("./src/Veri.txt");
    } if(!VeriDosyasi) {
        VeriDosyasi.close();
        VeriDosyasi.open("../src/Veri.txt");
    }
    
    string text;
    int counter = 0, index = 0;

    while (getline(VeriDosyasi, text)) {
        Split* split = new Split(text);
        vector <int> hucreler = split->splitTextBySpace();
        counter++;
        Doku *yeniDoku = new Doku();
        for(int i = 0; i < hucreler.size(); i++) {
            Hucre *yeniHucre = new Hucre();
            yeniHucre->setHucreDegeri(hucreler[i]);
            yeniDoku->setDokuDegerleri(yeniHucre);
            // delete yeniHucre;
        }
        yeniDoku->setOrtaDeger();
        dokular.push_back(yeniDoku);
        // delete split;
    }
    VeriDosyasi.close();
}

void organlariOlustur(vector <Organ *> &organlar, vector <Doku *> dokular) {
    vector <Doku *> geciciDokular;
    Organ* yeniOrgan = new Organ();
    int counter = 0, index = 0;

    for(int i = 0; i < dokular.size(); i++) {
        geciciDokular.push_back(dokular[i]);
        if(geciciDokular.size() %20 == 0) {
            for(index; index < geciciDokular.size(); index++) {
                yeniOrgan->setOrgan(geciciDokular[index]);
            }
            organlar.push_back(yeniOrgan);
            yeniOrgan = new Organ();
            counter++;
        }
    }
    geciciDokular.clear();
    // delete yeniOrgan;
}

void sistemleriOlustur(vector <Sistem*> &sistemler, vector <Organ*> organlar) {
    Sistem* yeniSistem = new Sistem();
    for(int i = 0; i < organlar.size(); i++) {
        yeniSistem->setOrganlar(organlar[i]);
        if(yeniSistem->getSizeOfOrganlar() == 100) {
            sistemler.push_back(yeniSistem);
            yeniSistem = new Sistem();
        }
    }
    // delete yeniSistem;
}

void organizmaOlustur(Organizma* &organizma, vector <Sistem*> sistemler) {
    for(int i = 0; i < sistemler.size(); i++) {
        organizma->setSistemler(sistemler[i]);
    }
}

void organizmayiYazdir(Organizma* organizma) {
    for(int i = 0; i < organizma->getSistemler().size(); i++) {
        for(int j = 0; j < organizma->getSistemler()[i]->getOrganlar().size(); j++) {
            int dengeDegeri = organizma->getSistemler()[i]->getOrganlar()[j]->getBST()->checkBalance();
            if(dengeDegeri > 0) { cout << " "; }
            else { cout << "#"; }
        }
        cout << endl;
    }
}

Organ* mutasyonaUgrat(Organ* mutasyonsuzOrgan) {
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
    // mutasyonsuzDokular.clear();
    int balance = mutasyonluOrgan->getBST()->checkBalance();
    return mutasyonluOrgan;
}

void mutasyonKontrolEt(Organizma* &yeniOrganizma) {
    IkiliAramaAgaci* geciciBST;
    /* organizmada bulunan sistemlerin içerisindeyiz */
    for(int i = 0; i < yeniOrganizma->getSistemler().size(); i++) {
        /* sistemin içerisinde bulunan organın içerisindeyiz */
        for(int j = 0; j < yeniOrganizma->getSistemler()[i]->getOrganlar().size(); j++) {
            geciciBST = yeniOrganizma->getSistemler()[i]->getOrganlar()[j]->getBST();
            /* if koşuluna girerse BST'nin kök değeri 50 ile kalansız bölünebilmektedir */
            if(geciciBST->getkokOrganValue() %50 == 0) {
                Organ* mutasyonluOrgan = new Organ();
                mutasyonluOrgan = mutasyonaUgrat(yeniOrganizma->getSistemler()[i]->getOrganlar()[j]);
                yeniOrganizma->getSistemler()[i]->getOrganlar()[j]->mutasyonGecir(mutasyonluOrgan);
            }
        }
    }
}

int main() {
    vector <Doku*> dokular;
    vector <Organ*> organlar;
    vector <Sistem*> sistemler;
    Organizma *organizma = new Organizma();

    dokulariOlustur("Veri.txt", dokular);
    organlariOlustur(organlar, dokular);
    // dokular.clear();
    sistemleriOlustur(sistemler, organlar);
    // organlar.clear();
    organizmaOlustur(organizma, sistemler);
    // sistemler.clear();
    cout << "\t\t\t\tORGANIZMA\n";
    organizmayiYazdir(organizma);
    cin.ignore();
    mutasyonKontrolEt(organizma);
    cout << "\t\tORGANIZMA (MUTASYONA UGRADI)\n";
    organizmayiYazdir(organizma);
    // delete organizma;
    system("pause");
    return 0;
}