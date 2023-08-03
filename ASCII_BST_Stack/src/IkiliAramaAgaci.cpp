#include "../include/IkiliAramaAgaci.h"

IkiliAramaAgaci::IkiliAramaAgaci() : root(nullptr) {}

AgacDugumu* IkiliAramaAgaci::insert(AgacDugumu* node, int sayi) {
    if (node == nullptr) {
        return new AgacDugumu(sayi);
    }

    if (sayi < node->data) {
        node->sol = insert(node->sol, sayi);
    } else if (sayi > node->data) {
        node->right = insert(node->right, sayi);
    } else {
        return node;
    }

    return node;
}

void IkiliAramaAgaci::insert(int sayi) {
    root = insert(root, sayi);
}

void IkiliAramaAgaci::display() {
    postorderTraversal(root);
    std::cout << std::endl;
}

int IkiliAramaAgaci::getHeight(AgacDugumu* node) {
    if (node == nullptr) {
        return -1;
    }

    int leftHeight = getHeight(node->sol);
    int rightHeight = getHeight(node->right);

    return 1 + std::max(leftHeight, rightHeight);
}


int IkiliAramaAgaci::getHeight() {
    return getHeight(root);
}

int IkiliAramaAgaci::getSum(AgacDugumu* node) {
    if (node == nullptr) {
        return 0;
    }

    return node->data + getSum(node->sol) + getSum(node->right);
}

int IkiliAramaAgaci::getSum() {
    return getSum(root);
}

void IkiliAramaAgaci::postorderTraversal(AgacDugumu* node) {
    if (node != nullptr) {
        postorderTraversal(node->sol);
        postorderTraversal(node->right);
        std::cout << char(node->data) << " ";
    }
}

void IkiliAramaAgaci::postorderTraversal() {
    postorderTraversal(root);
}








IkiliAramaAgaciListesi::IkiliAramaAgaciListesi() : head(nullptr), tail(nullptr) {}

IkiliAramaAgaciListesi::~IkiliAramaAgaciListesi() {
    Node* current = head;
    while (current) {
        Node* next = current->next;
        delete current->tree;
        delete current;
        current = next;
    }
}

void IkiliAramaAgaciListesi::addTree(IkiliAramaAgaci* tree) {
    Node* newNode = new Node(tree);

    if (!head) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}


IkiliAramaAgaci* IkiliAramaAgaciListesi::getTreeByIndex(int index) const {
    Node* current = head;
    int count = 0;

    while (current) {
        if (count == index) {
            return current->tree;
        }
        count++;
        current = current->next;
    }

    return nullptr;
}
