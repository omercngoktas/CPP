#include "../include/singly_linked_list.h"

using namespace std;

// Node class methods

// Default constructor
Node::Node() {
    data = 0;
    next = NULL;
}

// Parameterized Constructor
Node::Node(int data) {
    this->data = data;
    this->next = NULL;
}

// Linked list class methods

// Default constructor
LinkedList::LinkedList() {
    head = NULL;
}

Node* LinkedList::getHead() const {
    return head;
}

// Function to insert a new node.
void LinkedList::insertNode(int data) {
    // Create the new Node.
    Node* newNode = new Node(data);

    // Assign to head
    if (head == NULL) {
        head = newNode;
        return;
    }

    // Traverse till end of list
    Node* temp = head;
    while (temp->next != NULL) {
        // Update temp
        temp = temp->next;
    }

    // Insert at the last.
    temp->next = newNode;
}

// Function to print the nodes of the linked list.
void LinkedList::printList() {
    Node* temp = head;

    // Check for empty list.
    if (head == NULL) {
        cout << "List empty" << endl;
        return;
    }

    // Traverse the list.
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

// Function to delete the node at a given position.
void LinkedList::deleteNode(int nodeOffset) {
    Node* temp1 = head, *temp2 = NULL;
    int ListLen = 0;

    if (head == NULL) {
        cout << "List empty." << endl;
        return;
    }

    // Find length of the linked-list.
    while (temp1 != NULL) {
        temp1 = temp1->next;
        ListLen++;
    }

    // Check if the position to be deleted is greater than the length of the linked list.
    if (ListLen < nodeOffset) {
        cout << "Index out of range" << endl;
        return;
    }

    // Declare temp1
    temp1 = head;

    // Deleting the head.
    if (nodeOffset == 1) {
        // Update head
        head = head->next;
        delete temp1;
        return;
    }

    // Traverse the list to find the node to be deleted.
    while (nodeOffset-- > 1) {
        // Update temp2
        temp2 = temp1;
        // Update temp1
        temp1 = temp1->next;
    }

    // Change the next pointer of the previous node.
    temp2->next = temp1->next;

    // Delete the node
    delete temp1;
}

int LinkedList::get(int position) {
    Node* temp = head;
    int currentPosition = 0;

    // Traverse the list until the desired position is reached.
    while (temp != NULL && currentPosition < position) {
        temp = temp->next;
        currentPosition++;
    }

    // Check if the position is valid.
    if (temp == NULL) {
        // The position is beyond the end of the list.
        cout << "Invalid position. No node found at index " << position << endl;
        return -1; // Or you can handle this differently based on your requirements.
    }

    // Return the data of the node at the specified position.
    return temp->data;
}
