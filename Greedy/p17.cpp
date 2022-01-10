// In operating systems that use paging for memory management, page replacement algorithm is needed to decide which page needs to be replaced when the new page comes in. Whenever a new page is referred and is not present in memory, the page fault occurs and Operating System replaces one of the existing pages with a newly needed page.

// Given a sequence of pages in an array pages[] of length N and memory capacity C, find the number of page faults using Least Recently Used (LRU) Algorithm. 

// Example 1:

// Input: N = 9, C = 4
// pages = {5, 0, 1, 3, 2, 4, 1, 0, 5}
// Output: 8
// Explaination: memory allocated with 4 pages 5, 0, 1, 
// 3: page fault = 4
// page number 2 is required, replaces LRU 5: 
// page fault = 4+1 = 5
// page number 4 is required, replaces LRU 0: 
// page fault = 5 + 1 = 6
// page number 1 is required which is already present: 
// page fault = 6 + 0 = 6
// page number 0 is required which replaces LRU 1: 
// page fault = 6 + 1 = 7
// page number 5 is required which replaces LRU 3: 
// page fault = 7 + 1  =8.
// Probelm Link: https://practice.geeksforgeeks.org/problems/page-faults-in-lru5603/1#
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int pageFaults(int N, int C, int pages[]){
        // code here
        vector<int> v;
       
        int faults=0;
        
        for(int i=0;i<N;i++){
            auto it=find(v.begin(),v.end(),pages[i]);
            if(it==v.end()){
                if(v.size()==C){
                    v.erase(v.begin());
                }
                v.push_back(pages[i]);
                faults++;
            }
            else{
                v.erase(it);
                v.push_back(pages[i]);
            }
        }
        return faults;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, C;
        cin>>N;
        int pages[N];
        for(int i = 0;i < N;i++)
            cin>>pages[i];
        cin>>C;
        
        Solution ob;
        cout<<ob.pageFaults(N, C, pages)<<"\n";
    }
    return 0;
} 