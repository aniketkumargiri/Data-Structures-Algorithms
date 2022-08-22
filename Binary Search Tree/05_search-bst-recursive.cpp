// Search in a BST recursively
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

bool searchBST(Node *root, int val)  // recursive
{
    if (!root) {
        return false;
    }
    if (root->data == val) {
        return true;
    }

    if (val > root->data) {
        return searchBST(root->right, val);
    } else {
        return searchBST(root->left, val);
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

    int val;
    cin >> val;
    bool search = searchBST(root, val);

    if (search == true) {
        cout << val << " Found" << endl;  // must be equal to val
    } else {
        cout << val << " Not Found (-1)" << endl;
    }

    return 0;
}