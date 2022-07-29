// Reverse a Linked List recursively
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

Node *reverse(Node *head)
{
    // base case
    if (!head || !head->next)
    {
        return head;
    }

    Node *chotaHead = reverse(head->next);
    head->next->next = head;
    head->next = NULL;

    return chotaHead;
}

// it will return head of the reverse list
Node *reverseList(Node *head)
{
    return reverse(head);
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

    // reverse linked list recursively
    head = reverseList(head);

    // printing the reverse linked list
    print(head);

    return 0;
}