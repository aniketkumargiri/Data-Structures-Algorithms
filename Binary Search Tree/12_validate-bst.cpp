// Validate a BST
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

bool isBST(Node *root, long long mini, long long maxi) {
    if (!root) {
        return true;
    }

    if (root->data >= mini && root->data <= maxi) {
        bool left = isBST(root->left, mini, root->data);
        bool right = isBST(root->right, root->data, maxi);
        return left && right;
    } else {
        return false;
    }
}

bool isValidBST(Node *root) { return isBST(root, LLONG_MIN, LLONG_MAX); }

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

    // validate BST
    if (isValidBST(root)) {
        cout << "Valid BST\n";
    } else {
        cout << "Invalid BST\n";
    }

    return 0;
}
