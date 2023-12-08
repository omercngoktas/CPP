#include "../include/AvlTree.h"

Dugum::Dugum(int sayi) : sayi(sayi), yukseklik(1), sol(nullptr), sag(nullptr) {}

AvlTree::AvlTree() : kok(nullptr) {}

// dugumun bulundugu yuksekligi dondurur
int AvlTree::getYukseklik(Dugum* dugum) {
    if(dugum == nullptr) {
        return 0;
    } else {
        return dugum->yukseklik;
    }
}

// agacin sol ve sag dugumlerine bakarak dengede olup olmadigi anlasilir
int AvlTree::getDenge(Dugum* dugum) {
    if(dugum == nullptr) {
        return 0;
    } else {
        return getYukseklik(dugum->sol) - getYukseklik(dugum->sag);
    }
}

// agactaki dengesizligi gidererek agaci dengeler
Dugum* AvlTree::sagaDondur(Dugum* dugum) {
    Dugum* solCocuk = dugum->sol;
    Dugum* sagCocuk = solCocuk->sag;

    solCocuk->sag = dugum;
    dugum->sol = sagCocuk;

    dugum->yukseklik = 1 + max(getYukseklik(dugum->sol), getYukseklik(dugum->sag));
    solCocuk->yukseklik = 1 + max(getYukseklik(solCocuk->sol), getYukseklik(solCocuk->sag));
    
    return solCocuk;
}

// agactaki dengesizligi gidererek agaci dengeler
Dugum* AvlTree::solaDondur(Dugum* dugum) {
    Dugum* sagCocuk = dugum->sag;
    Dugum* solCocuk = sagCocuk->sol;

    sagCocuk->sol = dugum;
    dugum->sag = solCocuk;

    dugum->yukseklik = 1 + max(getYukseklik(dugum->sol), getYukseklik(dugum->sag));
    sagCocuk->yukseklik = 1 + max(getYukseklik(sagCocuk->sol), getYukseklik(sagCocuk->sag));
    
    return sagCocuk;
}

// agaci dengeler
Dugum* AvlTree::agaciDengele(Dugum* dugum) {
    if (dugum == nullptr) {
        return dugum;
    }

    dugum->yukseklik = 1 + max(getYukseklik(dugum->sol), getYukseklik(dugum->sag));
    int denge = getDenge(dugum);

    // Sol-Sol Durumu
    if (denge > 1 && getDenge(dugum->sol) >= 0) {
        return sagaDondur(dugum);
    }
    // Sağ-Sağ Durumu
    if (denge < -1 && getDenge(dugum->sag) <= 0) {
        return solaDondur(dugum);
    }
    // Sol-Sağ Durumu
    if (denge > 1 && getDenge(dugum->sol) < 0) {
        dugum->sol = solaDondur(dugum->sol);
        return sagaDondur(dugum);
    }
    // Sağ-Sol Durumu
    if (denge < -1 && getDenge(dugum->sag) > 0) {
        dugum->sag = sagaDondur(dugum->sag);
        return solaDondur(dugum);
    }
    return dugum;
}

// avl agacini display eder
void AvlTree::agaciGoster(Dugum* kok, int seviye) {
    if (kok != nullptr) {
        agaciGoster(kok->sag, seviye + 1);
        for (int i = 0; i < seviye; i++) {
            cout << "      ";
        }
            
        cout << kok->sayi << "\n";
        agaciGoster(kok->sol, seviye + 1);
    }
}

// gonderilen dugumu agactan kaldirir ve bellekten siler
void AvlTree::agaciTemizle(Dugum* dugum) {
    if (dugum != nullptr) {
        agaciTemizle(dugum->sol);
        agaciTemizle(dugum->sag);
        delete dugum;
    }
}

// gelen sayiyi avl agacina ekler
Dugum* AvlTree::sayiEkle(Dugum* dugum, int sayi) {
    // agacta daha once sayi yoksa
    if (dugum == nullptr) {
        return new Dugum(sayi);
    }
    // sayi dugumde bulunan sayidan kucukse agacin soluna eklenir
    if (sayi < dugum->sayi) {
        dugum->sol = sayiEkle(dugum->sol, sayi);
    
    }
    // sayi dugumden daha buyukse dugumun sagina eklenir
    else if (sayi > dugum->sayi) {
        dugum->sag = sayiEkle(dugum->sag, sayi);
    }
    // sayi dugume esitse eklenmeden dugum return edilir
    else {
        return dugum;
    }
    // eklenme isleminden sonra agacin yuksekligi onceki uzunluga 1 eklenerek guncellenir
    dugum->yukseklik = 1 + max(getYukseklik(dugum->sol), getYukseklik(dugum->sag));
    // eklenme islemi bittikten sonra agac dengelenir
    return agaciDengele(dugum);
}

// // post order mantigi ile agac taranarak yapraklar stack'e eklenir,
// // yigin'a eklenmeyen sayilara verilen islem uygulanir (toplamdugumdegeri % (90-65+1) + 65)
// void AvlTree::postOrder(Dugum* dugum) {
//     if(dugum != NULL) {
//         postOrder(dugum->sol);
//         postOrder(dugum->sag);
//         if(dugum->sag == nullptr && dugum->sol == nullptr) {
//             cout << dugum->sayi << " ";
//         }
//     }
// }