// Given an array A of N elements. Find the majority element in the array. A majority element in an array A of size N is an element that appears more than N/2 times in the array.
 

// Example 1:

// Input:
// N = 3 
// A[] = {1,2,3} 
// Output:
// -1
// Explanation:
// Since, each element in 
// {1,2,3} appears only once so there 
// is no majority element.
// Probelm link: https://practice.geeksforgeeks.org/problems/majority-element-1587115620/1#
#include <stdio.h>
#include <stdbool.h>


 // } Driver Code Ends
//User function Template for C

// Function to find majority element in the array
// a: input array
// size: size of input array
int majorityElement(int arr[], int n)
{
        
    // your code here
    int cnt=1;
    int maj_index=0;
    if(n==1){
        return arr[0];
    }
    for(int i=1;i<n;i++){
        if(arr[maj_index]==arr[i])
            cnt++;
        else
            cnt--;
        if(cnt==0){
            maj_index=i;
            cnt=1;
        }
    }
    int c=0;
    for(int i=0;i<n;i++){
        if(arr[i]==arr[maj_index])
            c++;
    }
    if(c>n/2)
        return arr[maj_index];
    else
        return -1;
}

// { Driver Code Starts.

int main(){

    int t;
    scanf("%d", &t);

    while(t--){
        int n;
        scanf("%d", &n);
        int arr[n];
        
        for(int i = 0;i<n;i++){
            scanf("%d", &arr[i]);
        }
        printf("%d\n", majorityElement(arr, n));
    }

    return 0;
}