// A pivot Element in rotated srted array
//Link: http://theoryofprogramming.com/2017/12/16/find-pivot-element-sorted-rotated-array/
#include <iostream>
using namespace std;
int pivotElement(int arr[],int l,int h){
    while (l<=h)
    {
        int m=(l+h)/2;
        if(arr[m]>arr[m-1] && arr[m]>arr[m+1])
            return arr[m];
        
        else if(arr[m]>arr[h])

            l=m+1;
        else
            h=m-1;
    }
    return -1;
}
int main()
{
    int arr[]={73,85,94,21,23,34,47,54,66};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<pivotElement(arr,0,n-1);
    return 0;
}