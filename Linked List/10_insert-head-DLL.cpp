// Doubly Linked List: insert at the head position
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

void insertAtHead(Node *&head, int d)
{
    Node *temp = new Node(d);
    temp->next = head;
    head->prev = temp;
    head = temp;
}

// gives length of Linked List
int getLength(Node *head)
{
    int len = 0;
    Node *temp = head;

    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }

    return len;
}

// traversing a linked list
void print(Node *head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    // created a new node
    Node *node1 = new Node(10);
    // cout << node1->data << endl;
    // cout << node1->next << endl;
    // cout << node1->prev << endl;

    // head pointed to node1
    Node *head = node1;
    Node *tail = node1;
    print(head);

    // length of doubly linked list
    cout << getLength(head) << endl;

    insertAtHead(head, 11);
    print(head);

    insertAtHead(head, 13);
    print(head);

    insertAtHead(head, 8);
    print(head);

    return 0;
}