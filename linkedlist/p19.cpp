// Given a link list of size N, modify the list such that all the even numbers appear before all the odd numbers in the modified list. The order of appearance of numbers within each segregation should be same as that in the original list.

// NOTE: Don't create a new linked list, instead rearrange the provided one.

// Example 1:

// Input: 
// N = 7
// Link List:
// 17 -> 15 -> 8 -> 9 -> 2 -> 4 -> 6 -> NULL

// Output: 8 2 4 6 17 15 9

// Explaination: 8,2,4,6 are the even numbers 
// so they appear first and 17,15,9 are odd 
// numbers that appear later.
// Probelm Link: https://practice.geeksforgeeks.org/problems/segregate-even-and-odd-numbers-in-a-linked-list/1

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data <<" "; 
        node = node->next; 
    }  
    cout<<"\n";
} 


 // } Driver Code Ends
//User function template for C++

/*
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution{
public:
    
    Node* divide(int N, Node *head){
        // code here
        Node* ptr=head;
        while(ptr->next!=NULL)
            ptr=ptr->next;
            
        Node *last=ptr,*end=last;
        
        ptr=head;
        while(ptr->data%2!=0 && ptr!=end){
            int x=ptr->data;
            Node * n=new Node(x);
            last->next=n;
            last=n;
            ptr=ptr->next;
        }
        Node *prev;
        
        if(ptr->data%2==0){
                head=ptr;
                while(ptr!=end){
                if(ptr->data%2==0){
                     prev=ptr;
                     ptr=ptr->next;
                }
                   
                else{
                   int x=ptr->data;
                   Node * n=new Node(x);
                   last->next=n;
                   last=n;
                   prev->next=ptr->next;
                   ptr=ptr->next;
                  
                }
            }
        }
        else
            prev=ptr;
        if(last!=end && end->data%2!=0){
            prev->next=end->next;
             end->next = NULL;
            last->next = end;
        }
        return head;
    }
};

// { Driver Code Starts.

int main() {
    //code
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        
        Solution ob;
        Node *ans = ob.divide(N, head);
        printList(ans); 
    }
    return 0;
}