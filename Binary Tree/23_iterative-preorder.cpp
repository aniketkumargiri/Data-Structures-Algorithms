// Iterative Preorder traversal
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

void iterativePreorder(Node *root)
{
    if (!root)
    {
        return;
    }

    stack<Node *> st;
    st.push(root);

    while (!st.empty())
    {
        Node *temp = st.top();
        st.pop();

        cout << temp->data << " ";
        if (temp->right)
        {
            st.push(temp->right);
        }
        if (temp->left)
        {
            st.push(temp->left);
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

    // iterative preorder
    iterativePreorder(root);

    return 0;
}