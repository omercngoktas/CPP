vector <int> soruIdleri;
    KlasikSoru yeniKlasikSoru;
    int j = 0, soruIndexi, vectordeVarMi = 0;

    while( YeniKlasikSinav.getPuanToplami() < 100 ) {
        vectordeVarMi = 0;
        soruIndexi = randomSayiUret(KlasikSorular.size());

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