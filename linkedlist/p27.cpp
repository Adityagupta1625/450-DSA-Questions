// Given Pointer/Reference to the head of the linked list, the task is to Sort the given linked list using Merge Sort.
// Note: If the length of linked list is odd, then the extra node should go in the first list while splitting.

// Example 1:

// Input:
// N = 5
// value[]  = {3,5,2,4,1}
// Output: 1 2 3 4 5
// Explanation: After sorting the given
// linked list, the resultant matrix
// will be 1->2->3->4->5.

// Probelm Link: https://practice.geeksforgeeks.org/problems/sort-a-linked-list/1#

// { Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


 // } Driver Code Ends
/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/


class Solution{
  public:
    //Function to sort the given linked list using Merge Sort.
    void split(Node** a,Node** b,Node* head){
        Node* slow=head;
        Node* fast=head->next;
        while(fast!=NULL){
            fast=fast->next;
            if(fast!=NULL){
                 slow=slow->next;
                fast=fast->next;
            }
           
        }
        *a=head;
        *b=slow->next;
        slow->next=NULL;
        
    }
    Node* merge(Node* a,Node* b){
        if(a==NULL)
            return b;
        if(b==NULL)
            return a;
        
        Node* newNode=NULL;
        if(a->data<b->data){
            newNode=a;
            newNode->next=merge(a->next,b);
        }
        else{
            newNode=b;
            newNode->next=merge(a,b->next);
        }
        return newNode;
    }
    void mergeSorting(Node** head){
        Node* curr=*head;
        if(curr==NULL || curr->next==NULL)
            return;
            
        Node* a;
        Node* b;
        split(&a,&b,curr);
        
        mergeSorting(&a);
        mergeSorting(&b);
        *head=merge(a,b);
        
    }
    Node* mergeSort(Node* head) {
        // your code here
       mergeSorting(&head);
       return head;
    }
};


// { Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}