// Print Root to Node Path --> O(N)
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

bool getPath(Node *root, vector<int> &ans, int val)
{
    if (!root)
    {
        return false;
    }

    ans.push_back(root->data);

    if (root->data == val)
    {
        return true;
    }

    bool left = getPath(root->left, ans, val);
    bool right = getPath(root->right, ans, val);

    if (left || right)
    {
        return true;
    }

    // node not found with the pushed value in the ans. So, pop it to go another path
    ans.pop_back();
    return false;
}

vector<int> path(Node *node, int val)
{
    vector<int> ans;
    if (node == NULL)
    {
        return ans;
    }

    getPath(node, ans, val);
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
    root->left->right->left = new Node(6);
    root->left->right->right = new Node(7);

    vector<int> ans;
    ans = path(root, 7);

    cout << "Printing the root to node path:\n";
    for (auto i : ans)
    {
        cout << i << " ";
    }

    return 0;
}
