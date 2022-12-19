#include "BinarySearchTree.h"

struct BinarySearchTree::node {
        Doku* doku;
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

BinarySearchTree::node* BinarySearchTree::insert(Doku* doku, BinarySearchTree::node* t) {
    if(t == NULL) {
        t = new node;
        t->doku = doku;
        t->left = t->right = NULL;
    }
    else if(doku->getOrtancaDeger() < t->doku->getOrtancaDeger()) t->left = insert(doku, t->left);
    else if(doku->getOrtancaDeger() > t->doku->getOrtancaDeger()) t->right = insert(doku, t->right);
    else if(doku->getOrtancaDeger() == t->doku->getOrtancaDeger()) t->left = insert(doku, t->left);
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

BinarySearchTree::node* BinarySearchTree::remove(Doku* doku, BinarySearchTree::node* t) {
    node* temp;
    if(t == NULL) return NULL;
    else if(doku->getOrtancaDeger() < t->doku->getOrtancaDeger()) t->left = remove(doku, t->left);
    else if(doku->getOrtancaDeger() > t->doku->getOrtancaDeger()) t->right = remove(doku, t->right);
    else if(t->left && t->right) {
        temp = findMin(t->right);
        t->doku = temp->doku;
        t->right = remove(t->doku, t->right);
    }
    else {
        temp = t;
        if(t->left == NULL) t = t->right;
        else if(t->right == NULL) t = t->left;
        delete temp;
    }
    return t;
}

void BinarySearchTree::inorder(BinarySearchTree::node* t) {
    if(t == NULL) return;
    inorder(t->left);
    cout << t->doku->getOrtancaDeger() << " ";
    inorder(t->right);
}

BinarySearchTree::node* BinarySearchTree::find(BinarySearchTree::node* t, Doku* doku) {
    if(t == NULL) return NULL;
    else if(doku->getOrtancaDeger() < t->doku->getOrtancaDeger()) return find(t->left, doku);
    else if(doku->getOrtancaDeger() > t->doku->getOrtancaDeger()) return find(t->right, doku);
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

void BinarySearchTree::insert(Doku* doku) {
    root = insert(doku, root);
}

void BinarySearchTree::remove(Doku* doku) {
    root = remove(doku, root);
}

void BinarySearchTree::display() {
    inorder(root);
    cout << endl;
}

void BinarySearchTree::search(Doku* doku) {
    root = find(root, doku);
}

int BinarySearchTree::numberOfElements() {
    return totalNodes(root);
}

int BinarySearchTree::checkIfBalancedAVL(node *t) {
    if(t == NULL){ return 0; cout << "Not balance\n"; }

    /* checking left subtree */
    int leftSubtreeHeight = checkIfBalancedAVL(t->left);
    if(leftSubtreeHeight == -1) return -1;

    /* checking right subtree */
    int rightSubtreeHeight = checkIfBalancedAVL(t->right);
    if(rightSubtreeHeight == -1) return -1;

    if((leftSubtreeHeight - rightSubtreeHeight)> 1 ) return -1;
    if(leftSubtreeHeight > rightSubtreeHeight) return leftSubtreeHeight + 1;
    else if(rightSubtreeHeight > leftSubtreeHeight) return rightSubtreeHeight + 1;
}

int BinarySearchTree::getRootValue() {
    return root->doku->getOrtancaDeger();
}