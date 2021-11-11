// AGGRCOW - Aggressive cows

// Farmer John has built a new long barn, with N (2 <= N <= 100,000) stalls. The stalls are located along a straight line at positions x1,...,xN (0 <= xi <= 1,000,000,000).

// His C (2 <= C <= N) cows don't like this barn layout and become aggressive towards each other once put into a stall. To prevent the cows from hurting each other, FJ wants to assign the cows to the stalls, such that the minimum distance between any two of them is as large as possible. What is the largest minimum distance?

// Input
// t – the number of test cases, then t test cases follows.
// * Line 1: Two space-separated integers: N and C
// * Lines 2..N+1: Line i+1 contains an integer stall location, xi

// Output
// For each test case output one integer: the largest minimum distance.

// Example
// Input:
// 1
// 5 3
// 1
// 2
// 8
// 4
// 9

// Output:
// 3

// Link:  https://www.spoj.com/problems/AGGRCOW/
#include <iostream>
#include <algorithm>
#define ll long long

using namespace std;

void solve()
{
    int n, c;
    cin >> n >> c;
    ll int l = INT32_MAX, h = 0;
    ll int arr[100000];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        l = min(arr[i], l);
        h = max(arr[i], h);
    }
    sort(arr, arr + n);
    int cnt=1;
    ll int prev = arr[0];
    int ans;
    while (l <= h)
    {
        int m = (l + h) / 2;
        cnt=1;
        prev=arr[0];
        
        for (int i = 1; i < n && c!=cnt; i++)
        {
            if (arr[i] - prev >= m)
            {
                cnt++;
                
                prev = arr[i];
            }
        }
        if (cnt==c)
        {
            l = m + 1;
            ans = m;
        }
        else
        {
            h = m - 1;
        }
    }
    cout << ans << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}