// Count leaf Nodes
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

void inorder(struct Node *root, int &cnt)
{
    if (!root)
    {
        return;
    }

    inorder(root->left, cnt);
    if (root->left == NULL && root->right == NULL)
    {
        cnt++;
    }
    inorder(root->right, cnt);
}

int countLeafNodes(Node *root)
{
    int cnt = 0;
    inorder(root, cnt);
    return cnt;
}

int main()
{
    struct Node *root = NULL;
    root = new Node(20);
    root->left = new Node(10);
    root->right = new Node(35);
    root->left->left = new Node(5);
    root->left->right = new Node(15);
    root->left->right->left = new Node(13);
    root->right->left = new Node(30);
    root->right->right = new Node(42);


    // count leafs
    cout << "No. of Leaf Nodes in the tree is: " << countLeafNodes(root) << endl;

    return 0;
}