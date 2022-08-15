// Insert Into BST recursively
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

// BST: root->left < root < root->right
Node *insertIntoBST(Node *root, int val) {
    if (root == NULL)  // base case
    {
        root = new Node(val);
        return root;
    }

    if (val > root->data)  // insert into right part
    {
        root->right = insertIntoBST(root->right, val);
    } else  // insert into left part
    {
        root->left = insertIntoBST(root->left, val);
    }

    return root;
}

void takeinput(Node *&root) {
    int val;
    cin >> val;

    while (val != -1) {
        root = insertIntoBST(root, val);
        cin >> val;
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
    cout << "Enter data to create BST" << endl;
    takeinput(root);  // 10 8 21 7 27 5 4 3 -1

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
