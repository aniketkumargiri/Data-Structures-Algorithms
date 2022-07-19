// Binary Tree buildTree function
#include <bits/stdc++.h>
using namespace std;

struct Node
{
public:
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) // constructor
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

int main()
{
    struct Node *root = NULL;

    // build tree
    root = buildTree(root); // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    return 0;
}