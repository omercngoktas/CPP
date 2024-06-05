#ifndef LINKEDLIST_H
#define LINKEDLIST_H

using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;
    Node* tail;


public:
    LinkedList();
    void insert(int value);
    int size() const;
    Node* getHead() const;
    LinkedList* getNodeAtIndex(int konum) const;
    void setNodeAtIndex(int index, LinkedList* newList);
    LinkedList copyList() const;
    int calculateMaxInnerSize() const;
    double getAverage();
    int getNodeDataAtIndex(int index) const;
    void setNodeDataAtIndex(int index, int data);


};

#endif
