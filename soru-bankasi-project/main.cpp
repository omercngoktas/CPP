#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cctype>
#include <unistd.h>

using namespace std;

class Soru
{
private:
    int id;
    string soruMetni;
    int soruPuani;
    string zorlukDerecesi;

public:
    void SetId(int soruId) { id = soruId; }
    int getId() { return id; }
    void SetSoruMetni(string soruM) { soruMetni = soruM; }
    string getSoruMetni() { return soruMetni; }
    void SetSoruPuani(int soruP) { soruPuani = soruP; }
    int getSoruPuani() { return soruPuani; }
    void SetZorlukDerecesi(string zorlukD) { zorlukDerecesi = zorlukD; }
    string getZorlukDerecesi() { return zorlukDerecesi; }
    void SetSoru(int id, string soruMetni, int soruPuani, string zorlukDerecesi)
    {
        SetId(id);
        SetSoruMetni(soruMetni);
        SetSoruPuani(soruPuani);
        SetZorlukDerecesi(zorlukDerecesi);
    }
};

class CoktanSecmeliSoru : public Soru
{
private:
    vector<string> soruSiklari;
    string dogruCevap;

public:
    void SetSoruSikki(vector<string> yeniCoktanSecmeliCevabi) { soruSiklari = yeniCoktanSecmeliCevabi; }
    vector<string> getSoruSiklari() { return soruSiklari; }
    void SetDogruCevap(string dogruC) { dogruCevap = dogruC; }
    string getDogruCevap() { return dogruCevap; }
    void SetCoktanSecmeliSoru(int id, string soruMetni, int soruPuani, string zorlukDerecesi, string dogruCevap, vector<string> soruSikki)
    {
        SetSoru(id, soruMetni, soruPuani, zorlukDerecesi);
        SetSoruSikki(soruSikki);
        SetDogruCevap(dogruCevap);
    }
};

class DogruYanlisSoru : public Soru
{
private:
    string dogruCevap;

public:
    void SetDogruCevap(string dogruC) { dogruCevap = dogruC; }
    string getDogruCevap() { return dogruCevap; }
    void SetDogruYanlisSoru(int id, string soruMetni, int soruPuani, string zorlukDerecesi, string dogruCevap)
    {
        SetSoru(id, soruMetni, soruPuani, zorlukDerecesi);
        SetDogruCevap(dogruCevap);
    }
};

class KlasikSoru : public Soru
{
private:
    string soruCevabi;

public:
    void SetSoruCevabi(string soruC) { soruCevabi = soruC; }
    string getSoruCevabi() { return soruCevabi; }
    void SetKlasikSoru(int id, string soruMetni, int soruPuani, string zorlukDerecesi, string dogruCevap)
    {
        SetSoru(id, soruMetni, soruPuani, zorlukDerecesi);
        SetSoruCevabi(dogruCevap);
    }
};

class BoslukDoldurma : public Soru
{
private:
    string boslukCevabi;

public:
    void SetBoslukCevabi(string boslukC) { boslukCevabi = boslukC; }
    string getBoslukCevabi() { return boslukCevabi; }
    void SetBoslukDoldurmaSorusu(int id, string soruMetni, int soruPuani, string zorlukDerecesi, string dogruCevap)
    {
        SetSoru(id, soruMetni, soruPuani, zorlukDerecesi);
        SetBoslukCevabi(dogruCevap);
    }
};

class Sinav
{
    private:
        int puanToplami = 0;
        string sinavTuru;

    public:
        void SetPuanToplami(int puan) { puanToplami += puan; }
        int getPuanToplami() { return puanToplami; }
        void SetSinavTuru(string tur) { sinavTuru = tur; }
        string getSinavTuru() { return sinavTuru; }
        void SetSinav(int puan, string tur) {
            SetPuanToplami(puan);
            SetSinavTuru(tur);
        }
        void puaniDusur(int dusurmeDegeri) {
            puanToplami -= dusurmeDegeri;
        }
};

class TestSinavi : public Sinav {
    private:
        vector <CoktanSecmeliSoru> coktanSecmeliSorular;

    public:
        void SetCoktanSecmeliSorular(CoktanSecmeliSoru yeniCoktanSecmeli) { coktanSecmeliSorular.push_back(yeniCoktanSecmeli); SetPuanToplami(yeniCoktanSecmeli.getSoruPuani()); }
        vector <CoktanSecmeliSoru> getCoktanSecmeliSorular() { return coktanSecmeliSorular; }
};

class KlasikSinav : public Sinav {
    private:
        vector <KlasikSoru> klasikSorular;

    public:
        void SetKlasikSorular(KlasikSoru yeniKlasik) { klasikSorular.push_back(yeniKlasik); SetPuanToplami(yeniKlasik.getSoruPuani()); }
        vector <KlasikSoru> getKlasikSorular() { return klasikSorular; }
};

class DogruYanlisSinav : public Sinav {
    private:
        vector <DogruYanlisSoru> dogruYanlisSorulari;

    public:
        void SetDogruYanlisSorulari(DogruYanlisSoru yeniDogruYanlis) { dogruYanlisSorulari.push_back(yeniDogruYanlis); SetPuanToplami(yeniDogruYanlis.getSoruPuani()); }
        vector <DogruYanlisSoru> getDogruYanlisSorulari() { return dogruYanlisSorulari; }
};

class BoslukDoldurmaSinav : public Sinav {
    private:
        vector <BoslukDoldurma> boslukDoldurmaSorulari;

    public:
        void SetBoslukDoldurmaSorulari(BoslukDoldurma yeniBoslukDoldurma) { boslukDoldurmaSorulari.push_back(yeniBoslukDoldurma); SetPuanToplami(yeniBoslukDoldurma.getSoruPuani()); }
        vector <BoslukDoldurma> getBoslukDoldurmaSorulari() { return boslukDoldurmaSorulari; }
};

class KarisikSinav : public Sinav {
    private:
        vector <CoktanSecmeliSoru> coktanSecmeliSorular;
        vector <KlasikSoru> klasikSorular;
        vector <DogruYanlisSoru> dogruYanlisSorulari;
        vector <BoslukDoldurma> boslukDoldurmaSorulari;

    public:
        void SetCoktanSecmeliSorular(CoktanSecmeliSoru yeniCoktanSecmeli) { coktanSecmeliSorular.push_back(yeniCoktanSecmeli); SetPuanToplami(yeniCoktanSecmeli.getSoruPuani()); }
        vector <CoktanSecmeliSoru> getCoktanSecmeliSorular() { return coktanSecmeliSorular; }
        void SetKlasikSorular(KlasikSoru yeniKlasik) { klasikSorular.push_back(yeniKlasik); SetPuanToplami(yeniKlasik.getSoruPuani()); }
        vector <KlasikSoru> getKlasikSorular() { return klasikSorular; }
        void SetDogruYanlisSorulari(DogruYanlisSoru yeniDogruYanlis) { dogruYanlisSorulari.push_back(yeniDogruYanlis); SetPuanToplami(yeniDogruYanlis.getSoruPuani()); }
        vector <DogruYanlisSoru> getDogruYanlisSorulari() { return dogruYanlisSorulari; }
        void SetBoslukDoldurmaSorulari(BoslukDoldurma yeniBoslukDoldurma) { boslukDoldurmaSorulari.push_back(yeniBoslukDoldurma); SetPuanToplami(yeniBoslukDoldurma.getSoruPuani()); }
        vector <BoslukDoldurma> getBoslukDoldurmaSorulari() { return boslukDoldurmaSorulari; }
        void SilCoktanSecmeliSoru() {
            if(getPuanToplami() > 110) {
                for(int i = 0; i < getCoktanSecmeliSorular().size(); i++) {
                    if(getPuanToplami() > 110) {
                        puaniDusur(coktanSecmeliSorular[i].getSoruPuani());
                        coktanSecmeliSorular.erase(coktanSecmeliSorular.begin() + 1);
                    }
                }
                
            }
        }
};





vector<string> tokenize(string s, string del = " ")
{
    int start, end = -1 * del.size();
    vector<string> soruVectoru;
    do
    {
        start = end + del.size();
        end = s.find(del, start);
        // cout << s.substr(start, end - start) << endl;
        // cout << "test -> " << s << endl;
        soruVectoru.push_back(s.substr(start, end - start));
    } while (end != -1);
    return soruVectoru;
}

int randomSayiUret(int upperLimit) {
    // srand( time(NULL) );
    return ( rand() % (upperLimit - 1 + 1) + 1 );
}

/* bu kod girilen stringi lowercase'e çevirir, bu sayede inputları da lower yaparak arama algoritmasını daha iyi hale getiririz */
void toLowerLetter(string &metin) {
    for_each(metin.begin(), metin.end(), [](char & c) { c = ::tolower(c); });
}

int idOlustur(
    vector<CoktanSecmeliSoru> CoktanSecmeliSorular,
    vector<DogruYanlisSoru> DogruYanlisSorulari,
    vector<BoslukDoldurma> BoslukDoldurmaSorulari,
    vector<KlasikSoru> KlasikSorular);

/* çoktan seçmeli soru bilgilerinin kullanıcı tarafından alınmasında ve vector'e eklenmesinde kullanılır */
void coktanSecmeliSoruEkle(vector<CoktanSecmeliSoru> &CoktanSecmeliSorular, int yeniId)
{
    CoktanSecmeliSoru YeniCoktanSecmeliSorusu;
    string soruMetni, zorlukDerecesi, a, b, c, d;
    int soruPuani;
    string dogruCevap;
    vector<string> cevaplar;

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
    cout << "Sorunun cevabini giriniz (a-b-c-d): ";
    cin >> dogruCevap;
    toLowerLetter(dogruCevap);
    cout << "Sorunun zorluk derecesini giriniz (kolay-orta-zor): ";
    cin >> zorlukDerecesi;
    toLowerLetter(zorlukDerecesi);
    cout << "Soru puanini giriniz: ";
    cin >> soruPuani;

    cevaplar.push_back(a);
    cevaplar.push_back(b);
    cevaplar.push_back(c);
    cevaplar.push_back(d);
    YeniCoktanSecmeliSorusu.SetCoktanSecmeliSoru(yeniId, soruMetni, soruPuani, zorlukDerecesi, dogruCevap, cevaplar);
    CoktanSecmeliSorular.push_back(YeniCoktanSecmeliSorusu);
}

/* klasik soru bilgisinin kullanıcıdan alınmasında ve vector'e eklenmesinde kullanılır */
void klasikSoruEkle(vector<KlasikSoru> &KlasikSorular, int yeniId)
{
    KlasikSoru YeniKlasikSorusu;
    string soruMetni, zorlukDerecesi, soruCevabi;
    int soruPuani;

    cout << "Klasik soru metnini giriniz: ";
    getline(cin >> ws, soruMetni);
    cout << "Klasik sorunun cevabini giriniz: ";
    getline(cin >> ws, soruCevabi);
    cout << "Sorunun zorluk derecesini giriniz (kolay-orta-zor): ";
    cin >> zorlukDerecesi;
    toLowerLetter(zorlukDerecesi);
    cout << "Soru puanini giriniz: ";
    cin >> soruPuani;

    YeniKlasikSorusu.SetKlasikSoru(yeniId, soruMetni, soruPuani, zorlukDerecesi, soruCevabi);
    KlasikSorular.push_back(YeniKlasikSorusu);
}

/* doğru yanlış soru bilgisinin alınmasında ve vector'e eklenmesinde kullanılır */
void dogruYanlisSoruEkle(vector<DogruYanlisSoru> &DogruYanlisSorulari, int yeniId)
{
    DogruYanlisSoru YeniDogruYanlisSorusu;
    string soruMetni, zorlukDerecesi;
    string soruCevabi;
    int soruPuani;

    cout << "Dogru/Yanlis sorusunun metnini giriniz: ";
    getline(cin >> ws, soruMetni);
    cout << "Dogru/Yanlis sorusunun cevabini giriniz (Yanlis/Dogru): ";
    cin >> soruCevabi;
    cout << "Dogru/Yanlis sorusunun zorluk derecesini giriniz (kolay-orta-zor): ";
    cin >> zorlukDerecesi;
    toLowerLetter(zorlukDerecesi);
    cout << "Dogru/Yanlis sorusunun puanini giriniz: ";
    cin >> soruPuani;

    YeniDogruYanlisSorusu.SetDogruYanlisSoru(yeniId, soruMetni, soruPuani, zorlukDerecesi, soruCevabi);
    DogruYanlisSorulari.push_back(YeniDogruYanlisSorusu);
}

/* boşluk doldurma sorusu bilgisinin alınmasında ve vector'e eklenmesinde kullanılır */
void boslukDoldurmaSoruEkle(vector<BoslukDoldurma> &BoslukDoldurmaSorulari, int yeniId)
{
    BoslukDoldurma YeniBoslukDoldurmaSorusu;
    string soruMetni, zorlukDerecesi, soruCevabi;
    int soruPuani;

    cout << "Bosluk doldurma metnini giriniz (bosluk birakmayi unutmayiniz): ";
    getline(cin >> ws, soruMetni);
    cout << "Bosluk doldurma sorusunun cevabini giriniz: ";
    getline(cin >> ws, soruCevabi);
    cout << "Bosluk doldurma sorusunun zorluk derecesini giriniz (kolay-orta-zor): ";
    cin >> zorlukDerecesi;
    toLowerLetter(zorlukDerecesi);
    cout << "Bosluk doldurma sorusunun puanini giriniz: ";
    cin >> soruPuani;

    YeniBoslukDoldurmaSorusu.SetBoslukDoldurmaSorusu(yeniId, soruMetni, soruPuani, zorlukDerecesi, soruCevabi);
    BoslukDoldurmaSorulari.push_back(YeniBoslukDoldurmaSorusu);
}

/*
    kullanıcı soru bankasına soru eklemek istediği zaman bu bu fonksiyon çağrılır,
    bu fonksiyon da menüyü bastırarak eklenmek istenen soru tipine göre gerekli
    olan fonksiyonları çağırır
*/
void soruEkle(
    vector<CoktanSecmeliSoru> &CoktanSecmeliSorular,
    vector<DogruYanlisSoru> &DogruYanlisSorulari,
    vector<BoslukDoldurma> &BoslukDoldurmaSorulari,
    vector<KlasikSoru> &KlasikSorular)
{
    int soruCesidi;
    int yeniId = idOlustur(CoktanSecmeliSorular, DogruYanlisSorulari, BoslukDoldurmaSorulari, KlasikSorular);
    while (true)
    {
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
            coktanSecmeliSoruEkle(CoktanSecmeliSorular, yeniId);
            return;

        case 2:
            klasikSoruEkle(KlasikSorular, yeniId);
            break;

        case 3:
            dogruYanlisSoruEkle(DogruYanlisSorulari, yeniId);
            break;

        case 4:
            boslukDoldurmaSoruEkle(BoslukDoldurmaSorulari, yeniId);
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

/* alınan CoktanSecmeliSoru objesinin değerlerini yazdırır */
void coktanSecmeliSoruyuYazdir(CoktanSecmeliSoru coktanSecmeliSoru)
{
    cout << endl;
    cout << coktanSecmeliSoru.getId();
    cout << "-) " << coktanSecmeliSoru.getSoruMetni() << endl;
    cout << "a) " << coktanSecmeliSoru.getSoruSiklari()[0] << "\t";
    cout << "b) " << coktanSecmeliSoru.getSoruSiklari()[1] << "\t";
    cout << "c) " << coktanSecmeliSoru.getSoruSiklari()[2] << "\t";
    cout << "d) " << coktanSecmeliSoru.getSoruSiklari()[3] << endl;
    cout << "Soru puani: " << coktanSecmeliSoru.getSoruPuani() << "\t";
    cout << "Soru zorlugu: " << coktanSecmeliSoru.getZorlukDerecesi() << "\t";
    cout << "Soru cevabi: " << coktanSecmeliSoru.getDogruCevap() << endl;
}

/* alınan klasikSoruyuYazdir objesinin değerlerini yazdırır */
void klasikSoruyuYazdir(KlasikSoru klasikSoru)
{
    cout << endl;
    cout << klasikSoru.getId();
    cout << "-) " << klasikSoru.getSoruMetni() << endl;
    cout << "Soru cevabi: " << klasikSoru.getSoruCevabi() << endl;
    cout << "Soru puani: " << klasikSoru.getSoruPuani() << "\t";
    cout << "Soru zorlugu: " << klasikSoru.getZorlukDerecesi() << endl;
}

/* alınan boslukDoldurmaSorusunuYazdir objesinin değerlerini yazdırır */
void boslukDoldurmaSorusunuYazdir(BoslukDoldurma boslukDoldurmaSorusu)
{
    cout << endl;
    cout << boslukDoldurmaSorusu.getId();
    cout << "-) " << boslukDoldurmaSorusu.getSoruMetni() << endl;
    cout << "Bosluga gelecek cevap: " << boslukDoldurmaSorusu.getBoslukCevabi() << endl;
    cout << "Soru puani: " << boslukDoldurmaSorusu.getSoruPuani() << "\t";
    cout << "Soru zorlugu: " << boslukDoldurmaSorusu.getZorlukDerecesi() << endl;
}

/* alınan dogruYanlisSorusunuYazdir objesinin değerlerini yazdırır */
void dogruYanlisSorusunuYazdir(DogruYanlisSoru dogruYanlisSorusu)
{
    cout << endl;
    cout << dogruYanlisSorusu.getId();
    cout << "-) " << dogruYanlisSorusu.getSoruMetni() << endl;
    cout << "Dogru yanlis cevabi : " << dogruYanlisSorusu.getDogruCevap() << endl;
    cout << "Soru puani: " << dogruYanlisSorusu.getSoruPuani() << "\t";
    cout << "Soru zorlugu: " << dogruYanlisSorusu.getZorlukDerecesi() << endl;
}

/* txt dosyasında bulunan çoktan seçmeli soruları CoktanSecmeliSorular vector'une ekler */
void coktanSecmeliTxtdenEkle(string textFileName, vector<CoktanSecmeliSoru> &CoktanSecmeliSorular)
{
    int id, soruPuani;
    string aSikki, bSikki, cSikki, dSikki, soruMetni, soruCevabi, zorlukDerecesi, textMetni, idString, soruPuaniString;
    ifstream coktanSecmeliText(textFileName);
    vector<string> coktanSecmeli;

    while (getline(coktanSecmeliText, textMetni))
    {
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
        vector<string> cevaplar;
        cevaplar.push_back(aSikki);
        cevaplar.push_back(bSikki);
        cevaplar.push_back(cSikki);
        cevaplar.push_back(dSikki);

        CoktanSecmeliSoru geciciCoktanSecmeli;
        geciciCoktanSecmeli.SetCoktanSecmeliSoru(id, soruMetni, soruPuani, zorlukDerecesi, soruCevabi, cevaplar);
        CoktanSecmeliSorular.push_back(geciciCoktanSecmeli);
    }
}

/* txt dosyasında bulunan doğru yanlış sorularını DogruYanlisSorulari vector'une ekler */
void dogruYanlisTxtdenEkle(string textFileName, vector<DogruYanlisSoru> &DogruYanlisSorulari)
{
    int id, soruPuani;
    string soruMetni, soruCevabi, soruZorlugu, textMetni;
    ifstream dogruYanlisText(textFileName);
    vector<string> dogruYanlis;

    while (getline(dogruYanlisText, textMetni))
    {
        dogruYanlis = tokenize(textMetni, "\t");
        id = stoi(dogruYanlis[0]);
        soruMetni = dogruYanlis[1];
        soruCevabi = dogruYanlis[2];
        soruPuani = stoi(dogruYanlis[3]);
        soruZorlugu = dogruYanlis[4];
        DogruYanlisSoru geciciDogruYanlis;
        geciciDogruYanlis.SetDogruYanlisSoru(id, soruMetni, soruPuani, soruZorlugu, soruCevabi);
        DogruYanlisSorulari.push_back(geciciDogruYanlis);
    }
}

/* txt dosyasında bulunan boşluk doldurma sorularını BoslukDoldurmaSorulari vector'une ekler */
void boslukDoldurmaTxtdenEkle(string textFileName, vector<BoslukDoldurma> &BoslukDoldurmaSorulari)
{
    int id, soruPuani;
    string soruMetni, soruCevabi, soruZorlugu, textMetni;
    ifstream boslukDoldurmaText(textFileName);
    vector<string> boslukDoldurma;

    while (getline(boslukDoldurmaText, textMetni))
    {
        boslukDoldurma = tokenize(textMetni, "\t");
        id = stoi(boslukDoldurma[0]);
        soruMetni = boslukDoldurma[1];
        soruCevabi = boslukDoldurma[2];
        soruPuani = stoi(boslukDoldurma[3]);
        soruZorlugu = boslukDoldurma[4];
        BoslukDoldurma geciciBoslukDoldurma;
        geciciBoslukDoldurma.SetBoslukDoldurmaSorusu(id, soruMetni, soruPuani, soruZorlugu, soruCevabi);
        BoslukDoldurmaSorulari.push_back(geciciBoslukDoldurma);
    }
}

/* txt dosyasında bulunan klasik soruları KlasikSorular vector'une ekler */
void klasikSoruTxtdenEkle(string textFileName, vector<KlasikSoru> &KlasikSorular)
{
    int id, soruPuani;
    string soruMetni, soruCevabi, soruZorlugu, textMetni;
    ifstream klasikSoruText(textFileName);
    vector<string> klasikSoru;

    while (getline(klasikSoruText, textMetni))
    {
        klasikSoru = tokenize(textMetni, "\t");
        id = stoi(klasikSoru[0]);
        soruMetni = klasikSoru[1];
        soruCevabi = klasikSoru[2];
        soruPuani = stoi(klasikSoru[3]);
        soruZorlugu = klasikSoru[4];
        KlasikSoru geciciKlasikSoru;
        geciciKlasikSoru.SetKlasikSoru(id, soruMetni, soruPuani, soruZorlugu, soruCevabi);
        KlasikSorular.push_back(geciciKlasikSoru);
    }
}

/* txtden ekleme yapan fonksiyonları çağırır */
void TxtdenSoruEkle(
    vector<CoktanSecmeliSoru> &CoktanSecmeliSorular,
    vector<DogruYanlisSoru> &DogruYanlisSorulari,
    vector<BoslukDoldurma> &BoslukDoldurmaSorulari,
    vector<KlasikSoru> &KlasikSorular)
{
    coktanSecmeliTxtdenEkle("sorular/coktan-secmeli-sorular.txt", CoktanSecmeliSorular);
    dogruYanlisTxtdenEkle("sorular/dogru-yanlis-sorulari.txt", DogruYanlisSorulari);
    boslukDoldurmaTxtdenEkle("sorular/bosluk-doldurma-sorulari.txt", BoslukDoldurmaSorulari);
    klasikSoruTxtdenEkle("sorular/klasik-sorular.txt", KlasikSorular);
}

/* id'yi 1'den başlatır, tüm sorular içerisinde gezerek mümkün olan en düşük id'yi bulur */
int idOlustur(
    vector<CoktanSecmeliSoru> CoktanSecmeliSorular,
    vector<DogruYanlisSoru> DogruYanlisSorulari,
    vector<BoslukDoldurma> BoslukDoldurmaSorulari,
    vector<KlasikSoru> KlasikSorular)
{
    int uniqueId = 1;
    while (true)
    {
        for (int i = 0; i < CoktanSecmeliSorular.size(); i++)
        {
            if (uniqueId == CoktanSecmeliSorular[i].getId())
            {
                uniqueId++;
                i = 0;
                continue;
            }
        }
        for (int i = 0; i < DogruYanlisSorulari.size(); i++)
        {
            if (uniqueId == DogruYanlisSorulari[i].getId())
            {
                uniqueId++;
                i = 0;
                continue;
            }
        }
        for (int i = 0; i < BoslukDoldurmaSorulari.size(); i++)
        {
            if (uniqueId == BoslukDoldurmaSorulari[i].getId())
            {
                uniqueId++;
                i = 0;
                continue;
            }
        }
        for (int i = 0; i < KlasikSorular.size(); i++)
        {
            if (uniqueId == KlasikSorular[i].getId())
            {
                uniqueId++;
                i = 0;
                continue;
            }
        }
        break;
    }
    return uniqueId;
}

/* anahtar kelime girerek soru metninde eşleşme olursa soru listelenir */
int soruMetniAnahtarKelimeListele(
    vector<CoktanSecmeliSoru> CoktanSecmeliSorular,
    vector<DogruYanlisSoru> DogruYanlisSorulari,
    vector<BoslukDoldurma> BoslukDoldurmaSorulari,
    vector<KlasikSoru> KlasikSorular)
{
    string anahtarKelime;

    cout << "Soru metninde aramak istediginiz anahtar kelimeyi giriniz: ";
    getline(cin >> ws, anahtarKelime);
    toLowerLetter(anahtarKelime);
    int bulunanSoruSayisi = 0;

    for (int i = 0; i < CoktanSecmeliSorular.size(); i++)
    {
        string soruMetniLowerCase = CoktanSecmeliSorular[i].getSoruMetni();
        toLowerLetter(soruMetniLowerCase);
        if (soruMetniLowerCase.find(anahtarKelime) != std::string::npos)
        {
            coktanSecmeliSoruyuYazdir(CoktanSecmeliSorular[i]);
            bulunanSoruSayisi++;
        }
    }
    for (int i = 0; i < DogruYanlisSorulari.size(); i++)
    {
        string soruMetniLowerCase = DogruYanlisSorulari[i].getSoruMetni();
        toLowerLetter(soruMetniLowerCase);
        if (soruMetniLowerCase.find(anahtarKelime) != std::string::npos)
        {
            dogruYanlisSorusunuYazdir(DogruYanlisSorulari[i]);
            bulunanSoruSayisi++;
        }
    }
    for (int i = 0; i < BoslukDoldurmaSorulari.size(); i++)
    {
        string soruMetniLowerCase = BoslukDoldurmaSorulari[i].getSoruMetni();
        toLowerLetter(soruMetniLowerCase);
        if (soruMetniLowerCase.find(anahtarKelime) != std::string::npos)
        {
            boslukDoldurmaSorusunuYazdir(BoslukDoldurmaSorulari[i]);
            bulunanSoruSayisi++;
        }
    }
    for (int i = 0; i < KlasikSorular.size(); i++)
    {
        string soruMetniLowerCase = KlasikSorular[i].getSoruMetni();
        toLowerLetter(soruMetniLowerCase);
        if (soruMetniLowerCase.find(anahtarKelime) != std::string::npos)
        {
            klasikSoruyuYazdir(KlasikSorular[i]);
            bulunanSoruSayisi++;
        }
    }
    cout << endl << "Toplam " << bulunanSoruSayisi << " soru listelendi.\n" << endl;
    return bulunanSoruSayisi;
}

/* anahtar kelime girerek soru şıklarında eşleşme olursa soru listelenir */
int soruSikkindaAnahtarKelimeListele(
    vector<CoktanSecmeliSoru> CoktanSecmeliSorular,
    vector<DogruYanlisSoru> DogruYanlisSorulari,
    vector<BoslukDoldurma> BoslukDoldurmaSorulari,
    vector<KlasikSoru> KlasikSorular)
{
    string anahtarKelime;
    int bulunanSoruSayisi = 0;
    cout << "Soru cevaplarinin icinde aramak istediginiz anahtar kelimeyi giriniz: ";
    getline(cin >> ws, anahtarKelime);
    toLowerLetter(anahtarKelime);

    for (int i = 0; i < CoktanSecmeliSorular.size(); i++)
    {
        for (int j = 0; j < CoktanSecmeliSorular[i].getSoruSiklari().size(); j++)
        {
            string soruCevabiLowerCase = CoktanSecmeliSorular[i].getSoruSiklari()[j];
            toLowerLetter(soruCevabiLowerCase);
            if (soruCevabiLowerCase.find(anahtarKelime) != std::string::npos)
            {
                coktanSecmeliSoruyuYazdir(CoktanSecmeliSorular[i]);
                bulunanSoruSayisi++;
            }
        }
    }
    for (int i = 0; i < DogruYanlisSorulari.size(); i++)
    {
        string soruCevabiLowerCase = DogruYanlisSorulari[i].getDogruCevap();
        toLowerLetter(soruCevabiLowerCase);
        if (soruCevabiLowerCase.find(anahtarKelime) != std::string::npos)
        {
            dogruYanlisSorusunuYazdir(DogruYanlisSorulari[i]);
            bulunanSoruSayisi++;
        }
    }
    for (int i = 0; i < BoslukDoldurmaSorulari.size(); i++)
    {
        string soruCevabiLowerCase = BoslukDoldurmaSorulari[i].getBoslukCevabi();
        toLowerLetter(soruCevabiLowerCase);
        if (soruCevabiLowerCase.find(anahtarKelime) != std::string::npos)
        {
            boslukDoldurmaSorusunuYazdir(BoslukDoldurmaSorulari[i]);
            bulunanSoruSayisi++;
        }
    }
    for (int i = 0; i < KlasikSorular.size(); i++)
    {
        string soruCevabiLowerCase = KlasikSorular[i].getSoruCevabi();
        toLowerLetter(soruCevabiLowerCase);
        if (soruCevabiLowerCase.find(anahtarKelime) != std::string::npos)
        {
            klasikSoruyuYazdir(KlasikSorular[i]);
            bulunanSoruSayisi++;
        }
    }
    cout << endl << "Toplam " << bulunanSoruSayisi << " soru listelendi.\n" << endl;
    return bulunanSoruSayisi;
}

/* kullanıcı a-b-c-d şıklarından birisini girer ve cevabı girilen şık olan sorular listelenir */
int dogruSikkaGoreListele(vector<CoktanSecmeliSoru> CoktanSecmeliSorular)
{
    int bulunanSoruSayisi = 0;
    string soruSikki;
    cout << "Dogru siklari uzerinden aramak icin cevap sikki giriniz (a-b-c-d): ";
    getline(cin >> ws, soruSikki);
    toLowerLetter(soruSikki);
    if(soruSikki != "a" && soruSikki != "b" && soruSikki != "c" && soruSikki != "d") {
        cout << "Lutfen yalnizca 'a', 'b', 'c' ya da 'd' giriniz." << endl;
        return bulunanSoruSayisi;
    }

    for (int i = 0; i < CoktanSecmeliSorular.size(); i++)
    {
        string geciciSoruSikki = CoktanSecmeliSorular[i].getDogruCevap();
        toLowerLetter(geciciSoruSikki);
        if (geciciSoruSikki == soruSikki)
        {
            coktanSecmeliSoruyuYazdir(CoktanSecmeliSorular[i]);
            bulunanSoruSayisi++;
        }
    }
    cout << endl << "Toplam " << bulunanSoruSayisi << " soru listelendi.\n" << endl;
    return bulunanSoruSayisi;
}

/* kullanıcı puan girer, eşleşen sorular listelenir */
int girilenPuanaGoreListele(
    vector<CoktanSecmeliSoru> CoktanSecmeliSorular,
    vector<DogruYanlisSoru> DogruYanlisSorulari,
    vector<BoslukDoldurma> BoslukDoldurmaSorulari,
    vector<KlasikSoru> KlasikSorular)
{
    int bulunanSoruSayisi = 0;
    int girilenSoruPuani;
    cout << "Puanina gore aramak istediginiz sorular icin puan giriniz: ";
    cin >> girilenSoruPuani;

    for (int i = 0; i < CoktanSecmeliSorular.size(); i++)
    {
        if (CoktanSecmeliSorular[i].getSoruPuani() == girilenSoruPuani) {
            coktanSecmeliSoruyuYazdir(CoktanSecmeliSorular[i]);
            bulunanSoruSayisi++;
        }
    }
    for (int i = 0; i < DogruYanlisSorulari.size(); i++)
    {
        if (DogruYanlisSorulari[i].getSoruPuani() == girilenSoruPuani) {
            dogruYanlisSorusunuYazdir(DogruYanlisSorulari[i]);
            bulunanSoruSayisi++;
        }
    }
    for (int i = 0; i < BoslukDoldurmaSorulari.size(); i++)
    {
        if (BoslukDoldurmaSorulari[i].getSoruPuani() == girilenSoruPuani) {
            boslukDoldurmaSorusunuYazdir(BoslukDoldurmaSorulari[i]);
            bulunanSoruSayisi++;
        }
    }
    for (int i = 0; i < KlasikSorular.size(); i++)
    {
        if (KlasikSorular[i].getSoruPuani() == girilenSoruPuani) {
            klasikSoruyuYazdir(KlasikSorular[i]);
            bulunanSoruSayisi++;
        }
    }
    cout << endl << "Toplam " << bulunanSoruSayisi << " soru listelendi.\n" << endl;
    return bulunanSoruSayisi;
}

/* kullanıcı kolay-orta-zor seçeneklerinden birisini girer ve eşleşen sorular listelenir */
int zorlugaGoreListele(
    vector<CoktanSecmeliSoru> CoktanSecmeliSorular,
    vector<DogruYanlisSoru> DogruYanlisSorulari,
    vector<BoslukDoldurma> BoslukDoldurmaSorulari,
    vector<KlasikSoru> KlasikSorular)
{
    int bulunanSoruSayisi = 0;
    string soruZorlugu;
    cout << "Zorluguna gore listelemek icin 'kolay', 'orta' veya 'zor' seceneklerinden birisini yaziniz: ";
    getline(cin >> ws, soruZorlugu);
    if (soruZorlugu != "kolay" && soruZorlugu != "orta" && soruZorlugu != "zor")
    {
        cout << "Lutfen yalnizca 'kolay', 'orta' veya 'zor' giriniz." << endl
             << endl;
        return bulunanSoruSayisi;
    }
    for (int i = 0; i < CoktanSecmeliSorular.size(); i++)
    {
        if (CoktanSecmeliSorular[i].getZorlukDerecesi() == soruZorlugu) {
            coktanSecmeliSoruyuYazdir(CoktanSecmeliSorular[i]);
            bulunanSoruSayisi++;
        }
    }
    for (int i = 0; i < DogruYanlisSorulari.size(); i++)
    {
        if (DogruYanlisSorulari[i].getZorlukDerecesi() == soruZorlugu) {
            dogruYanlisSorusunuYazdir(DogruYanlisSorulari[i]);
            bulunanSoruSayisi++;
        }
    }
    for (int i = 0; i < BoslukDoldurmaSorulari.size(); i++)
    {
        if (BoslukDoldurmaSorulari[i].getZorlukDerecesi() == soruZorlugu) {
            boslukDoldurmaSorusunuYazdir(BoslukDoldurmaSorulari[i]);
            bulunanSoruSayisi++;
        }
    }
    for (int i = 0; i < KlasikSorular.size(); i++)
    {
        if (KlasikSorular[i].getZorlukDerecesi() == soruZorlugu) {
            klasikSoruyuYazdir(KlasikSorular[i]);
            bulunanSoruSayisi++;
        }
    }
    cout << endl << "Toplam " << bulunanSoruSayisi << " soru listelendi.\n" << endl;
    return bulunanSoruSayisi;
}

/* istenen listeleme yöntemlerinin sorulduğu menü */
void soruListele(
    vector<CoktanSecmeliSoru> CoktanSecmeliSorular,
    vector<DogruYanlisSoru> DogruYanlisSorulari,
    vector<BoslukDoldurma> BoslukDoldurmaSorulari,
    vector<KlasikSoru> KlasikSorular)
{
    int menuSecimi;
    while (true)
    {
        cout << "1- Soru metninde anahtar kelime ile sorulari listele" << endl;
        cout << "2- Soru siklari icerisinde anahtar kelime arayarak listele" << endl;
        cout << "3- Girilen sikka gore listele" << endl;
        cout << "4- Soru puanina gore sorulari listele" << endl;
        cout << "5- Soru zorluguna gore listele" << endl;
        cout << "6- Ana menuye don" << endl;
        cout << "Lutfen yapmak istediginiz islemi giriniz: ";
        cin >> menuSecimi;

        switch (menuSecimi)
        {
        case 1:
            soruMetniAnahtarKelimeListele(CoktanSecmeliSorular, DogruYanlisSorulari, BoslukDoldurmaSorulari, KlasikSorular);
            return;

        case 2:
            soruSikkindaAnahtarKelimeListele(CoktanSecmeliSorular, DogruYanlisSorulari, BoslukDoldurmaSorulari, KlasikSorular);
            return;

        case 3:
            dogruSikkaGoreListele(CoktanSecmeliSorular);
            return;

        case 4:
            girilenPuanaGoreListele(CoktanSecmeliSorular, DogruYanlisSorulari, BoslukDoldurmaSorulari, KlasikSorular);
            return;

        case 5:
            zorlugaGoreListele(CoktanSecmeliSorular, DogruYanlisSorulari, BoslukDoldurmaSorulari, KlasikSorular);
            return;

        case 6:
            return;

        default:
            break;
        }
    }
}

/* kullanıcının girdiği anahtar kelime bulunduktan sonra id'ler bir vectore atanır ve returnlenir*/
vector <int> soruAraVeBulunanlariReturn(
    vector<CoktanSecmeliSoru> CoktanSecmeliSorular,
    vector<DogruYanlisSoru> DogruYanlisSorulari,
    vector<BoslukDoldurma> BoslukDoldurmaSorulari,
    vector<KlasikSoru> KlasikSorular
) {
    string anahtarKelime;

    cout << "Silmek istediginiz soru icin anahtar kelime giriniz: ";
    getline(cin >> ws, anahtarKelime);
    toLowerLetter(anahtarKelime);
    int bulunanSoruSayisi = 0;
    vector <int> bulunanSorular;

    for (int i = 0; i < CoktanSecmeliSorular.size(); i++)
    {
        string soruMetniLowerCase = CoktanSecmeliSorular[i].getSoruMetni();
        toLowerLetter(soruMetniLowerCase);
        if (soruMetniLowerCase.find(anahtarKelime) != std::string::npos)
        {
            coktanSecmeliSoruyuYazdir(CoktanSecmeliSorular[i]);
            bulunanSoruSayisi++;
            bulunanSorular.push_back(CoktanSecmeliSorular[i].getId());
        }
    }
    for (int i = 0; i < DogruYanlisSorulari.size(); i++)
    {
        string soruMetniLowerCase = DogruYanlisSorulari[i].getSoruMetni();
        toLowerLetter(soruMetniLowerCase);
        if (soruMetniLowerCase.find(anahtarKelime) != std::string::npos)
        {
            dogruYanlisSorusunuYazdir(DogruYanlisSorulari[i]);
            bulunanSoruSayisi++;
            bulunanSorular.push_back(DogruYanlisSorulari[i].getId());
        }
    }
    for (int i = 0; i < BoslukDoldurmaSorulari.size(); i++)
    {
        string soruMetniLowerCase = BoslukDoldurmaSorulari[i].getSoruMetni();
        toLowerLetter(soruMetniLowerCase);
        if (soruMetniLowerCase.find(anahtarKelime) != std::string::npos)
        {
            boslukDoldurmaSorusunuYazdir(BoslukDoldurmaSorulari[i]);
            bulunanSoruSayisi++;
            bulunanSorular.push_back(BoslukDoldurmaSorulari[i].getId());
        }
    }
    for (int i = 0; i < KlasikSorular.size(); i++)
    {
        string soruMetniLowerCase = KlasikSorular[i].getSoruMetni();
        toLowerLetter(soruMetniLowerCase);
        if (soruMetniLowerCase.find(anahtarKelime) != std::string::npos)
        {
            klasikSoruyuYazdir(KlasikSorular[i]);
            bulunanSoruSayisi++;
            bulunanSorular.push_back(KlasikSorular[i].getId());
        }
    }
    /*  bulunanSorular vector'une bulunanSoruSayisi'ni ekliyoruz.
        bu sayede vector'un en sonunda soru sayisinin yer aldığını biliyoruz.
        eğer ki bulunan sayısı 0 olursa kullanıcının silmek istediği sorunun
        ID'si sorulmayacak.
    */
    bulunanSorular.push_back(bulunanSoruSayisi);
    cout << "Toplam " << bulunanSoruSayisi << " soru listelendi.\n" << endl;
    return bulunanSorular;
}

/* verilen id vectorlerde aranır ve bulunursa vectorden silinir */
int soruCikar(
    vector<CoktanSecmeliSoru> &CoktanSecmeliSorular,
    vector<DogruYanlisSoru> &DogruYanlisSorulari,
    vector<BoslukDoldurma> &BoslukDoldurmaSorulari,
    vector<KlasikSoru> &KlasikSorular,
    int soruId
) {
    for (int i = 0; i < CoktanSecmeliSorular.size(); i++) {
        if(CoktanSecmeliSorular[i].getId() == soruId) {
            CoktanSecmeliSorular.erase(CoktanSecmeliSorular.begin() + i);
            return 1;
        }
    }
    for (int i = 0; i < DogruYanlisSorulari.size(); i++) {
        if(DogruYanlisSorulari[i].getId() == soruId) {
            DogruYanlisSorulari.erase(DogruYanlisSorulari.begin() + i);
            return 1;
        }
    }
    for (int i = 0; i < BoslukDoldurmaSorulari.size(); i++) {
        if(BoslukDoldurmaSorulari[i].getId() == soruId) {
            BoslukDoldurmaSorulari.erase(BoslukDoldurmaSorulari.begin() + i);
            return 1;
        }
    }
    for (int i = 0; i < KlasikSorular.size(); i++) {
        if(KlasikSorular[i].getId() == soruId) {
            KlasikSorular.erase(KlasikSorular.begin() + i);
            return 1;
        }
    }
    return 0;
}

/* girilen id çoktan seçmeli sorular içerisinde aranır ve bulunursa obje olarak return edilir */
CoktanSecmeliSoru idIleCoktanSecmeliSoruBul(int id, vector<CoktanSecmeliSoru> CoktanSecmeliSorular) {
    for(int i = 0; i < CoktanSecmeliSorular.size(); i++) {
        if(CoktanSecmeliSorular[i].getId() == id) {
            return CoktanSecmeliSorular[i];
        }
    }
    CoktanSecmeliSoru coktansecmelisoru;
    return coktansecmelisoru;
}

/*  anahtar kelime ile sorular tarandıktan sonra eşleşmeler varsa kullanıcıya
    silinmesini istediği sorunun ID'si sorulur, girilen ID tekrar kontrol edildikten 
    sonra yine eşleşme bulunursa soru vectorden silinir
*/
void soruCikarmaMenusu(
    vector<CoktanSecmeliSoru> &CoktanSecmeliSorular,
    vector<DogruYanlisSoru> &DogruYanlisSorulari,
    vector<BoslukDoldurma> &BoslukDoldurmaSorulari,
    vector<KlasikSoru> &KlasikSorular
) {
    int soruId;
    vector <int> bulunanSorular = soruAraVeBulunanlariReturn(CoktanSecmeliSorular, DogruYanlisSorulari, BoslukDoldurmaSorulari, KlasikSorular);
    cout << "Silmek istediginiz sorunun ID'sini giriniz: ";
    cin >> soruId;
    int bulunanSoruSayisi = bulunanSorular[bulunanSorular.size() - 1];

    if(bulunanSoruSayisi == 0) {
        cout << "Anahtar kelime ile eslesen herhangi bir soru bulunamamistir. Ana menuye donuluyor." << endl;
        return;
    } 

    for(int i = 0; i < bulunanSorular.size(); i++) {
        if(bulunanSorular[i] == soruId) {
            int silmeBasariliMi = soruCikar(CoktanSecmeliSorular, DogruYanlisSorulari, BoslukDoldurmaSorulari, KlasikSorular, soruId);
            if(silmeBasariliMi == 1) {
                cout << "ID'si " << soruId << " olan soru, soru bankasindan cikarilmistir." << endl;
                return;
            } else {
                cout << "Silme isleminde hatayla karsilasildi." << endl;
                return;
            }
        }
    }
    cout << "Girmis oldugunuz ID listelenen listedeki sorularla eslesmemistir." << endl << endl;
    return;
}

/* bu fonksiyonla 1.seçenek olan 100-110 puan arasında  test sınavı oluşturulur */
void testSinaviOlustur(vector<CoktanSecmeliSoru> CoktanSecmeliSorular, TestSinavi &YeniTestSinavi) {
    vector <int> soruIdleri;
    CoktanSecmeliSoru yeniCoktanSecmeliSoru;
    int j = 0, soruIndexi, vectordeVarMi = 0;

    while( YeniTestSinavi.getPuanToplami() < 60 ) {
        vectordeVarMi = 0;
        soruIndexi = randomSayiUret(CoktanSecmeliSorular.size()) - 1;

        for(int i = 0; i < soruIdleri.size(); i++) {
            if(soruIdleri[i] == soruIndexi){
                vectordeVarMi = 1;
                break;
            }
        }
        if(vectordeVarMi == 0) {
            soruIdleri.push_back(soruIndexi);
            j++;
            YeniTestSinavi.SetCoktanSecmeliSorular(CoktanSecmeliSorular[soruIndexi]);
        }
    }

    cout << "Test sinavi icin toplam elde edilen puan: " << YeniTestSinavi.getPuanToplami() << endl;
}

/* 2.seçenek olan klasik sınav oluşturulur 100-110 puan arasında */
void klasikSinavOlustur(vector<KlasikSoru> KlasikSorular, KlasikSinav &YeniKlasikSinav) {
    vector <int> soruIdleri;
    KarisikSinav yeniKlasikSoru;
    int j = 0, soruIndexi, vectordeVarMi = 0;

    while( YeniKlasikSinav.getPuanToplami() < 100 ) {
        vectordeVarMi = 0;
        soruIndexi = randomSayiUret(KlasikSorular.size()) - 1;

        for(int i = 0; i < soruIdleri.size(); i++) {
            if(soruIdleri[i] == soruIndexi){
                vectordeVarMi = 1;
                break;
            }
        }
        if(vectordeVarMi == 0) {
            soruIdleri.push_back(soruIndexi);
            j++;
            YeniKlasikSinav.SetKlasikSorular(KlasikSorular[soruIndexi]);
        }
    }

    cout << "Klasik sinav icin toplam elde edilen puan: " << YeniKlasikSinav.getPuanToplami() << endl;
}

/* 3.seçenek olan tüm soru tiplerinden bir karışık sınav oluşturulur */
void karisikSinavOlustur(
    vector<CoktanSecmeliSoru> &CoktanSecmeliSorular,
    vector<DogruYanlisSoru> &DogruYanlisSorulari,
    vector<BoslukDoldurma> &BoslukDoldurmaSorulari,
    vector<KlasikSoru> &KlasikSorular,
    KarisikSinav &YeniKarisikSinav
) {
    int randomSinavTuru;
    vector <int> soruIdleri;
    int soruIndexi, vectordeVarMi;
    
    while( YeniKarisikSinav.getPuanToplami() < 25 ) {
        vectordeVarMi = 0;
        soruIndexi = randomSayiUret(CoktanSecmeliSorular.size()) - 1;
        for(int i = 0; i < soruIdleri.size(); i++) {
            if(soruIdleri[i] == soruIndexi){
                vectordeVarMi = 1;
                break;
            }
        }
        if(vectordeVarMi == 0) {
            soruIdleri.push_back(soruIndexi);
            YeniKarisikSinav.SetCoktanSecmeliSorular(CoktanSecmeliSorular[soruIndexi]);
        }
    }
    soruIdleri.clear();
    while(YeniKarisikSinav.getPuanToplami() < 50) {
        for(int i = 0; i < DogruYanlisSorulari.size(); i++) {
            vectordeVarMi = 0;
            soruIndexi = randomSayiUret(DogruYanlisSorulari.size()) - 1;
            for(int i = 0; i < soruIdleri.size(); i++) {
                if(soruIdleri[i] == soruIndexi){
                    vectordeVarMi = 1;
                    break;
                }
            }
            if(vectordeVarMi == 0 && YeniKarisikSinav.getPuanToplami() < 50) {
                soruIdleri.push_back(soruIndexi);
                YeniKarisikSinav.SetDogruYanlisSorulari(DogruYanlisSorulari[soruIndexi]);
            }
        }
    }
    soruIdleri.clear();
    while(YeniKarisikSinav.getPuanToplami() < 75) {
        for(int i = 0; i < BoslukDoldurmaSorulari.size(); i++) {
            vectordeVarMi = 0;
            soruIndexi = randomSayiUret(BoslukDoldurmaSorulari.size()) - 1;
            for(int i = 0; i < soruIdleri.size(); i++) {
                if(soruIdleri[i] == soruIndexi){
                    vectordeVarMi = 1;
                    break;
                }
            }
            if(vectordeVarMi == 0 && YeniKarisikSinav.getPuanToplami() < 75) {
                soruIdleri.push_back(soruIndexi);
                YeniKarisikSinav.SetBoslukDoldurmaSorulari(BoslukDoldurmaSorulari[soruIndexi]);
            }
        }
    }
    soruIdleri.clear();
    while(YeniKarisikSinav.getPuanToplami() < 100) {
        for(int i = 0; i < KlasikSorular.size(); i++) {
            vectordeVarMi = 0;
            soruIndexi = randomSayiUret(KlasikSorular.size()) - 1;
            for(int i = 0; i < soruIdleri.size(); i++) {
                if(soruIdleri[i] == soruIndexi){
                    vectordeVarMi = 1;
                    break;
                }
            }
            if(vectordeVarMi == 0 && YeniKarisikSinav.getPuanToplami() < 100) {
                soruIdleri.push_back(soruIndexi);
                YeniKarisikSinav.SetKlasikSorular(KlasikSorular[soruIndexi]);
            }
        }
    }
    YeniKarisikSinav.SilCoktanSecmeliSoru();
}

void cevaplariDosyayaKaydet(int id, string verilenCevap) {
    ofstream cevapText;
    cevapText.open("sinav.txt", ios_base::app);
    cevapText << id << "\t" << verilenCevap << endl;
}

void karisikSinaviUygula(KarisikSinav karisikSinavSorulari) {
    string verilenCevap;
    ofstream cevapText("sinav.txt", ios_base::out);
    cevapText.close();

    for(int i = 0; i < karisikSinavSorulari.getCoktanSecmeliSorular().size(); i++) {
        // coktanSecmeliSoruyuYazdir(testSinaviSorulari.getCoktanSecmeliSorular()[i]);
        // cout << "---------------------------------------------" << endl;
        cout << karisikSinavSorulari.getCoktanSecmeliSorular()[i].getId() << "-) ";
        cout << karisikSinavSorulari.getCoktanSecmeliSorular()[i].getSoruMetni() << endl;
        cout << "a) " << karisikSinavSorulari.getCoktanSecmeliSorular()[i].getSoruSiklari()[0] << "\t";
        cout << "b) " << karisikSinavSorulari.getCoktanSecmeliSorular()[i].getSoruSiklari()[1] << "\t";
        cout << "c) " << karisikSinavSorulari.getCoktanSecmeliSorular()[i].getSoruSiklari()[2] << "\t";
        cout << "d) " << karisikSinavSorulari.getCoktanSecmeliSorular()[i].getSoruSiklari()[3] << endl;
        cout << "Cevabinizi giriniz (Yalnizca 'a', 'b', 'c' ya da 'd' olarak giriniz): ";
        cin >> verilenCevap;
        while( verilenCevap != "a" && verilenCevap != "b" && verilenCevap != "c" && verilenCevap != "d" ) {
            cout << "Yanitinizin yalnizca 'a', 'b', 'c' ya da 'd' oldugundan emin olun." << endl;
            cout << "Cevabinizi giriniz (Yalnizca 'a', 'b', 'c' ya da 'd' olarak giriniz): ";
            cin >> verilenCevap;
        }
        toLowerLetter(verilenCevap);
        cevaplariDosyayaKaydet(karisikSinavSorulari.getCoktanSecmeliSorular()[i].getId(), verilenCevap);
    }
    for(int i = 0; i < karisikSinavSorulari.getKlasikSorular().size(); i++) {
        cout << karisikSinavSorulari.getKlasikSorular()[i].getId() << "-) ";
        cout << karisikSinavSorulari.getKlasikSorular()[i].getSoruMetni() << endl;
        cout << "Cevabinizi giriniz: ";
        getline(cin >> ws, verilenCevap);
        cevaplariDosyayaKaydet(karisikSinavSorulari.getKlasikSorular()[i].getId(), verilenCevap);
    }
    for(int i = 0; i < karisikSinavSorulari.getBoslukDoldurmaSorulari().size(); i++) {
        cout << karisikSinavSorulari.getBoslukDoldurmaSorulari()[i].getId() << "-) ";
        cout << karisikSinavSorulari.getBoslukDoldurmaSorulari()[i].getSoruMetni() << endl;
        cout << "Bosluga gelecek cevabi giriniz: ";
        getline(cin >> ws, verilenCevap);
        cevaplariDosyayaKaydet(karisikSinavSorulari.getBoslukDoldurmaSorulari()[i].getId(), verilenCevap);
    }
    for(int i = 0; i < karisikSinavSorulari.getDogruYanlisSorulari().size(); i++) {
        cout << karisikSinavSorulari.getDogruYanlisSorulari()[i].getId() << "-) ";
        cout << karisikSinavSorulari.getDogruYanlisSorulari()[i].getSoruMetni() << endl;
        cout << "Cevabinizi giriniz (D/Y): ";
        getline(cin >> ws, verilenCevap);
        toLowerLetter(verilenCevap);
        while(verilenCevap != "y" && verilenCevap != "d") {
            cout << "Cevabi dogru formatta girdiginizden emin olun." << endl;
            cout << "Cevabinizi giriniz (D/Y): ";
            getline(cin >> ws, verilenCevap);
            toLowerLetter(verilenCevap);
        }
        cevaplariDosyayaKaydet(karisikSinavSorulari.getDogruYanlisSorulari()[i].getId(), verilenCevap);
    }
    cout << "Sinaviniz basariyla kaydedilmistir." << endl << endl;
}

void klasikSinaviUygula(KlasikSinav klasikSinavSorulari) {
    string verilenCevap;
    string dogruCevap;
    ofstream cevapText("sinav.txt", ios_base::out);
    cevapText.close();
    for(int i = 0; i < klasikSinavSorulari.getKlasikSorular().size(); i++) {
        cout << klasikSinavSorulari.getKlasikSorular()[i].getId() << "-) ";
        cout << klasikSinavSorulari.getKlasikSorular()[i].getSoruMetni() << endl;
        cout << "Cevabinizi giriniz: ";
        getline(cin >> ws, verilenCevap);
        dogruCevap = klasikSinavSorulari.getKlasikSorular()[i].getSoruCevabi();
        cevaplariDosyayaKaydet(klasikSinavSorulari.getKlasikSorular()[i].getId(), verilenCevap);
    }
    cout << "Sinaviniz basariyla kaydedilmistir." << endl << endl;
}

void testSinaviniUygula(TestSinavi testSinaviSorulari) {
    string verilenCevap;
    string dogruCevap;
    int alinanPuan = 0;
    for(int i = 0; i < testSinaviSorulari.getCoktanSecmeliSorular().size(); i++) {
        // coktanSecmeliSoruyuYazdir(testSinaviSorulari.getCoktanSecmeliSorular()[i]);
        // cout << "---------------------------------------------" << endl;
        cout << testSinaviSorulari.getCoktanSecmeliSorular()[i].getId() << "-) ";
        cout << testSinaviSorulari.getCoktanSecmeliSorular()[i].getSoruMetni() << endl;
        cout << "a) " << testSinaviSorulari.getCoktanSecmeliSorular()[i].getSoruSiklari()[0] << "\t";
        cout << "b) " << testSinaviSorulari.getCoktanSecmeliSorular()[i].getSoruSiklari()[1] << "\t";
        cout << "c) " << testSinaviSorulari.getCoktanSecmeliSorular()[i].getSoruSiklari()[2] << "\t";
        cout << "d) " << testSinaviSorulari.getCoktanSecmeliSorular()[i].getSoruSiklari()[3] << endl;
        cout << "Cevabinizi giriniz (Yalnizca 'a', 'b', 'c' ya da 'd' olarak giriniz): ";
        cin >> verilenCevap;
        while( verilenCevap != "a" && verilenCevap != "b" && verilenCevap != "c" && verilenCevap != "d" ) {
            cout << "Yanitinizin yalnizca 'a', 'b', 'c' ya da 'd' oldugundan emin olun." << endl;
            cout << "Cevabinizi giriniz (Yalnizca 'a', 'b', 'c' ya da 'd' olarak giriniz): ";
            cin >> verilenCevap;
        }
        toLowerLetter(verilenCevap);
        dogruCevap = testSinaviSorulari.getCoktanSecmeliSorular()[i].getDogruCevap();
        toLowerLetter(dogruCevap);
        if(verilenCevap == dogruCevap) {
            alinanPuan += testSinaviSorulari.getCoktanSecmeliSorular()[i].getSoruPuani();
        }
    }
    cout << testSinaviSorulari.getPuanToplami() << " uzerinden " << alinanPuan << " puan aldiniz." << endl << endl;
}

/* kullanıcıya hangi sınav çeşidini oluşturmak istediğinin sorulduğu menü */
void sinavOlusturmaMenusu(
    vector<CoktanSecmeliSoru> CoktanSecmeliSorular,
    vector<DogruYanlisSoru> DogruYanlisSorulari,
    vector<BoslukDoldurma> BoslukDoldurmaSorulari,
    vector<KlasikSoru> KlasikSorular
) {
    int sinavSecimi;
    while(true) {
        cout << "1- Test sinavi olustur" << endl;
        cout << "2- Klasik sinav olustur" << endl;
        cout << "3- Karisik sinav olustur" << endl;
        cout << "4- Ana menuye don" << endl;
        cout << "Lutfen yapmak istediginiz secimi giriniz: ";
        cin >> sinavSecimi;

        TestSinavi YeniTestSinavi;
        KlasikSinav YeniKlasikSinav;
        KarisikSinav YeniKarisikSinav;

        switch (sinavSecimi)
        {
            case 1:
                testSinaviOlustur(CoktanSecmeliSorular, YeniTestSinavi);
                testSinaviniUygula(YeniTestSinavi);
                return;

            case 2:
                klasikSinavOlustur(KlasikSorular, YeniKlasikSinav);
                klasikSinaviUygula(YeniKlasikSinav);
                return;

            case 3:
                karisikSinavOlustur(CoktanSecmeliSorular, DogruYanlisSorulari, BoslukDoldurmaSorulari, KlasikSorular, YeniKarisikSinav);
                karisikSinaviUygula(YeniKarisikSinav);
                return;

            case 4:
                return;
        
        default:
            break;
        }
    }
}

/* main fonksiyonu */
int main()
{
    vector<CoktanSecmeliSoru> CoktanSecmeliSorular;
    vector<DogruYanlisSoru> DogruYanlisSorulari;
    vector<BoslukDoldurma> BoslukDoldurmaSorulari;
    vector<KlasikSoru> KlasikSorular;
    TxtdenSoruEkle(CoktanSecmeliSorular, DogruYanlisSorulari, BoslukDoldurmaSorulari, KlasikSorular);

    int menuSecimi;
    while (true)
    {
        
        cout << "1- Soru bankasina soru ekle" << endl;
        cout << "2- Soru bankasindan soru cikar" << endl;
        cout << "3- Soru bankasindaki sorulari listele" << endl;
        cout << "4- Sinav olustur" << endl;
        cout << "5- Cikis yap" << endl;
        cout << "Lutfen yapmak istediginiz islemi giriniz: ";
        cin >> menuSecimi;
        
        switch (menuSecimi)
        {
        case 1:
            soruEkle(CoktanSecmeliSorular, DogruYanlisSorulari, BoslukDoldurmaSorulari, KlasikSorular);
            continue;

        case 2:
            soruCikarmaMenusu(CoktanSecmeliSorular, DogruYanlisSorulari, BoslukDoldurmaSorulari, KlasikSorular);
            break;

        case 3:
            soruListele(CoktanSecmeliSorular, DogruYanlisSorulari, BoslukDoldurmaSorulari, KlasikSorular);
            break;

        case 4:
            sinavOlusturmaMenusu(CoktanSecmeliSorular, DogruYanlisSorulari, BoslukDoldurmaSorulari, KlasikSorular);
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