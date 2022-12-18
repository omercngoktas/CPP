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
        BinarySearchTree *BinarySearchTrees = new BinarySearchTree();

    public:
        Organ();
        ~Organ();
        void setBinarySearchTree(Hucre *hucre);
        int getSizeOfBST();
        // void displayBinarySearchTrees(vector <BinarySearchTree *> BinarySearchTrees);
        // vector <BinarySearchTree *> getBinarySearchTree() { return BinarySearchTrees; }

};

#endif