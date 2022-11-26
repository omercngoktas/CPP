#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Soru
{
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
    void setSoru(int id, string soruMetni, int soruPuani, string zorlukDerecesi)
    {
        setId(id);
        setSoruMetni(soruMetni);
        setSoruPuani(soruPuani);
        setZorlukDerecesi(zorlukDerecesi);
    }
};

class CoktanSecmeliSoru : public Soru
{
private:
    vector<string> soruSiklari;
    string dogruCevap;

public:
    void setSoruSikki(vector<string> yeniCoktanSecmeliCevabi) { soruSiklari = yeniCoktanSecmeliCevabi; }
    vector<string> getSoruSiklari() { return soruSiklari; }
    void setDogruCevap(string dogruC) { dogruCevap = dogruC; }
    string getDogruCevap() { return dogruCevap; }
    void setCoktanSecmeliSoru(int id, string soruMetni, int soruPuani, string zorlukDerecesi, string dogruCevap, vector<string> soruSikki)
    {
        setSoru(id, soruMetni, soruPuani, zorlukDerecesi);
        setSoruSikki(soruSikki);
        setDogruCevap(dogruCevap);
    }
};

class DogruYanlisSoru : public Soru
{
private:
    string dogruCevap;

public:
    void setDogruCevap(string dogruC) { dogruCevap = dogruC; }
    string getDogruCevap() { return dogruCevap; }
    void setDogruYanlisSoru(int id, string soruMetni, int soruPuani, string zorlukDerecesi, string dogruCevap)
    {
        setSoru(id, soruMetni, soruPuani, zorlukDerecesi);
        setDogruCevap(dogruCevap);
    }
};

class KlasikSoru : public Soru
{
private:
    string soruCevabi;

public:
    void setSoruCevabi(string soruC) { soruCevabi = soruC; }
    string getSoruCevabi() { return soruCevabi; }
    void setKlasikSoru(int id, string soruMetni, int soruPuani, string zorlukDerecesi, string dogruCevap)
    {
        setSoru(id, soruMetni, soruPuani, zorlukDerecesi);
        setSoruCevabi(dogruCevap);
    }
};

class BoslukDoldurma : public Soru
{
private:
    string boslukCevabi;

public:
    void setBoslukCevabi(string boslukC) { boslukCevabi = boslukC; }
    string getBoslukCevabi() { return boslukCevabi; }
    void setBoslukDoldurmaSorusu(int id, string soruMetni, int soruPuani, string zorlukDerecesi, string dogruCevap)
    {
        setSoru(id, soruMetni, soruPuani, zorlukDerecesi);
        setBoslukCevabi(dogruCevap);
    }
};

class Sinav
{
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
    YeniCoktanSecmeliSorusu.setCoktanSecmeliSoru(yeniId, soruMetni, soruPuani, zorlukDerecesi, dogruCevap, cevaplar);
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
    cout << "Soru puanini giriniz: ";
    cin >> soruPuani;

    YeniKlasikSorusu.setKlasikSoru(yeniId, soruMetni, soruPuani, zorlukDerecesi, soruCevabi);
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
    cout << "Dogru/Yanlis sorusunun cevabini giriniz (Y/N): ";
    cin >> soruCevabi;
    cout << "Dogru/Yanlis sorusunun zorluk derecesini giriniz (kolay-orta-zor): ";
    cin >> zorlukDerecesi;
    cout << "Dogru/Yanlis sorusunun puanini giriniz: ";
    cin >> soruPuani;

    YeniDogruYanlisSorusu.setDogruYanlisSoru(yeniId, soruMetni, soruPuani, zorlukDerecesi, soruCevabi);
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
    cout << "Bosluk doldurma sorusunun puanini giriniz: ";
    cin >> soruPuani;

    YeniBoslukDoldurmaSorusu.setBoslukDoldurmaSorusu(yeniId, soruMetni, soruPuani, zorlukDerecesi, soruCevabi);
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
    cout << "Soru puani: " << coktanSecmeliSoru.getSoruPuani() << endl;
    cout << "Soru zorlugu: " << coktanSecmeliSoru.getZorlukDerecesi() << endl;
    cout << "Soru cevabi: " << coktanSecmeliSoru.getDogruCevap() << endl;
}

/* alınan klasikSoruyuYazdir objesinin değerlerini yazdırır */
void klasikSoruyuYazdir(KlasikSoru klasikSoru)
{
    cout << endl;
    cout << klasikSoru.getId();
    cout << "-) " << klasikSoru.getSoruMetni() << endl;
    cout << "Soru cevabi: " << klasikSoru.getSoruCevabi() << endl;
    cout << "Soru puani: " << klasikSoru.getSoruPuani() << endl;
    cout << "Soru zorlugu: " << klasikSoru.getZorlukDerecesi() << endl;
}

/* alınan boslukDoldurmaSorusunuYazdir objesinin değerlerini yazdırır */
void boslukDoldurmaSorusunuYazdir(BoslukDoldurma boslukDoldurmaSorusu)
{
    cout << endl;
    cout << boslukDoldurmaSorusu.getId();
    cout << "-) " << boslukDoldurmaSorusu.getSoruMetni() << endl;
    cout << "Bosluga gelecek cevap: " << boslukDoldurmaSorusu.getBoslukCevabi() << endl;
    cout << "Soru puani: " << boslukDoldurmaSorusu.getSoruPuani() << endl;
    cout << "Soru zorlugu: " << boslukDoldurmaSorusu.getZorlukDerecesi() << endl;
}

/* alınan dogruYanlisSorusunuYazdir objesinin değerlerini yazdırır */
void dogruYanlisSorusunuYazdir(DogruYanlisSoru dogruYanlisSorusu)
{
    cout << endl;
    cout << dogruYanlisSorusu.getId();
    cout << "-) " << dogruYanlisSorusu.getSoruMetni() << endl;
    cout << "Dogru yanlis cevabi : " << dogruYanlisSorusu.getDogruCevap() << endl;
    cout << "Soru puani: " << dogruYanlisSorusu.getSoruPuani() << endl;
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
        geciciCoktanSecmeli.setCoktanSecmeliSoru(id, soruMetni, soruPuani, zorlukDerecesi, soruCevabi, cevaplar);
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
        geciciDogruYanlis.setDogruYanlisSoru(id, soruMetni, soruPuani, soruZorlugu, soruCevabi);
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
        geciciBoslukDoldurma.setBoslukDoldurmaSorusu(id, soruMetni, soruPuani, soruZorlugu, soruCevabi);
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
        geciciKlasikSoru.setKlasikSoru(id, soruMetni, soruPuani, soruZorlugu, soruCevabi);
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
void soruMetniAnahtarKelimeListele(
    vector<CoktanSecmeliSoru> CoktanSecmeliSorular,
    vector<DogruYanlisSoru> DogruYanlisSorulari,
    vector<BoslukDoldurma> BoslukDoldurmaSorulari,
    vector<KlasikSoru> KlasikSorular)
{
    string anahtarKelime;

    cout << "Soru metninde aramak istediginiz anahtar kelimeyi giriniz: ";
    getline(cin >> ws, anahtarKelime);

    for (int i = 0; i < CoktanSecmeliSorular.size(); i++)
    {
        if (CoktanSecmeliSorular[i].getSoruMetni().find(anahtarKelime) != std::string::npos)
        {
            coktanSecmeliSoruyuYazdir(CoktanSecmeliSorular[i]);
        }
    }
    for (int i = 0; i < DogruYanlisSorulari.size(); i++) 
    {
        if (DogruYanlisSorulari[i].getSoruMetni().find(anahtarKelime) != std::string::npos)
        {
            dogruYanlisSorusunuYazdir(DogruYanlisSorulari[i]);
        }
    }
    for (int i = 0; i < BoslukDoldurmaSorulari.size(); i++) 
    {
        if (BoslukDoldurmaSorulari[i].getSoruMetni().find(anahtarKelime) != std::string::npos)
        {
            boslukDoldurmaSorusunuYazdir(BoslukDoldurmaSorulari[i]);
        }
    }
    for (int i = 0; i < KlasikSorular.size(); i++) 
    {
        if (KlasikSorular[i].getSoruMetni().find(anahtarKelime) != std::string::npos)
        {
            klasikSoruyuYazdir(KlasikSorular[i]);
        }
    }
}

/* anahtar kelime girerek soru şıklarında eşleşme olursa soru listelenir */
void soruSikkindaAnahtarKelimeListele(
    vector<CoktanSecmeliSoru> CoktanSecmeliSorular,
    vector<DogruYanlisSoru> DogruYanlisSorulari,
    vector<BoslukDoldurma> BoslukDoldurmaSorulari,
    vector<KlasikSoru> KlasikSorular)
{
    string anahtarKelime;
}

/* kullanıcı a-b-c-d şıklarından birisini girer ve cevabı girilen şık olan sorular listelenir */
void dogruSikkaGoreListele(
    vector<CoktanSecmeliSoru> CoktanSecmeliSorular,
    vector<DogruYanlisSoru> DogruYanlisSorulari,
    vector<BoslukDoldurma> BoslukDoldurmaSorulari,
    vector<KlasikSoru> KlasikSorular)
{
    string soruSikki;
}

/* kullanıcı puan girer, eşleşen sorular listelenir */
void girilenPuanaGoreListele(
    vector<CoktanSecmeliSoru> CoktanSecmeliSorular,
    vector<DogruYanlisSoru> DogruYanlisSorulari,
    vector<BoslukDoldurma> BoslukDoldurmaSorulari,
    vector<KlasikSoru> KlasikSorular)
{
    int girilenSoruPuani;
}

/* sorular zorluguna gore kolay-orta-zor şeklinde listelenir */
void zorlugaGoreListele(
    vector<CoktanSecmeliSoru> CoktanSecmeliSorular,
    vector<DogruYanlisSoru> DogruYanlisSorulari,
    vector<BoslukDoldurma> BoslukDoldurmaSorulari,
    vector<KlasikSoru> KlasikSorular)
{
}

/* sorular puanlarına göre küçükten büyüğe listelenir */
void puanaGoreListele(
    vector<CoktanSecmeliSoru> CoktanSecmeliSorular,
    vector<DogruYanlisSoru> DogruYanlisSorulari,
    vector<BoslukDoldurma> BoslukDoldurmaSorulari,
    vector<KlasikSoru> KlasikSorular)
{
}

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
        cout << "5- Soru zorluguna gore kolaydan zora sorulari listele" << endl;
        cout << "6- Soru puanina gore kucukten buyuge sorulari listele" << endl;
        cout << "7- Ana menuye don" << endl;
        cout << "Lutfen yapmak istediginiz islemi giriniz: ";
        cin >> menuSecimi;

        switch (menuSecimi)
        {
        case 1:
            soruMetniAnahtarKelimeListele(CoktanSecmeliSorular, DogruYanlisSorulari, BoslukDoldurmaSorulari, KlasikSorular);
            break;

        case 2:
            soruSikkindaAnahtarKelimeListele(CoktanSecmeliSorular, DogruYanlisSorulari, BoslukDoldurmaSorulari, KlasikSorular);
            break;

        case 3:
            dogruSikkaGoreListele(CoktanSecmeliSorular, DogruYanlisSorulari, BoslukDoldurmaSorulari, KlasikSorular);
            break;

        case 4:
            girilenPuanaGoreListele(CoktanSecmeliSorular, DogruYanlisSorulari, BoslukDoldurmaSorulari, KlasikSorular);
            break;

        case 5:
            zorlugaGoreListele(CoktanSecmeliSorular, DogruYanlisSorulari, BoslukDoldurmaSorulari, KlasikSorular);
            break;

        case 6:
            puanaGoreListele(CoktanSecmeliSorular, DogruYanlisSorulari, BoslukDoldurmaSorulari, KlasikSorular);
            break;

        case 7:
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
            break;

        case 3:
            soruListele(CoktanSecmeliSorular, DogruYanlisSorulari, BoslukDoldurmaSorulari, KlasikSorular);
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