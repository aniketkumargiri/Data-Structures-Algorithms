// Binary Tree Inorder Traversal
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

Node *buildTree(Node *root)
{
    cout << "Enter the data: " << endl;
    int data;
    cin >> data;

    root = new Node(data);
    if (data == -1)
    {
        return NULL;
    }

    cout << "Enter data for inserting in left: " << endl;
    root->left = buildTree(root->left);

    cout << "Enter data for inserting in right: " << endl;
    root->right = buildTree(root->left);
}

void inorder(struct Node *root)
{
    if (!root)
    {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{
    struct Node *root = NULL;

    // build tree
    root = buildTree(root); // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    // inorder
    inorder(root);

    return 0;
}