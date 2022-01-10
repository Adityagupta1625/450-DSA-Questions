// Program for Shortest Job First (or SJF) CPU Scheduling | Set 1 (Non- preemptive)

// Probelm link: https://www.geeksforgeeks.org/program-for-shortest-job-first-or-sjf-cpu-scheduling-set-1-non-preemptive/?ref=lbp
#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <queue>
using namespace std;

// priority while sorting: arrival time, burst time, id
bool comp(vector<int> a, vector<int> b)
{
    if (a[1] == b[1])
    {
        if (a[2] == b[2])
            return a[0] < b[0];
        else
            return a[2] < b[2];
    }
    return a[1] < b[1];
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> v(n);

    // insert the data: id, arrival time, burst time
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            int x;
            cin >> x;
            v[i].push_back(x);
        }
    }
    sort(v.begin(), v.end(), comp);
    vector<int> ans;

    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

    pq.push({v[0][2], v[0][1], v[0][0]});

    int i = 1, curr_time = 0;
    while (!pq.empty())
    {
        int burst_time = pq.top()[0];
        int id = pq.top()[2];
        pq.pop();

        curr_time += burst_time;
        ans.push_back(id);
        while (1)
        {
            if (i < n && v[i][1] <= curr_time)
            {
                pq.push({v[i][2], v[i][1], v[i][0]});
                i++;
            }
            else
                break;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " " << endl;
    }
}