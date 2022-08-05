// Maximum width of a Binary Tree
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

int widthOfBinaryTree(Node *root)
{
    if (!root)
    {
        return 0;
    }

    int ans = 0;
    queue<pair<Node *, int>> q;
    q.push({root, 0});

    while (!q.empty())
    {
        int size = q.size();
        int min_idx = q.front().second;
        int first;
        int last;

        for (int i = 0; i < size; i++)
        {
            int cur_idx = q.front().second - min_idx;
            Node *node = q.front().first;
            q.pop();

            if (i == 0)
                first = cur_idx;
            if (i == size - 1)
                last = cur_idx;

            if (node->left)
            {
                q.push({node->left, cur_idx * 2 + 1});
            }
            if (node->right)
            {
                q.push({node->right, cur_idx * 2 + 2});
            }
        }

        ans = max(ans, last - first + 1);
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
    root->left->left->left = new Node(7);
    root->right->right = new Node(6);
    // root->right->right->right = new Node(5);

    // Maximum width of a Binary Tree
    // maximum distance between first and last node of any particular level
    cout << "Maximum width of the binary tree is: " << widthOfBinaryTree(root) << endl;

    return 0;
}