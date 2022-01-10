#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// number of platforms and trains
#define n 2
#define m 5

// function to calculate maximum trains stoppage
int maxStop(int arr[][3])
{
    vector<pair<int, int>> v[n + 1];

    for (int i = 0; i < m; i++)
        v[arr[i][2]].push_back(
            make_pair(arr[i][1], arr[i][0]));

    for (int i = 0; i <=n; i++)
        sort(v[i].begin(), v[i].end());

   
    int total=0;
    for(int i=0;i<=n;i++){
        if(v[i].size()==0)
            continue;

        int cnt=1;
        int prev=v[i][0].first;
        for(int j=1;j<v[i].size();j++){
            if(prev<=v[i][j].second){
                cnt++;
                prev=v[i][j].first;
            }
        }
        total+=cnt;
    }
    return total;
}

// driver function
int main()
{
    int arr[m][3] = {1000, 1030, 1,
                     1010, 1020, 1,
                     1025, 1040, 1,
                     1130, 1145, 2,
                     1130, 1140, 2};
    cout << "Maximum Stopped Trains = "
         << maxStop(arr);
    return 0;
}