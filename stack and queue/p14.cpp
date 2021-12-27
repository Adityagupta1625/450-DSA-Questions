// Given an integer K and a queue of integers, we need to reverse the order of the first K elements of the queue, leaving the other elements in the same relative order.

// Only following standard operations are allowed on queue.

// enqueue(x) : Add an item x to rear of queue
// dequeue() : Remove an item from front of queue
// size() : Returns number of elements in queue.
// front() : Finds front item.
// Example 1:

// Input:
// 5 3
// 1 2 3 4 5

// Output: 
// 3 2 1 4 5
// Probelm Link: https://practice.geeksforgeeks.org/problems/reverse-first-k-elements-of-queue/1#

#include <bits/stdc++.h>
using namespace std;
queue<int> modifyQueue(queue<int> q, int k);
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n, k;
        cin >> n >> k;
        queue<int> q;
        while (n-- > 0) {
            int a;
            cin >> a;
            q.push(a);
        }
        queue<int> ans = modifyQueue(q, k);
        while (!ans.empty()) {
            int a = ans.front();
            ans.pop();
            cout << a << " ";
        }
        cout << endl;
    }
}// } Driver Code Ends


// User function Template for C++

// Function to reverse first k elements of a queue.
queue<int> modifyQueue(queue<int> q, int k) {
    // add code here.
    stack<int> s;
    int i=0;
    while(i<k){
        s.push(q.front());
        q.pop();
        i++;
    }
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
    i=k;
    while(i<q.size()){
        int t=q.front();
        q.push(t);
        q.pop();
        i++;
    }
    return q;
  