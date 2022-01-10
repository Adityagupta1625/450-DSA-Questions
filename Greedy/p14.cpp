// Given an array a, we have to find maximum product possible with the subset of elements present in the array. The maximum product can be single element also.
// Examples: 

// Input: a[] = { -1, -1, -2, 4, 3 }
// Output: 24
// Explanation : Maximum product will be ( -2 * -1 * 4 * 3 ) = 24

// Input: a[] = { -1, 0 }
// Output: 0
// Explanation: 0(single element) is maximum product possible
 
// Input: a[] = { 0, 0, 0 }
// Output: 0
// Probelm Link: https://www.geeksforgeeks.org/maximum-product-subset-array/
#include <iostream>
#include <algorithm>
using namespace std;
 
int maxProductSubset(int a[], int n)
{
   if(n==1)
        return a[0];

   int prod=1;
   int count_neg=0,count_zero=0;
   int max_neg=INT_MIN;
   for(int i=0;i<n;i++){
       if(a[i]==0){
        count_zero++;
        continue;
       }
       
       if(a[i]<0){
           count_neg++;
           max_neg=max(a[i],max_neg);
       }
       prod=prod*a[i];
   }
   if(count_zero==n)
        return 0;
   if(count_neg%2!=0){
       if(count_neg==1 && count_zero>0 && count_neg+count_zero==n)
            return 0;
       else
         prod=prod/max_neg;
   }
   return prod;

}
 
// Driver Code
int main()
{
    int a[] = {  0, 0  };
    int n = sizeof(a) / sizeof(a[0]);
    cout << maxProductSubset(a, n);
    return 0;
}