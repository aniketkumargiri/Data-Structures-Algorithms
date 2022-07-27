// Diameter of Binary Tree using height --> O(N^2)
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

int height(Node *root)
{
    if (!root)
    {
        return 0;
    }

    return max(height(root->left), height(root->right)) + 1;
}

int diameter(Node *root)
{
    if (!root)
    {
        return 0;
    }

    int lHeight = height(root->left);
    int rHeight = height(root->right);
    int currDiameter = lHeight + rHeight + 1;

    int lDiameter = diameter(root->left);
    int rDiameter = diameter(root->right);

    return max(currDiameter, max(lDiameter, rDiameter));
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