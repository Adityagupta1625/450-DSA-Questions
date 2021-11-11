// Given two numbers represented by two linked lists of size N and M. The task is to return a sum list.
// The sum list is a linked list representation of the addition of two input numbers from the last.

// Example 1:

// Input:
// N = 2
// valueN[] = {4,5}
// M = 3
// valueM[] = {3,4,5}
// Output: 3 9 0  
// Explanation: For the given two linked
// list (4 5) and (3 4 5), after adding
// the two linked list resultant linked
// list will be (3 9 0).
// Probelm Link: https://practice.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1#
#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


 // } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    struct Node* reverse(struct Node* head)
    {
        if (head == NULL || head->next == NULL)
            return head;
 
        /* reverse the rest list and put
          the first element at the end */
        Node* rest = reverse(head->next);
        head->next->next = head;
 
        /* tricky step -- see the diagram */
        head->next = NULL;
 
        /* fix the head pointer */
        return rest;
    }
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
       
      
        first=reverse(first);
        second=reverse(second);
        Node * ptr1=first;
        Node *ptr2=second;
        Node* head=NULL;
        int carry=0;
        int sum=0;
        while(ptr1!=NULL && ptr2!=NULL){
            sum=ptr1->data+ptr2->data+carry;
            carry=sum/10;
            if(head==NULL){
                Node * n=new Node(sum%10);
                
                head=n;
            }
            else{
                Node * n=new Node(sum%10);
                
                n->next=head;
                head=n;
            }
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
        while(ptr1!=NULL){
            sum=ptr1->data+carry;
            carry=sum/10;
            Node* n=new Node(sum%10);
            
            n->next=head;
            head=n;
            ptr1=ptr1->next;
        }
        while(ptr2!=NULL){
            sum=ptr2->data+carry;
            carry=sum/10;
            Node* n=new Node(sum%10);
            n->next=head;
            head=n;
            ptr2=ptr2->next;
        }
        if(carry!=0){
            Node* n=new Node(carry);
            
            n->next=head;
            head=n;
        }
        // head=reverse(head);
        return head;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}