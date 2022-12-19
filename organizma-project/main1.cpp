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
#include "BinarySearchTree.h"
#include "Doku.h"
#include "Organ.h"
#include "Organizma.h"
#include "Sistem.h"

#include <time.h>

using namespace std;

void dokulariOlustur(string txtDosyaAdi, vector <Doku *> &dokular) {
    ifstream VeriDosyasi(txtDosyaAdi);
    string text;
    int counter = 0, index = 0;

    while (getline(VeriDosyasi, text)) {
        vector <int> hucreler = splitBySpace(text);
        counter++;
        Doku *yeniDoku = new Doku();
        for(int i = 0; i < hucreler.size(); i++) {
            Hucre *yeniHucre = new Hucre();
            yeniHucre->setHucreDegeri(hucreler[i]);
            yeniDoku->setDokuDegerleri(yeniHucre);
        }
        yeniDoku->setOrtaDeger();
        dokular.push_back(yeniDoku);
    }
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
            //vector <Doku *> geciciDokular;
            counter++;
        }
    }
}

void ekranaBastir(vector <Organ*> organlar) {
    for(int i = 0; i < organlar.size(); i++) {
        int balanceDegeri = organlar[i]->getBST()->checkBalance();
        if(balanceDegeri > 0) {
            cout << " ";
        } else {
            cout << "#";
        }
        if(i %100 == 0) cout << endl;
    }
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
}

void organizmaOlustur(Organizma* &organizma, vector <Sistem*> sistemler) {
    for(int i = 0; i < sistemler.size(); i++) {
        organizma->setSistemler(sistemler[i]);
    }
}

void ekranaYazdir(Organizma* organizma) {
    for(int i = 0; i < organizma->getSistemler().size(); i++) {
        for(int j = 0; j < organizma->getSistemler()[i]->getOrganlar().size(); j++) {
            int dengeDegeri = organizma->getSistemler()[i]->getOrganlar()[j]->getBST()->checkBalance();
            if(dengeDegeri > 0) { cout << " "; }
            else { cout << "#"; }
        }
        cout << endl;
    }
}

void mutasyonaUgrat(Organizma* &organizma) {
    int sistemSayisi = organizma->getSistemler().size();
    int organSayisi = organizma->getSistemler()[0]->getOrganlar().size();
    cout << "Organ sayisi->" << organSayisi << endl;
    Organizma* yeniOrganizma = new Organizma();
    int counter = 0;
    for(int i = 0; i < sistemSayisi; i++) {
        for(int j = 0; j < organizma->getSistemler()[i]->getOrganlar().size(); j++) {
            if(organizma->getSistemler()[i]->getOrganlar()[j]->getBST()->getRootValue() %50 == 0) {
                cout << organizma->getSistemler()[i]->getOrganlar()[j]->getBST()->getRootValue() << "\t";
                
                counter++;
            }
        }
    }
    cout << endl;
    cout << "Coutner : " << counter << endl;
}

int main() {
    clock_t start = clock();
    vector <Doku*> dokular;
    vector <Organ*> organlar;
    vector <Sistem*> sistemler;
    Organizma *organizma = new Organizma();

    dokulariOlustur("Veri.txt", dokular);
    organlariOlustur(organlar, dokular);
    dokular.clear();
    sistemleriOlustur(sistemler, organlar);
    organlar.clear();
    organizmaOlustur(organizma, sistemler);
    sistemler.clear();
    ekranaYazdir(organizma);
    // cin.ignore();
    mutasyonaUgrat(organizma);

    clock_t end = clock();
    double elapsed = double(end - start)/CLOCKS_PER_SEC;
    cout << "Timer: " << elapsed << endl;
    return 0;
}