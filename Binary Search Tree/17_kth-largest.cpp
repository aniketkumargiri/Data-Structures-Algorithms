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
Node *kthLargest(Node *root, int &k) {
    if (!root) {
        return NULL;
    }

    Node *right = kthLargest(root->right, k);
    if (right) {
        return right;
    }
    k--;
    if (k == 0) {
        return root;
    }
    return kthLargest(root->left, k);
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

    // kth largest element
    Node *kthLarge = kthLargest(root, k);
    if (kthLarge == NULL) {
        cout << "Invalid input\n";
    } else {
        cout << "kth Largest element is " << kthLarge->data << endl;
    }

    return 0;
}
