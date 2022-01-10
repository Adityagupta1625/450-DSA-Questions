// Given a doubly linked list containing n nodes, where each node is at most k away from its target position in the list. The problem is to sort the given doubly linked list. 
// For example, let us consider k is 2, a node at position 7 in the sorted doubly linked list, can be at positions 5, 6, 7, 8, 9 in the given doubly linked list.
// Probelm Link: https://www.geeksforgeeks.org/sort-k-sorted-doubly-linked-list/

#include <iostream>
#include <stdlib.h>
#include <queue>
using namespace std;
 
// a node of the doubly linked list
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};
 
 
// function to sort a k sorted doubly linked list

// o(n*k) solution
// struct Node* sortAKSortedDLL(struct Node* head, int k)
// {
//    if(head==NULL && head->next==NULL)
//         return head;
   
   
//    for(Node* temp=head->next;temp!=NULL;temp=temp->next){
//        Node* j=temp;
//        while(j->prev!=NULL && j->data<j->prev->data){
//            Node* temp1=j->prev->prev;
//            Node* temp2=j->prev;
//            Node* temp3=j->next;

//            j->prev->next=temp3;
//            j->prev->prev=j;
//            j->prev=temp1;
//            j->next=temp2;

//            if(temp1!=NULL)
//                 temp1->next=j;
//            if(temp3!=NULL)
//                 temp3->prev=temp2;
//        }
//        if(j->prev==NULL)
//             head=j;
      
//    }
//    return head;
// }
// o(nlogk) and o(k) solution
struct comp{

    bool operator()(struct Node* a,struct Node* b){
        return a->data>b->data;
    }
};
struct Node* sortAKSortedDLL(struct Node* head, int k)
{
   if(head==NULL && head->next==NULL)
        return head;
   priority_queue<Node *,vector<Node*>,comp> pq;

   struct Node* newhead=NULL;
   for (int i = 0; i <=k && head!=NULL; i++)
   {
       pq.push(head);
       head=head->next;
   }
   Node* last=NULL;
   while(!pq.empty()){
       if(newhead==NULL){
           newhead=pq.top();
           newhead->prev=NULL;
           pq.pop();
           last=newhead;
       }
       else{
           last->next=pq.top();
           pq.top()->prev=last;
           last=pq.top();
           pq.pop();
       }

       if(head!=NULL){
           pq.push(head);
           head=head->next;
       }

   }
   last->next=NULL;
   return newhead;
}
// Function to insert a node at the beginning
// of the Doubly Linked List
void push(struct Node** head_ref, int new_data)
{
    // allocate node
    struct Node* new_node =
        (struct Node*)malloc(sizeof(struct Node));
 
    // put in the data
    new_node->data = new_data;
 
    // since we are adding at the beginning,
    // prev is always NULL
    new_node->prev = NULL;
 
    // link the old list off the new node
    new_node->next = (*head_ref);
 
    // change prev of head node to new node
    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;
 
    // move the head to point to the new node
    (*head_ref) = new_node;
}
 
// Function to print nodes in a given doubly linked list
void printList(struct Node* head)
{
    // if list is empty
    if (head == NULL)
        cout << "Doubly Linked list empty";
 
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}
 
// Driver program to test above
int main()
{
    struct Node* head = NULL;
 
    // Create the doubly linked list:
    // 3<->6<->2<->12<->56<->8
    push(&head, 8);
    push(&head, 56);
    push(&head, 12);
    push(&head, 2);
    push(&head, 6);
    push(&head, 3);
 
    int k = 2;
 
    cout << "Original Doubly linked list:\n";
    printList(head);
 
    // sort the biotonic DLL
    head = sortAKSortedDLL(head, k);
 
    cout << "\nDoubly linked list after sorting:\n";
    printList(head);
 
    return 0;
}