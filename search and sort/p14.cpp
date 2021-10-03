// Write a C function to return minimum and maximum in an array. Your program should make the minimum number of comparisons. 

// Probelm link: https://www.geeksforgeeks.org/maximum-and-minimum-in-an-array/
#include <iostream>
#include <algorithm>
using namespace std;
// Structure is used to return
// two values from minMax()
struct Pair
{
    int min;
    int max;
};
// Approach 1:
struct Pair getMinMax1(int arr[], int l, int h)
{
    struct Pair p, mmr, mml;
    int mid;
    if (l == h)
    {
        p.min = arr[l];
        p.max = arr[l];
        return p;
    }
    if (h == l + 1)
    {
        p.max = max(arr[l], arr[h]);
        p.min = min(arr[l], arr[h]);
        return p;
    }
    mid = (l + h) / 2;
    mml = getMinMax1(arr, l, mid);
    mmr = getMinMax1(arr, mid + 1, h);

    p.min = min(mml.min, mmr.min);
    p.max = max(mml.max, mmr.max);

    return p;
}

// Approach 2:
struct Pair getMinMax2(int arr[], int n)
{
    struct Pair p;
    int i;
    if (n%2==0)
    {
        p.min=min(arr[0],arr[1]);
        p.max=max(arr[0],arr[1]);
        i=2;
    }
    else{
        p.min=arr[0];
        p.max=arr[0];
        i=1;
    }
    while (i<n-1)
    {
        p.min=min(min(arr[i],arr[i+1]),p.min);
        p.max=max(max(arr[i],arr[i+1]),p.max);
        i=i+2;
    }
    
    return p;
}
int main()
{
    int arr[] = {1000, 11, 445,
                 1, 3000};
    int arr_size = 6;

    Pair minmax = getMinMax1(arr, 0, arr_size - 1);
    Pair minmax = getMinMax2(arr,arr_size);

    cout << "nMinimum element is "
         << minmax.min << endl;
    cout << "nMaximum element is "
         << minmax.max;

    return 0;
}