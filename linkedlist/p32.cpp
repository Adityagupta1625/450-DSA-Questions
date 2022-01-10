// Sort the given Linked List using quicksort. which takes O(n^2) time in worst case and O(nLogn) in average and best cases, otherwise you may get TLE.

// Input:
// In this problem, method takes 1 argument: address of the head of the linked list. The function should not read any input from stdin/console.
// The struct Node has a data part which stores the data and a next pointer which points to the next element of the linked list.
// There are multiple test cases. For each test case, this method will be called individually.

// Output:
// Set *headRef to head of resultant linked list.
// Probelm link: https://practice.geeksforgeeks.org/problems/quick-sort-on-linked-list/1#
#include <iostream>
#include <cstdio>
using namespace std;
 
/* a node of the singly linked list */
struct node
{
    int data;
    struct node *next;
    
    node(int x){
        data = x;
        next = NULL;
    }
};

/* A utility function to insert a node at the beginning of linked list */
void push(struct node** head_ref, int new_data)
{
    /* allocate node */
    struct node* new_node = new node(new_data);
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);
 
    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}
 
/* A utility function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}
void quickSort(struct node **headRef);
int main()
{
	int t,n,x;
	cin>>t;
	while(t--){
		
        
        cin>>n;n=n-1;
		cin>>x;
        node *temp,*head = new node(x);
        temp=head;
        while(n--)
        {
			cin>>x;
          temp->next=new node(x);
          temp=temp->next;
			}
    
    quickSort(&head);
 
    printList(head);
 while(head!= NULL){
     temp=head;
     head=head->next;
     free(temp);
     
 }
	}
    return 0;
}// } Driver Code Ends


 
/* a node of the singly linked list 
struct node
{
    int data;
    struct node *next;
    
    node(int x){
        data = x;
        next = NULL;
    }
}; */

//you have to complete this function
struct node* gettail(struct node* head){
    while(head->next!=NULL && head!=NULL)
        head=head->next;
    return head;
}
struct node* partition(struct node* head,struct node* end,
struct node** newhead,struct node** newend){
    struct node* pivot=end;
    struct node* curr=head;
    struct node* tail=end;
   struct node* prev=NULL;
    while(curr!=pivot){
        
        if(curr->data<pivot->data){
            if(*newhead==NULL)
                *newhead=curr;
            
            prev=curr;
            curr=curr->next;
        }
        else{
            if(prev!=NULL)
                prev->next=curr->next;
            struct node* temp=curr->next;
            
            curr->next=NULL;
            tail->next=curr;
            tail=curr;
            curr=temp; 
        }
        
    }
    if(*newhead==NULL)
            *newhead=pivot;
        
    *newend=tail;
     return pivot;
}
struct node* quicksortrecur(struct node* head,struct node* end){
    if(!head || head==end)
        return head;
    struct node* newhead=NULL;
    struct node* newend=NULL;
    struct node* pivot=partition(head,end,&newhead,&newend);
    if(newhead!=pivot){
        struct node* temp=newhead;
        while(temp->next!=pivot)
            temp=temp->next;
        temp->next=NULL;
        newhead=quicksortrecur(newhead,temp);
        temp=gettail(newhead);
        temp->next=pivot;
    }
    pivot->next=quicksortrecur(pivot->next,newend);
    return newhead;
}
void quickSort(struct node **headRef) {
    struct node* head=*headRef;
    struct node* end=gettail(head);
    *headRef=quicksortrecur(head,end);
}