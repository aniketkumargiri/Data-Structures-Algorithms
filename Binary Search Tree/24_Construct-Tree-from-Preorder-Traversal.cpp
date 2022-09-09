// Construct Binary Search from Preorder Traversal
#include <bits/stdc++.h>
using namespace std;

// Following is the class structure of BinaryTreeNode class for referance:
template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~BinaryTreeNode() {
        if (left) {
            delete left;
        }
        if (right) {
            delete right;
        }
    }
};

BinaryTreeNode<int> *solve(vector<int> &preorder, int mn, int mx, int &i) {
    if (i >= preorder.size()) {
        return NULL;
    }
    if (preorder[i] < mn || preorder[i] > mx) {
        return NULL;
    }

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(preorder[i++]);
    root->left = solve(preorder, mn, root->data, i);
    root->right = solve(preorder, root->data, mx, i);
    return root;
}

BinaryTreeNode<int> *preorderToBST(vector<int> &preOrder) {
    // Write your code here.
    int mn = INT_MIN;
    int mx = INT_MAX;
    int preIdx = 0;
    return solve(preOrder, INT_MIN, INT_MAX, preIdx);
}

int main() { return 0; }