// Iterative Postorder traversal using 2 stacks
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

void iterativePostorder(Node *root)
{
    stack<Node *> st1, st2;
    st1.push(root);

    while (!st1.empty())
    {
        Node *temp = st1.top();
        st1.pop();
        st2.push(temp);

        if (temp->left)
        {
            st1.push(temp->left);
        }
        if (temp->right)
        {
            st1.push(temp->right);
        }
    }

    while (!st2.empty())
    {
        cout << st2.top()->data << " ";
        st2.pop();
    }
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

    // iterative Postorder
    iterativePostorder(root);

    return 0;
}