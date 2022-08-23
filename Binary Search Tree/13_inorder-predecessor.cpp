// Inorder Predecessor in a BST
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

int predecessor(Node *root, int val) {
    int pred = -1;
    Node *temp = root;

    // findkey
    while (temp->data != val) {
        if (temp->data > val) {
            temp = temp->left;
        } else {
            pred = temp->data;
            temp = temp->right;
        }
    }

    // predecessor
    Node *leftTree = temp->left;
    while (leftTree != NULL) {
        pred = leftTree->data;
        leftTree = leftTree->right;
    }
    return pred;
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

    // inorder predecessor
    int pred = predecessor(root, key);
    cout << "Inorder predecessor of " << key << " is: " << pred << endl;

    return 0;
}
