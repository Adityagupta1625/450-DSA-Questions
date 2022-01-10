#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#define ll long long
using namespace std;
ll int findheight(vector<ll int> v, ll int mid)
{
    ll int diff = 0;
    for (ll int i = 0; i < v.size(); i++)
    {
        if (v[i] > mid)
        {
            diff += (v[i] - mid);
        }
    }
    return diff;
}
int main()
{
    ll int n, m;
    cin >> n >> m;
    vector<ll int> v;
    ll int maxi = INT_MIN;
    for (ll int i = 0; i < n; i++)
    {
        ll int x;
        cin >> x;
        v.push_back(x);
        maxi = max(maxi, x);
    }

    ll int lo = 0, hi = maxi;
    ll int mid;
    ll int ans = 0;
    while (lo <= hi)
    {
        mid = (lo + hi) / 2;
        ll int check = findheight(v, mid);

        if (check == m)
        {
            ans = mid;
            break;
        }
        else if (check > m)
        {
            ans=max(ans,mid);
            lo = mid + 1;
        }
        else
        {

            hi = mid - 1;
        }
    }
    cout << ans << endl;
    return 0;
}