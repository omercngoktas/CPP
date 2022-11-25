#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Soru {
    private:
        int id;
        string soruMetni;
        int soruPuani;
        string zorlukDerecesi;

    public:
        void setId(int soruId) { id = soruId; }
        int getId() { return id; }
        void setSoruMetni(string soruM) { soruMetni = soruM; }
        string getSoruMetni() { return soruMetni; }
        void setSoruPuani(int soruP) { soruPuani = soruP; }
        int getSoruPuani() { return soruPuani; }
        void setZorlukDerecesi(string zorlukD) { zorlukDerecesi = zorlukD; }
        string getZorlukDerecesi() { return zorlukDerecesi; }
        void setSoru(int id, string soruMetni, int soruPuani, string zorlukDerecesi) {
            setId(id);
            setSoruMetni(soruMetni);
            setSoruPuani(soruPuani);
            setZorlukDerecesi(zorlukDerecesi);
        }
};

class CoktanSecmeliSoru: public Soru {
    private:
        vector <string> soruSiklari;
        string dogruCevap;
    
    public:
        void setSoruSikki(vector <string> yeniCoktanSecmeliCevabi) { soruSiklari = yeniCoktanSecmeliCevabi; }
        vector <string> getSoruSiklari() { return soruSiklari; }
        void setDogruCevap(string dogruC) { dogruCevap = dogruC; }
        string getDogruCevap() { return dogruCevap; }
        void setCoktanSecmeliSoru(int id, string soruMetni, int soruPuani, string zorlukDerecesi, string dogruCevap, vector <string> soruSikki) {
            setSoru(id, soruMetni, soruPuani, zorlukDerecesi);
            setSoruSikki(soruSikki);
            setDogruCevap(dogruCevap);
        }
};

class DogruYanlisSoru: public Soru {
    private:
        string dogruCevap;

    public:
        void setDogruCevap(string dogruC) { dogruCevap = dogruC; }
        string getDogruCevap() { return dogruCevap; }
        void setDogruYanlisSoru(int id, string soruMetni, int soruPuani, string zorlukDerecesi, string dogruCevap) {
            setSoru(id, soruMetni, soruPuani, zorlukDerecesi);
            setDogruCevap(dogruCevap);
        }
};

class KlasikSoru: public Soru {
    private:
        string soruCevabi;

    public:
        void setSoruCevabi(string soruC) { soruCevabi = soruC; }
        string getSoruCevabi() { return soruCevabi; }
        void setKlasikSoru(int id, string soruMetni, int soruPuani, string zorlukDerecesi, string dogruCevap) {
            setSoru(id, soruMetni, soruPuani, zorlukDerecesi);
            setSoruCevabi(dogruCevap);
        }
};

class BoslukDoldurma: public Soru {
    private:
        string boslukCevabi;

    public:
        void setBoslukCevabi(string boslukC) { boslukCevabi = boslukC; }
        string getBoslukCevabi() { return boslukCevabi; }
        void setBoslukDoldurmaSorusu(int id, string soruMetni, int soruPuani, string zorlukDerecesi, string dogruCevap) {
            setSoru(id, soruMetni, soruPuani, zorlukDerecesi);
            setBoslukCevabi(dogruCevap);
        }
};

class Sinav {

};

/* çoktan seçmeli soru bilgilerinin kullanıcı tarafından alınmasında ve vector'e eklenmesinde kullanılır */
void coktanSecmeliSoruEkle(vector <CoktanSecmeliSoru> &CoktanSecmeliSorular) {
    CoktanSecmeliSoru YeniCoktanSecmeliSorusu;
    string soruMetni, zorlukDerecesi, a, b, c, d;
    int soruPuani;
    string dogruCevap;
    vector <string> cevaplar;

    cout << "Coktan secmeli soru metnini giriniz: ";
    getline(cin >> ws, soruMetni);
    cout << "A sikkini giriniz: ";
    getline(cin >> ws, a);
    cout << "B sikkini giriniz: ";
    getline(cin >> ws, b);
    cout << "C sikkini giriniz: ";
    getline(cin >> ws, c);
    cout << "D sikkini giriniz: ";
    getline(cin >> ws, d);
    cout << "Sorunun cevabini giriniz (Soru cevabi A ise a giriniz): ";
    cin >> dogruCevap;
    cout << "Sorunun zorluk derecesini giriniz (kolay-orta-zor): ";
    cin >> zorlukDerecesi;
    cout << "Soru puanini giriniz: ";
    cin >> soruPuani;

    cevaplar.push_back(a);
    cevaplar.push_back(b);
    cevaplar.push_back(c);
    cevaplar.push_back(d);
    YeniCoktanSecmeliSorusu.setCoktanSecmeliSoru(999, soruMetni, soruPuani, zorlukDerecesi, dogruCevap, cevaplar);    
    CoktanSecmeliSorular.push_back(YeniCoktanSecmeliSorusu);
}

/* klasik soru bilgisinin kullanıcıdan alınmasında ve vector'e eklenmesinde kullanılır */
void klasikSoruEkle(vector <KlasikSoru> &KlasikSorular) {
    KlasikSoru YeniKlasikSorusu;
    string soruMetni, zorlukDerecesi, soruCevabi;
    int soruPuani;

    cout << "Klasik soru metnini giriniz: ";
    getline(cin >> ws, soruMetni);
    cout << "Klasik sorunun cevabini giriniz: ";
    getline(cin >> ws, soruCevabi);
    cout << "Sorunun zorluk derecesini giriniz (kolay-orta-zor): ";
    cin >> zorlukDerecesi;
    cout << "Soru puanini giriniz: ";
    cin >> soruPuani;

    YeniKlasikSorusu.setKlasikSoru(999, soruMetni, soruPuani, zorlukDerecesi, soruCevabi);

    KlasikSorular.push_back(YeniKlasikSorusu);
}

/* doğru yanlış soru bilgisinin alınmasında ve vector'e eklenmesinde kullanılır */
void dogruYanlisSoruEkle(vector <DogruYanlisSoru> &DogruYanlisSorulari) {
    DogruYanlisSoru YeniDogruYanlisSorusu;
    string soruMetni, zorlukDerecesi;
    string soruCevabi;
    int soruPuani;

    cout << "Dogru/Yanlis sorusunun metnini giriniz: ";
    getline(cin >> ws, soruMetni);
    cout << "Dogru/Yanlis sorusunun cevabini giriniz (Y/N): ";
    cin >> soruCevabi;
    cout << "Dogru/Yanlis sorusunun zorluk derecesini giriniz (kolay-orta-zor): ";
    cin >> zorlukDerecesi;
    cout << "Dogru/Yanlis sorusunun puanini giriniz: ";
    cin >> soruPuani;

    YeniDogruYanlisSorusu.setDogruYanlisSoru(999, soruMetni, soruPuani, zorlukDerecesi, soruCevabi);

    DogruYanlisSorulari.push_back(YeniDogruYanlisSorusu);
}

/* boşluk doldurma sorusu bilgisinin alınmasında ve vector'e eklenmesinde kullanılır */
void boslukDoldurmaSoruEkle(vector <BoslukDoldurma> &BoslukDoldurmaSorulari) {
    BoslukDoldurma YeniBoslukDoldurmaSorusu;
    string soruMetni, zorlukDerecesi, soruCevabi;
    int soruPuani;

    cout << "Bosluk doldurma metnini giriniz (bosluk birakmayi unutmayiniz): ";
    getline(cin >> ws, soruMetni);
    cout << "Bosluk doldurma sorusunun cevabini giriniz: ";
    getline(cin >> ws, soruCevabi);
    cout << "Bosluk doldurma sorusunun zorluk derecesini giriniz (kolay-orta-zor): ";
    cin >> zorlukDerecesi;
    cout << "Bosluk doldurma sorusunun puanini giriniz: ";
    cin >> soruPuani;

    YeniBoslukDoldurmaSorusu.setBoslukDoldurmaSorusu(999, soruMetni, soruPuani, zorlukDerecesi, soruCevabi);

    BoslukDoldurmaSorulari.push_back(YeniBoslukDoldurmaSorusu);
}

/*
    kullanıcı soru bankasına soru eklemek istediği zaman bu bu fonksiyon çağrılır,
    bu fonksiyon da menüyü bastırarak eklenmek istenen soru tipine göre gerekli
    olan fonksiyonları çağırır
*/
void soruEkle (
    vector <CoktanSecmeliSoru> &CoktanSecmeliSorular,
    vector <DogruYanlisSoru> &DogruYanlisSorulari,
    vector <BoslukDoldurma> &BoslukDoldurmaSorulari,
    vector <KlasikSoru> &KlasikSorular
) {
    int soruCesidi;

    while(true) {
        cout << "1- Coktan secmeli soru" << endl;
        cout << "2- Klasik soru" << endl;
        cout << "3- Dogru yanlis sorusu" << endl;
        cout << "4- Bosluk doldurmali soru" << endl;
        cout << "5- Ana menuye don" << endl;
        cout << "Eklemek istediginiz soru cesidi nedir?: ";
        cin >> soruCesidi;
        
        switch (soruCesidi)
        {
            case 1:
                coktanSecmeliSoruEkle(CoktanSecmeliSorular);
                return;

            case 2:
                klasikSoruEkle(KlasikSorular);
                break;

            case 3:
                dogruYanlisSoruEkle(DogruYanlisSorulari);
                break;

            case 4:
                boslukDoldurmaSoruEkle(BoslukDoldurmaSorulari);
                break;

            case 5:
                cout << "Ana menuye donuluyor." << endl;
                return;

            default:
                cout << "Gecersiz islem girdiniz. Tekrar deneyiniz." << endl;
                continue;
        }
    }
}

void CoktanSecmeliSorulariListele(vector <CoktanSecmeliSoru> CoktanSecmeliSorular) {
    for(int i = 0; i < CoktanSecmeliSorular.size(); i++) {
        cout << "ID: " << CoktanSecmeliSorular[i].getId() << endl;
        cout << "Soru: " << CoktanSecmeliSorular[i].getSoruMetni() << endl;
        cout << "a) " << CoktanSecmeliSorular[i].getSoruSiklari()[0] << endl;
        cout << "b) " << CoktanSecmeliSorular[i].getSoruSiklari()[1] << endl;
        cout << "c) " << CoktanSecmeliSorular[i].getSoruSiklari()[2] << endl;
        cout << "d) " << CoktanSecmeliSorular[i].getSoruSiklari()[3] << endl;
        cout << "Soru puani: " << CoktanSecmeliSorular[i].getSoruPuani() << endl;
        cout << "Soru zorlugu: " << CoktanSecmeliSorular[i].getZorlukDerecesi() << endl;
        cout << "Soru cevabi: " << CoktanSecmeliSorular[i].getDogruCevap() << endl;
        cout << "-------------------------------------------------------------------------" << endl;
    }
}

vector <string> tokenize(string s, string del = " ") {
    int start, end = -1*del.size();
    vector <string> soruVectoru;
    do {
        start = end + del.size();
        end = s.find(del, start);
        //cout << s.substr(start, end - start) << endl;
        //cout << "test -> " << s << endl;
        soruVectoru.push_back(s.substr(start, end - start));
    } while (end != -1);
    return soruVectoru;
}

void coktanSecmeliTxtdenEkle(string textFileName, vector <CoktanSecmeliSoru> &CoktanSecmeliSorular) {
    int id, soruPuani;
    string aSikki, bSikki, cSikki, dSikki, soruMetni, soruCevabi, zorlukDerecesi, textMetni, idString, soruPuaniString;
    ifstream coktanSecmeliText(textFileName);
    vector <string> coktanSecmeli;

    while(getline(coktanSecmeliText, textMetni)) {
        coktanSecmeli = tokenize(textMetni, "\t");
        id = stoi(coktanSecmeli[0]);
        soruMetni = coktanSecmeli[1];
        aSikki = coktanSecmeli[2];
        bSikki = coktanSecmeli[3];
        cSikki = coktanSecmeli[4];
        dSikki = coktanSecmeli[5];
        soruCevabi = coktanSecmeli[6];
        soruPuani = stoi(coktanSecmeli[7]);
        zorlukDerecesi = coktanSecmeli[8];
        vector <string> cevaplar;
        cevaplar.push_back(aSikki);
        cevaplar.push_back(bSikki);
        cevaplar.push_back(cSikki);
        cevaplar.push_back(dSikki);
        
        CoktanSecmeliSoru geciciCoktanSecmeli;
        geciciCoktanSecmeli.setCoktanSecmeliSoru(id, soruMetni, soruPuani, zorlukDerecesi, soruCevabi, cevaplar);
        CoktanSecmeliSorular.push_back(geciciCoktanSecmeli);
    }
}

void dogruYanlisTxtdenEkle(string textFileName, vector <DogruYanlisSoru> &DogruYanlisSorulari) {
    int id, soruPuani;
    string soruMetni, soruCevabi, soruZorlugu, textMetni;
    ifstream dogruYanlisText(textFileName);
    vector <string> dogruYanlis;

    while(getline(dogruYanlisText, textMetni)) {
        dogruYanlis = tokenize(textMetni, "\t");
        id = stoi(dogruYanlis[0]);
        soruMetni = dogruYanlis[1];
        soruCevabi = dogruYanlis[2];
        soruPuani = stoi(dogruYanlis[3]);
        soruZorlugu = dogruYanlis[4];
        DogruYanlisSoru geciciDogruYanlis;
        geciciDogruYanlis.setDogruYanlisSoru(id, soruMetni, soruPuani, soruZorlugu, soruCevabi);
        DogruYanlisSorulari.push_back(geciciDogruYanlis);
    }
}

void boslukDoldurmaTxtdenEkle(string textFileName, vector <BoslukDoldurma> &BoslukDoldurmaSorulari) {
    int id, soruPuani;
    string soruMetni, soruCevabi, soruZorlugu, textMetni;
    ifstream boslukDoldurmaText(textFileName);
    vector <string> boslukDoldurma;

    while(getline(boslukDoldurmaText, textMetni)) {
        boslukDoldurma = tokenize(textMetni, "\t");
        id = stoi(boslukDoldurma[0]);
        soruMetni = boslukDoldurma[1];
        soruCevabi = boslukDoldurma[2];
        soruPuani = stoi(boslukDoldurma[3]);
        soruZorlugu = boslukDoldurma[4];
        BoslukDoldurma geciciBoslukDoldurma;
        geciciBoslukDoldurma.setBoslukDoldurmaSorusu(id, soruMetni, soruPuani, soruZorlugu, soruCevabi);
        BoslukDoldurmaSorulari.push_back(geciciBoslukDoldurma);
    }
}

void klasikSoruTxtdenEkle(string textFileName, vector <KlasikSoru> &KlasikSorular) {
    int id, soruPuani;
    string soruMetni, soruCevabi, soruZorlugu, textMetni;
    ifstream klasikSoruText(textFileName);
    vector <string> klasikSoru;
    
    while(getline(klasikSoruText, textMetni)) {
        klasikSoru = tokenize(textMetni, "\t");
        id = stoi(klasikSoru[0]);
        soruMetni = klasikSoru[1];
        soruCevabi = klasikSoru[2];
        soruPuani = stoi(klasikSoru[3]);
        soruZorlugu = klasikSoru[4];
        KlasikSoru geciciKlasikSoru;
        geciciKlasikSoru.setKlasikSoru(id, soruMetni, soruPuani, soruZorlugu, soruCevabi);
        KlasikSorular.push_back(geciciKlasikSoru);
    }
}

void TxtdenSoruEkle(
    vector <CoktanSecmeliSoru> &CoktanSecmeliSorular,
    vector <DogruYanlisSoru> &DogruYanlisSorulari,
    vector <BoslukDoldurma> &BoslukDoldurmaSorulari,
    vector <KlasikSoru> &KlasikSorular
) {
    coktanSecmeliTxtdenEkle("coktan-secmeli-sorular.txt", CoktanSecmeliSorular);
    dogruYanlisTxtdenEkle("dogru-yanlis-sorulari.txt", DogruYanlisSorulari);
    boslukDoldurmaTxtdenEkle("bosluk-doldurma-sorulari.txt", BoslukDoldurmaSorulari);
    klasikSoruTxtdenEkle("klasik-sorular.txt", KlasikSorular);
}

void idOlustur (
    vector <CoktanSecmeliSoru> CoktanSecmeliSorular,
    vector <DogruYanlisSoru> DogruYanlisSorulari,
    vector <BoslukDoldurma> BoslukDoldurmaSorulari,
    vector <KlasikSoru> KlasikSorular
) {
    int uniqueId = 1;
    while(true) {
        for(int i = 0; i < CoktanSecmeliSorular.size(); i++) {
            if(uniqueId == CoktanSecmeliSorular[i].getId()) {
                uniqueId++;
                i = 0;
                continue;
            }
        }
        for(int i = 0; i < DogruYanlisSorulari.size(); i++) {
            if(uniqueId == DogruYanlisSorulari[i].getId()) {
                uniqueId++;
                i = 0;
                continue;
            }
        }
        for(int i = 0; i < BoslukDoldurmaSorulari.size(); i++) {
            if(uniqueId == BoslukDoldurmaSorulari[i].getId()) {
                uniqueId++;
                i = 0;
                continue;
            }
        }
        for(int i = 0; i < KlasikSorular.size(); i++) {
            if(uniqueId == KlasikSorular[i].getId()) {
                uniqueId++;
                i = 0;
                continue;
            }
        }
        break;
    }
    cout << "Unique id bulundu -> " << uniqueId << endl;
}

/* main fonksiyonu */
int main() {
    vector <CoktanSecmeliSoru> CoktanSecmeliSorular;
    vector <DogruYanlisSoru> DogruYanlisSorulari;
    vector <BoslukDoldurma> BoslukDoldurmaSorulari;
    vector <KlasikSoru> KlasikSorular;
    TxtdenSoruEkle(CoktanSecmeliSorular, DogruYanlisSorulari, BoslukDoldurmaSorulari, KlasikSorular);
    idOlustur(CoktanSecmeliSorular, DogruYanlisSorulari, BoslukDoldurmaSorulari, KlasikSorular);

    int menuSecimi;
    while(true) {
        cout << "1- Soru bankasina soru ekle" << endl;
        cout << "2- Soru bankasindan soru cikar" << endl;
        cout << "3- Soru bankasindaki sorulari listele" << endl;
        cout << "4- Sinav olustur" << endl;
        cout << "5- Cikis yap" << endl;
        cout << "Lutfen yapmak istediginiz islemi giriniz: ";
        cin >> menuSecimi;

        switch (menuSecimi) {
            case 1:
                soruEkle(CoktanSecmeliSorular, DogruYanlisSorulari, BoslukDoldurmaSorulari, KlasikSorular);
                continue;

            case 2:
                break;

            case 3:
                CoktanSecmeliSorulariListele(CoktanSecmeliSorular);
                break;

            case 4:
                break;

            case 5:
                cout << "Cikis yapiliyor." << endl;
                return 0;
            
            default:
                cout << "Yanlis islem girdiniz. Tekrar deneyiniz." << endl;
                continue;
        }
    }

    return 0;
}