#include "Organ.h"

void Organ::setBinarySearchTree(BinarySearchTree *yeniBST) {
    BinarySearchTrees.push_back(yeniBST);
}

void Organ::displayBinarySearchTrees(vector <BinarySearchTree *> BinarySearchTrees) {
    cout << "Size of binary search tree vector: " << BinarySearchTrees.size() << endl;
}

Organ::Organ() {

}

Organ::~Organ() {
    
}