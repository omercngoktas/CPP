#ifndef KONTROL_H
#define KONTROL_H
#include "Organizma.h"

class Kontrol {
    private:
        Organizma* organizma = new Organizma();
        
    public:
        Kontrol(Organizma*);
        ~Kontrol();
        void mutasyonKontrolEt();
        Organ* mutasyonaUgrat(Organ*);
};

#endif