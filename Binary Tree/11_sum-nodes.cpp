// Sum of Nodes
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

int sumNodes(Node *root)
{
    if (!root)
    {
        return 0;
    }

    int left = sumNodes(root->left);
    int right = sumNodes(root->right);

    int ans = left + right + root->data;
    return ans;
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

    // sum of nodes
    cout << "sum: " << sumNodes(root) << endl;

    return 0;
}