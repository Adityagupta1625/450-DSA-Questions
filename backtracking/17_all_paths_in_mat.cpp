#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

// Approach 1: Backtracking
// void display(vector<int> path)
// {

//     for (auto x : path)
//         cout << x << " ";
//     cout << endl;
// }
// bool isSafe(int i, int j, vector<vector<int>> vis, int n, int m)
// {
//     if (i >= 0 && i < n && j >= 0 && j < m && vis[i][j] == 0)
//         return true;
//     return false;
// }
// void helper(vector<vector<int>> maze, int n, int m,  int i, int j, vector<vector<int>> visited, vector<int> path)
// {
//     if (i == n - 1 && j == m - 1)
//     {
//         path.push_back(maze[i][j]);
//         display(path);
//         return;
//     }

//     visited[i][j] = 1;
//     int x = maze[i][j];
//     path.push_back(x);

//     if (isSafe(i + 1, j, visited, n, m))
//         helper(maze, n, m,i + 1, j, visited, path);

//     if (isSafe(i, j + 1, visited, n, m))
//         helper(maze, n, m, i, j + 1, visited, path);

//     visited[i][j] = 0;
//     path.pop_back();
// }
// void findPaths(vector<vector<int>> maze, int n, int m)
// {
//     vector<vector<int>> visited(n);
//     vector<int> path;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             visited[i].push_back(0);
//         }
//     }

//     helper(maze, n, m,0, 0, visited, path);
// }

// Approach 2: BFS
struct ele
{
    int i;
    int j;
    vector<int> path;
};
void findPaths(vector<vector<int>> maze, int n, int m)
{
    queue<ele> q;
    vector<int> v;
    v.push_back(maze[0][0]);
    q.push({0, 0, v});

    while (!q.empty())
    {
        int i = q.front().i;
        int j = q.front().j;
        vector<int> p = q.front().path;
        q.pop();

        if (i == n - 1 && j == m - 1)
        {
            for (auto x : p)
            {
                cout << x << " ";
            }
            cout << endl;
        }
        else if (i == n - 1)
        {
            p.push_back(maze[i][j + 1]);

            q.push({i, j + 1, p});
        }
        else if (j == m - 1)
        {
            p.push_back(maze[i + 1][j]);

            q.push({i + 1, j, p});
        }
        else{
            p.push_back(maze[i][j + 1]);

            q.push({i, j + 1, p});

            p.pop_back();
            
            p.push_back(maze[i + 1][j]);

            q.push({i + 1, j, p});
        }
    }
}
// Driver Code
int main()
{
    vector<vector<int>> maze = {{1, 2, 3},
                                {4, 5, 6},
                                {7, 8, 9}};
    findPaths(maze, 3, 3);

    // {{1, 2, 3},
    // {4, 5, 6},
    // {7, 8, 9}};
    // print(allPaths)
    return 0;
}
