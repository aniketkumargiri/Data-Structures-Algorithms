// Iterative Inorder traversal
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

void iterativeInorder(Node *root)
{

    stack<Node *> st;
    Node *temp = root;

    while (true)
    {
        if (temp != NULL)
        {
            st.push(temp);
            temp = temp->left;
        }
        else
        {
            if (st.empty())
            {
                break;
            }
                temp = st.top();
                st.pop();
                cout << temp->data << " ";
                temp = temp->right;
        }
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

    // iterative inorder
    iterativeInorder(root);

    return 0;
}