// Given an array of N integers arr[] where each element represents the max number of steps that can be made forward from that element. Find the minimum number of jumps to reach the end of the array (starting from the first element). If an element is 0, then you cannot move through that element.

// Note: Return -1 if you can't reach the end of the array.

// Input:
// N = 11 
// arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9} 

// Output: 3 

// Explanation: 
// First jump from 1st element to 2nd 
// element with value 3. Now, from here 
// we jump to 5th element with value 9, 
// and from here we will jump to last. 

// Link for the question: https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps-1587115620/1#

#include <iostream>
#include <algorithm>
using namespace std;
class Solution{
  public:
    int minJumps(int arr[], int n){
       int jump=1;
       int step=arr[0];
       int maxreach=arr[0];
       if(arr[0]==0){
           return -1;
       }
       for(int i=1;i<n;i++){
           
          if(i==n-1){
              return jump;
          }
          maxreach=max(maxreach,i+arr[i]);
          step--;
           
           if(step==0){
               jump++;
               if(i>=maxreach){
                   return -1;
               }
               step=maxreach-i;
               
               
           }
        
           
       }
       return jump;
    }
};
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[100000];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}