// Create Binary Search Tree(BST)
#include <bits/stdc++.h>
using namespace std;

class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

int main() {
    // BST: root->left < root < root->right
    Node *root = NULL;
    root = new Node(5);
    root->left = new Node(3);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right = new Node(7);
    root->right->left = new Node(6);
    root->right->right = new Node(8);

    cout << root->data << " ";
    cout << root->left->data << " ";
    cout << root->left->left->data << " ";
    cout << root->left->right->data << " ";
    cout << root->right->data << " ";
    cout << root->right->left->data << " ";
    cout << root->right->right->data << endl;

    return 0;
}