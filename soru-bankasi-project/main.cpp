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
};

class CoktanSecmeliSoru: public Soru {
    private:
        vector <string> soruSiklari;
        char dogruCevap;
    
    public:
        void setSoruSikki(string yeniCoktanSecmeliCevabi) { soruSiklari.push_back(yeniCoktanSecmeliCevabi); }
        vector <string> getSoruSiklari() { return soruSiklari; }
        void setDogruCevap(char dogruC) { dogruCevap = dogruC; }
        char getDogruCevap() { return dogruCevap; }
};

class DogruYanlisSoru: public Soru {
    private:
        char dogruCevap;

    public:
        void setDogruCevap(char dogruC) { dogruCevap = dogruC; }
        char getDogruCevap() { return dogruCevap; }
};

class KlasikSoru: public Soru {
    private:
        string soruCevabi;

    public:
        void setSoruCevabi(string soruC) { soruCevabi = soruC; }
        string getSoruCevabi() { return soruCevabi; }
};

class BoslukDoldurma: public Soru {
    private:
        string boslukCevabi;

    public:
        void setBoslukCevabi(string boslukC) { boslukCevabi = boslukC; }
        string getBoslukCevabi() { return boslukCevabi; }
};

class Sinav {

};

void coktanSecmeliSoruEkle(vector <CoktanSecmeliSoru> &CoktanSecmeliSorular) {
    CoktanSecmeliSoru YeniCoktanSecmeliSorusu;
    string soruMetni, zorlukDerecesi, a, b, c, d;
    int soruPuani;
    char dogruCevap;

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

    YeniCoktanSecmeliSorusu.setSoruMetni(soruMetni);
    YeniCoktanSecmeliSorusu.setDogruCevap(dogruCevap);
    YeniCoktanSecmeliSorusu.setZorlukDerecesi(zorlukDerecesi);
    YeniCoktanSecmeliSorusu.setSoruPuani(soruPuani);
    YeniCoktanSecmeliSorusu.setSoruSikki(a);
    YeniCoktanSecmeliSorusu.setSoruSikki(b);
    YeniCoktanSecmeliSorusu.setSoruSikki(c);
    YeniCoktanSecmeliSorusu.setSoruSikki(d);
    
    CoktanSecmeliSorular.push_back(YeniCoktanSecmeliSorusu);
}

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

    YeniKlasikSorusu.setSoruMetni(soruMetni);
    YeniKlasikSorusu.setSoruPuani(soruPuani);
    YeniKlasikSorusu.setZorlukDerecesi(zorlukDerecesi);
    YeniKlasikSorusu.setSoruCevabi(soruCevabi);

    KlasikSorular.push_back(YeniKlasikSorusu);
}

void dogruYanlisSoruEkle(vector <DogruYanlisSoru> &DogruYanlisSorulari) {
    DogruYanlisSoru YeniDogruYanlisSorusu;
    string soruMetni, zorlukDerecesi;
    char soruCevabi;
    int soruPuani;

    cout << "Dogru/Yanlis sorusunun metnini giriniz: ";
    getline(cin >> ws, soruMetni);
    cout << "Dogru/Yanlis sorusunun cevabini giriniz (Y/N): ";
    cin >> soruCevabi;
    cout << "Dogru/Yanlis sorusunun zorluk derecesini giriniz (kolay-orta-zor): ";
    cin >> zorlukDerecesi;
    cout << "Dogru/Yanlis sorusunun puanini giriniz: ";
    cin >> soruPuani;

    YeniDogruYanlisSorusu.setDogruCevap(soruCevabi);
    YeniDogruYanlisSorusu.setSoruMetni(soruMetni);
    YeniDogruYanlisSorusu.setSoruPuani(soruPuani);
    YeniDogruYanlisSorusu.setZorlukDerecesi(zorlukDerecesi);

    DogruYanlisSorulari.push_back(YeniDogruYanlisSorusu);
}


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

    YeniBoslukDoldurmaSorusu.setSoruMetni(soruMetni);
    YeniBoslukDoldurmaSorusu.setSoruPuani(soruPuani);
    YeniBoslukDoldurmaSorusu.setZorlukDerecesi(zorlukDerecesi);
    YeniBoslukDoldurmaSorusu.setBoslukCevabi(soruCevabi);
}

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
        cout << "Soru: " << CoktanSecmeliSorular[i].getSoruMetni() << endl;
        cout << "a) " << CoktanSecmeliSorular[i].getSoruSiklari()[0] << endl;
        cout << "b) " << CoktanSecmeliSorular[i].getSoruSiklari()[1] << endl;
        cout << "c) " << CoktanSecmeliSorular[i].getSoruSiklari()[2] << endl;
        cout << "d) " << CoktanSecmeliSorular[i].getSoruSiklari()[3] << endl;
        cout << "Soru puani: " << CoktanSecmeliSorular[i].getSoruPuani() << endl;
        cout << "Soru zorlugu: " << CoktanSecmeliSorular[i].getZorlukDerecesi() << endl;
        cout << "Soru cevabi: " << CoktanSecmeliSorular[i].getSoruMetni() << endl;
    }
}



void TxtdenSoruEkle() {
    int id;
    string a, b, c, d, soruMetni, soruCevabi, soruZorlugu, textMetni;

    ifstream coktanSecmeliText("coktan-secmeli-sorular.txt");
    ifstream dogruYanlisText("dogru-yanlis-sorulari.txt");
    ifstream boslukDoldurmaText("bosluk-doldurma-sorulari.txt");
    ifstream klasikSoruText("klasik-sorular.txt");

    while(getline(coktanSecmeliText, textMetni)) {
        for(int i = 0; i < textMetni.size(); i++) {
            
        }
    }
}

int idOlustur (
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
    }
}

int main() {
    vector <CoktanSecmeliSoru> CoktanSecmeliSorular;
    vector <DogruYanlisSoru> DogruYanlisSorulari;
    vector <BoslukDoldurma> BoslukDoldurmaSorulari;
    vector <KlasikSoru> KlasikSorular;

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