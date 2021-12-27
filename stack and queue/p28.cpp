// Given an array of both positive and negative integers, the task is to compute sum of minimum and maximum elements of all sub-array of size k.
// Examples: 
 

// Input : arr[] = {2, 5, -1, 7, -3, -1, -2}  
//         K = 4
// Output : 18
// Probelm Link: https://www.geeksforgeeks.org/sum-minimum-maximum-elements-subarrays-size-k/

#include <iostream>
#include <deque>
using namespace std;
int SumOfKsubArray(int arr[],int n,int k){
    deque <int> p,q;
    int sum=0;
    int i=0;
    for(i=0;i<k;i++){
        while(!p.empty() && arr[p.back()]>=arr[i])
            p.pop_back();
        while(!q.empty() && arr[q.back()]<=arr[i])
            q.pop_back();
        
        p.push_back(i);
        q.push_back(i);
        
    }
    for(;i<n;i++){
        sum+=(arr[q.front()]+arr[p.front()]);
        while(!p.empty() && p.front()<i-k+1)
            p.pop_front();
        while(!q.empty() && q.front()<i-k+1)
            q.pop_front();

        while(!p.empty() && arr[p.back()]>=arr[i])
            p.pop_back();
        while(!q.empty() && arr[q.back()]<=arr[i])
            q.pop_back();
           
        p.push_back(i);
        q.push_back(i);
    }
    sum+=(arr[q.front()]+arr[p.front()]);
    return sum;
}
int main()
{
    
    int arr[] = {2, 5, -1, 7, -3, -1, -2} ;
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 4;
    cout << SumOfKsubArray(arr, n, k) ;
    return 0;

    
}