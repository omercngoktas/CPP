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
        vector <BinarySearchTree *> BinarySearchTrees;

    public:
        Organ();
        ~Organ();
        void setBinarySearchTree(BinarySearchTree *yeniBST);
        void displayBinarySearchTrees(vector <BinarySearchTree *> BinarySearchTrees);
        vector <BinarySearchTree *> getBinarySearchTree() { return BinarySearchTrees; }

};

#endif