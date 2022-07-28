// Height balanced Binary Tree using pairs --> O(N)
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


pair<bool, int> isBalancedFast(Node *root)
{
    if (!root)
    {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }

    pair<bool, int> left = isBalancedFast(root->left);
    pair<bool, int> right = isBalancedFast(root->right);

    bool leftAns = left.first;
    bool rightAns = right.first;
    bool diff = abs(left.second - right.second) <= 1;

    pair<bool, int> ans;
    ans.second = max(left.second, right.second) + 1;
    if (leftAns && rightAns && diff)
    {
        ans.first = true;
    }
    else
    {
        ans.second = false;
    }

    return ans;
}

bool isBalanced(Node *root)
{
    return isBalancedFast(root).first;
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

    if (isBalanced(root))
    {
        cout << "Balanced Tree\n";
    }
    else
    {
        cout << "Unbalanced Tree\n";
    }

    return 0;
}
