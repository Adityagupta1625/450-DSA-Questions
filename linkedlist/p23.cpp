// Given two singly linked lists of size N and M, write a program to get the point where two linked lists intersect each other.

// Example 1:

// Input:
// LinkList1 = 3->6->9->common
// LinkList2 = 10->common
// common = 15->30->NULL
// Output: 15
// Probelm Link: https://practice.geeksforgeeks.org/problems/intersection-point-in-linked-lists/1

#include<iostream>

using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

int intersectPoint(struct Node* head1, struct Node* head2);

Node* inputList(int size)
{
    if(size==0) return NULL;
    
    int val;
    cin>> val;
    
    Node *head = new Node(val);
    Node *tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

/* Driver program to test above function*/
int main()
{
    int T,n1,n2,n3;

    cin>>T;
    while(T--)
    {
        cin>>n1>>n2>>n3;
        
        Node* head1 = inputList(n1);
        Node* head2 = inputList(n2);
        Node* common = inputList(n3);
        
        Node* temp = head1;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        temp = head2;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        cout << intersectPoint(head1, head2) << endl;
    }
    return 0;
}

// } Driver Code Ends


/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

//Function to find intersection point in Y shaped Linked Lists.
int intersectPoint(Node* head1, Node* head2)
{
    // Your Code Here
    Node* ptr=head1;
    int cnt_1=0,cnt_2=0;
    
    while(ptr!=NULL){
        ptr=ptr->next;
        cnt_1++;
    }
    ptr=head2;
    while(ptr!=NULL){
        ptr=ptr->next;
        cnt_2++;
    }
    int diff=abs(cnt_1-cnt_2);
    Node* ptr1,*ptr2;
    if(cnt_1>cnt_2){
        ptr=head1;
        while(diff--){
            ptr=ptr->next;
        }
        ptr1=ptr;
        ptr2=head2;
    }
    else{
        ptr=head2;
         while(diff--){
            ptr=ptr->next;
        }
        ptr1=head1;
        ptr2=ptr;
    }
    while(ptr1!=ptr2){
        ptr1=ptr1->next;
        ptr2=ptr2->next;
        
    }
    return ptr1->data;
    
}