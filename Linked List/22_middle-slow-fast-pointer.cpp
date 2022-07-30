// Middle of the Linked List using slow & fast pointer
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

Node *getMiddle(Node *head)
{
    if (!head || !head->next)
    {
        return head;
    }
    if (!head->next->next)
    {
        return head->next;
    }

    Node *slow = head;
    Node *fast = head->next;

    while (fast)
    {
        fast = fast->next;
        if (fast)
        {
            fast = fast->next;
        }
        slow = slow->next;
    }

    return slow;
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
    Node *middle = getMiddle(head);
    cout << "Middle of the linked list is: " << middle->data << endl;

    return 0;
}