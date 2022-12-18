#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <cstddef>
#include <algorithm>
#include <memory>

#include "radixSort.h"
#include "Hucre.h"
#include "BinarySearchTree.h"
#include "Doku.h"
#include "Organ.h"
#include "Organizma.h"
#include "Sistem.h"

#include <time.h>

using namespace std;

void organlariOlustur(string txtDosyaAdi, vector <Organ *> &organListesi) {
    ifstream VeriDosyasi(txtDosyaAdi);
    
    string text;
    int counter = 0, index = 0;

    BinarySearchTree *yeniBST = new BinarySearchTree();
    Organ *yeniOrgan = new Organ();

    while (getline(VeriDosyasi, text)) {
        vector <Doku *> dokuDegerleri;
        vector <int> hucreler = splitBySpace(text);
        radix_sort(hucreler);

        /* radix algoritması ile siralanan hucre sayilari sirasiyla satir satir hucre vectorune eklenir */
        for(int i = 0; i < hucreler.size(); i++) {
            Hucre *yeniHucre = new Hucre();
            yeniHucre->setHucreDegeri(hucreler[i]);
            Doku *yeniDoku = new Doku();
            yeniDoku->setDokuDegerleri(*yeniHucre);
            dokuDegerleri.push_back(yeniDoku);
        }
        // yeniBST->insert(getOrtadakiDoku(dokuDegerleri));
        counter++;
        Hucre *geciciHucre = new Hucre();
        geciciHucre->setHucreDegeri(getOrtadakiDoku(dokuDegerleri).getHucreDegeri());

        yeniOrgan->setBinarySearchTree(geciciHucre);
        if(yeniOrgan->getSizeOfBST() == 20) {
            //cout << "Size: " << yeniOrgan->getSizeOfBST() << endl;
            organListesi.push_back(yeniOrgan);
            yeniOrgan = new Organ();
        }
    }
    // cout << "Size of vector: " << organlar->getBinarySearchTree().size() << endl;
    cout << "Counter : " << counter << endl;
}

void addElement(vector <BinarySearchTree *> &BSTS) {
    BinarySearchTree *BST = new BinarySearchTree();
    Hucre* hucre;

    int counter = 0;
    for(int i = 0; i < 20; i++) {
        BST->insert(* new Hucre());
        counter++;
    }
    //cout << "Counter: " << counter << endl;
    BSTS.push_back(BST);
}

void sistemleriOlustur(vector <Sistem *> &sistemListesi, vector <Organ *> organListesi) {
    Organ *yeniOrgan = new Organ();
    Sistem *yeniSistem = new Sistem();

    for(int i = 0; i < organListesi.size(); i++) {
        yeniSistem->setOrganlar(organListesi[i]);

        if(yeniSistem->getSizeOfOrganlar() == 100) {
            sistemListesi.push_back(yeniSistem);
            yeniSistem = new Sistem();
        }
    }
}

void organizmayiOlustur(Organizma *&organizma, vector <Sistem *> sistemListesi) {
    for(int i = 0; i < sistemListesi.size(); i++) {
        organizma->setSistemler(sistemListesi[i]);
    }
}

void organizmayiYazdir(Organizma *organizma) {
    int counter1 = 0;
    Sistem *sistem;
    Organ *organ;

    for(int i = 0; i < organizma->getSizeOfOrganizma(); i++) {
        sistem = organizma->getSistemler()[i];
        counter1 = 0;
        for(int j = 0; j < sistem->getSizeOfOrganlar(); j++) {
            counter1++;
            organ = sistem->getOrganlar()[j];
            cout << "- ";
        }
        // cout << "Counter1 -> " << counter1 << endl;
        cout << endl;
    }

}

int main() {
    clock_t start = clock();

    vector <Organ *> organListesi;
    vector <Sistem *> sistemListesi;
    Organizma *organizma = new Organizma();

    cout << "Start\n";
    organlariOlustur("Veri.txt", organListesi);
    sistemleriOlustur(sistemListesi, organListesi);
    organizmayiOlustur(organizma, sistemListesi);
    cout << "Size of organListesi : " << organListesi.size() << endl;
    cout << "Size of sistemListesi: " << sistemListesi.size() << endl;
    cout << "Size of organizma: " << organizma->getSizeOfOrganizma() << endl;
    organizmayiYazdir(organizma);


    clock_t end = clock();
    double elapsed = double(end - start)/CLOCKS_PER_SEC;
    cout << "Timer: " << elapsed << endl;
    return 0;
}