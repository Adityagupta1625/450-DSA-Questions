// Common elements in all rows of a given matrix
// Given an m x n matrix, find all common elements present in all rows in O(mn) time and one traversal of matrix.
// Example: 

// Input:
// mat[4][5] = {{1, 2, 1, 4, 8},
//              {3, 7, 8, 5, 1},
//              {8, 7, 7, 3, 1},
//              {8, 1, 2, 7, 9},
//             };

// Output: 
// 1 8 or 8 1
// 8 and 1 are present in all rows.

// probelm link: https://www.geeksforgeeks.org/common-elements-in-all-rows-of-a-given-matrix/

#include <iostream>
using namespace std;

void printCommonElements(int n, int m, int mat[][5])
{
    int h[100] = {0};
    for (int i = 0; i < m; i++)
    {
        h[mat[0][i]] = 1;
    }

    for (int i = 1; i < n; i++)
    {

        for (int j = 0; j < m; j++)
        {
            if (h[mat[i][j]] == i)
            {

                h[mat[i][j]] = i + 1;
                if(i==n-1){
                    cout<<mat[i][j]<<endl;
                }
            }
        }
    }
  
}
int main()
{
    int mat[4][5] =
        {
            {1, 7, 1, 4, 8},
            {3, 7, 8, 5, 1},
            {8, 7, 7, 3, 1},
            {8, 1, 2, 7, 9},
        };
    int n = 4;
    int m = 5;
    printCommonElements(n, m, mat);

    return 0;
}