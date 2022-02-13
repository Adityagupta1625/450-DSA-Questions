#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
typedef pair<int, int> pli;

void printpath(map<pli, pli> mp, pli u)
{
    if (u.first == 0 && u.second == 0)
    {
        cout << 0 << " " << 0 << endl;
        return;
    }
    printpath(mp, mp[u]);
    cout << u.first << " " << u.second << endl;
}
void BFS(int a, int b, int target)
{
    queue<pli> q;
    map<pli,int> m;
    map<pli,pli> mp;

    q.push({0, 0});

    while (!q.empty())
    {
        pli u = q.front();
        q.pop();
        if (u.first == target || u.second == target)
        {
            printpath(mp, u);
            if(u.first==target){
                if(u.second!=0){
                    cout<<u.first<<" "<<0<<endl;
                }
            }
            else{
                if(u.first!=0){
                    cout<<0<<" "<<u.second<<endl;
                }
            }
            return;
        }
        if (u.first < 0 || u.second > b || u.first > a || u.second < 0)
            continue;

        if (m[u] == 1)
            continue;
        m[u]=1;
        if (m[{u.first, b}] != 1)
        {
            mp[{u.first, b}] = u;
            q.push({u.first, b});
        }

        if (m[{a,u.second}] != 1)
        {
            mp[{a, u.second}] = u;
            q.push({a, u.second});
        }

        int d=b-u.second;
        if(u.first>=d){
            if(m[{u.first-d,u.second+d}]!=1){
                mp[{u.first-d,u.second+d}]=u;
                q.push({u.first-d,u.second+d});
            }
        }
        else{
            if(m[{0,u.second+u.first}]!=1){
                mp[{0,u.second+u.first}]=u;
                q.push({0,u.second+u.first});
            }
        }

        d=b-u.first;
        if(u.second>=d){
            if(m[{u.first+d,u.second-d}]!=1){
                mp[{u.first+d,u.second-d}]=u;
                q.push({u.first+d,u.second-d});
            }
        }
        else{
            if(m[{u.second+u.first,0}]!=1){
                mp[{u.second+u.first,0}]=u;
                q.push({u.second+u.first,0});
            }
        }

        if(m[{u.first,0}]!=1){
            mp[{u.first,0}]=u;
            q.push({u.first,0});
        }

        if(m[{0,u.second}]!=1){
            mp[{0,u.second}]=u;
            q.push({0,u.second});
        }
        

    }
}

int main()
{
    int Jug1 = 5, Jug2 = 7, target = 3;
    cout << "Path from initial state "
            "to solution state ::\n";
    BFS(Jug1, Jug2, target);
    return 0;
}