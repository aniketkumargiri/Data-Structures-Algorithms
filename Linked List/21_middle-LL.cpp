// Middle of the Linked List using length function
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

int getLength(Node *head)
{
    int len = 0;
    while (head != NULL)
    {
        len++;
        head = head->next;
    }

    return len;
}

Node *findMiddle(Node *head)
{
    int len = getLength(head);
    // cout << "Length of the linked list is: " << len << endl;

    int ans = (len / 2);

    Node *temp = head;
    while (ans--)
    {
        temp = temp->next;
    }

    return temp;
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
    Node *node = new Node(1);

    // head pointed to node
    Node *head = node;

    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    // printing the linked list
    print(head);

    // middle of the linked list
    Node *middle = findMiddle(head);
    cout << "Middle of the linked list is: " << middle->data << endl;

    return 0;
}