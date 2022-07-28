// Height balanced Binary Tree using recursion(DFS) --> O(N)
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

int dfsHeight(Node *root)
{
    if (!root)
    {
        return 0;
    }

    int leftHeight = dfsHeight(root->left);
    if (leftHeight == -1)
    {
        return -1;
    }

    int rightHeight = dfsHeight(root->right);
    if (rightHeight == -1)
    {
        return -1;
    }

    if (abs(leftHeight - rightHeight) > 1)
    {
        return -1;
    }

    return max(leftHeight, rightHeight) + 1;
}

bool isBalanced(Node *root)
{
    return dfsHeight(root) != -1;
}

int main()
{
    struct Node *root = NULL;
    root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    if (isBalanced(root))
    {
        cout << "Balanced Tree\n";
    }
    else
    {
        cout << "Unbalanced Tree\n";
    }

    return 0;
}
