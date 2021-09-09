// Find minimum number of merge operations to make an array palindrome

#include <iostream>
using namespace std;
int findMinOps(int arr[], int n)
{
    int i = 0, j = n - 1;
    int cnt = 0;
    while (i <= j)
    {
        if (arr[i] == arr[j])
        {
            /* code */
            i++;
            j--;
        }
        else if (arr[i] > arr[j])
        {
            /* code */
            arr[j - 1] = arr[j] + arr[j - 1];
            j--;
            cnt++;
        }
        else
        {
            arr[i + 1] = arr[i] + arr[i + 1];
            i++;
            cnt++;
        }
    }
    return cnt;
}
int main()
{
    int arr[] = {1, 4, 6, 9, 7, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Count of minimum operations is "
         << findMinOps(arr, n) << endl;
    return 0;
}