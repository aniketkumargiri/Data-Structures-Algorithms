// Inorder, Preorder, Postorder & level Order Traversal in BST
#include <bits/stdc++.h>
using namespace std;

class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void inorder(Node *root) {
    if (!root) {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Node *root) {
    if (!root) {
        return;
    }

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node *root) {
    if (!root) {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

void levelOrder(Node *root) {
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()) {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL)  // old level completed
        {
            cout << endl;
            if (!q.empty())  // queue still have some child
            {
                q.push(NULL);
            }
        } else {
            cout << temp->data << " ";
            if (temp->left) {
                q.push(temp->left);
            }
            if (temp->right) {
                q.push(temp->right);
            }
        }
    }
}

int main() {
    // BST: root->left < root < root->right
    Node *root = NULL;
    root = new Node(5);
    root->left = new Node(3);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right = new Node(7);
    root->right->left = new Node(6);
    root->right->right = new Node(8);

    // inorder traversal of BST --> increasing order always
    cout << "Inorder traversal of BST:\n";
    inorder(root);

    // preorder traversal
    cout << "\nPreorder traversal of BST:\n";
    preorder(root);

    // postorder traversal
    cout << "\nPostorder traversal of BST:\n";
    postorder(root);

    // level order traversal
    cout << "\nLevel order traversal of BST:\n";
    levelOrder(root);

    return 0;
}