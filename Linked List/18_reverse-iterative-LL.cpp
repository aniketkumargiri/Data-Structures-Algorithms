// Reverse a Linked List iteratively
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

Node *reverseListIterative(Node *&head)
{
    if (!head || !head->next)
    {
        return head;
    }

    Node *prev = NULL;
    Node *curr = head;

    while (curr != NULL)
    {
        Node *next = curr->next;
        curr->next = prev;

        // move prev and curr pointers forward
        prev = curr;
        curr = next;
    }

    return prev;
}

void print(Node *&head)
{

    if (head == NULL)
    {
        cout << "List is empty " << endl;
        return;
    }
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    // created a new node
    Node *node = new Node(3);

    // head pointed to node
    Node *head = node;

    head->next = new Node(5);
    head->next->next = new Node(7);
    head->next->next->next = new Node(9);

    // printing the linked list
    print(head);

    // reverse linked list iteratively
    head = reverseListIterative(head);
    
    // printing the reverse linked list
    print(head);

    return 0;
}