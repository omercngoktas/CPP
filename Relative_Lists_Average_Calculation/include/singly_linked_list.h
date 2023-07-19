#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
// Node class to represent a node of the linked list.
class Node {
    public:
        int data;
        Node* next;

        // Default constructor
        Node();

        // Parameterized Constructor
        Node(int data);
};

// Linked list class to implement a linked list.
class LinkedList {
    Node* head;

    public:
        // Default constructor
        LinkedList();

        // Function to insert a node at the end of the linked list.
        void insertNode(int data);

        // Function to print the linked list.
        void printList();

        // Function to delete the node at a given position.
        void deleteNode(int nodeOffset);

        int get(int position);
        Node* getHead() const; // Add this method to access the head member.

};

#endif
