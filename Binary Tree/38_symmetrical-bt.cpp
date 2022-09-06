// Symmetrical Tree
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

bool symmetric(Node *left, Node *right)
{
    if (!left && !right)
    {
        return true;
    }
    if (!left && right)
    {
        return false;
    }
    if (left && !right)
    {
        return false;
    }
    if (left->data != right->data)
    {
        return false;
    }

    bool first = symmetric(left->left, right->right);
    bool second = symmetric(left->right, right->left);
    bool value = (left->data == right->data);

    if (first && second && value)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isSymmetric(Node *root)
{
    if (root == NULL)
    {
        return true;
    }

    return symmetric(root->left, root->right);
}

int main()
{
    struct Node *root = NULL;
    root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(4);
    root->right->right = new Node(3);

    // Are both tree symmetrical
    if (isSymmetric(root))
    {
        cout << "Both trees are symmetrical\n";
    }
    else
    {
        cout << "Both trees are not symmetrical\n";
    }

    return 0;
}