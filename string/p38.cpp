// Minimum characters to be added at front to make string palindrome

// Given a string str we need to tell minimum characters to be added at front of string to make string palindrome.
// Examples:

// Input  : str = "ABC"
// Output : 2
// We can make above string palindrome as "CBABC"
// by adding 'B' and 'C' at front.

// Input  : str = "AACECAAAA";
// Output : 2
// We can make above string palindrome as AAAACECAAAA
// by adding two A's at front of string.
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
vector<int> Computelps(string s)
{
    int len = 0;
    vector<int> l;
    l.push_back(0);
    int i = 1;
    while (i < s.length())
    {
        if (s[i] == s[len])
        {
            len++;
            i++;
            l.push_back(len);
        }
        else
        {
            if (len != 0)
            {
                len = l[len - 1];
            }
            else
            {

                l.push_back(0);
                i++;
            }
        }
    }

    return l;
}
int main()
{
    string s = "AB";
    string org = s;
    reverse(s.begin(), s.end());
    string final = org + "$" + s;
    vector<int> lps = Computelps(final);
    cout << org.length() - lps[lps.size() - 1];
}