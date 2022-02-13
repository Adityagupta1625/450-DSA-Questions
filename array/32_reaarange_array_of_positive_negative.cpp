// Rearrange array in alternating positive & negative items with O(1) extra space
 
// Given an array of positive and negative numbers, arrange them in an alternate fashion such that every positive number is followed by negative and vice-versa maintaining the order of appearance. 
// Number of positive and negative numbers need not be equal. If there are more positive numbers they appear at the end of the array. If there are more negative numbers, they too appear in the end of the array.

// Examples : 

// Input:  arr[] = {1, 2, 3, -4, -1, 4}
// Output: arr[] = {-4, 1, -1, 2, 3, 4}

// Input:  arr[] = {-5, -2, 5, 2, 4, 7, 1, 8, 0, -8}
// output: arr[] = {-5, 5, -2, 2, -8, 4, 7, 1, 8, 0}
#include <iostream>
#include <algorithm>
using namespace std;
void reaarange(int arr[], int n)
{
    sort(arr, arr + n);
    int cnt_pos = 0, cnt_neg = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= 0)
        {
            cnt_pos++;
        }
        else if (arr[i] < 0)
        {
            cnt_neg++;
        }
    }
    int j;
    if (cnt_pos >= cnt_neg)
    {

        for (int i = 1; i <= cnt_neg; i++)
        {

            if (arr[i] < 0)
            {

                if (i % 2 != 0 && cnt_neg % 2 != 0)
                {

                    swap(arr[i + cnt_neg], arr[i]);
                }
                else if (i % 2 != 0 && cnt_neg % 2 == 0)
                {

                    swap(arr[i + cnt_neg - 1], arr[i]);
                }
            }
        }
    }
    else
    {
        reverse(arr, arr + n);
        for (int i = 1; i <= cnt_pos; i++)
        {

            if (arr[i] > 0)
            {

                if (i % 2 != 0 && cnt_pos % 2 != 0)
                {

                    swap(arr[i + cnt_pos], arr[i]);
                }
                else if (i % 2 != 0 && cnt_pos % 2 == 0)
                {

                    swap(arr[i + cnt_pos - 1], arr[i]);
                }
            }
        }
    }
}
void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
void efficientreaarange(int arr[], int n)
{
}
int main()
{
    int arr[] = {-5, 3, -2, 5, -6, 4, -4, -9, -1, 8};
    int n = 10;
    int i = 0, j = n - 1;
    while (i <= j)
    {
        if (arr[i] <= 0)
        {
            i++;
        }
        else
        {
            swap(arr[i], arr[j]);
            j--;
        }
    }
    int cnt_pos = 0, cnt_neg = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= 0)
        {
            cnt_pos++;
        }
        else
        {
            cnt_neg++;
        }
    }
    int p = 1, q = n - 1;
    if (cnt_pos >= cnt_neg)
    {
        int j = 1;
        while (cnt_neg--)
        {
            if (arr[j] < 0)
            {
                swap(arr[j], arr[j + cnt_neg]);
                j = j + 2;
            }
        }
    }
    else
    {
        reverse(arr,arr+n);
        int j = 1;
        while (cnt_pos--)
        {
            if (arr[j] > 0)
            {
                swap(arr[j], arr[j + cnt_pos]);
                j = j + 2;
            }
        }
    }
    print(arr,n);
    return 0;
}