#include "../include/singly_linked_list.h"

using namespace std;

LinkedList::LinkedList() { root = NULL; }

Node::Node() {
    sayi = 0;
    sonraki = NULL;
}

Node::Node(int sayi) {
    this->sayi = sayi;
    this->sonraki = NULL;
}

void LinkedList::insert_node(int sayi) {
    Node* new_node = new Node(sayi);

    if (root == NULL) {
        root = new_node;
        return;
    }

    Node* temp = root;
    while (temp->sonraki != NULL) {
        temp = temp->sonraki;
    }

    temp->sonraki = new_node;
}

int LinkedList::get(int index) {
    Node* temp_root = root;
    int current_index = 0;

    while (temp_root != NULL && current_index < index) {
        temp_root = temp_root->sonraki;
        current_index++;
    }

    if (temp_root == NULL) {
        cout << "Gecersiz index." << index << endl;
    }

    return temp_root->sayi;
}

Node* LinkedList::get_root() const { return root; }