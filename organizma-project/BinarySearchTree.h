#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <cstddef>
#include <algorithm>
#include "Doku.h"
#include <math.h>
using namespace std;

class BinarySearchTree {
    private:
        struct node;
        node* root;
        node* makeEmpty(node* t);
        node* insert(Doku*, node* t);
        node* findMin(node* t);
        node* findMax(node* t);
        node* remove(Doku*, node* t);
        void inorder(node* t);
        node* find(node* t, Doku*);
        int totalNodes(node* root);
        int checkIfBalancedAVL(node* t);

    public:
        BinarySearchTree();
        ~BinarySearchTree();
        void insert(Doku*);
        void remove(Doku*);
        void display();
        void search(Doku*);
        int numberOfElements();
        int checkBalance() { return checkIfBalancedAVL(root); }
        int getRootValue();
};

#endif