#include <iostream>
using namespace std;
 
class Queue
{
    // Initialize front and rear
    private:
    int rear, front;
 
    // Circular Queue
    int size;
    int *arr;
    
    public:
    Queue(int s)
    {
       front = rear = -1;
       size = s;
       arr = new int[s];
    }
 
    void enQueue(int value);
    int deQueue();
    void displayQueue();
    bool isFull();
    bool isEmpty();
};
bool Queue::isFull(){
    if((rear)%(size+1)==front)
        return true;
    return false;
}
bool Queue::isEmpty(){
    if(rear==front)
        return true;
    return false;
}
void Queue::enQueue(int value){
    if(isFull()){
        cout<<"Queue is Full";
        return;
    }
    rear=(rear+1)%size;
    arr[rear]=value;
} 
int Queue::deQueue(){
    if(isEmpty()){
        cout<<"Queue is empty";
        return -1;
    }
    front=(front+1)%(size);
    int x=arr[front];
    return x;
} 
void Queue::displayQueue(){
    if(isEmpty()){
        cout<<"Queue is Empty";
        return;
    }
    

        if(rear>=front){
            for(int i=front+1;i<=rear;i++)
                cout<<arr[i]<<" ";
            cout<<endl;
        }
        else{
            for(int i=front+1;i<size;i++)
                cout<<arr[i]<<" ";
            for(int i=0;i<=rear;i++)
                cout<<arr[i]<<" ";
            cout<<endl;
        }
    
}
/* Driver of the program */
int main()
{
    Queue q(5);
 
    // Inserting elements in Circular Queue
    q.enQueue(14);
    q.enQueue(22);
    q.enQueue(13);
    q.enQueue(-6);
 
    // Display elements present in Circular Queue
    q.displayQueue();
 
    // Deleting elements from Circular Queue
    printf("\nDeleted value = %d", q.deQueue());
    printf("\nDeleted value = %d", q.deQueue());
    
    cout<<endl;
    q.displayQueue();

    q.enQueue(9);
    q.enQueue(20);
    q.enQueue(5);
 
    q.displayQueue();
 
    q.enQueue(20);
    return 0;
}