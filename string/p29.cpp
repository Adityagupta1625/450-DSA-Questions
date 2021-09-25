// Given a 2D grid of n*m of characters and a word, find all occurrences of given word in grid. A word can be matched in all 8 directions at any point. Word is said be found in a direction if all characters match in this direction (not in zig-zag form). The 8 directions are, horizontally left, horizontally right, vertically up, vertically down and 4 diagonal directions.
 

// Example 1:

// Input: grid = {{a,b,c},{d,r,f},{g,h,i}},
// word = "abc"
// Output: {{0,0}}
// Expalnation: From (0,0) one can find "abc"
// in horizontally right direction.

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    vector<int> x = {-1, -1, -1, 0, 0, 1, 1, 1};
    vector<int> y = {-1, 0, 1, -1, 1, -1, 0, 1};
    bool search(int i, int j, vector<vector<char>> grid, string word)
    {
        if (grid[i][j] != word[0])
            return false;
        int col = grid[i].size();
        int row = grid.size();
        int len = word.length();
        for (int k = 0; k < 8; k++)
        {
            int rd = i + x[k], cd = j + y[k], d;

            for (d = 1; d < len; d++)
            {
                if (rd < 0 || cd < 0 || rd >= row || cd >= col)
                    break;

                if (grid[rd][cd] != word[d])
                    break;
                rd = rd + x[k];
                cd = cd + y[k];
            }
            if (len == d)
            {
                return true;
            }
        }
        return false;
    }
    vector<vector<int>> searchWord(vector<vector<char>> grid, string word)
    {
        vector<vector<int>> v;
        int k = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {

                if (search(i, j, grid, word))
                {

                    vector<int> vec;
                    vec.push_back(i);
                    vec.push_back(j);
                    v.push_back(vec);
                }
            }
        }
        return v;

    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
	}
	return 0;
}