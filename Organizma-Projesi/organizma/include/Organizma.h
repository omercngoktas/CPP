#ifndef ORGANIZMA_H
#define ORGANIZMA_H
#include <vector>
#include "Sistem.h"

class Organizma {
    private:
        std::vector <Sistem*> sistemler;

    public:
        Organizma();
        ~Organizma();
        void setSistemler(Sistem*);
        int getSizeOfOrganizma() { return sistemler.size(); }
        std::vector <Sistem*> getSistemler() { return sistemler; }
};

#endif