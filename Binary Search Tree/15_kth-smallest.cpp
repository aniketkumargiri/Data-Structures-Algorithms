// kth Smallest in BST
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

Node *insertBST(Node *root, int val) {
    if (!root) {
        return new Node(val);
    }

    if (val < root->data) {
        root->left = insertBST(root->left, val);
    } else {
        root->right = insertBST(root->right, val);
    }
    return root;
}

// morris traversal
Node *kthSmallest(Node *root, int &k) {
    if (!root) {
        return NULL;
    }

    Node *left = kthSmallest(root->left, k);
    if (left != NULL) {
        return left;
    }
    k--;
    if (k == 0) {
        return root;
    }
    return kthSmallest(root->right, k);
}

int main() {
    int arr[] = {10, 40, 45, 20, 25, 30, 50};
    int n = sizeof(arr) / sizeof(arr[0]);

    Node *root = NULL;
    for (int i = 0; i < n; i++) {
        root = insertBST(root, arr[i]);
    }

    int k;
    cin >> k;

    // kth smallest element
    Node *kthSmall = kthSmallest(root, k);
    if (kthSmall == NULL) {
        cout << "Invalid input\n";
    } else {
        cout << "kth smallest element is " << kthSmall->data << endl;
    }

    return 0;
}