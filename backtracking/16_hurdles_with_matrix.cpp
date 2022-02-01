#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define R 3
#define C 10

bool isSafe(int mat[R][C], int i, int j, int visited[R][C])
{
    if (mat[i][j] == 1 && visited[i][j] == 0 && (i >= 0 && i < R) && (j >= 0 && j < C))
        return true;
    return false;
}
pair<int, int> helper(int mat[R][C], int i, int j, int desx, int desy, int visited[R][C])
{
    if (i == desx && j == desy)
    {
        return {1, 0};
    }
    if(!isSafe(mat,i,j,visited))
        return {0,INT_MAX};

    visited[i][j] = 1;
    int res = INT_MIN;
    pair<int, int> p;

    p = helper(mat, i + 1, j, desx, desy, visited);
    if (p.first == 1)
        res = max(res, p.second);

    p = helper(mat, i - 1, j, desx, desy, visited);

    if (p.first == 1)
        res = max(res, p.second);

    p = helper(mat, i, j + 1, desx, desy, visited);

    if (p.first == 1)
        res = max(res, p.second);

    p = helper(mat, i, j - 1, desx, desy, visited);

    if (p.first == 1)
        res = max(res, p.second);

    visited[i][j] = 0;
    if (res != INT_MIN)
    {
        return {1, res + 1};
    }
    else
    {
        return {0, INT_MAX};
    }
}
void findLongestPath(int mat[R][C], int i, int j, int desx, int desy)
{
    int visited[R][C];

    memset(visited, false, sizeof(visited));

    int maxlen = INT_MIN;
    pair<int,int> p=helper(mat, 0, 0, 1, 7, visited);
    cout<<p.second<<endl;
}

int main()
{
    // input matrix with hurdles shown with number 0
    int mat[R][C] = {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                     {1, 1, 0, 1, 1, 0, 1, 1, 0, 1},
                     {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

    // find longest path with source (0, 0) and
    // destination (1, 7)
    findLongestPath(mat, 0, 0, 1, 7);

    return 0;
}