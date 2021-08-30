// Given an array, rotate the array by one position in clock-wise direction.
 
// Example 1:

// Input:
// N = 5
// A[] = {1, 2, 3, 4, 5}

// Output:
// 5 1 2 3 4

// link for the question: 
// https://practice.geeksforgeeks.org/problems/cyclically-rotate-an-array-by-one2614/1

#include <stdio.h>
using namespace std;
void rotate(int arr[], int n){
    int x=arr[n-1];
    for (int i = n-1; i>=0; i--)
    {
        arr[i+1]=arr[i];
    }
    arr[0]=x;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int a[100000] , i;
        for(i=0;i<n;i++)
        scanf("%d",&a[i]);
        rotate(a, n);
        for (i = 0; i < n; i++){
            printf("%d ", a[i]);

        }
        printf("\n");
    }
        return 0;
}