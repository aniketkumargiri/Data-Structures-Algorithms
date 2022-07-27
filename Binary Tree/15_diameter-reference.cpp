// Diameter of Binary Tree using extra variable as reference --> O(N)
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

int height(Node *root, int &maxi)
{
    if (!root)
    {
        return 0;
    }

    int lheight = height(root->left, maxi);
    int rheight = height(root->right, maxi);
    maxi = max(maxi, 1 + lheight + rheight);

    return 1 + max(lheight, rheight);
}

int diameter(Node *root)
{
    int dia = 0;
    height(root, dia);
    return dia;
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