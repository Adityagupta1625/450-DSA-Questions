// Count of number of given string in 2D character array

// Given a 2-Dimensional character array and a string, we need to find the given string in 2-dimensional character array such that individual characters can be present left to right, right to left, top to down or down to top.

// Examples: 

// Input : a ={
//             {D,D,D,G,D,D},
//             {B,B,D,E,B,S},
//             {B,S,K,E,B,K},
//             {D,D,D,D,D,E},
//             {D,D,D,D,D,E},
//             {D,D,D,D,D,G}
//            }
//         str= "GEEKS"
// Output :2
// Probelm link: https://www.geeksforgeeks.org/find-count-number-given-string-present-2d-character-array/

#include <iostream>
#include <string>
using namespace std;
int solve(string s,string inp[],int j,int i,int size,int idx,int len){
    int found=0;
    if (i>=0 && j>=0 && i<len && j<len)
    {
        if (inp[i][j]==s[idx])
        {
            idx++;
            char temp=s[idx];
            inp[i][j]='0';
            if (idx==size)
            {
               found=1;
            }
            else{
                found+=solve(s,inp,j,i+1,size,idx,len);
                found+=solve(s,inp,j+1,i,size,idx,len);
                found+=solve(s,inp,j,i-1,size,idx,len);
                found+=solve(s,inp,j-1,i,size,idx,len);
            }
            inp[i][j]=temp;
        }
        
    }
    return found;
}
int main()
{

    string needle = "MAGIC";
    string input[] = {"BBABBM",
                      "CBMBBA",
                      "IBABBG",
                      "GOZBBI",
                      "ABCBBB",
                      "MCIGAM"};
    
    int ans=0;
    int n=6,m=5;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
           ans+=solve(needle,input,j,i,m,0,n);
        }
        
    }
    

    cout << "count: " << ans << endl;
    return 0;
}
