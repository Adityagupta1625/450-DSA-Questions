// 12 6
// 1 2 3 4 8 9 5 27 92 69 11 12
// 63 11 12 1 2 3
#include <bits/stdc++.h>
using namespace std;

string isSubset(int a1[], int a2[], int n, int m);

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int a1[n], a2[m];

        for (int i = 0; i < n; i++)
        {
            cin >> a1[i];
        }
        for (int i = 0; i < m; i++)
        {
            cin >> a2[i];
        }

        cout << isSubset(a1, a2, n, m) << endl;
    }
    return 0;
}
string isSubset(int a1[], int a2[], int n, int m)
{
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        if (max < a1[i])
        {
            max = a1[i];
        }
    }
    int h[max] = {0};
    for (int i = 0; i < n; i++)
    {
        h[a1[i]]++;
    }

    for (int i = 0; i < m; i++)
    {
        if (max < a2[i])
        {
            return "No";
        }
        if (h[a2[i]] == 0)
        {
            return "No";
        }
    }
    return "Yes";
}