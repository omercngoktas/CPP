#include "../include/LinkedList.h"
#include <iostream>

LinkedList::LinkedList() : head(nullptr), tail(nullptr) {}

// linked list'in sonuna yeni bir değer eklenmesi
void LinkedList::insert(int value) {
    Node* newNode = new Node(value);
    if (!head) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

// en baştaki düğümün döndürülmesi
Node* LinkedList::getHead() const {
    return head;
}

int LinkedList::size() const {
    int count = 0;
    Node* current = head;
    while (current) {
        count++;
        current = current->next;
    }
    return count;
}

// parametre olarak verilen konumdaki düğümün döndürülmesi
LinkedList* LinkedList::getNodeAtIndex(int index) const {
    int count = 0;
    Node* current = head;
    while (current) {
        if (count == index) {
            return reinterpret_cast<LinkedList*>(current);
        }
        count++;
        current = current->next;
    }
    return nullptr;
}

// alınan listenin kopyalanması
LinkedList LinkedList::copyList() const {
    LinkedList newList;
    Node* current = head;
    while (current) {
        newList.insert(current->data);
        current = current->next;
    }
    return newList;
}

// alınan konum değerine göre yeni değerin girilmesi
void LinkedList::setNodeAtIndex(int index, LinkedList* newList) {
    int count = 0;
    Node* current = head;
    while (current) {
        if (count == index) {
            LinkedList newListCopy = newList->copyList();
            current->data = reinterpret_cast<intptr_t>(newListCopy.getHead());
            return;
        }
        count++;
        current = current->next;
    }
}

// tüm linked listlerin içindeki en uzun listenin uzunluğunu bul
int LinkedList::calculateMaxInnerSize() const {
    int maxSize = 0;
    Node* currentList = head;

    while (currentList) {
        int innerSize = 0;
        Node* currentNode = reinterpret_cast<Node*>(currentList->data);
        while (currentNode) {
            innerSize++;
            currentNode = currentNode->next;
        }
        maxSize = max(maxSize, innerSize);
        currentList = currentList->next;
    }
    return maxSize;
}

// verilen konumdaki düğümün sayısını döndür
int LinkedList::getNodeDataAtIndex(int index) const {
    Node* current = head;
    int count = 0;
    while (current && count < index) {
        current = current->next;
        count++;
    }
    if (current) {
        return current->data;
    }
    return -1;
}

// verilen konumdaki düğümün sayısını güncelle
void LinkedList::setNodeDataAtIndex(int index, int data) {
    Node* current = head;
    int count = 0;
    while (current && count < index) {
        current = current->next;
        count++;
    }
    if (current) {
        current->data = data;
    }
}

// linked listlerin içindeki değerlerin ortalamasını bulur
double LinkedList::getAverage() {
    int maxSize = calculateMaxInnerSize();

    LinkedList sums;
    LinkedList counts;

    for (int i = 0; i < maxSize; i++) {
        sums.insert(0);
        counts.insert(0);
    }

    Node* currentList = head;
    while (currentList) {
        LinkedList* currentHead = reinterpret_cast<LinkedList*>(currentList);
        Node* currentNode = currentHead->getHead();

        int position = 0;
        while (currentNode) {
            sums.setNodeDataAtIndex(position, sums.getNodeDataAtIndex(position) + currentNode->data);
            counts.setNodeDataAtIndex(position, counts.getNodeDataAtIndex(position) + 1);
            currentNode = currentNode->next;
            position++;
        }
        currentList = currentList->next;
    }

    double overallSum = 0.0;
    for (int i = 0; i < maxSize; i++) {
        int count = counts.getNodeDataAtIndex(i);
        if (count > 0) {
            double average = static_cast<double>(sums.getNodeDataAtIndex(i)) / count;
            overallSum += average;
        }
    }
    return overallSum;
}

