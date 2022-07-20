// Reverse Level Order Traversal
#include <bits/stdc++.h>
using namespace std;

struct Node
{
public:
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) // constructor
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void reverseLevelOrder(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    vector<vector<int>> ans;

    while (!q.empty())
    {
        vector<int> level;
        int n = q.size();

        for (int i = 0; i < n; i++)
        {
            Node *temp = q.front();
            q.pop();

            if (temp == NULL) // purana level complete ho chuka hai
            {
                cout << endl;
                if (!q.empty()) // queue still have some element
                {
                    q.push(NULL);
                }
            }
            else
            {
                level.push_back(temp->data);
                if (temp->left)
                {
                    q.push(temp->left);
                }
                if (temp->right)
                {
                    q.push(temp->right);
                }
            }
        }
        ans.push_back(level);
    }

    reverse(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}

Node *buildTree(Node *root)
{
    cout << "Enter the data: " << endl;
    int data;
    cin >> data;

    root = new Node(data);
    if (data == -1)
    {
        return NULL;
    }

    cout << "Enter data for inserting in left: " << endl;
    root->left = buildTree(root->left);

    cout << "Enter data for inserting in right: " << endl;
    root->right = buildTree(root->left);
}

int main()
{
    struct Node *root = NULL;

    // build tree
    root = buildTree(root); // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    // reverse level order
    reverseLevelOrder(root);

    return 0;
}