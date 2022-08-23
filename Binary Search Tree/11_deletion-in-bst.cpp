// Deletion in a BST
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

Node *minVal(Node *root) {
    Node *temp = root;
    while (temp->left) {
        temp = temp->left;
    }

    return temp;
}

Node *deleteFromBST(Node *root, int val) {
    if (!root)  // NULL
    {
        return root;
    }

    if (root->data == val) {
        if (!root->left && !root->right)  // 0 child
        {
            delete root;
            return NULL;
        }

        // 1 child
        if (root->left && !root->right)  // left child
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        if (!root->left && root->right)  // right child
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }

        if (root->left && root->right)  // 2 child
        {
            int mini =
                minVal(root->right)->data;  // minimum value from right subtree
            root->data =
                mini;  // store minimum value from right subtree in root node
            root->right = deleteFromBST(
                root->right,
                mini);  // dlete minimum value from right subtree recursively
            return root;
        }
    } else if (root->data > val)  // left part
    {
        root->left = deleteFromBST(root->left, val);
        return root;
    } else  // right part
    {
        root->right = deleteFromBST(root->right, val);
        return root;
    }
}

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
    Node *root = NULL;
    root = new Node(21);

    root->left = new Node(10);
    root->left->left = new Node(5);
    root->left->right = new Node(15);

    root->right = new Node(50);
    root->right->left = new Node(40);
    root->right->right = new Node(60);
    root->right->right->left = new Node(55);

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

    // deleteFromBST(root, 15); // 0 child
    // deleteFromBST(root, 60); // 1 child
    deleteFromBST(root, 21);  // 2 child
    cout << "\n****************************************\n\n";

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
