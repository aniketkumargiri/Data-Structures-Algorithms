// Maximum in a BST
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

Node *maxVal(Node *root) {
    Node *temp = root;
    while (temp->right) {
        temp = temp->right;
    }

    return temp;
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

    // maximum value in BST
    Node *maxval = maxVal(root);
    cout << "Maximum value in BST is: " << maxval->data << endl;

    return 0;
}
