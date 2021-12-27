// Given an array, print the Next Smaller Element (NSE) for every element. The NSE for an element x is the first smaller element on the right side of x in array. Elements for which no smaller element exist (on right side), consider NSE as -1. 
// Examples: 
// a) For any array, rightmost element always has NSE as -1. 
// b) For an array which is sorted in increasing order, all elements have NSE as -1. 
// c) For the input array [4, 8, 5, 2, 25}, the NSE for each element are as follows.

// Element         NSE
//    4      -->    2
//    8      -->    5
//    5      -->    2
//    2      -->   -1
//    25     -->   -1

// Probelm Link: https://www.geeksforgeeks.org/next-smaller-element/
#include <iostream>
#include <stack>
using namespace std;
 
// prints NSE for elements of array arr[] of size n
 
void printNSE(int arr[], int n)
{
    stack<pair<int,int>> s;
    s.push({arr[0],0});
    int *ans=new int[n];
    for(int i=1;i<n;i++){
        while(!s.empty()){
            if(s.top().first>arr[i]){
                ans[s.top().second]=arr[i];
                s.pop();
            }
            else{
                break;
            }
        }
        s.push({arr[i],i});
    }
    while(!s.empty()){
        ans[s.top().second]=-1;
        s.pop();
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<"----->"<<ans[i]<<endl;
    }
}
 
// Driver program to test above functions
int main()
{
    int arr[] = { 4, 8, 5, 2, 25};
    int n = sizeof(arr) / sizeof(arr[0]);
    printNSE(arr, n);
    return 0;
}