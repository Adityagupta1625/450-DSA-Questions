#include <iostream>
using namespace std;
  
// A C++ class to represent k stacks in a single array of size n
class kStacks
{
    int *arr;   // Array of size n to store actual content to be stored in stacks
    int *top;   // Array of size k to store indexes of top elements of stacks
    int *next;  // Array of size n to store next entry in all stacks
                // and free list
    int n, k;
    int free; // To store beginning index of free list
public:
    //constructor to create k stacks in an array of size n
    kStacks(int k, int n);
  
    // A utility function to check if there is space available
    bool isFull()   {  return (free == -1);  }
  
    // To push an item in stack number 'sn' where sn is from 0 to k-1
    void push(int item, int sn);
  
    // To pop an from stack number 'sn' where sn is from 0 to k-1
    int pop(int sn);
  
    // To check whether stack number 'sn' is empty or not
    bool isEmpty(int sn)  {  return (top[sn] == -1); }

    void display(){
        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};
  
kStacks::kStacks(int k1,int n1){
    free=0;
    n=n1;
    k=k1;
    top=new int[k];
    next=new int[n];
    arr=new int[n];
    for(int i=0;i<n-1;i++){
        next[i]=i+1;
    }
    next[n-1]=-1;
    for(int i=0;i<k;i++)
        top[i]=-1;
}
 void kStacks::push(int item,int sn){
     if(isFull()){
         cout<<"Stack is full"<<endl;
         return;
     }
     int i=free;
     free=next[i];
     next[i]=top[sn];
     top[sn]=i;
     arr[i]=item;
     
 } 
int kStacks::pop(int sn){
     if(isEmpty(sn)){
         cout<<"Stack is Empty"<<endl;
         return -1;;
     }
     int i=top[sn];
     
     int val=arr[i];
     top[sn]=next[i];
     next[i]=free;
     free=i;
     
     return val;
 } 
/* Driver program to test twStacks class */
int main()
{
    // Let us create 3 stacks in an array of size 10
    int k = 3, n = 10;
    kStacks ks(k, n);
  
    // Let us put some items in stack number 2
    ks.push(15, 2);
    ks.push(45, 2);
  
    // Let us put some items in stack number 1
    ks.push(17, 1);
    ks.push(49, 1);
    ks.push(39, 1);
  
    // Let us put some items in stack number 0
    ks.push(11, 0);
    ks.push(9, 0);
    ks.push(7, 0);
    
    // ks.display();
   
    cout << "Popped element from stack 2 is " << ks.pop(2) << endl;
    cout << "Popped element from stack 1 is " << ks.pop(1) << endl;
    cout << "Popped element from stack 0 is " << ks.pop(0) << endl;
  
    return 0;
}