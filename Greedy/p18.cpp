#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
 
// function to find minimum elements needed.
int minElements(int arr[], int n)
{
    sort(arr,arr+n);
    int i=n-2,j=n-1;
    int len=1;
    int sum=0;
    for(int i=0;i<n-1;i++)
        sum+=arr[i];
    int newsum=arr[j];
    while(i>=0){
        if(sum>newsum){
            i--;
            j--;
            newsum+=arr[j];
            len++;
        }
        else{
            return len;
        }
    }
    return 0;
}
 
// Driver function
int main()
{
    int arr[] = {2, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << minElements(arr, n) << endl;
    return 0;
}