// Given a sorted doubly linked list of positive distinct elements, the task is to find pairs in a doubly-linked list whose sum is equal to given value x, without using any extra space?

// Example:

// Input : head : 1 <-> 2 <-> 4 <-> 5 <-> 6 <-> 8 <-> 9
//         x = 7
// Output: (6, 1), (5,2)

// Question link: https://www.geeksforgeeks.org/find-pairs-given-sum-doubly-linked-list/

// C++ program to find a pair with given sum x.
#include <iostream>
using namespace std;

// structure of node of doubly linked list
struct Node
{
    int data;
    struct Node *next, *prev;
};

// A utility function to insert a new node at the
// beginning of doubly linked list
void insert(struct Node **head, int data)
{
    struct Node *temp = new Node;
    temp->data = data;
    temp->next = temp->prev = NULL;
    if (!(*head))
        (*head) = temp;
    else
    {
        temp->next = *head;
        (*head)->prev = temp;
        (*head) = temp;
    }
}
void pairSum(struct Node *head, int x)
{
    struct Node *first, *second, *ptr = head;

    while (ptr->next != NULL)
        ptr = ptr->next;

    first = head;
    second = ptr;
    
    while (first != second || first == second->next)
    {
        if (first->data + second->data == x)
        {
            cout<<first->data<<" "<<second->data<<endl;
            first = first->next;
            second=second->prev;
        }
        else if (first->data + second->data<x)
        {
            first=first->next;
        }
        else{
            second=second->prev;
        }
    }
}
void printList(struct Node *head){
    struct Node *ptr=head;

    while(ptr!=NULL){
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
    cout<<endl;
}

// Driver program
int main()
{
    struct Node *head = NULL;
    insert(&head, 9);
    insert(&head, 8);
    insert(&head, 6);
    insert(&head, 5);
    insert(&head, 4);
    insert(&head, 2);
    insert(&head, 1);
    int x = 7;

    printList(head);
    pairSum(head, x);

    return 0;
}