// Circular Linked List print function
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

void print(Node *tail)
{

    Node *temp = tail;

    // empty list
    if (tail == NULL)
    {
        cout << "List is Empty " << endl;
        return;
    }

    do
    {
        cout << tail->data << " ";
        tail = tail->next;
    } while (tail != temp);

    cout << endl;
}

int main()
{

    Node *tail = NULL;
    Node *newNode = new Node(5);
    tail = newNode;
    newNode->next = newNode;

    // cout << tail->data << endl;
    // cout << tail->next << endl;

    print(tail);

    return 0;
}