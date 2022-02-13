// union of two sorted arrays

// Union of the two arrays can be defined as the set containing distinct elements from both the arrays. If there are repetitions, then only one occurrence of element should be printed in the union.

// Example 1:

// Input:
// 5 3
// 1 2 3 4 5
// 1 2 3

// Output: 
// 5

// Explanation: 
// 1, 2, 3, 4 and 5 are the
// elements which comes in the union set
// of both arrays. So count is 5.

// link of the question: https://practice.geeksforgeeks.org/problems/union-of-two-arrays3538/1

#include <iostream>
using namespace std;


class Solution{
    public:
    int doUnion(int a[], int n, int b[], int m)  {
       int i=0,j=0,k=0;
       int c[10000];
       while(i<n && j<m){
           if(a[i]<b[j]){
               c[k]=a[i];
               while(a[i]==a[i+1]){
                    i++;    
               }
               i++;
           }
           else if(a[i]>b[j]){
               c[k]=b[j];
               while(a[j]==a[j+1]){
                    j++;    
               }
               j++;
           }
           
           else{
               c[k]=a[i];
               i++;
               j++;
           }
           
           k++;
           
       }
       while(i<n){
           
        c[k]=a[i];
        while (a[i]==a[i+1])
        {
            i++;
        }
        
        i++;
        k++;
           
       }
       while(j<m){
           
        c[k]=b[j];
        while (b[j]==b[j+1])
        {
            j++;
        }
        j++;
        k++;
           
       }
       return k;
    }
};
int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, m;
	    cin >> n >> m;
	    int a[10000], b[1000];
	   
	    for(int i = 0;i<n;i++)
	       cin >> a[i];
	       
	    for(int i = 0;i<m;i++)
	       cin >> b[i];
	    Solution ob;
	    cout << ob.doUnion(a, n, b, m) << endl;
	    
	}
	
	return 0;
}  