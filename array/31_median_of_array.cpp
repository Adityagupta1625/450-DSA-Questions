#include <iostream>
using namespace std;
int median(int arr[],int n){
    if (n%2==0)
    {
        /* code */
        return (arr[n/2-1]+arr[n/2])/2;
    }
    else{
        return arr[n/2];
    }
}
int main()
{
    int arr1[]={1,12,15,26,38};
    int arr2[]={2,13,17,30,45};
    int m1=median(arr1,5);
    int m2=median(arr2,5);
    return 0;
}