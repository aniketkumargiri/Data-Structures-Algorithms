// Convert a Normal Binary Search Tree into a balanced BST
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

Node* insert(struct Node* node, int key) {
    if (node == NULL) return new Node(key);
    if (key < node->data)
        node->left = insert(node->left, key);
    else if (key > node->data)
        node->right = insert(node->right, key);
    return node;
}

void preOrder(Node* node) {
    if (node == NULL) return;
    printf("%d ", node->data);
    preOrder(node->left);
    preOrder(node->right);
}

int height(struct Node* node) {
    if (node == NULL)
        return 0;
    else {
        int lDepth = height(node->left);
        int rDepth = height(node->right);
        if (lDepth > rDepth)
            return (lDepth + 1);
        else
            return (rDepth + 1);
    }
    return 2;
}
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {
            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {
            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

Node* buildBalancedTree(Node* root);

int main() {
    int t;
    cin >> t;
    getchar();
    while (t--) {
        struct Node* root = NULL;
        int n, temp;
        string tree;
        getline(cin, tree);
        root = buildTree(tree);
        // cout<<height(root)<<endl;
        root = buildBalancedTree(root);
        cout << height(root) << endl;
    }
    return 0;
}

// } Driver Code Ends

/*Structure of the Node of the BST is as
struct Node
{
        int data;
        Node* left, *right;
};
*/

void inorder(Node* root, vector<int>& in) {
    if (!root) {
        return;
    }

    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}

Node* inorderToBST(int start, int end, vector<int> in) {
    // base case
    if (start > end) {
        return NULL;
    }

    int mid = start + (end - start) / 2;
    Node* root = new Node(in[mid]);
    if (start == end) {
        return root;
    }

    root->left = inorderToBST(start, mid - 1, in);
    root->right = inorderToBST(mid + 1, end, in);
    return root;
}
// Your are required to complete this function
// function should return root of the modified BST
Node* buildBalancedTree(Node* root) {
    // Code here
    vector<int> in;
    inorder(root, in);
    return inorderToBST(0, in.size() - 1, in);
}
