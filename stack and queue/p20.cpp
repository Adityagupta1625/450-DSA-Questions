// A stack permutation is a permutation of objects in the given input queue which is done by transferring elements from input queue to the output queue with the help of a stack and the built-in push and pop functions.
// The well defined rules are: 
 
// Only dequeue from the input queue.
// Use inbuilt push, pop functions in the single stack.
// Stack and input queue must be empty at the end.
// Only enqueue to the output queue.
// There are a huge number of permutations possible using a stack for a single input queue. 

// Given two arrays, both of unique elements. One represents the input queue and the other represents the output queue. Our task is to check if the given output is possible through stack permutation.

// Examples: 
// Input : First array: 1, 2, 3  
//         Second array: 2, 1, 3
// Output : Yes
// Procedure:
// push 1 from input to stack
// push 2 from input to stack
// pop 2 from stack to output
// pop 1 from stack to output
// push 3 from input to stack
// pop 3 from stack to output

// Input : First array: 1, 2, 3  
//         Second array: 3, 1, 2
// Output : Not Possible  

// Probelm link: https://www.geeksforgeeks.org/stack-permutations-check-if-an-array-is-stack-permutation-of-other/
#include <iostream>
#include <queue>
#include<stack>
using namespace std;
 
// function to check if input queue is
// permutable to output queue
bool checkStackPermutation(int ip[], int op[], int n)
{
   queue <int> inp,out;

   for(int i=0;i<n;i++)
    inp.push(ip[i]);

   for(int i=0;i<n;i++)
    out.push(op[i]);
   
   stack<int> s;
   while(!inp.empty()){

       int ele=inp.front();

       if(ele!=out.front()){
           s.push(inp.front());
           inp.pop();
        }
       else{
           inp.pop();
           out.pop();
           int g=out.front();
           while(!s.empty()){
               if(s.top()==g){
                   s.pop();
                   g=out.front();
                   out.pop();
               }
               else
                break;
           }
       }
   }
   if(s.empty()){
       return true;
   }
   else
     return false;
    
}
 
// Driver program to test above function
int main()
{
    // Input Queue
    int input[] = {1, 2, 3};
 
    // Output Queue
    int output[] = {2, 1, 3};
 
    int n = 3;
 
    if (checkStackPermutation(input, output, n))
        cout << "Yes";
    else
        cout << "Not Possible";
    return 0;
}