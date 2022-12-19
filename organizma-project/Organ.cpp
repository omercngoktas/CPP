#include "Organ.h"

Organ::Organ() {
    BST = new BinarySearchTree();
}

Organ::~Organ() {
    
}

void Organ::setDoku(Doku *doku) {
    dokular.push_back(doku);
}

void Organ::setOrgan(Doku* yeniDoku) {
    dokular.push_back(yeniDoku);
    BST->insert(yeniDoku);
}

void Organ::setBST(Doku* yeniDoku) {
    BST->insert(yeniDoku);
}


// void Organ::displayBinarySearchTrees(vector <BinarySearchTree *> BinarySearchTrees) {
//     cout << "Size of binary search tree vector: " << BinarySearchTrees.size() << endl;
// }


