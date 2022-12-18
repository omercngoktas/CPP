#include "Organ.h"

void Organ::setBinarySearchTree(Hucre *hucre) {
    BinarySearchTrees->insert(*hucre);
}

// void Organ::displayBinarySearchTrees(vector <BinarySearchTree *> BinarySearchTrees) {
//     cout << "Size of binary search tree vector: " << BinarySearchTrees.size() << endl;
// }

int Organ::getSizeOfBST() { return BinarySearchTrees->numberOfElements(); }

Organ::Organ() {

}

Organ::~Organ() {
    
}