// Given K sorted linked lists of different sizes. The task is to merge them in such a way that after merging they will be a single sorted linked list.

// Example 1:

// Input:
// K = 4
// value = {{1,2,3},{4 5},{5 6},{7,8}}
// Output: 1 2 3 4 5 5 6 7 8
// Explanation:
// The test case has 4 sorted linked 
// list of size 3, 2, 2, 2
// 1st    list     1 -> 2-> 3
// 2nd   list      4->5
// 3rd    list      5->6
// 4th    list      7->8
// The merged list will be
// 1->2->3->4->5->5->6->7->8.
// Probelm link: https://practice.geeksforgeeks.org/problems/merge-k-sorted-linked-lists/1#

#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

/* Function to print nodes in a given linked list */
void printList(Node* node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	cout<<endl;
}

 // } Driver Code Ends
/*Linked list Node structure

struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};
*/ 

class Solution{
  public:
    //Function to merge K sorted linked list.
    
    Node * mergeKLists(Node *arr[], int K)
    {
           // Your code here
           Node* newhead=NULL;
           Node* last;
           while(true){
               int mi=INT_MAX;
               int z;
               int flag=0;
               for(int i=0;i<K;i++){
                   if(arr[i]!=NULL){
                       
                        flag=1;
                        if(arr[i]->data<mi){
                            z=i;
                            mi=arr[i]->data;
                        }
                   }
                   
               }
               if(flag==0)
                 return newhead;
               
               Node* temp=arr[z];
               arr[z]=arr[z]->next;
               if(newhead==NULL){
                   newhead=temp;
                   last=temp;
               }
               else{
                   last->next=temp;
                   last=last->next;
               }
           }
           return newhead;
    }
};



// { Driver Code Starts.
// Driver program to test above functions
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
	   int N;
	   cin>>N;
       struct Node *arr[N];
       for(int j=0;j<N;j++)
        {
           int n;
           cin>>n;

           int x;
           cin>>x;
           arr[j]=new Node(x);
           Node *curr = arr[j];
           n--;

           for(int i=0;i<n;i++)
           {
               cin>>x;
               Node *temp = new Node(x);
               curr->next =temp;
               curr=temp;
           }
   		}
   		Solution obj;
   		Node *res = obj.mergeKLists(arr,N);
		printList(res);

   }

	return 0;
}