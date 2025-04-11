#include<iostream>
using namespace std;
struct Node{
    int value;
    Node* left;
    Node* right;
};
struct Tree {
    Node* root;
    Tree() {
        root = nullptr;
    }
};
void insertNode(int v,Tree *t) {
    if (t->root == nullptr) {
        t->root = new Node;
        t->root->value = v;
        t->root->left = nullptr;
        t->root->right = nullptr;
    } else {
        Node* current = t->root;
        Node* parent = nullptr;
        while (current != nullptr) {
            parent = current;
            if (v < current->value) {
                current = current->left;
            } else {
                current = current->right;
            }
        }
        Node* newNode = new Node;
        newNode->value = v;
        newNode->left = nullptr;
        newNode->right = nullptr;

        if (v < parent->value) {
            parent->left = newNode;
        } else {
            parent->right = newNode;
        }
    }
}
void printTree(Node* node) {
    if (node != nullptr) {
        printTree(node->left);
        cout << node->value << " ";
        cout << "\n .\n";
        printTree(node->right);
    }
}
int main() {
    int a[] = {-10,-15,-2,-12,5, 2,0,6,8};
    Tree t = Tree();
    for (int i = 0; i < sizeof(a)/sizeof(a[0]); i++) {
        insertNode(a[i], &t);
    }
    cout << "Binary Search Tree: ";
    printTree(t.root);

    return 0;
}