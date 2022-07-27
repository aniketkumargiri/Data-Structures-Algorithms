// Diameter of Binary Tree using extra variable --> O(N)
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

int diameterFast(Node *root, int *height)
{
    if (!root)
    {
        *height = 0;
        return 0;
    }

    int lHeight = 0;
    int rHeight = 0;
    int lDiameter = diameterFast(root->left, &lHeight);
    int rDiameter = diameterFast(root->right, &rHeight);

    int currDiameter = lHeight + rHeight + 1;
    *height = max(lHeight, rHeight) + 1;

    return max(currDiameter, max(lDiameter, rDiameter));
}

int diameter(Node *root)
{
    int height = 0;
    return diameterFast(root, &height);
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

    // diameter of Binary Tree
    // longest path between any two nodes
    cout << "diameter: " << diameter(root) << endl;

    return 0;
}