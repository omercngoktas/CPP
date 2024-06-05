#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstdint>


#include "../include/Sayi.h"
#include "../include/Basamak.h"
#include "../include/Dugum.h"
#include "../include/SayilarListesi.h"

using namespace std;

void openFile(ifstream& sayilarDosyasi, SayilarListesi* sayilarListesi) {
    string satir;
    while (getline(sayilarDosyasi, satir)) {
        istringstream ss(satir);
        int sayi;
        while (ss >> sayi) {
            Sayi* yeniSayi = new Sayi();
            while (sayi > 0) {
                int basamak = sayi % 10;
                yeniSayi->ekleBasamak(basamak);
                sayi /= 10;
            }
            sayilarListesi->sayiEkle(yeniSayi);
        }
    }
    sayilarDosyasi.close();
}

int main() {
    ifstream sayilarDosyasi("../bin/sayilar.txt");
    if (!sayilarDosyasi) {
        cerr << "Dosya acilamadi." << endl;
        return 1;
    }

    SayilarListesi* sayilarListesi = new SayilarListesi();
    openFile(sayilarDosyasi, sayilarListesi);

    sayilarListesi->ekranaYaz();
    int secim;

    do {
        std::cout << "1. Tek basamaklari Basa Al\n";
        std::cout << "2. Basamaklari Tersle\n";
        std::cout << "3. En Buyuk Cikar\n";
        std::cout << "4. Cikis\n";
        std::cin >> secim;

        switch (secim) {
            case 1:
                sayilarListesi->tekleriBasaAl();
                sayilarListesi->ekranaYaz();
                break;
            case 2:
                sayilarListesi->basamaklariTersle();
                sayilarListesi->ekranaYaz();
                break;
            case 3:
                sayilarListesi->enBuyuguCikar();
                sayilarListesi->ekranaYaz();
                break;
            case 4:
                break;
            default:
                std::cout << "Geçersiz secim. Tekrar deneyin.\n";
        }

    } while (secim != 4);    
    
    return 0;
}
