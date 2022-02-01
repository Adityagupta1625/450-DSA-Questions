#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define R 12
#define C 10

bool isValid(int mat[R][C], int i, int j)
{
    if (i >= 0 && i < R && j >= 0 && j < C)
        return true;
    return false;
}
void markunsafe(int mat[R][C])
{
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (mat[i][j] == 0)
            {
                if (isValid(mat, i - 1, j))
                    mat[i - 1][j] = -1;
                if (isValid(mat, i + 1, j))
                    mat[i + 1][j] = -1;
                if (isValid(mat, i, j - 1))
                    mat[i][j - 1] = -1;
                if (isValid(mat, i, j + 1))
                    mat[i][j + 1] = -1;
            }
        }
    }
}
bool isSafe(int mat[R][C], int i, int j, int visited[R][C])
{
    if (i < R && j < C && i >= 0 && j >= 0 &&
        mat[i][j] == 1 && visited[i][j] == 0)
        return true;
    return false;
}
void helper(int mat[R][C], int visited[R][C], int dis, int &min_dis, int row, int col)
{
    if (col == C - 1)
    {
        min_dis = min(dis, min_dis);
        return;
    }

    if (dis > min_dis)
        return;

    visited[row][col] = 1;
    // down
    if (isSafe(mat, row + 1, col, visited))
    {
        helper(mat, visited, dis + 1, min_dis, row + 1, col);
    }

    // up
    if (isSafe(mat, row - 1, col, visited))
    {
        helper(mat, visited, dis + 1, min_dis, row - 1, col);
    }

    // left
    if (isSafe(mat, row, col - 1, visited))
    {

        helper(mat, visited, dis + 1, min_dis, row, col - 1);
    }

    // right
    if (isSafe(mat, row, col + 1, visited))
    {

        helper(mat, visited, dis + 1, min_dis, row, col + 1);
    }
    visited[row][col] = 0;
}
void findShortestPath(int mat[R][C])
{
    markunsafe(mat);

    int visited[R][C];
    int path = 0;
    int min_dis = INT_MAX;
    for (int i = 0; i < R; i++)
    {
        if (mat[i][0] == 1)
        {
            int col = 0;
            for (int i = 0; i < R; i++)
            {
                for (int j = 0; j < C; j++)
                {
                    visited[i][j] = 0;
                }
            }
            helper(mat, visited, path, min_dis, i, col);
        }
    }
    cout << min_dis << endl;
}

// Driver code
int main()
{
    // input matrix with landmines shown with number 0
    int mat[R][C] =
        {
            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
            {1, 0, 1, 1, 1, 1, 1, 1, 1, 1},
            {1, 1, 1, 0, 1, 1, 1, 1, 1, 1},
            {1, 1, 1, 1, 0, 1, 1, 1, 1, 1},
            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
            {1, 1, 1, 1, 1, 0, 1, 1, 1, 1},
            {1, 0, 1, 1, 1, 1, 1, 1, 0, 1},
            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
            {0, 1, 1, 1, 1, 0, 1, 1, 1, 1},
            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
            {1, 1, 1, 0, 1, 1, 1, 1, 1, 1}};

    // find shortest path
    findShortestPath(mat);

    return 0;
}