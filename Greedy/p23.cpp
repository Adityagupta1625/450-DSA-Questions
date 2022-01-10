// Theodore implements a new strategy game “Defense of a Kingdom”. On each level a player defends the Kingdom that is represented by a rectangular grid of cells. The player builds crossbow towers in some cells of the grid. The tower defends all the cells in the same row and the same column. No two towers share a row or a column.

// The penalty of the position is the number of cells in the largest undefended rectangle. For example, the position shown on the picture has penalty 12.
// Input:
// 1
// 15 8 3
// 3 8
// 11 2
// 8 6

// Output:
// 12
// Probelm Link: https://www.spoj.com/problems/DEFKIN/
#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
using namespace std;
void solve()
{
    int w, h, n;
    cin >> w >> h >> n;
    vector<int> v_h;
    vector<int> v_w;
    v_h.push_back(0);
    v_w.push_back(0);
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        
        v_w.push_back(x);
        v_h.push_back(y);
    }
    v_w.push_back(w+1);
    v_h.push_back(h+1);
    sort(v_w.begin(), v_w.end());
    sort(v_h.begin(), v_h.end());
    int max_w = 0, max_h = 0;

    for (int i = 0; i < v_w.size()-1; i++)
    {
        max_w = max(max_w, (v_w[i + 1] - v_w[i]-1));
        max_h = max(max_h, (v_h[i + 1] - v_h[i]-1));
    }
    cout<<max_h*max_w<<endl;
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