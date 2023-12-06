#include "../include/AvlTreeList.h"
#include <iostream>

AvlTreeList::AvlDugum::AvlDugum(AvlTree* avlTree) : avlTree(avlTree), onceki(nullptr), sonraki(nullptr), avlToplamDugumDegeri(0) {}

AvlTreeList::AvlTreeList() : bas(nullptr) {}

// avl agaclarini en sona ekler, while dongusu kullanmak yerine son isminde en sondaki
// avl agacinin adresini gosteren bir pointer kullanilir, bu sayede gereksiz yere
// while dongulerinde dolasip en sona eklemeye gerek kalmaz
void AvlTreeList::ekle(AvlTree* avlTree) {
    AvlDugum* yeniDugum = new AvlDugum(avlTree);
    if (bas == nullptr) {
        // daha once hic agac eklenmemisse bas ve son pointerlari yeni dugumu gosterir
        bas = yeniDugum;
        son = yeniDugum;
    } else {
        // yeni gelen dugum son pointerinin sonraki adresine eklenir ve son pointeri bir sonraki adresini gosterir
        yeniDugum->onceki = son;
        son->sonraki = yeniDugum;
        son = son->sonraki;
    }
}

// avl agaclarindaki datalar ekrana bastirilir
void AvlTreeList::agaclariGoruntule() {
    AvlDugum* current = bas;
    while (current != nullptr) {
        current->avlTree->agaciGoster(current->avlTree->kok, 0);
        cout << "---------------------------------------------------\n";
        current = current->sonraki;
    }
}

// postorder olarak avl agaci taranir ve yapraklar yigin'a eklenir,
// sagda ve solda dugum olan (yaprak olmayan) dugumlerin sayi degeri
// avlToplamDugumDegeri degiskeninde toplanir
void AvlTreeList::AvlDugum::postOrderYiginaEkle(Dugum* dugum) {
    if(dugum != nullptr) {
        postOrderYiginaEkle(dugum->sol);
        postOrderYiginaEkle(dugum->sag);
        if(dugum->sag == nullptr && dugum->sol == nullptr) {
            yigin.ekle(dugum->sayi);
        } else {
            avlToplamDugumDegeri += dugum->sayi;
        }
    }
}

// her bir avl agaci icin postOrderYiginaEkle fonksiyonu cagirilir ve
// postorder algoritmasiyla avl agaclari taranir
void AvlTreeList::postOrder() {
    if(bas == nullptr) {
        return;
    }

    AvlDugum* temp = bas;
    while(temp) {
        temp->yigin.yiginiBosalt();
        temp->avlToplamDugumDegeri = 0;
        temp->postOrderYiginaEkle(temp->avlTree->kok);
        temp = temp->sonraki;
    }
    cout << "Postorder olarak yiginlar olusturuldu\n";
}

// avl agaclarinin yapraklariyla olusturulan yiginlar ekranda gosterilir
void AvlTreeList::yiginlariGoruntule() {
    AvlDugum* temp = bas;
    while(temp) {
        cout << "AVLToplamDugumDegeri: " << static_cast<char>(temp->avlToplamDugumDegeri % (90-65+1)+65) << " -> " << (temp->avlToplamDugumDegeri % (90-65+1)+65) << " : " << temp->avlToplamDugumDegeri << " | ";
        temp->yigin.yiginiGoruntule();
        temp = temp->sonraki;
    }
}

// gonderilen avl agaci, avl agaclarinin bulundugu avlTreeList'ten kaldirilir ve silinir
bool AvlTreeList::avlDugumKaldir(AvlDugum* silinecekDugum) {
    if(bas == nullptr) {
        return false;
    }
    // dugum listenin basindaysa listenin basi guncellenir
    if(silinecekDugum == bas) {
        bas = silinecekDugum->sonraki;
    }
    // dugum listenin sonundaysa listenin sonu guncellenir
    if(silinecekDugum == son) {
        son = silinecekDugum->onceki;
        // bu dugum listede bulunan tek dugumse bas da nullptr yapilir
        if(silinecekDugum->onceki == nullptr) {
            bas = nullptr;
        }
    }
    // dugum aradan cikarilir ve silinir
    if(silinecekDugum->onceki != nullptr) {
        silinecekDugum->onceki->sonraki = silinecekDugum->sonraki;
    } if(silinecekDugum->sonraki != nullptr) {
        silinecekDugum->sonraki->onceki = silinecekDugum->onceki;
    }
    delete silinecekDugum;
    return true;
}

// yiginlardan sirasiyla en kucuk ve en buyuk sayilar cikarilarak islemler uygulanir
bool AvlTreeList::yigindanMinMaxCikar() {
    if(bas == nullptr) {
        return false;
    }

    AvlDugum* temp = bas;
    int enKucukSayi = bas->yigin.getYiginBasi();
    int enBuyukSayi = bas->yigin.getYiginBasi();
    // en kucuk sayi bulunduktan sonra tum yiginlari tekrar tarayip fazladan while
    // dongusune girmek yerine en kucuk sayinin bulundugu yigin bir pointera atanir
    // ve en kucuk sayinin arandigi while dongusu tamamlandiktan sonra bu yigin'a
    // cikar (pop) islemi uygulanir. en buyuk sayi icin de ayni mantik uygulanir
    AvlDugum* enKucukYigin = temp;
    AvlDugum* enBuyukYigin = temp;
    // en basta en kucuk olan sayi oldugu stackden cikartilir
    while(temp) {
        // daha kucuk degere sahip yigin bulundu
        if(temp->yigin.getYiginBasi() < enKucukSayi) {
            enKucukSayi = temp->yigin.getYiginBasi();
            enKucukYigin = temp;
        }
        // enBuyukSayi ve yigin guncellenir ancak enKucukSayi'nin bulundugu yigin'a pop
        // islemi uygulandiktan sonra en buyuk sayinin degisip degismedigine bakilir ve
        // duruma gore enBuyukSayi'nin bulundugu yigin'a pop islemi uygulanir.
        // bu sayede en buyuk sayiyi bulmak icin baska bir dongu kullanilmamis olur
        if(temp->yigin.getYiginBasi() > enBuyukSayi) {
            enBuyukSayi = temp->yigin.getYiginBasi();
            enBuyukYigin = temp;
        }
        temp = temp->sonraki;
    }

    cout << "Bulunan en kucuk deger: " << enKucukSayi << endl;
    // en kucuk sayi yigindan cikartilir
    enKucukYigin->yigin.cikar();

    // yigindan en kucuk sayi cikartilinca yigin'in bos olma durumu kontrol edilir
    if(enKucukYigin->yigin.yiginBosMu()) {
        avlDugumKaldir(enKucukYigin);
        return true;
    }

    // en buyuk sayi bulunmasina ragmen pop isleminden sonra, yigindaki deger en buyuk
    // oldugundan en buyuk yigin guncellenir
    if(enBuyukSayi < enKucukYigin->yigin.getYiginBasi()) {
        enBuyukYigin = enKucukYigin;
    }

    cout << "Bulunan en buyuk deger: " << enBuyukYigin->yigin.getYiginBasi() << endl;
    // en buyuk sayi yigindan cikartilir
    enBuyukYigin->yigin.cikar();

    // yigindan en buyuk sayi cikartilinca yigin'in bos olma durumu kontrol edilir
    if(enBuyukYigin->yigin.yiginBosMu()) {
        avlDugumKaldir(enBuyukYigin);
        return true;
    }
    return false;
}