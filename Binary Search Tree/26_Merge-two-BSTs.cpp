// Merge two Binary Search Trees
#include <bits/stdc++.h>
using namespace std;

// /*************************************************************
// Following is the Binary Tree node structure:
template <typename T>
class TreeNode {
   public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~TreeNode() {
        if (left) {
            delete left;
        }

        if (right) {
            delete right;
        }
    }
};
// *************************************************************/
// convert binary search tree to a sorted doubly linked list
void convertIntoSortedDLL(TreeNode<int> *root, TreeNode<int> *&head) {
    // base case
    if (!root) {
        return;
    }

    convertIntoSortedDLL(root->right, head);
    root->right = head;
    if (head) {
        head->left = root;
    }

    head = root;
    convertIntoSortedDLL(root->left, head);
}

// merge two sorted linked list into a single list
TreeNode<int> *mergedLinkedList(TreeNode<int> *head1, TreeNode<int> *head2) {
    TreeNode<int> *head = NULL;
    TreeNode<int> *tail = NULL;

    while (head1 && head2) {
        if (head1->data < head2->data) {
            if (head == NULL) {
                head = head1;
                tail = head1;
                head1 = head1->right;
            } else {
                tail->right = head1;
                head1->left = tail;
                tail = head1;
                head1 = head1->right;
            }
        } else {
            if (head == NULL) {
                head = head2;
                tail = head2;
                head2 = head2->right;
            } else {
                tail->right = head2;
                head2->left = tail;
                tail = head2;
                head2 = head2->right;
            }
        }
    }

    while (head1) {
        tail->right = head1;
        head1->left = tail;
        tail = head1;
        head1 = head1->right;
    }
    while (head2) {
        tail->right = head2;
        head2->left = tail;
        tail = head2;
        head2 = head2->right;
    }
    return head;
}

int countNodes(TreeNode<int> *head) {
    int cnt = 0;
    TreeNode<int> *temp = head;
    while (temp) {
        cnt++;
        temp = temp->right;
    }
    return cnt;
}

// create BST from sorted Linked List
TreeNode<int> *sortedLLToBST(TreeNode<int> *&head, int n) {
    // base case
    if (n <= 0 || !head) {
        return NULL;
    }

    TreeNode<int> *left = sortedLLToBST(head, n / 2);
    TreeNode<int> *root = head;
    root->left = left;

    head = head->right;
    root->right = sortedLLToBST(head, n - n / 2 - 1);
    return root;
}

TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2) {
    // Write your code here.

    // convert a BST into sorted Doubly Linked List in-place
    TreeNode<int> *head1 = NULL;
    convertIntoSortedDLL(root1, head1);
    head1->left = NULL;

    TreeNode<int> *head2 = NULL;
    convertIntoSortedDLL(root2, head2);
    head2->left = NULL;

    // Merge two sorted Linked List
    TreeNode<int> *head = mergedLinkedList(head1, head2);

    // convert sorted Linked List in BST
    return sortedLLToBST(head, countNodes(head));
}

int main() { return 0; }