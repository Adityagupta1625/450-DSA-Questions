// Find a specific pair in Matrix
// Given an n x n matrix mat[n][n] of integers, find the maximum value of mat(c, d) – mat(a, b) over all choices of indexes such that both c > a and d > b.
// Example: 
// Input:
// mat[N][N] = {{ 1, 2, -1, -4, -20 },
//              { -8, -3, 4, 2, 1 }, 
//              { 3, 8, 6, 1, 3 },
//              { -4, -1, 1, 7, -6 },
//              { 0, -4, 10, -5, 1 }};
// Output: 18
// The maximum value is 18 as mat[4][2] 
// - mat[1][0] = 18 has maximum difference. 

// Probelm link: https://www.geeksforgeeks.org/find-a-specific-pair-in-matrix/
#include <iostream>
#include <algorithm>
using namespace std;
#define N 5
int findMaxValue(int mat[N][N])
{
    int maxResult[N][N];
    maxResult[N - 1][N - 1] = mat[N - 1][N - 1];
    int maxv=mat[N-1][N-1];
    for (int i = N - 2; i >= 0; i--)
    {
       if (maxv<mat[N-1][i])
       {
           maxv=mat[N-1][i];
       }
       maxResult[N-1][i]=maxv;
    }
    maxv=mat[N-1][N-1];
    for (int i = N - 2; i >= 0; i--)
    {
       if (maxv<mat[i][N-1])
       {
           maxv=mat[i][N-1];
       }
       maxResult[i][N-1]=maxv;
    }
    int maxsum=0,sum;
    for (int i = N - 2; i >= 0; i--)
    {
        for (int j = N - 2; j >= 0; j--)
        {
            sum=maxResult[i+1][j+1]-mat[i][j];
            if (sum>maxsum)
            {
                maxsum=sum;
            }
            maxResult[i][j]=max(mat[i][j],max(maxResult[i][j+1],maxResult[i+1][j]));
        }
    }
    return maxsum;
}
int main()
{
    int mat[N][N] = {
        {1, 2, -1, -4, -20},
        {-8, -3, 4, 2, 1},
        {3, 8, 6, 1, 3},
        {-4, -1, 1, 7, -6},
        {0, -4, 10, -5, 1}};
    cout << "Maximum Value is "
         << findMaxValue(mat);

    return 0;
}