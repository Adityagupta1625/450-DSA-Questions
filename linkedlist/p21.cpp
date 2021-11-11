// Given a doubly-linked list, rotate the linked list counter-clockwise by N nodes. Here N is a given positive integer and is smaller than the count of nodes in linked list.

// Input : a  b  c  d  e   N = 2
// Output : c  d  e  a  b 

// Input : a  b  c  d  e  f  g  h   N = 4
// Output : e  f  g  h  a  b  c  d 

// Probelm Link : https://practice.geeksforgeeks.org/problems/rotate-a-linked-list/1
#include <iostream>
using namespace std;

class Node
{
public:
    char data;
    Node *next;
    Node *pre;
    Node(int data)
    {
        this->data = data;
        pre = NULL;
        next = NULL;
    }
    Node()
    {
        next=NULL;
    }
};

void insertAtHead(Node *&head, int data)
{
    Node *n = new Node(data);
    if (head == NULL)
    {
        head = n;
        return;
    }
    n->next = head;
    head->pre = n;
    head = n;
    return;
}
void insertAtTail(Node *&head, int data)
{
    if (head == NULL)
    {
        insertAtHead(head, data);
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    Node *n = new Node(data);
    temp->next = n;
    n->pre = temp;
    return;
}
void display(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << "-->";
        head = head->next;
    }
    cout << "NULL\n";
}

void rotateByN(Node *&head, int pos)
{
    Node *ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    Node* last=ptr;
    
    while(pos--)
    {
        Node* n=new Node();
        n->data=head->data;
        n->pre=last;
        last->next=n;
        last=n; 
        head=head->next;
        head->pre=NULL;
    }
    
}
int main()
{
    Node *head = NULL;
    insertAtTail(head, 'a');
    insertAtTail(head, 'b');
    insertAtTail(head, 'c');
    insertAtTail(head, 'd');
    insertAtTail(head, 'e');

    int n = 14;
    cout << "\nBefore Rotation : \n";
    display(head);
    rotateByN(head, n);
    cout << "\nAfter Rotation : \n";
    display(head);
    cout << "\n\n";

    return 0;
}