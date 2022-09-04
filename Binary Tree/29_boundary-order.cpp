// Boundary traversal
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void traverseLeft(Node *root, vector<int> &ans) {
    if (!root)  // base case
    {
        return;
    }

    if (root->left == NULL &&
        root->right == NULL)  // ignore leaf nodes in left part for now
    {
        return;
    }

    ans.push_back(root->data);
    if (root->left) {
        traverseLeft(root->left, ans);
    } else {
        traverseLeft(root->right, ans);
    }
}

void traverseLeaf(Node *root, vector<int> &ans) {
    if (!root)  // base case
    {
        return;
    }

    if (!root->left && !root->right) {
        ans.push_back(root->data);
    }

    traverseLeaf(root->left, ans);
    traverseLeaf(root->right, ans);
}

void traverseRight(Node *root, vector<int> &ans) {
    if (!root)  // base case
    {
        return;
    }

    if (root->left == NULL &&
        root->right == NULL)  // ignore right nodes in left part for now
    {
        return;
    }

    if (root->right) {
        traverseRight(root->right, ans);
    } else {
        traverseRight(root->left, ans);
    }
    ans.push_back(root->data);
}

vector<int> boundaryOrderTraversal(Node *root) {
    vector<int> ans;
    if (root == NULL) {
        return ans;
    }

    ans.push_back(root->data);

    // left part print/store
    traverseLeft(root->left, ans);

    // traverse leaf nodes

    // left subtree
    traverseLeaf(root->left, ans);
    // right subtree
    traverseLeaf(root->right, ans);

    // right part print/store
    traverseRight(root->right, ans);

    return ans;
}

int main() {
    struct Node *root = NULL;
    root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->left->left = new Node(8);
    root->left->left->right = new Node(9);

    // boundary order traversal
    vector<int> ans = boundaryOrderTraversal(root);
    for (auto i : ans) {
        cout << i << " ";
    }

    return 0;
}