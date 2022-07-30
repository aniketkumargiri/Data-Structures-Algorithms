// Reverse a Linked List in "k" groups recursively
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

// it will return head of the reverse list
Node *reverseK(Node *head, int k)
{
    // base case
    if (head == NULL)
    {
        return NULL;
    }

    // step1: reverse first k nodes
    Node *prev = NULL;
    Node *curr = head;
    Node *next = NULL;
    int cnt = 0;

    while (curr && cnt < k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        cnt++;
    }

    // step2: recursive call for rest of the part
    if (next != NULL)
    {
        head->next = reverseK(next, k);
    }

    // step3: return head of reversed list
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

    int k;
    cin >> k;
    // reverse linked list recursively
    head = reverseK(head, k);

    // printing the reverse linked list
    print(head);

    return 0;
}