// Height balanced Binary Tree using extra variable as reference --> O(N)
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


bool isBalancedFast(Node *root, int *height)
{
    if (!root)
    {
        return true;
    }

    int lh = 0;
    int rh = 0;
    if (isBalancedFast(root->left, &lh) == false)
    {
        return false;
    }
    if (isBalancedFast(root->right, &rh) == false)
    {
        return false;
    }

    *height = max(lh, rh) + 1;
    if (abs(lh - rh) <= 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isBalanced(Node *root)
{
    int height = 0;
    return isBalancedFast(root, &height);
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
