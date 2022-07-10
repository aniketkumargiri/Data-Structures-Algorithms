// Doubly Linked List Creation & constructor
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *prev; // address to previous node
    Node *next; // address to next node

    // constructor
    Node(int d)
    {
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }
};

int main()
{
    // created a new node
    Node *node1 = new Node(10);
    cout << node1->data << endl;
    cout << node1->next << endl;
    cout << node1->prev << endl;

    return 0;
}