#include <iostream>
using namespace std;

class Node {
    public:
        int key;
        struct Node* next;
};
 
Node* newNode(int key)
{
    Node* temp = new Node;
    temp->key = key;
    temp->next = NULL;
    return temp;
}
 
// A utility function to print a linked list
void printList(Node* head)
{
    while (head != NULL) {
        cout << head->key << " ";
        head = head->next;
    }
    cout << endl;
}
 
Node* detectAndRemoveLoop(Node* head)
{
  if(head==NULL && head->next==NULL)
  {
    return NULL;
  }
  int flag=0;
  Node* slow_p=head,*fast_p=head;
   while(slow_p!=NULL && fast_p!=NULL && fast_p->next!=NULL)
    {
        slow_p=slow_p->next;
        fast_p=fast_p->next->next;
        if(slow_p==fast_p)
        {
            flag=1;
            break;
        }
    }
    if(!flag)
    {
        return NULL;
    }
    slow_p=head;
    while(slow_p!=fast_p)
    {
        slow_p=slow_p->next;
        fast_p=fast_p->next;
    }
    return slow_p;
}
 
/* Driver program to test above function*/
int main()
{
    Node* head = newNode(50);
    head->next = newNode(20);
    head->next->next = newNode(15);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(10);
 
    /* Create a loop for testing */
    head->next->next->next->next->next = head->next->next;
 
    Node* res = detectAndRemoveLoop(head);
    if (res == NULL)
        cout << "Loop does not exist";
    else
        cout << "Loop starting node is " << res->key;
 
    return 0;
}