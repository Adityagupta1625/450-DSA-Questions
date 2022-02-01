#include <iostream>
#include <iomanip>
using namespace std;

#define N 8

bool isSafe(int grid[N][N], int i, int j)
{
    if (i >= 0 && i < N && j >= 0 && j < N && grid[i][j] == -1)
        return true;
    return false;
}
void printSolution(int sol[N][N])
{
    for (int x = 0; x < N; x++)
    {
        for (int y = 0; y < N; y++)
            cout << " " << setw(2) << sol[x][y] << " ";
        cout << endl;
    }
}
int helper(int grid[N][N], int row, int col, int x[], int y[], int moves)
{
    if (moves == N * N)
        return 1;
    for (int i = 0; i < 8; i++)
    {
        int next_x = row + x[i];
        int next_y = col + y[i];
        if (isSafe(grid, next_x, next_y))
        {
     
            grid[next_x][next_y] = moves;
            if (helper(grid, next_x, next_y, x, y, moves + 1) == 1)
            {
                return 1;
            }
            else
            {
                grid[next_x][next_y] = -1;
            }
        }
    }
    return 0;
}
void solveKT()
{
    int grid[N][N];

    int x[] = { 2, 1, -1, -2, -2, -1, 1, 2 };
    int y[] = { 1, 2, 2, 1, -1, -2, -2, -1 };

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            grid[i][j] = -1;
        }
    }
    grid[0][0] = 0;
    helper(grid, 0, 0, x, y, 1);
    printSolution(grid);
}

int main()
{

    solveKT();

    return 0;
}