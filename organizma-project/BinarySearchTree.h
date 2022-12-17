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

using namespace std;

class BinarySearchTree {
    
    struct node;

    node* root;

    node* makeEmpty(node* t);

    node* insert(Hucre hucre, node* t);

    node* findMin(node* t);

    node* findMax(node* t);

    node* remove(Hucre hucre, node* t);

    void inorder(node* t);

    node* find(node* t, Hucre hucre);

    // Function to get the count of nodes
    // in complete binary tree
    int totalNodes(node* root);

    public:
        BinarySearchTree();

        ~BinarySearchTree();

        void insert(Hucre hucre);

        void remove(Hucre hucre);

        void display();

        void search(Hucre hucre);

        int numberOfElements();
};

#endif