#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    vector<int> arr = {1,5,1};
    int n = 3;
    int j = n - 1;
    while (arr[j] < arr[j - 1])
    {
        /* code */
        j--;
    }
    if (j==-1)
    {
        reverse(arr.begin(),arr.end());
        for (int i = 0; i < n; i++)
        {
            /* code */
            cout << arr[i] << " ";
        }
    }
    else{

        int idx = j;
        int prev=idx;
        for (int i = idx+1; i < n; i++)
        {
            if (arr[i] > arr[idx - 1] && arr[prev]>=arr[i])
            {
                prev=i;
            }
        }
        swap(arr[prev], arr[idx - 1]);
        reverse(arr.begin(),arr.end());
        for (int i = 0; i < n; i++)
        {
            /* code */
            cout << arr[i] << " ";
        }
        
    }

    return 0;
}