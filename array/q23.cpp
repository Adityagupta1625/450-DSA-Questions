// Given an array of size n and a number k, find all elements that appear more than n/k times

// Given an array of size n, find all elements in array that appear more than n/k times.

//For example, if the input arrays is {3, 1, 2, 2, 1, 2, 3, 3} and k is 4, then the output should be [2, 3]. Note that size of array is 8 (or n = 8), so we need to find all elements that appear more than 2 (or 8/4) times. There are two elements that appear more than two times, 2 and 3.

#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;
void morethanNbyK(int arr[], int n, int k)
{
    int fr = n / k;
    unordered_map<int, int> s;
    for (int i = 0; i < n; i++)
    {
        /* code */
        s[arr[i]]++;
    }

    for (auto x : s)
    {
        if (x.second > fr)
        {
            /* code */
            cout << x.first << endl;
        }
    }
  
    
    
}
int main()
{
    int arr[] = {1, 1, 2, 2, 3, 5,
                 4, 2, 2, 3, 1, 1, 1,2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 4;

    morethanNbyK(arr, n, k);
    return 0;
}
