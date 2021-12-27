#include<iostream>
#include<climits>
using namespace std;

class kQueues
{  
    // Array of size n to store actual content to be stored in queue
    int *arr;
 
    // Array of size k to store indexes of front elements of the queue 
    int *front;  
 
    // Array of size k to store indexes of rear elements of queue
    int *rear;
 
    // Array of size n to store next entry in all queues           
    int *next; 
    int n, k;
 
    int free; // To store the beginning index of the free list
 
public:
    //constructor to create k queue in an array of size n
    kQueues(int k, int n);
 
    // A utility function to check if there is space available
    bool isFull()   {  return (free == -1);  }
 
    // To enqueue an item in queue number 'qn' where qn is from 0 to k-1
    void enqueue(int item, int qn);
 
    // To dequeue an from queue number 'qn' where qn is from 0 to k-1
    int dequeue(int qn);
 
    // To check whether queue number 'qn' is empty or not
    bool isEmpty(int qn)  {  return (front[qn] == -1); }
};
kQueues::kQueues(int k,int n){
    arr=new int[n];
    front=new int[k];
    rear=new int[k];
    next=new int[n];

    free=0;
    this->n=n;
    this->k=k;

    for(int i=0;i<k;i++){
        front[i]=rear[i]=-1;
    }

    for(int i=0;i<n-1;i++){
        next[i]=i+1;
    }
    next[n-1]=-1;
}
void kQueues::enqueue(int item, int qn)
{
    if(isFull())
        cout<<"Stack is full"<<endl;
    
    int i=free;

    free=next[i];

    if(front[qn]==-1)
        front[qn]=i;
    else
        next[rear[qn]]= i;

    next[i]=-1;
    rear[qn]=i;
    arr[i]=item;
}
int kQueues::dequeue(int qn){
    if(isEmpty(qn)){
        cout<<"Stack is empty"<<endl;
        return -1;
    }
    int i=front[qn];
    int val=arr[i];
    
    front[qn]=next[i];
    next[i]=free;
    free=i;
    
    return val;
} 

int main()
{
    // Let us create 3 queue in an array of size 10
    int k = 3, n = 10;
    kQueues ks(k, n);
 
    // Let us put some items in queue number 2
    ks.enqueue(15, 2);
    ks.enqueue(45, 2);
 
    // Let us put some items in queue number 1
    ks.enqueue(17, 1);
    ks.enqueue(49, 1);
    ks.enqueue(39, 1);
 
    // Let us put some items in queue number 0
    ks.enqueue(11, 0);
    ks.enqueue(9, 0);
    ks.enqueue(7, 0);
 
    cout << "Dequeued element from queue 2 is " << ks.dequeue(2) << endl;
    cout << "Dequeued element from queue 1 is " << ks.dequeue(1) << endl;
    cout << "Dequeued element from queue 0 is " << ks.dequeue(0) << endl;
 
    return 0;
}