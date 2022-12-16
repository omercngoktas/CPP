#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <cstddef>
#include <algorithm>
#include "radixSort.h"
#include "Hucre.h"
#include "BinarySearchTree.h"

#include <time.h>

using namespace std;

// class BST {
    
//     struct node {
//         int data;
//         node* left;
//         node* right;
//     };

//     node* root;

//     node* makeEmpty(node* t) {
//         if(t == NULL)
//             return NULL;
//         {
//             makeEmpty(t->left);
//             makeEmpty(t->right);
//             delete t;
//         }
//         return NULL;
//     }

//     node* insert(int x, node* t)
//     {
//         if(t == NULL)
//         {
//             t = new node;
//             t->data = x;
//             t->left = t->right = NULL;
//         }
//         else if(x < t->data)
//             t->left = insert(x, t->left);
//         else if(x > t->data)
//             t->right = insert(x, t->right);
//         else if(x == t->data)
//             t->left = insert(x, t->left);
//         return t;
//     }

//     node* findMin(node* t)
//     {
//         if(t == NULL)
//             return NULL;
//         else if(t->left == NULL)
//             return t;
//         else
//             return findMin(t->left);
//     }

//     node* findMax(node* t) {
//         if(t == NULL)
//             return NULL;
//         else if(t->right == NULL)
//             return t;
//         else
//             return findMax(t->right);
//     }

//     node* remove(int x, node* t) {
//         node* temp;
//         if(t == NULL)
//             return NULL;
//         else if(x < t->data)
//             t->left = remove(x, t->left);
//         else if(x > t->data)
//             t->right = remove(x, t->right);
//         else if(t->left && t->right)
//         {
//             temp = findMin(t->right);
//             t->data = temp->data;
//             t->right = remove(t->data, t->right);
//         }
//         else
//         {
//             temp = t;
//             if(t->left == NULL)
//                 t = t->right;
//             else if(t->right == NULL)
//                 t = t->left;
//             delete temp;
//         }

//         return t;
//     }

//     void inorder(node* t) {
//         if(t == NULL)
//             return;
//         inorder(t->left);
//         cout << t->data << " ";
//         inorder(t->right);
//     }

//     node* find(node* t, int x) {
//         if(t == NULL)
//             return NULL;
//         else if(x < t->data)
//             return find(t->left, x);
//         else if(x > t->data)
//             return find(t->right, x);
//         else
//             return t;
//     }

//     // Function to get the count of nodes
//     // in complete binary tree
//     int totalNodes(node* root) {
//         if (root == NULL)
//             return 0;
//         int l = totalNodes(root->left);
//         int r = totalNodes(root->right);
//         return 1 + l + r;
//     }

//     public:
//         BST() {
//             root = NULL;
//         }

//         ~BST() {
//             root = makeEmpty(root);
//         }

//         void insert(int x) {
//             root = insert(x, root);
//         }

//         void remove(int x) {
//             root = remove(x, root);
//         }

//         void display() {
//             inorder(root);
//             cout << endl;
//         }

//         void search(int x) {
//             root = find(root, x);
//         }

//         int numberOfElements() {
//             return totalNodes(root);
//         }
// };

Hucre getOrtadakiHucre(vector <Hucre> hucreListesi) {
    return hucreListesi[hucreListesi.size()/2];
}

void txtdenOku(string txtDosyaAdi) {
    ifstream VeriDosyasi(txtDosyaAdi);
    string text;
    int counter = 0;
    while (getline(VeriDosyasi, text)) {
        vector <Hucre> hucreListesi;
        vector <int> hucreler = tokenize(text);
        radix_sort(hucreler);
        int midElement = hucreler[hucreler.size() / 2];

        for(int i = 0; i < hucreler.size(); i++) {
            Hucre yeniHucre;
            yeniHucre.setHucreDegeri(hucreler[i]);
            hucreListesi.push_back(yeniHucre);
        }
        // cout << "Orta deger: " << getOrtaSayiDegeri(hucreListesi) << "\tSize: " << hucreListesi.size() << endl;
        for(int j = 0; j < hucreListesi.size(); j+=1) {
            // cout << hucreListesi[j].getHucreDegeri() << "\t";
            counter++;
        }
        
    }
    //organlar[1].insert(1);
    // organlar[0].insert(0);
    // organlar[2].insert(2);
    cout << "Counter: " << counter << endl;
}


int main() {
    clock_t start = clock();
    vector <BST> organlar;
    BST organ;
    organ.insert(1);
    organ.insert(13);
    organ.insert(12);
    organ.insert(15);
    organ.insert(100);
    organlar.push_back(organ);
    organlar[0].insert(50);
    organlar[0].display();



    cout << "Start\n";
    txtdenOku("Veri.txt");
    // cout << "Number of elements: " << bstNode.numberOfElements() << endl;
    clock_t end = clock();
    double elapsed = double(end - start)/CLOCKS_PER_SEC;
    cout << "Timer: " << elapsed << endl;
    return 0;
}