// Vertical Traversal
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

vector<int> verticalOrderTraversal(Node *root) {
    vector<int> ans;
    if (!root) {
        return ans;
    }

    // mapping of horizontal distance ->with-> levelwise nodes(mapping of levels
    // ->with-> nodes)
    map<int, map<int, vector<int>>> nodes;
    // pair of nodes, pair of horizontal distance with level
    queue<pair<Node *, pair<int, int>>> q;

    q.push(make_pair(root, make_pair(0, 0)));
    while (!q.empty()) {
        pair<Node *, pair<int, int>> temp = q.front();
        q.pop();

        Node *frontNode = temp.first;
        int hd = temp.second.first;
        int level = temp.second.second;

        nodes[hd][level].push_back(frontNode->data);

        if (frontNode->left) {
            q.push(make_pair(frontNode->left, make_pair(hd - 1, level + 1)));
        }
        if (frontNode->right) {
            q.push(make_pair(frontNode->right, make_pair(hd + 1, level + 1)));
        }
    }

    for (auto i : nodes) {
        for (auto j : i.second) {
            for (auto k : j.second) {
                ans.push_back(k);
            }
        }
    }

    return ans;
}

int main() {
    struct Node *root = NULL;
    root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->left->right = new Node(8);
    root->right->right->right = new Node(9);

    // vertical order traversal
    vector<int> ans = verticalOrderTraversal(root);
    for (auto i : ans) {
        cout << i << " ";
    }

    return 0;
}