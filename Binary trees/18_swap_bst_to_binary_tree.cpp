// Given the array representation of Complete Binary Tree i.e, if index i is the parent, index 2*i + 1 is the left child and index 2*i + 2 is the right child. The task is to find the minimum number of swap required to convert it into Binary Search Tree.

// Examples:  

// Input : arr[] = { 5, 6, 7, 8, 9, 10, 11 }
// Output : 3
// Probelm Link: https://www.geeksforgeeks.org/minimum-swap-required-convert-binary-tree-binary-search-tree/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void inorder(int a[], vector<int> &v,
             int n, int index)
{
    if (index >= n)
        return;

    inorder(a, v, n, 2 * index + 1);
    v.push_back(a[index]);
    inorder(a, v, n, 2 * index + 2);
}

// Function to find minimum swaps to sort an array
int minSwaps(vector<int> &v)
{

    int swaps = 0;
    vector<pair<int, int>> temp;
    for (int i = 0; i < v.size(); i++)
    {
        temp.push_back({v[i], i});
    }
    sort(temp.begin(), temp.end());
    for (int i = 0; i < temp.size(); i++)
    {
        if (i == temp[i].second)
            continue;
        else
        {
            int ind = temp[i].second;
            swap(temp[i].first, temp[ind].first);
            swap(temp[i].second, temp[ind].second);
            --i;
            swaps++;
        }
    }

    return swaps;
}

// Driver code
int main()
{
    int a[] = {5, 6, 7, 8, 9, 10, 11};
    int n = sizeof(a) / sizeof(a[0]);
    vector<int> v;
    inorder(a, v, n, 0);
    cout << minSwaps(v) << endl;
}