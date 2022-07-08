// Linked List Creation & constructor
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next; // address to next node

    // constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

int main()
{
    // created a new node
    Node *node1 = new Node(10);
    cout << node1->data << endl;
    cout << node1->next << endl;

    return 0;
}