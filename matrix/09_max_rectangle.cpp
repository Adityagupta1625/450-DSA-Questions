
// Probelm link: https://practice.geeksforgeeks.org/problems/max-rectangle/1#

// Given a binary matrix M of size n X m. Find the maximum area of a rectangle formed only of 1s in the given matrix.

// Example 1:
// Input:
// n = 4, m = 4

// M[][] = {{0 1 1 0},
//          {1 1 1 1},
//          {1 1 1 1},
//          {1 1 0 0}}
// Output: 8
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


 // } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
    int maxrect(int M[MAX],int n){
        vector <int> left(n),right(n);
        stack <int> st;
        for(int i=0;i<n;i++){
            if(st.empty()){
                left[i]=0; st.push(i);
            }
            else{
                while(!st.empty() && M[st.top()]>=M[i])
                    st.pop();
                left[i]=st.empty()?0:st.top()+1;
                st.push(i);
            }
        }
        while(!st.empty())
            st.pop();
        
        for(int i=n-1;i>=0;i--){
            if(st.empty()){
                right[i]=n-1; st.push(i);
            }
            else{
                while(!st.empty() && M[st.top()]>=M[i])
                    st.pop();
                right[i]=st.empty()?n-1:st.top()-1;
                st.push(i);
            }
        }
        int mxarea=0;
        for(int i=0;i<n;i++){
            mxarea=max(mxarea,M[i]*(right[i]-left[i]+1));
        }
        return mxarea;
    }
    int maxArea(int M[MAX][MAX], int n, int m) {
        // Your code here
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(M[i][j]==1)
                M[i][j]=M[i][j]+M[i-1][j];
            }
        }
        int mx_area=0,area,temp[m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                temp[j]=M[i][j];
            }
            area=maxrect(temp,m);
            mx_area=max(mx_area,area);
        }
        return mx_area;
    }
};


// { Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}