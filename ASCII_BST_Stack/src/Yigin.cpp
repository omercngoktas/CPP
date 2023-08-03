#include "../include/Yigin.h"

Stack::Stack() : elements(nullptr), topIndex(-1) {}

Stack::~Stack() {
    delete[] elements;
}

void Stack::push(int item) {
    int* newElements = new int[topIndex + 2];
    for (int i = 0; i <= topIndex; i++) {
        newElements[i] = elements[i];
    }
    newElements[topIndex + 1] = item;

    delete[] elements;
    elements = newElements;
    topIndex++;
}

void Stack::pop() {
    if (!empty()) {
        topIndex--;
    }
}

int Stack::top() const {
    if (!empty()) {
        return elements[topIndex];
    }

    return -1;
}

bool Stack::empty() const {
    return topIndex == -1;
}

int Stack::size() const {
    return topIndex + 1;
}

void Stack::display() const {
    if (empty()) {
        std::cout << "Stack is empty." << std::endl;
        return;
    }

    std::cout << "Stack items: ";
    for (int i = topIndex; i >= 0; i--) {
        std::cout << elements[i] << " ";
    }
    std::cout << std::endl;
}





StackList::StackList() : head(nullptr), tail(nullptr) {}

StackList::~StackList() {
    Node* current = head;
    while (current) {
        Node* next = current->next;
        delete current->stack;
        delete current;
        current = next;
    }
}

void StackList::addStack(Stack* s) {
    Node* newNode = new Node(s);

    if (!head) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

void StackList::removeStack(Stack* s) {
    Node* current = head;
    Node* prev = nullptr;

    while (current) {
        if (current->stack == s) {
            if (prev) {
                prev->next = current->next;
            } else {
                head = current->next;
            }

            if (current == tail) {
                tail = prev;
            }

            delete current->stack;
            delete current;
            return;
        }

        prev = current;
        current = current->next;
    }
}

void StackList::printAllStacks() const {
    Node* current = head;
    int stackNum = 1;

    while (current) {
        std::cout << "Stack " << stackNum << " items: ";
        Stack* stack = current->stack;
        while (!stack->empty()) {
            std::cout << stack->top() << " ";
            stack->pop();
        }
        std::cout << std::endl;

        current = current->next;
        stackNum++;
    }
}

void StackList::removeStacks() {
    Node* current = head;
    while (current) {
        Node* next = current->next;
        delete current->stack;
        delete current;
        current = next;
    }
    head = nullptr;
    tail = nullptr;
}

Stack* StackList::getStack(int index) const {
    if (index < 0) {
        return nullptr; // Return nullptr if the index is invalid (less than 0)
    }

    Node* current = head;
    int count = 0;

    while (current) {
        if (count == index) {
            return current->stack;
        }

        current = current->next;
        count++;
    }

    return nullptr; // Return nullptr if the index is greater than the number of stacks in the list
}