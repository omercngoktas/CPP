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
#include "Kontrol.h"

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
    Kontrol* kontrol = new Kontrol(organizma);
    kontrol->mutasyonKontrolEt();

    // mutasyonKontrolEt(organizma);
    cout << "\t\tORGANIZMA (MUTASYONA UGRADI)\n";
    organizmayiYazdir(organizma);
    // delete organizma;
    system("pause");
    return 0;
}