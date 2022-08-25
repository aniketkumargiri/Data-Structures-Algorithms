// kth Largest in BST
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

// inorder traversal by maintaining the count
int solve(Node *root, int &i, int k) {
    if (!root) {
        return -1;
    }

    // right
    int right = solve(root->right, i, k);
    if (right != -1) {
        return right;
    }
    i++;
    // node
    if (i == k) {
        return root->data;
    }
    // left
    return solve(root->left, i, k);
}

int kthLargest(Node *root, int k) {
    int idx = 0;
    return solve(root, idx, k);
    return idx;
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

    int k;
    cin >> k;

    // kth largest element
    int kthLarge = kthLargest(root, k);
    if (kthLarge == -1) {
        cout << "Invalid input\n";
    } else {
        cout << "kth Largest element is " << kthLarge << endl;
    }

    return 0;
}
