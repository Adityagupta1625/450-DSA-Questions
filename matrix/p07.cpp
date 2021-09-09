// Given a N x N matrix, where every row and column is sorted in non-decreasing order. Find the kth smallest element in the matrix.

// Example 1:
// Input:
// N = 4
// mat[][] =     {{16, 28, 60, 64},
//                    {22, 41, 63, 91},
//                    {27, 50, 87, 93},
//                    {36, 78, 87, 94 }}
// K = 3
// Output: 27
// Explanation: 27 is the 3rd smallest element

// Probelm link: https://practice.geeksforgeeks.org/problems/kth-element-in-matrix/1
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
int mat[MAX][MAX];
int kthSmallest(int mat[MAX][MAX], int n, int k);
// driver program to test above function
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
    
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>mat[i][j];
        int r;
        cin>>r;
        cout<<kthSmallest(mat,n,r)<<endl;
    }
     // cout << "7th smallest element is " << kthSmallest(mat, 4, 7);
      return 0;
}
// } Driver Code Ends




int kthSmallest(int mat[MAX][MAX], int n, int k)
{
  //Your code here
  int highval=mat[n-1][n-1];
  int lowval=mat[0][0];
  int midval;
  while(lowval<=highval){
      midval=(lowval+highval)/2;
      int ans=0;
      for(int i=0;i<n;i++){
          int l=0,h=n-1;
          int m;
          while(l<=h){
            m=l+(h-l)/2;
            if(mat[i][m]<=midval){
                l=m+1;
            }
            else{
                h=m-1;
            }
          }
          ans=ans+l;
      }
      if(ans<=k-1){
          lowval=midval+1;
      }
      else{
          highval=midval-1;
      }
      
  }
  return lowval;
 
}