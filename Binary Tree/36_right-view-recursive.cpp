// Right View of Binary Tree using recursion
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

void solve(Node *root, vector<int> &ans, int level)
{
    if (root == NULL)
    {
        return;
    }

    if (level == ans.size())
    {
        ans.push_back(root->data);
    }

    solve(root->right, ans, level + 1);
    solve(root->left, ans, level + 1);
}

vector<int> rightView(Node *root)
{
    vector<int> ans;
    solve(root, ans, 0);
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
    root->right->right->right = new Node(9);

    // Right View of Binary Tree
    
    vector<int> ans = rightView(root);
    for (auto i : ans)
    {
        cout << i << " ";
    }

    return 0;
}