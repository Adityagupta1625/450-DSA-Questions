// Rotate Matrix by 90 degree
#include <iostream>
#include <algorithm>
using namespace std;
#define N 4
void printMatrix(int arr[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << arr[i][j] << " ";
        cout << '\n';
    }
}

void rotate90Clockwise(int arr[N][N])
{
    for (int i = 0; i < N / 2; i++)
    {
        for (int j = i; j < N-i-1; j++)
        {
            swap(arr[i][j], arr[N - j - 1][i]);
            swap(arr[j][N - i - 1], arr[N - j - 1][i]);
            swap(arr[N - i - 1][N - j - 1], arr[N - j - 1][i]);
        }
    }
}

// Driver code
int main()
{
    int arr[N][N] = {{1, 2, 3, 4},
                     {5, 6, 7, 8},
                     {9, 10, 11, 12},
                     {13, 14, 15, 16}};
    rotate90Clockwise(arr);
    printMatrix(arr);
    return 0;
}