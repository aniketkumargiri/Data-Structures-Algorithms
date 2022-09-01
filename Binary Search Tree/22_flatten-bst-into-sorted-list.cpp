// Flatten a Binary Search Tree into a Sorted List
#include <bits/stdc++.h>
using namespace std;

// Node of the binary tree
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

// Function to print flattened binary Tree
void print(Node* parent) {
    Node* curr = parent;
    while (curr != NULL) cout << curr->data << " ", curr = curr->right;
}

// Function to perform in-order traversal recursively
void inorder(Node* root, vector<int>& in) {
    if (!root) {
        return;
    }

    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}

// Function to flatten binary tree using level order traversal
Node* flatten(Node* root) {
    vector<int> in;
    // store inorder
    inorder(root, in);
    int n = in.size();

    Node* newNode = new Node(in[0]);
    Node* cur = newNode;

    // 2nd step
    for (int i = 1; i < n; i++) {
        Node* tmp = new Node(in[i]);
        cur->left = NULL;
        cur->right = tmp;
        cur = tmp;
    }

    // step 3
    cur->left = NULL;
    cur->right = NULL;
    return newNode;
}

// Driver code
int main() {
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(7);

    // Calling required function
    print(flatten(root));

    return 0;
}
