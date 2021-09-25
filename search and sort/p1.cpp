// Given a sorted array arr containing n elements with possibly duplicate elements, the task is to find indexes of first and last occurrences of an element x in the given array.

// Example 1:

// Input:
// n=9, x=5
// arr[] = { 1, 3, 5, 5, 5, 5, 67, 123, 125 }
// Output:  2 5
// Explanation: First occurrence of 5 is at index 2 and last
//              occurrence of 5 is at index 5.
// Probelm link: https://practice.geeksforgeeks.org/problems/first-and-last-occurrences-of-x3116/1#

#include<bits/stdc++.h>
using namespace std;
vector<int> find(int a[], int n , int x );

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}


// } Driver Code Ends


vector<int> find(int arr[], int n , int x )
{
    // code here
    int l=0,h=n-1;
    int m;
    vector <int> a;
    while(l<=h){
        m=(l+h)/2;
        if(arr[m]==x)
            break;
        else if(arr[m]<x)
            l=m+1;
        else
            h=m-1;
    }
    if(l>h){
        a.push_back(-1);
        a.push_back(-1);
    }
    int i=m,j=m;
    while(i>=0 && arr[m]==arr[i])
        i--;
    while(j>=0 && arr[m]==arr[j])
        j++;
    
    a.push_back(i+1);
    a.push_back(j-1);
    return a;
}