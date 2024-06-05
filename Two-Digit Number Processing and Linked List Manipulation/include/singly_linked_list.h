#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>

class Node {
    public:
        int sayi;
        Node();
        Node(int sayi);
        Node* sonraki;
};

class LinkedList {
    Node* root;

    public:
        LinkedList();
        void insert_node(int sayi);
        int get(int index);
        Node* get_root() const;
};

#endif
