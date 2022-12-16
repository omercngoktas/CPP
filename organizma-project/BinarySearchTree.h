#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <cstddef>
#include <algorithm>

using namespace std;

class BST {
    
    struct node;

    node* root;

    node* makeEmpty(node* t);

    node* insert(int x, node* t);

    node* findMin(node* t);

    node* findMax(node* t);

    node* remove(int x, node* t);

    void inorder(node* t);

    node* find(node* t, int x);

    // Function to get the count of nodes
    // in complete binary tree
    int totalNodes(node* root);

    public:
        BST();

        ~BST();

        void insert(int x);

        void remove(int x);

        void display();

        void search(int x);

        int numberOfElements();
};

#endif