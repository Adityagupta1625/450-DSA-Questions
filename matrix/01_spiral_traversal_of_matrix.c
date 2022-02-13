// Given a matrix of size r*c. Traverse the matrix in spiral form.

// Example 1:

// Input:
// r = 4, c = 4
// matrix[][] = {{1, 2, 3, 4},
//            {5, 6, 7, 8},
//            {9, 10, 11, 12},
//            {13, 14, 15,16}}
// Output: 
// 1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10

// probelm link: https://practice.geeksforgeeks.org/problems/spirally-traversing-a-matrix-1587115621/1#
#include <stdio.h>


 // } Driver Code Ends
//User function Template for C


//Function to return a list of integers denoting spiral traversal of matrix. 
int* spirallyTraverse(int m, int n, int arr[][n])
{   
    int *result;
    result=(int *)malloc((m*n)*sizeof(int));
    int i,k=0,l=0;
    int j=0;
    while(k<m && l<n){
        for(i=l;i<n;i++){
            result[j++]=arr[k][i];
        }
        k++;
        for(i=k;i<m;i++){
            result[j++]=arr[i][n-1];
        }
        n--;
        if(k<m){
            for(i=n-1;i>=l;i--){
                result[j++]=arr[m-1][i];
            }
            m--;
        }
        if(l<n){
            for(i=m-1;i>=k;i--){
                result[j++]=arr[i][l];
            }
            l++;
        }
    }
    return result;
}

// { Driver Code Starts.

int main()
{
    int tc;
	scanf("%d", &tc);
	while(tc--){
		int r, c;
		scanf("%d", &r);
		scanf("%d", &c);
		int matrix[r][c];
	 
		for(int i = 0; i < r; i++){
			for(int j = 0; j < c; j++){
				scanf("%d", &matrix[i][j]);
			}
		}
		
		int *result = spirallyTraverse(r, c, matrix);
		for(int i = 0; i < r*c; i++)
			printf("%d ", result[i]);
		printf("\n");
	}
	return 0;
} 