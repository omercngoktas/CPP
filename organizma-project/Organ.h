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
        BinarySearchTree* BST;
        std::vector <Doku *> dokular;

    public:
        Organ();
        ~Organ();
        void setDoku(Doku*);
        void setOrgan(Doku*);
        void setBST(Doku*);
        BinarySearchTree* getBST() { return BST; }
        std::vector <Doku *> getDokular() { return dokular; }
        // void displayBinarySearchTrees(vector <BinarySearchTree *> BinarySearchTrees);
        // vector <BinarySearchTree *> getBinarySearchTree() { return BinarySearchTrees; }

};

#endif