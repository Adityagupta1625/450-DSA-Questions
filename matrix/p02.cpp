// Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

// Integers in each row are sorted from left to right.
// The first integer of each row is greater than the last integer of the previous row.

// question link: https://leetcode.com/problems/search-a-2d-matrix/
#include <iostream>
#include <vector>
using namespace std;
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int index = -1;
    for (int i = 0; i < matrix.size(); i++)
    {
        int last = matrix[i].size();
        if (matrix[i][3] == target)
        {
            
            return true;
        }
        if (matrix[i][last - 1] > target)
        {
        
            index = i;
            break;
        }
    }
    if(index==-1){
        return false;
    }
    for (int j = 0; j < matrix[index].size(); j++)
    {
        if (matrix[index][j] == target)
        {
            return true;
        }
    }
    return false;
}
int main()
{
    vector<vector<int>> v={{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    cout<<searchMatrix(v,3);
    return 0;
}