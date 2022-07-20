// Binary Tree Level Order Traversal
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

void levelOrder(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL) // purana level complete ho chuka hai
        {
            cout << endl;
            if (!q.empty()) // queue still have some element
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

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

    // levelOrder
    levelOrder(root);

    return 0;
}