#ifndef ORGAN_H
#define ORGAN_H
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <cstddef>
#include <algorithm>
#include "BinarySearchTree.h"

class Organ {
    private:
        BinarySearchTree* BST = new BinarySearchTree();
        std::vector <Doku *> dokular;

    public:
        Organ();
        ~Organ();
        void setOrgan(Doku*);
        void mutasyonGecir(Organ*);
        BinarySearchTree* getBST() { return BST; }
        std::vector <Doku *> getDokular() { return dokular; }
};

#endif