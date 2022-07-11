// Circular Linked List Creation & constructor
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // constrcutor
    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }
};

int main()
{

    Node *tail = NULL;
    Node *newNode = new Node(5);
    tail = newNode;
    newNode->next = newNode;

    cout << tail->data << endl;
    cout << tail->next << endl;

    return 0;
}