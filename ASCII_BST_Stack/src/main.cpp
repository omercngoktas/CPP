#include <iostream>
#include "../include/DosyaOku.h"
#include "../include/Yigin.h"
#include "../include/IkiliAramaAgaci.h"

using namespace std;

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Kullanim: " << argv[0] << " <dosya_adi>" << endl;
        return 1;
    }

    dosya_oku(argv[1]);


    return 0;
}
