#include <iostream>
#include <algorithm>
using namespace std;
int search(int arr[],int n,int x,int k){
    int i=0;
    while(i<n){
        if(arr[i]==x)
            return i;
        else{
            int diff=x-arr[i];
            i=i+max(1,diff/k);
        }
    }
    return -1;
}
int main()
{
    int arr[] = {2, 4, 5, 7, 7, 6};
    int x = 6;
    int k = 2;
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Element " << x << " is present at index "
         << search(arr, n, x, k);
    return 0;
}
