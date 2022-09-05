// Bottom View of Binary Tree
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

vector<int> bottomView(Node *root)
{
    vector<int> ans;
    if (!root)
    {
        return ans;
    }

    // mapping of horizontal distance ->with-> node's data
    map<int, int> bottomNode;
    // pair of node ->with-> horizontal distance
    queue<pair<Node *, int>> q;

    q.push(make_pair(root, 0));
    while (!q.empty())
    {
        pair<Node *, int> temp = q.front();
        q.pop();

        Node *frontNode = temp.first;
        int hd = temp.second;

        bottomNode[hd] = frontNode->data;

        if (frontNode->left)
        {
            q.push(make_pair(frontNode->left, hd - 1));
        }
        if (frontNode->right)
        {
            q.push(make_pair(frontNode->right, hd + 1));
        }
    }

    for (auto i : bottomNode)
    {
        ans.push_back(i.second);
    }

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

    // bottom View of Binary Tree
    vector<int> ans = bottomView(root);
    for (auto i : ans)
    {
        cout << i << " ";
    }

    return 0;
}