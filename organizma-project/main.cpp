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

void organlariOlustur(string txtDosyaAdi, Organ* &organlar) {
    ifstream VeriDosyasi(txtDosyaAdi);
    
    string text;
    int counter = 0;
    BinarySearchTree *yeniBST = new BinarySearchTree();

    while (getline(VeriDosyasi, text)) {
        vector <Doku *> dokuDegerleri;
        vector <int> hucreler = tokenize(text);
        radix_sort(hucreler);

        /* radix algoritması ile siralanan hucre sayilari sirasiyla satir satir hucre vectorune eklenir */
        for(int i = 0; i < hucreler.size(); i++) {
            Hucre *yeniHucre = new Hucre();
            yeniHucre->setHucreDegeri(hucreler[i]);
            Doku *yeniDoku = new Doku();
            yeniDoku->setDokuDegerleri(*yeniHucre);
            dokuDegerleri.push_back(yeniDoku);
        }
        yeniBST->insert(getOrtadakiDoku(dokuDegerleri));
        counter++;
        if(counter > 19) {
            counter = 0;
            organlar->setBinarySearchTree(yeniBST);
            yeniBST = new BinarySearchTree();
        }
        
        
    }
    // cout << "Size of vector: " << organlar->getBinarySearchTree().size() << endl;
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


int main() {
    clock_t start = clock();
    
    Organ *organlar = new Organ();
    vector <Organ *> organListesi;
    vector <BinarySearchTree *> BSTs;

    cout << "Start\n";
    organlariOlustur("Veri.txt", organlar);

    organlar->displayBinarySearchTrees(organlar->getBinarySearchTree());

    clock_t end = clock();
    double elapsed = double(end - start)/CLOCKS_PER_SEC;
    cout << "Timer: " << elapsed << endl;
    return 0;
}