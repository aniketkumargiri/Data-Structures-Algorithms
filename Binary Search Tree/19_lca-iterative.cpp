// Lowest Common Ancestors in a BST iteratively
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

Node *LCA(Node *root, Node *node1, Node *node2)  // iterative
{
    while (root) {
        if (root->data < node1->data && root->data < node2->data) {
            root = root->right;
        } else if (root->data > node1->data && root->data > node2->data) {
            root = root->left;
        } else {
            return root;
        }
    }
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

    // lowest common ancestor
    Node *lca = LCA(root, root->right->left, root->right->right->right);
    cout << "LCA in the BST for given nodes is: " << lca->data << endl;

    return 0;
}
