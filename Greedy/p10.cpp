// A board of length m and width n is given, we need to break this board into m*n squares such that cost of breaking is minimum. cutting cost for each edge will be given for the board. In short, we need to choose such a sequence of cutting such that cost is minimized. 
// Examples: 
// For above board optimal way to cut into square is:
// Total minimum cost in above case is 42. It is 
// evaluated using following steps.

// Initial Value : Total_cost = 0
// Total_cost = Total_cost + edge_cost * total_pieces
// Probelm Link: https://www.geeksforgeeks.org/minimum-cost-cut-board-squares/
#include <iostream>
#include <algorithm>
using namespace std;

// method returns minimum cost to break board into
// m*n squares
int minimumCostOfBreaking(int X[], int Y[], int m, int n)
{
    sort(X,X+m,greater<int>());
    sort(Y,Y+n,greater<int>());
    int i=0,j=0;
    int hort=1,vect=1;
    int res=0;
    while(i<m && j<n){
        if(X[i]>Y[j]){
            res+=(X[i]*vect);
            hort++;
            i++;
        }
        else{
          res+=(Y[j]*hort);
          vect++;  
          j++;
        }
    }
    while(i<m){
        res+=(X[i]*vect);
        i++;
    }
    while(j<n){
        res+=(Y[j]*hort);
        j++;
    }
    return res;
}
  
//  Driver code to test above methods
int main()
{
    int m = 6, n = 4;
    int X[5] = {2, 1, 3, 1, 4};
    int Y[3] = {4, 1, 2};
    cout << minimumCostOfBreaking(X, Y, m-1, n-1);
    return 0;
}