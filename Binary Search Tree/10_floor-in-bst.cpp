// Floor(greatest value smaller than equal to key) in a BST
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

int floorBST(Node *root, int key) {
    int floor = -1;
    while (root) {
        if (root->data == key) {
            floor = root->data;
            return floor;
        }
        if (key > root->data) {
            floor = root->data;
            root = root->right;
        } else {
            root = root->left;
        }
    }

    return floor;
}

int main() {
    Node *root = NULL;
    root = new Node(10);

    root->left = new Node(5);
    root->left->left = new Node(3);
    root->left->left->left = new Node(2);
    root->left->left->right = new Node(4);
    root->left->right = new Node(6);
    root->left->right->right = new Node(9);

    root->right = new Node(13);
    root->right->left = new Node(11);
    root->right->right = new Node(14);

    int key;
    cin >> key;

    // floor value in BST
    int floor = floorBST(root, key);

    if (floor != -1) {
        cout << floor << endl;
    } else {
        cout << "-1\n";
    }

    return 0;
}