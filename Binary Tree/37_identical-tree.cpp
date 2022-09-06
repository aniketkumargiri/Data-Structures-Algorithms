// Identical Tree
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

bool isIdentical(Node *root1, Node *root2)
{
    if (!root1 && !root2)
    {
        return true;
    }
    if (!root1 && root2)
    {
        return false;
    }
    if (root1 && !root2)
    {
        return false;
    }
    if (root1->data != root2->data)
    {
        return false;
    }

    bool left = isIdentical(root1->left, root2->left);
    bool right = isIdentical(root1->right, root2->right);
    bool value = (root1->data == root2->data);

    if (left && right && value)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    struct Node *root1 = NULL;
    root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->left = new Node(4);
    root1->left->right = new Node(5);
    // root1->right->left = new Node(6);
    // root1->right->right = new Node(7);

    struct Node *root2 = NULL;
    root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(3);
    root2->left->left = new Node(4);
    root2->left->right = new Node(5);

    // Are both tree identical
    if (isIdentical(root1, root2))
    {
        cout << "Both trees are identical\n";
    }
    else
    {
        cout << "Both trees are not identical\n";
    }

    return 0;
}