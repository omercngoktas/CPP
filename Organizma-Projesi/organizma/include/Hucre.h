#ifndef HUCRE_H
#define HUCRE_H

class Hucre {
    private:
        int hucreDegeri;

    public:
        Hucre();
        ~Hucre();
        void setHucreDegeri(int);
        int getHucreDegeri() { return hucreDegeri; }
};

#endif