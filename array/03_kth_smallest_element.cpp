// Given an array arr[] and an integer K where K is smaller than size of array, the task is to find the Kth smallest element in the given array. It is given that all array elements are distinct.

// Example 1:

// Input:
// N = 6
// arr[] = 7 10 4 3 20 15
// K = 3
// Output : 7

// Explanation :
// 3rd smallest element in the given 
// array is 7.

//question link: https://practice.geeksforgeeks.org/problems/kth-smallest-element5635/1#

#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int randompartiton(int arr[],int l,int r){
        int n=r-l+1;
        int pivot=rand()%n;
        swap(arr[l+pivot],arr[r]);
        return partition(arr,l,r);
    }
    int partition(int arr[], int l, int r)
        {
            int x = arr[r];
            int j = l;
            int i;
            for (i = l; i <= r - 1; i++)
            {
                if (x >= arr[i])
                {
                    /* code */
                    swap(arr[i], arr[j]);
                    j++;
                }
            }
            swap(arr[j], arr[r]);
            return j;
        }
    int kthSmallest(int arr[], int l, int r, int k)
        {
            if (k > 0 && k <= r - l + 1)
            {
                /* code */
                int index = randompartiton(arr, l, r);
                if (index-l == k-1)
                {
                    return arr[index];
                }
                if (index-l > k-1)
                {
                    return  kthSmallest(arr, l, index - 1, k);
                }
        
                return  kthSmallest(arr, index + 1, r, k - index +l - 1);
            }
            return INT_MAX;
        }
};

// { Driver Code Starts.
 
int main()
{
    int test_case;
    cin>>test_case;
    while(test_case--)
    {
        int number_of_elements;
        cin>>number_of_elements;
        int a[number_of_elements];
        
        for(int i=0;i<number_of_elements;i++)
            cin>>a[i];
            
        int k;
        cin>>k;
        Solution ob;
        cout<<ob.kthSmallest(a, 0, number_of_elements-1, k)<<endl;
    }
    return 0;
}