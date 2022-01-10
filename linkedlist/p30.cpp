// Given a doubly linked list containing n nodes. The problem is to reverse every group of k nodes in the list.

// Probelm Link: https://www.geeksforgeeks.org/reverse-doubly-linked-list-groups-given-size/

#include <iostream>
using namespace std;
struct Node {
    int data;
    Node *next, *prev;
};
// function to add Node at the end of a Doubly LinkedList
Node* insertAtEnd(Node* head, int data)
{
 
    Node* new_node = new Node();
    new_node->data = data;
    new_node->next = NULL;
    Node* temp = head;
    if (head == NULL) {
        new_node->prev = NULL;
        head = new_node;
        return head;
    }
 
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
    new_node->prev = temp;
    return head;
}
// function to print Doubly LinkedList
void printDLL(Node* head)
{
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
// function to Reverse a doubly linked list
// in groups of given size
Node* reverseByN(Node* head, int k)
{
    if(head==NULL)
        return head;
    head->prev=NULL;
    Node* temp=NULL;
    Node* newhead=NULL;
    Node* curr=head;
    int count=0;
    while(curr!=NULL && count<k){
        newhead=curr;
        temp=curr->prev;
        curr->prev=curr->next;
        curr->next=temp;
        curr=curr->prev;
        count++;
    }
    if(count>=k){
        Node* rest=reverseByN(curr,k);
        head->next= rest;
        if(rest!=NULL)
            rest->prev=head;
    }
    return newhead;
}
int main()
{
    Node* head=NULL;
    for (int i = 1; i <= 10; i++) {

        head = insertAtEnd(head, i);
        
    }
    printDLL(head);
    int n = 4;
    head = reverseByN(head, n);
    printDLL(head);
}