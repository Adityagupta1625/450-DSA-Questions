// Transform One String to Another using Minimum Number of Given Operation
// Given two strings A and B, the task is to convert A to B if possible. The only operation allowed is to put any character from A and insert it at front. Find if it’s possible to convert the string. If yes, then output minimum no. of operations required for transformation.

// Examples:

// Input:  A = "ABD", B = "BAD"
// Output: 1
// Explanation: Pick B and insert it at front.

// Input:  A = "EACBD", B = "EABCD"
// Output: 3
// Explanation: Pick B and insert at front, EACBD => BEACD
//              Pick A and insert at front, BEACD => ABECD
//              Pick E and insert at front, ABECD => EABCD

#include <iostream>
using namespace std;
int minOps(string a, string b)
{
    int n = a.length();
    int h1[256] = {0}, h2[256] = {0};
    for (int i = 0; i < n; i++)
    {
        h1[a[i]]++;
        h2[b[i]]++;
    }
    for (int i = 0; i < 256; i++)
    {
        if (h1[i] != h2[i])
            return -1;
    }

    int i = n - 1, j = n - 1, res = 0;
    while (i >= 0)
    {
        while (a[i] != b[j] && i >= 0)
        {
            i--;
            res++;
        }
        if (i >= 0)
        {
            i--;
            j--;
        }
    }
    return res;
}
int main()
{
    string A = "EACBD";
    string B = "EABCD";
    cout << "Minimum number of operations "
            "required is "
         << minOps(A, B);
    return 0;
}