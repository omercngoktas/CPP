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
    int agacNumarasi = 1;
    while (getline(sayilarDosyasi, satir)) {
        istringstream ss(satir);
        AvlTree* avlTree = new AvlTree();
        int sayi;
        while (ss >> sayi) {
            avlTree->kok = avlTree->sayiEkle(avlTree->kok, sayi);
        }
        avlTreeList->ekle(avlTree, agacNumarasi);
        agacNumarasi++;
    }
    sayilarDosyasi.close();
}

int main() {
    // txt dosyasindan okunan her bir satirdaki sayilar avlTree'ye eklenir,
    // her bir satir avlTree olusturur ve avlTree'lerin her biri avlTreeList'e eklenir
    AvlTreeList* avlTreeList = new AvlTreeList;

    const string dosyaYolu = "../bin/Veri.txt";
    ifstream file(dosyaYolu);
    
    if (!file.is_open()) {
        cerr << "Dosya acilamadi: " << dosyaYolu << endl;
        return 1;
    }

    // dosyadan okunan tum sayilar avlTree'lere eklenerek avlTreeList'te tutulur
    openFile(file, avlTreeList);

    avlTreeList->agaclariGoruntule();

    do
    {
        if(avlTreeList->bas == nullptr) {
            break;
        }
        avlTreeList->postOrder();
        avlTreeList->yiginlariGoruntule();
        int dugumCikarildiMi;
        int agacNumarasi;
        int sonKarakter;
        do
        {
            agacNumarasi = avlTreeList->bas->agacNumarasi;
            sonKarakter = avlTreeList->bas->avlToplamDugumDegeri;
            dugumCikarildiMi = avlTreeList->yigindanMinMaxCikar();
            if(avlTreeList->bas == nullptr && dugumCikarildiMi == 1) {
                int agacNumarasiKarakterUzunlugu = to_string(agacNumarasi).length();
                cout << "==============================" << endl;
                cout << "|                            |" << endl;
                cout << "|                            |" << endl;
                cout << "|     Son Karakter: " << static_cast<char>(sonKarakter % (90-65+1)+65) << "        |" << endl;
                cout << "|     AVL No      : " << agacNumarasi;
                for(int i = 21; i < 30 - agacNumarasiKarakterUzunlugu; i++) { cout << " "; }
                cout << "|" << endl;
                cout << "|                            |" << endl;
                cout << "|                            |" << endl;
                cout << "==============================" << endl;
            }

        } while (!dugumCikarildiMi);

    } while (true);
    
    /*
        firstly, create stack with postorder algorithm,
        then apply pop -> first to the smallest one then
        to the biggest one until one of the stack becomes empty
    */

    
    
    return 0;
}