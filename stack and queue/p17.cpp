// Given a queue of integers of even length, rearrange the elements by interleaving the first half of the queue with the second half of the queue.

// Only a stack can be used as an auxiliary space.
// Input :  1 2 3 4
// Output : 1 3 2 4

// Input : 11 12 13 14 15 16 17 18 19 20
// Output : 11 16 12 17 13 18 14 19 15 20

// probelm link: https://www.geeksforgeeks.org/interleave-first-half-queue-second-half/
#include<iostream>
#include <queue>
#include <stack>
using namespace std;
  
// Function to interleave the queue
void interLeaveQueue(queue<int>& q)
{
   if(q.size()%2!=0){
       cout<<"Enter even no of elements."<<endl;
       return;

   }
   stack<int> st;
   int halfsize=q.size()/2;
//    Stage 1
   for (int i = 0; i < halfsize; i++)
   {
       st.push(q.front());
       q.pop();
       
   }
   while(!st.empty()){
       q.push(st.top());
       st.pop();
   }
   
//    stage 2
   for (int i = 0; i < halfsize; i++)
   {
       q.push(q.front());
       q.pop();
   }

//    stage 3
   for (int i = 0; i < halfsize; i++)
   {
       st.push(q.front());
       q.pop();
   }

//    stage 4
    while(!st.empty()){
        q.push(st.top());
        st.pop();
        q.push(q.front());
        q.pop();
    }
   
}
  
// Driver program to test above function
int main()
{
    queue<int> q;
    q.push(11);
    q.push(12);
    q.push(13);
    q.push(14);
    q.push(15);
    q.push(16);
    q.push(17);
    q.push(18);
    q.push(19);
    q.push(20);
    interLeaveQueue(q);
    int length = q.size();
    for (int i = 0; i < length; i++) {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}

// 11 16 12 17 13 18 14 19 15 20 