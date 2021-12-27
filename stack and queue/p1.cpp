// How to implement a stack which will support following operations in O(1) time complexity? 
// 1) push() which adds an element to the top of stack. 
// 2) pop() which removes an element from top of stack. 
// 3) findMiddle() which will return middle element of the stack. 
// 4) deleteMiddle() which will delete the middle element. 
// Push and pop are standard stack operations. 

// Probelm Link: https://www.geeksforgeeks.org/design-a-stack-with-find-middle-operation/

#include <iostream>
using namespace std;
class Node{
public:
    int data;
    Node *next;
    Node* prev;
};
class Stack{
    public:
    int count=0;
    Node* mid;
    Node* insertatfront(Node* head,int data){
        Node* newnode=new Node();
        newnode->data=data;
        newnode->next=NULL;
        newnode->prev=NULL;
        if(head==NULL){
            head=newnode;
            return head;
        }
        newnode->next=head;
        head->prev=newnode;
        head=newnode;
        count++;
        if(count==1){
           mid=head;
        }
        else if(count%2!=0){
            mid=mid->prev;
        }
        return head;
    }
    Node* deleteatfront(Node* head){
        if(head==NULL){
            cout<<"Stack is empty"<<endl;
            return NULL;
        }
        Node* temp=head;
        head=head->next;
        head->prev=NULL;
        int data=temp->data;
        count--;
        if(count==0){
            mid=NULL;
        }
        else if(count%2!=0){
            mid=mid->next;
        }
        cout<<"Deleted element is "<<data<<endl;
        delete temp;
        return head;
    }
    int getMid(){
        if(count==0){
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        return mid->data;
    }
    int deleteatMid(){
        if(count==0){
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        int x=mid->data;
        mid->prev->next=mid->next;
        return x;
    }
    void printStack(Node* head){
        if(head==NULL){
            cout<<"Stack is empty"<<endl;
            return;
        }
        while(head!=NULL){
            cout<<head->data<<" ";
            head=head->next;
        }
    }
};
int main()
{
    Stack s;
    Node* head=NULL;
    head=s.insertatfront(head,1);
    head=s.insertatfront(head,2);
    head=s.insertatfront(head,3);
    head=s.insertatfront(head,4);
    head=s.insertatfront(head,5);

    s.printStack(head);
    cout<<endl;

    cout<<s.getMid()<<endl;
    cout<<s.deleteatMid()<<endl;
    head=s.deleteatfront(head);
    head=s.deleteatfront(head);
   
    cout<<s.getMid()<<endl;

    s.printStack(head);
    return 0;
}