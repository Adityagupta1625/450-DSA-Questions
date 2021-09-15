// Split the binary string into substrings with equal number of 0s and 1s

// Given a binary string str of length N, the task is to find the maximum count of consecutive substrings str can be divided into such that all the substrings are balanced i.e. they have equal number of 0s and 1s. If it is not possible to split str satisfying the conditions then print -1.
// Example: 
 
// Input: str = “0100110101” 
// Output: 4 
// The required substrings are “01”, “0011”, “01” and “01”.

// Input: str = “0111100010” 
// Output: 3 

// Input: str = “0000000000” 
// Output: -1

#include <iostream>
using namespace std;
int countpair(string s)
{
    int cnt_one = 0, cnt_zero = 0, count = 0;
    int i = 0;
    while (i < s.length())
    {
        while (s[i] == '0')
        {
            cnt_zero++;
            i++;
        }
        while (s[i] == '1')
        {
            cnt_one++;
            i++;
        }
        if (cnt_one == cnt_zero)
        {
            cnt_zero = 0;
            cnt_one = 0;
            count++;
        }
    }
    if (count==0)
    {
        return -1;
    }
    
    return count;
}
int main()
{
    string s = "0100110101";
    cout<<countpair(s);
    return 0;
}