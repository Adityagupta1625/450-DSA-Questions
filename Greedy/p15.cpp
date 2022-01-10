// Given an array, we need to find the maximum sum of absolute difference of any permutation of the given array.
// Examples: 
 

// Input : { 1, 2, 4, 8 }
// Output : 18
// Explanation : For the given array there are 
// several sequence possible
// like : {2, 1, 4, 8}
//        {4, 2, 1, 8} and some more.
// Now, the absolute difference of an array sequence will be
// like for this array sequence {1, 2, 4, 8}, the absolute
// difference sum is 
// = |1-2| + |2-4| + |4-8| + |8-1|
// = 14
// For the given array, we get the maximum value for
// the sequence {1, 8, 2, 4}
// = |1-8| + |8-2| + |2-4| + |4-1|
// = 18
// Probelm Link: https://www.geeksforgeeks.org/maximum-sum-absolute-difference-array/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
 
int MaxSumDifference(int a[], int n)
{
    sort(a,a+n);

    vector<int> v;
    int i=0,j=n-1;
    while(i<=j){
        if(i==j)
            v.push_back(a[i]);
        v.push_back(a[i]);
        v.push_back(a[j]);
        i++;
        j--;
    }
    
    int diff=0;
    for(int i=0;i<n-1;i++){
        diff+=abs(v[i+1]-v[i]);
    }
    diff+=abs(v[n-1]-v[0]);
    return diff;
}
 
// Driver function
int main()
{
    int a[] = { 1, 2, 4, 8,5 };
    int n = sizeof(a) / sizeof(a[0]);
 
    cout << MaxSumDifference(a, n) << endl;
}