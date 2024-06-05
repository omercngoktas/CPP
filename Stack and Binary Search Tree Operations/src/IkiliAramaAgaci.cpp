#include "../include/IkiliAramaAgaci.h"

IkiliAramaAgaci::IkiliAramaAgaci() : kok_dugum(nullptr) {}

AgacDugumu* IkiliAramaAgaci::ekle(AgacDugumu* dugum, int sayi) {
    if (dugum == nullptr) {
        return new AgacDugumu(sayi);
    }

    if (sayi < dugum->sayi) {
        dugum->sol = ekle(dugum->sol, sayi);
    } else if (sayi > dugum->sayi) {
        dugum->sag = ekle(dugum->sag, sayi);
    } else {
        return dugum;
    }

    return dugum;
}

void IkiliAramaAgaci::ekle(int sayi) {
    kok_dugum = ekle(kok_dugum, sayi);
}

void IkiliAramaAgaci::goruntule() {
    postorderTraversal(kok_dugum);
    cout << endl;
}

int IkiliAramaAgaci::agacUzunlugu(AgacDugumu* dugum) {
    if (dugum == nullptr) {
        return -1;
    }

    int sol_uzunluk = agacUzunlugu(dugum->sol);
    int sag_uzunluk = agacUzunlugu(dugum->sag);

    return 1 + max(sol_uzunluk, sag_uzunluk);
}


int IkiliAramaAgaci::agacUzunlugu() {
    return agacUzunlugu(kok_dugum);
}

int IkiliAramaAgaci::degerlerToplami(AgacDugumu* dugum) {
    if (dugum == nullptr) {
        return 0;
    }

    return dugum->sayi + degerlerToplami(dugum->sol) + degerlerToplami(dugum->sag);
}

int IkiliAramaAgaci::degerlerToplami() {
    return degerlerToplami(kok_dugum);
}

void IkiliAramaAgaci::postorderTraversal(AgacDugumu* dugum) {
    if (dugum != nullptr) {
        postorderTraversal(dugum->sol);
        postorderTraversal(dugum->sag);
        cout << char(dugum->sayi) << " ";
    }
}

void IkiliAramaAgaci::postorderTraversal() {
    postorderTraversal(kok_dugum);
}

IkiliAramaAgaciListesi::IkiliAramaAgaciListesi() : bas(nullptr), son(nullptr) {}

IkiliAramaAgaciListesi::~IkiliAramaAgaciListesi() {
    Dugum* suanki_dugum = bas;
    while (suanki_dugum) {
        Dugum* next = suanki_dugum->next;
        delete suanki_dugum->tree;
        delete suanki_dugum;
        suanki_dugum = next;
    }
}

void IkiliAramaAgaciListesi::agacEkle(IkiliAramaAgaci* yeni_agac) {
    Dugum* yeni_dugum = new Dugum(yeni_agac);

    if (!bas) {
        bas = yeni_dugum;
        son = yeni_dugum;
    } else {
        son->next = yeni_dugum;
        son = yeni_dugum;
    }
}

IkiliAramaAgaci* IkiliAramaAgaciListesi::indexleAgacBul(int index) const {
    Dugum* yeni_dugum = bas;
    int sayac = 0;

    while (yeni_dugum) {
        if (sayac == index) {
            return yeni_dugum->tree;
        }
        sayac++;
        yeni_dugum = yeni_dugum->next;
    }

    return nullptr;
}