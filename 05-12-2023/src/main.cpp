#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstdint>

#include "../include/AvlTree.h"
#include "../include/AvlTreeList.h"
#include "../include/Yigin.h"

using namespace std;

void openFile(ifstream& sayilarDosyasi, AvlTreeList* avlTreeList) {
    string satir;
    while (getline(sayilarDosyasi, satir)) {
        istringstream ss(satir);
        AvlTree* avlTree = new AvlTree();
        int sayi;
        while (ss >> sayi) {
            avlTree->kok = avlTree->sayiEkle(avlTree->kok, sayi);
        }
        avlTreeList->ekle(avlTree);
    }
    sayilarDosyasi.close();
}

int main() {
    // txt dosyasindan okunan her bir satirdaki sayilar avlTree'ye eklenir,
    // her bir satir avlTree olusturur ve avlTree'lerin her biri avlTreeList'e eklenir
    AvlTreeList* avlTreeList = new AvlTreeList;

    const string dosyaYolu = "../bin/sayilar.txt";
    ifstream file(dosyaYolu);
    
    if (!file.is_open()) {
        cerr << "Dosya acilamadi: " << dosyaYolu << endl;
        return 1;
    }

    // dosyadan okunan tum sayilar avlTree'lere eklenerek avlTreeList'te tutulur
    openFile(file, avlTreeList);


    avlTreeList->postOrder();
    avlTreeList->yiginlariGoruntule();
    
    avlTreeList->postOrder();
    avlTreeList->yiginlariGoruntule();

    avlTreeList->postOrder();
    avlTreeList->yiginlariGoruntule();

    avlTreeList->postOrder();
    avlTreeList->yiginlariGoruntule();

    avlTreeList->avlDugumKaldir(avlTreeList->bas);
    avlTreeList->postOrder();
    avlTreeList->yiginlariGoruntule();

    avlTreeList->avlDugumKaldir(avlTreeList->bas);
    avlTreeList->postOrder();
    avlTreeList->yiginlariGoruntule();

    avlTreeList->avlDugumKaldir(avlTreeList->bas);
    avlTreeList->postOrder();
    avlTreeList->yiginlariGoruntule();

    cout << "*****************\n";
    avlTreeList->avlDugumKaldir(avlTreeList->bas);
    avlTreeList->postOrder();
    avlTreeList->yiginlariGoruntule();
    cout << "*****************\n";
    avlTreeList->avlDugumKaldir(avlTreeList->bas);
    avlTreeList->postOrder();
    avlTreeList->yiginlariGoruntule();
    cout << "*****************\n";
    avlTreeList->avlDugumKaldir(avlTreeList->bas);
    avlTreeList->postOrder();
    avlTreeList->yiginlariGoruntule();
    cout << "*****************\n";
    avlTreeList->avlDugumKaldir(avlTreeList->bas);
    avlTreeList->postOrder();
    avlTreeList->yiginlariGoruntule();

    do
    {
        
    } while (true);
    
    

    
    

    return 0;
}