#ifndef IKILIARAMAAGACI_H
#define IKILIARAMAAGACI_H

#include <iostream>

using namespace std;

class AgacDugumu {
    public:
        int data;
        AgacDugumu* sol;
        AgacDugumu* right;
        AgacDugumu(int sayi) : data(sayi), sol(nullptr), right(nullptr) {};
};

class IkiliAramaAgaci {
    private:
        AgacDugumu* root;
        AgacDugumu* insert(AgacDugumu* node, int sayi);
        int getHeight(AgacDugumu* node);
        int getSum(AgacDugumu* node);
        void postorderTraversal(AgacDugumu* node);

    public:
        IkiliAramaAgaci();
        void insert(int sayi);
        void display();
        int getHeight();
        int getSum();
        void postorderTraversal();
};

class IkiliAramaAgaciListesi {
    private:
        class Node {
            public:
                IkiliAramaAgaci* tree;
                Node* next;
                Node(IkiliAramaAgaci* t) : tree(t), next(nullptr) {}
        };
        Node* head;
        Node* tail;

    public:
        IkiliAramaAgaciListesi();
        ~IkiliAramaAgaciListesi();
        void addTree(IkiliAramaAgaci* tree);
        IkiliAramaAgaci* getTreeByIndex(int index) const;

};

#endif
