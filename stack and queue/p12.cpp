// Given a Queue Q containing N elements. The task is to reverse the Queue. Your task is to complete the function rev(), that reverses the N elements of the queue.

// Example 1:

// Input:
// 6
// 4 3 1 10 2 6

// Output: 
// 6 2 10 1 3 4

// Explanation: 
// After reversing the given
// elements of the queue , the resultant
// queue will be 6 2 10 1 3 4.
// Probelm Link: https://practice.geeksforgeeks.org/problems/queue-reversal/1#
#include<bits/stdc++.h>
using namespace std;
queue<int> rev(queue<int> q);
int main()
{
    int test;
    cin>>test; 
    while(test--)
    {
    queue<int> q; 
    int n, var; 
    cin>>n; 
    while(n--)
    {
        cin>>var; 
        q.push(var);
    }
    queue<int> a=rev(q); 
    while(!a.empty())
    {
        cout<<a.front()<<" ";
        a.pop();
    }
    cout<<endl; 
    }
}// } Driver Code Ends


//function Template for C++

//Function to reverse the queue.

queue<int> rev(queue<int> q)
{
    stack<int> s;
    while(!q.empty()){
        s.push(q.front());
        q.pop();
    }
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
    return q;
}