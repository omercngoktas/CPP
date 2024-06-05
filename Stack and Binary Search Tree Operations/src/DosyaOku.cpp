#include "../include/DosyaOku.h"

// en büyük yüksekliğe sahip ağaç aranır, birden fazla en yüksek boya sahip ağaç varsa değerleri
// toplamı en büyük ağaç seçilir, toplamlar da aynıysa index olarak önce olan ağaç seçilir
IkiliAramaAgaci* ikiliAramaAgaciBul(IkiliAramaAgaciListesi* ikili_arama_agaci_listesi) {
    // daha yüksek uzunluğa sahip ya da düğüm toplamı daha büyük olan veya indexi daha önce
    // olan ağaçların bilgileri bu değişkenlerde tutulur
    IkiliAramaAgaci* agac = nullptr;
    int en_uzun_yukseklik = -1;
    int en_uzun_agac_deger_toplami = 0;
    int en_uzun_agac_indexi = -1;
    // sırasıyla tüm ağaçlarda gezilirken kullanılacak index
    int index = 0;
    // o sırada değerleri kontrol edilen ağaç
    IkiliAramaAgaci* suanki_agac = ikili_arama_agaci_listesi->indexleAgacBul(index);

    while (suanki_agac) {
        // şu an kontrol edilen ağacın uzunluk ve değerler toplamını tutan değişkenler
        int suanki_uzunluk = suanki_agac->agacUzunlugu();
        int suanki_degerler_toplami = suanki_agac->degerlerToplami();
        // sırasıyla şu an kontrol edilen ağacın uzunluğu önceki ağaçtan büyükse veya uzunluklar eşit ve değerler toplamı daha büyükse
        // veya uzunlukları ve değerler toplamları eşitse önceki index baz alınır
        if (suanki_uzunluk > en_uzun_yukseklik ||
            (suanki_uzunluk == en_uzun_yukseklik && suanki_degerler_toplami > en_uzun_agac_deger_toplami) ||
            (suanki_uzunluk == en_uzun_yukseklik && suanki_degerler_toplami == en_uzun_agac_deger_toplami && index < en_uzun_agac_indexi)) {
            // şu anki ağacın değerleri daha büyük olduğu için değişkenler güncellenir
            en_uzun_yukseklik = suanki_uzunluk;
            en_uzun_agac_deger_toplami = suanki_degerler_toplami;
            agac = suanki_agac;
            en_uzun_agac_indexi = index;
        }
        // index arttırılır ve suanki_agac bir sonraki ağaçla güncellenir
        index++;
        suanki_agac = ikili_arama_agaci_listesi->indexleAgacBul(index);
    }
    return agac;
}


// güncel satırdaki tüm sayılar stack'lere eklendi ve bu stackler stack_list' yerleştirildi
// stack_list'te gezilip her stack'le bir binary tree oluşturulacak
void ikiliAramaAgacinaEkle(IkiliAramaAgaciListesi* &ikili_arama_agaci_listesi, YiginListesi* &yigin_listesi) {
    // satırdan oluşturulan tüm stacklerde gezmek için index değeri
    int yigin_indexi = 0;
    // güncel olarak değerleri ikili arama ağacına eklenecek stack
    Yigin* guncel_yigin = yigin_listesi->getYigin(yigin_indexi);
    // stack'lerin içinde gezme
    while(guncel_yigin) {
        // stack değerlerinin ekleneceği ikili arama ağacı
        IkiliAramaAgaci* guncel_ikili_arama_agaci = new IkiliAramaAgaci;
        // stack boşaltılana kadar değerleri ikili arama ağacına eklenir
        while(!guncel_yigin->empty()) {
            guncel_ikili_arama_agaci->ekle(guncel_yigin->top());
            guncel_yigin->pop();
        }
        // stack'teki değerlerin eklendiği ikili arama ağaçlarının listeye eklenmesi
        ikili_arama_agaci_listesi->agacEkle(guncel_ikili_arama_agaci);
        yigin_indexi++; // sonraki stack için indexin arttırılması
        guncel_yigin = yigin_listesi->getYigin(yigin_indexi);
    }
}

// dosyadan okunan güncel satırdaki sayının stack'e eklenme işlemi
void yiginaYeniSayiEkle(int eklenecek_sayi, Yigin* &guncel_yigin, YiginListesi* &yigin_listesi) {
    // stack boşsa bellekten yer ayrılır
    if (!guncel_yigin) {
        guncel_yigin = new Yigin;
    } 
    // stack daha önceden oluşturulmuş
    else {
        // yeni gelen sayı çift ve son sayıdan daha büyükse yeni bir stack oluşturulur
        // ve eski stack stacklerin bulunduğu listeye yerleştirilir
        if (eklenecek_sayi > guncel_yigin->top() && eklenecek_sayi % 2 == 0) {
            // yeni stack oluşturulmadan önce şu anki stack stack listesine yerleştirilir
            yigin_listesi->yiginEkle(guncel_yigin);
            // yeni stack oluşturulur
            guncel_yigin = new Yigin;
        }
    }
    // sayı stack'e eklenir
    guncel_yigin->push(eklenecek_sayi);
}

void dosya_oku(string dosya_adi) {
    ifstream input_dosyasi(dosya_adi);
    if (!input_dosyasi) {
        cout << "Dosya adini kontrol edin." << endl;
        return;
    }
    string guncel_satir; // dosyadan okunan satırlar guncel_satir'a koyulur
    // satırdan okunan sayıların stacklere eklenip stacklerin de tutulacağı liste
    YiginListesi* yigin_listesi = new YiginListesi; 
    Yigin* guncel_yigin = nullptr;

    while (getline(input_dosyasi, guncel_satir)) {
        istringstream iss(guncel_satir);
        int guncel_sayi; // satırda okunan güncel sayının bulunduğu değişken
        // güncel satır kurala göre stack'lere eklendikten sonra
        // ikili arama ağaclarına yerleştirilir ve bu ikili arama
        // ağaçları da binary_tree_list'te bulunur
        IkiliAramaAgaciListesi* ikili_arama_agaci_listesi = new IkiliAramaAgaciListesi;

        while (iss >> guncel_sayi) {
            // güncel satırın sayıları okunur ve stack'e eklenir
            yiginaYeniSayiEkle(guncel_sayi, guncel_yigin, yigin_listesi);
        }
        // değerler guncel_stack'e eklendi ve bu stack de listeye eklenir
        yigin_listesi->yiginEkle(guncel_yigin);
        // güncel satıra ait tüm stackler listelere eklendi ve listeden ulaşılıp
        // ikili arama ağaçlarına yerleştirilmesi
        ikiliAramaAgacinaEkle(ikili_arama_agaci_listesi, yigin_listesi);
        ikiliAramaAgaciBul(ikili_arama_agaci_listesi)->goruntule();
        guncel_yigin = nullptr;
        yigin_listesi->yiginlariKaldir();
        delete ikili_arama_agaci_listesi;
        // 10 ms'lik bekleme süresi
        Sleep(10);
    }
    delete yigin_listesi;
    input_dosyasi.close();
}
