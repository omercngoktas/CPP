#include "BinarySearchTree.h"

struct BinarySearchTree::node {
        Doku doku;
        node* left;
        node* right;
};

BinarySearchTree::node* BinarySearchTree::makeEmpty(BinarySearchTree::node* t) {
    if(t == NULL) return NULL; {
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
    }
    return NULL;
}

BinarySearchTree::node* BinarySearchTree::insert(Hucre hucre, BinarySearchTree::node* t) {
    if(t == NULL) {
        t = new node;
        t->doku.setDokuDegerleri(hucre);
        t->left = t->right = NULL;
    }
    else if(hucre.getHucreDegeri() < t->doku.getDokuDegerleri().getHucreDegeri()) t->left = insert(hucre, t->left);
    else if(hucre.getHucreDegeri() > t->doku.getDokuDegerleri().getHucreDegeri()) t->right = insert(hucre, t->right);
    else if(hucre.getHucreDegeri() == t->doku.getDokuDegerleri().getHucreDegeri()) t->left = insert(hucre, t->left);
    return t;
}

BinarySearchTree::node* BinarySearchTree::findMin(BinarySearchTree::node* t) {
    if(t == NULL) return NULL;
    else if(t->left == NULL) return t;
    else return findMin(t->left);
}

BinarySearchTree::node* BinarySearchTree::findMax(BinarySearchTree::node* t) {
    if(t == NULL) return NULL;
    else if(t->right == NULL) return t;
    else return findMax(t->right);
}

BinarySearchTree::node* BinarySearchTree::remove(Hucre hucre, BinarySearchTree::node* t) {
    node* temp;
    if(t == NULL) return NULL;
    else if(hucre.getHucreDegeri() < t->doku.getDokuDegerleri().getHucreDegeri()) t->left = remove(hucre, t->left);
    else if(hucre.getHucreDegeri() > t->doku.getDokuDegerleri().getHucreDegeri()) t->right = remove(hucre, t->right);

    else if(t->left && t->right) {
        temp = findMin(t->right);
        t->doku = temp->doku;
        t->right = remove(t->doku.getDokuDegerleri(), t->right);
    }
    else {
        temp = t;
        if(t->left == NULL)
            t = t->right;
        else if(t->right == NULL)
            t = t->left;
        delete temp;
    }

    return t;
}

void BinarySearchTree::inorder(BinarySearchTree::node* t) {
    if(t == NULL) return;
    inorder(t->left);
    cout << t->doku.getDokuDegerleri().getHucreDegeri() << " ";
    inorder(t->right);
}

BinarySearchTree::node* BinarySearchTree::find(BinarySearchTree::node* t, Hucre hucre) {
    if(t == NULL) return NULL;
    else if(hucre.getHucreDegeri() < t->doku.getDokuDegerleri().getHucreDegeri()) return find(t->left, hucre);
    else if(hucre.getHucreDegeri() > t->doku.getDokuDegerleri().getHucreDegeri()) return find(t->right, hucre);
    else return t;
}

// Function to get the count of nodes
// in complete binary tree
int BinarySearchTree::totalNodes(BinarySearchTree::node* root) {
    if (root == NULL) return 0;
    int l = totalNodes(root->left);
    int r = totalNodes(root->right);
    return 1 + l + r;
}

BinarySearchTree::BinarySearchTree() {
    root = NULL;
}

BinarySearchTree::~BinarySearchTree() {
    root = makeEmpty(root);
    cout << "Tree deleted" << endl;
}

void BinarySearchTree::insert(Hucre hucre) {
    root = insert(hucre, root);
}

void BinarySearchTree::remove(Hucre hucre) {
    root = remove(hucre, root);
}

void BinarySearchTree::display() {
    inorder(root);
    cout << endl;
}

void BinarySearchTree::search(Hucre hucre) {
    root = find(root, hucre);
}

int BinarySearchTree::numberOfElements() {
    return totalNodes(root);
}