#include "BinarySearchTree.h"

struct BST::node {
        int data;
        node* left;
        node* right;
};

BST::node* BST::makeEmpty(BST::node* t) {
    if(t == NULL)
        return NULL;
    {
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
    }
    return NULL;
}

BST::node* BST::insert(int x, BST::node* t)
{
    if(t == NULL)
    {
        t = new node;
        t->data = x;
        t->left = t->right = NULL;
    }
    else if(x < t->data)
        t->left = insert(x, t->left);
    else if(x > t->data)
        t->right = insert(x, t->right);
    else if(x == t->data)
        t->left = insert(x, t->left);
    return t;
}

BST::node* BST::findMin(BST::node* t)
{
    if(t == NULL)
        return NULL;
    else if(t->left == NULL)
        return t;
    else
        return findMin(t->left);
}

BST::node* BST::findMax(BST::node* t) {
    if(t == NULL)
        return NULL;
    else if(t->right == NULL)
        return t;
    else
        return findMax(t->right);
}

BST::node* BST::remove(int x, BST::node* t) {
    node* temp;
    if(t == NULL)
        return NULL;
    else if(x < t->data)
        t->left = remove(x, t->left);
    else if(x > t->data)
        t->right = remove(x, t->right);
    else if(t->left && t->right)
    {
        temp = findMin(t->right);
        t->data = temp->data;
        t->right = remove(t->data, t->right);
    }
    else
    {
        temp = t;
        if(t->left == NULL)
            t = t->right;
        else if(t->right == NULL)
            t = t->left;
        delete temp;
    }

    return t;
}

void BST::inorder(BST::node* t) {
    if(t == NULL)
        return;
    inorder(t->left);
    cout << t->data << " ";
    inorder(t->right);
}

BST::node* BST::find(BST::node* t, int x) {
    if(t == NULL)
        return NULL;
    else if(x < t->data)
        return find(t->left, x);
    else if(x > t->data)
        return find(t->right, x);
    else
        return t;
}

// Function to get the count of nodes
// in complete binary tree
int BST::totalNodes(BST::node* root) {
    if (root == NULL)
        return 0;
    int l = totalNodes(root->left);
    int r = totalNodes(root->right);
    return 1 + l + r;
}
BST::BST() {
    root = NULL;
}

BST::~BST() {
    root = makeEmpty(root);
}

void BST::insert(int x) {
    root = insert(x, root);
}

void BST::remove(int x) {
    root = remove(x, root);
}

void BST::display() {
    inorder(root);
    cout << endl;
}

void BST::search(int x) {
    root = find(root, x);
}

int BST::numberOfElements() {
    return totalNodes(root);
}