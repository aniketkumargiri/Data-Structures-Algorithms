// Build Binary Tree from Level Order Traversal
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

void buildFromLevelOrder(Node *&root)
{
    queue<Node *> q;
    cout << "Enter the data for root: " << endl;
    int data;
    cin >> data;

    root = new Node(data);
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        cout << "Enter data for inserting in left: " << temp->data << endl;
        int leftData;
        cin >> leftData;
        if (leftData != -1)
        {
            temp->left = new Node(leftData);
            q.push(temp->left);
        }

        cout << "Enter data for inserting in left: " << temp->data << endl;
        int rightData;
        cin >> rightData;
        if (rightData != -1)
        {
            temp->right = new Node(rightData);
            q.push(temp->right);
        }
    }
}

int main()
{
    struct Node *root = NULL;
    
    // build tree from level order traversal
    buildFromLevelOrder(root); // 1 3 7 11 5 17 -1 -1 -1 -1 -1 -1 -1

    // level order traversal
    levelOrder(root);

    return 0;
}