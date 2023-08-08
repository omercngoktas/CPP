#ifndef DOSYAOKU_H
#define DOSYAOKU_H

#include <fstream>
#include <iostream>
#include <sstream>
#include <windows.h>
#include "Yigin.h"
#include "IkiliAramaAgaci.h"
using namespace std;

void dosya_oku(string dosya_adi);
void yiginaYeniSayiEkle(int eklenecek_sayi, Yigin* &guncel_yigin, YiginListesi* &yigin_listesi);
void ikiliAramaAgacinaEkle(IkiliAramaAgaciListesi* &ikili_arama_agaci_listesi, YiginListesi* &yigin_listesi);
IkiliAramaAgaci* ikiliAramaAgaciBul(IkiliAramaAgaciListesi* ikili_arama_agaci_listesi);

#endif
