// Reverse the array

#include <iostream>
using namespace std;
int main()
{
    int arr[7]={1,2,5,6,8,9,10};
    int n=7;
    for (int i = 0; i<=n/2; i++)
    {
        int temp=arr[i];
        arr[i]=arr[n-i-1];
        arr[n-i-1]=temp;
    }
    cout<<"Reversed Array: "<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    return 0;
}