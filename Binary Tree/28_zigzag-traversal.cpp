// Zig-Zag traversal
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

vector<vector<int>> zigZag(Node *root) {
    vector<vector<int>> ans;
    if (!root) {
        return ans;
    }

    queue<Node *> q;
    q.push(root);
    bool flag = true;

    while (!q.empty()) {
        int n = q.size();
        vector<int> level(n);

        for (int i = 0; i < n; i++)  // level process
        {
            Node *temp = q.front();
            q.pop();

            int idx = (flag) ? i : n - i - 1;  // index to insert
            level[idx] = temp->data;

            if (temp->left) {
                q.push(temp->left);
            }
            if (temp->right) {
                q.push(temp->right);
            }
        }

        flag = !flag;  // change direction
        ans.push_back(level);
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
    root->left->left->left = new Node(8);
    root->left->left->right = new Node(9);

    // Zig-Zag traversal
    vector<vector<int>> ans;
    ans = zigZag(root);
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}