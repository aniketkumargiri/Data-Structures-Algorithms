// Inorder successor in a BST
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

int successor(Node *root, int val) {
    int succ = -1;
    Node *temp = root;

    // findkey
    while (temp->data != val) {
        if (temp->data > val) {
            succ = temp->data;
            temp = temp->left;
        } else {
            temp = temp->right;
        }
    }

    // successor
    Node *rightTree = temp->right;
    while (rightTree != NULL) {
        succ = rightTree->data;
        rightTree = rightTree->left;
    }
    return succ;
}

int main() {
    Node *root = NULL;
    root = new Node(21);

    root->left = new Node(10);
    root->left->left = new Node(5);
    root->left->right = new Node(15);

    root->right = new Node(50);
    root->right->left = new Node(40);
    root->right->right = new Node(60);
    root->right->right->left = new Node(55);
    root->right->right->right = new Node(70);

    int key;
    cin >> key;

    // inorder successor
    int succ = successor(root, key);
    cout << "Inorder successor of " << key << " is: " << succ << endl;

    return 0;
}
