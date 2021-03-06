// The count-and-say sequence is a sequence of digit strings defined by the recursive formula:

// countAndSay(1) = "1"
// countAndSay(n) is the way you would "say" the digit string from countAndSay(n-1), which is then converted into a different digit string.
// To determine how you "say" a digit string, split it into the minimal number of groups so that each group is a contiguous section all of the same character. Then for each group, say the number of characters, then say the character. To convert the saying into a digit string, replace the counts with a number and concatenate every saying

// Input: n = 4
// Output: "1211"
// Explanation:
// countAndSay(1) = "1"
// countAndSay(2) = say "1" = one 1 = "11"
// countAndSay(3) = say "11" = two 1's = "21"
// countAndSay(4) = say "21" = one 2 + one 1 = "12" + "11" = "1211"

// PROBELM LINK: https://leetcode.com/problems/count-and-say/
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
class Solution
{
public:
    string generate(string s)
    {
        string newstr = "";

        int i = 0;
        while (i < s.length())
        {
            int cnt = 1;
            while (s[i] == s[i + 1])
            {
                cnt++;
                i++;
            }
            newstr = newstr + to_string(cnt) + s[i];
            i++;
        }
        return newstr;
    }
    string countAndSay(int n)
    {
        string f = "1";
        for (int i = 2; i <= n; i++)
        {
            f = generate(f);
        }
        return f;
    }
};
int main()
{
    Solution obj;
    int n;
    cin>>n;
    cout<< obj.countAndSay(n);

    return 0;
}