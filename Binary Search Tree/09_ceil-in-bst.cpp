// Ceil(lowest value greater than equal to key) in a BST
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

int ceilBST(Node *root, int key) {
    int ceil = -1;
    while (root) {
        if (root->data == key) {
            ceil = root->data;
            return ceil;
        }
        if (key > root->data) {
            root = root->right;
        } else {
            ceil = root->data;
            root = root->left;
        }
    }

    return ceil;
}

int main() {
    Node *root = NULL;
    root = new Node(10);

    root->left = new Node(5);
    root->left->left = new Node(3);
    root->left->left->left = new Node(2);
    root->left->left->right = new Node(4);
    root->left->right = new Node(6);
    root->left->right->right = new Node(9);

    root->right = new Node(13);
    root->right->left = new Node(11);
    root->right->right = new Node(14);

    int key;
    cin >> key;

    // ceil value in BST
    int ceil = ceilBST(root, key);

    if (ceil != -1) {
        cout << ceil << endl;
    } else {
        cout << "-1\n";
    }

    return 0;
}