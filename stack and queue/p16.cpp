#include <iostream>
using namespace std;
struct Node
{
    int val;
    Node *prev;
    Node *next;
};
class Dll
{
private:
    Node *last;
    Node *head;

public:
    Dll()
    {
        last = head = NULL;
    }
    bool isEmpty()
    {
        if (head == NULL)
            return true;
        return false;
    }
    int size()
    {
        Node *ptr = head;
        int len = 0;
        while (ptr != NULL)
        {
            len++;
            ptr = ptr->next;
        }
        return len;
    }
    void insert_first(int ele)
    {
        Node *newNode = new Node[sizeof(Node)];
        newNode->val = ele;
        if (head == NULL)
        {
            newNode->next = NULL;
            newNode->prev = NULL;
            last = newNode;
            head = newNode;
        }
        else
        {

            newNode->prev = NULL;
            head->prev = newNode;
            newNode->next = head;
            head = newNode;
        }
    }
    void insert_last(int ele)
    {
        Node *newNode = new Node[sizeof(Node)];
        newNode->val = ele;
        if (last == NULL)
        {
            newNode->next = NULL;
            newNode->prev = NULL;
            last = newNode;
            head = newNode;
        }
        else
        {

            newNode->prev = last;
            last->next = newNode;
            newNode->next = NULL;
            last = newNode;
        }
    }
    int remove_first()
    {
        if (!isEmpty())
        {

            Node *temp = new Node[sizeof(Node)];
            temp = head;
            head = head->next;
            int val=temp->val;
            delete temp;
            if(head)
                head->prev = NULL;
            if(head==NULL)
                last=NULL;
            return val;
        }
        else
        {
            cout << "Empty..." << endl;
            return -1;
        }
    }
    int remove_last()
    {
        if (!isEmpty())
        {

            Node *temp = new Node[sizeof(Node)];
            temp = last;
            int val=temp->val;
            last=last->prev;
            delete temp;
            if(last)
                last->next = NULL;
            if(last==NULL)
                head=NULL;
            return val;
        }
        else
        {
            cout << "Empty..." << endl;
            return -1;
        }
    }
    void display(){
        Node* n=new Node[sizeof(Node)];
        n=head;
        while(n!=NULL){
            cout<<n->val<<" ";
            n=n->next;
        }
        cout<<endl;
    }
};
class Stack{
    private:
        Dll d;
    public:
        Stack(){
            Dll();
        }
        void push(int val){
            d.insert_last(val);
        }
        int pop(){
            return d.remove_last();
        }
        int size(){
            return d.size();
        }
        bool empty(){
            return d.isEmpty();
        }
        void display(){
            d.display();
        }

};
class Queue{
    private:
        Dll d;
    public:
        Queue(){
            Dll();
        }
        void enqueue(int val){
            d.insert_last(val);
        }
        int dequeue(){
            return d.remove_first();
        }
        int size(){
            return d.size();
        }
        bool empty(){
            return d.isEmpty();
        }
        void display(){
            d.display();
        }
};
int main()
{
     // object of Stack
    Stack stk;
 
    // push 7 and 8 at top of stack
    stk.push(7);
    stk.push(8);
    cout << "Stack: ";
    stk.display();
 
    // pop an element
    stk.pop();
    cout << "Stack: ";
    stk.display();
 
    // object of Queue
    Queue que;
 
    // insert 12 and 13 in queue
    que.enqueue(12);
    que.enqueue(13);
    cout << "Queue: ";
    que.display();
 
    // delete an element from queue
    que.dequeue();
    cout << "Queue: ";
    que.display();
 
    cout << "Size of Stack is " << stk.size() << endl;
    cout << "Size of Queue is " << que.size() << endl;
    return 0;

}