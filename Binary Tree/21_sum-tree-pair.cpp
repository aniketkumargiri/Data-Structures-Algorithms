// Sum Tree using pairs --> O(N)
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

pair<bool, int> isSumTreeFast(Node *root)
{
    if (!root)
    {
        pair<bool, int> p = {true, 0};
        return p;
    }

    if (!root->left && !root->right)
    {
        pair<bool, int> p = {true, root->data};
        return p;
    }
    pair<bool, int> leftAns = isSumTreeFast(root->left);
    pair<bool, int> rightAns = isSumTreeFast(root->right);

    bool isLeftSumTree = leftAns.first;
    bool isRightSumTree = rightAns.first;

    int leftSum = leftAns.second;
    int rightSum = rightAns.second;

    bool condn = (root->data == leftSum + rightSum);

    pair<bool, int> ans;

    if (isLeftSumTree && isLeftSumTree && condn)
    {
        ans.first = true;
        ans.second = root->data + leftSum + rightSum;
        // ans.second = 2 * root->data;
    }
    else
    {
        ans.first = false;
    }

    return ans;
}

bool isSum(Node *root)
{
    return isSumTreeFast(root).first;
}

int main()
{
    struct Node *root = NULL;
    root = new Node(26);
    
    root->left = new Node(10);
    root->left->left = new Node(4);
    root->left->right = new Node(6);

    root->right = new Node(3);
    root->right->left = new Node(3);

    if (isSum(root))
    {
        cout << "Tree is a sum tree\n";
    }
    else
    {
        cout << "Tree is not a sum tree\n";
    }

    return 0;
}