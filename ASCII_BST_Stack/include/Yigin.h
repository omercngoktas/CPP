#ifndef YIGIN_H
#define YIGIN_H

#include <iostream>

using namespace std;

class Stack {
    private:
        int* elements;
        int topIndex;

    public:
        Stack();
        ~Stack();
        void push(int item);
        void pop();
        int top() const;
        bool empty() const;
        int size() const;
        void display() const;

};

class StackList {
    private:
        class Node {
        public:
            Stack* stack;
            Node* next;

            Node(Stack* s) : stack(s), next(nullptr) {}
        };

        Node* head;
        Node* tail;

    public:
        StackList();
        ~StackList();

        void addStack(Stack* s);
        void removeStack(Stack* s);
        void printAllStacks() const;
        void removeStacks();
        Stack* getStack(int index) const;

};


#endif
