// To find the duplicate element in an array

// link for the question: https://leetcode.com/problems/find-the-duplicate-number/

#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int arr[]={3,1,3,4,2};
    int n=5;
    sort(arr,arr+n);
    for (int i = 0; i < n; i++)
    {
        if (arr[i]==arr[i+1])
        {
            cout<< arr[i]<<endl;
            break;
        }
        
    }
    
    return 0;
}