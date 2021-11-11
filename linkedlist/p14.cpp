// Count triplets in a sorted doubly linked list whose sum is equal to a given value x

// Probelm Link: https://www.geeksforgeeks.org/count-triplets-sorted-doubly-linked-list-whose-sum-equal-given-value-x/

#include <iostream>
#include <unordered_map>
using namespace std;

// structure of node of doubly linked list
struct Node
{
    int data;
    struct Node *next, *prev;
};

// Two Pointer Approach
void countTriplets(struct Node *head,int x){
    Node *ptr1,*ptr3,*ptr2,*ptr=head;

    while(ptr->next!=NULL)
        ptr=ptr->next;

    ptr1=head;
    int cnt=0;
    int ans;
    while(ptr1!=NULL){

        ptr2=ptr1->next;
        ptr3=ptr;
        while(ptr2!=ptr3 || ptr2==ptr3->next){
            int sum=ptr1->data+ptr2->data+ptr3->data;
            if(sum==x){
                ptr2=ptr2->next;
                ptr3=ptr3->prev;
                cnt++;

            }
            else if(sum<x)
                ptr2=ptr2->next;
            else
                ptr3=ptr3->prev;
        }
        ptr1=ptr1->next;
        ans=cnt;
    }
    cout<<ans<<endl;
}

// Hashing Approach
void countTriplets(struct Node *head, int x)
{
    struct Node *ptr, *ptr1, *ptr2;
    int count = 0;
    unordered_map<int, Node *> m;
    for (ptr = head; ptr != NULL; ptr = ptr->next)
    {
        m[ptr->data] = ptr;
    }
    for (ptr1 = head; ptr1 != NULL; ptr1 = ptr1->next)
    {
        for (ptr2 = ptr1->next; ptr2 != NULL; ptr2 = ptr2->next)
        {
            int sum=ptr1->data+ptr2->data;
            if(m.find(x-sum)!=m.end() && m[x-sum]!=ptr1 && m[x-sum]!=ptr2)
                count++;
            
        }
    }
    cout<<count / 3;
}
// A utility function to insert a new node at the
// beginning of doubly linked list
void insert(struct Node **head, int data)
{
    // allocate node
    struct Node *temp = new Node();

    // put in the data
    temp->data = data;
    temp->next = temp->prev = NULL;

    if ((*head) == NULL)
        (*head) = temp;
    else
    {
        temp->next = *head;
        (*head)->prev = temp;
        (*head) = temp;
    }
}
void printList(struct Node *head)
{
    struct Node *ptr = head;

    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}
// Driver program to test above
int main()
{
    // start with an empty doubly linked list
    struct Node *head = NULL;

    // insert values in sorted order
    insert(&head, 9);
    insert(&head, 8);
    insert(&head, 6);
    insert(&head, 5);
    insert(&head, 4);
    insert(&head, 2);
    insert(&head, 1);

    printList(head);
    int x = 17;

    countTriplets(head, x);
    return 0;
}