#include <iostream>
#include <vector>
#include <string>
#include <string.h>
using namespace std;
string longestCommonPrefix(vector<string> &str)
{
    string s;
    if (str.size()==0)
    {
        return "";
    }
    if (str.size()==1)
    {
        return str[0];
    }
    s=str[0];
    for (int i = 1; i < str.size() ; i++)
    {
        if (str[i]=="")
        {
            return "";
        }
        int k=0;
        while (s!=str[i]  && s[k]!='\0')
        {
           s=str[i].substr(0,str[i].length()-1);
           k++;
        }
        
    }
    return s;
}
int main()
{
    vector<string> v = {"flower","flow","flight"};
    cout << longestCommonPrefix(v);
    return 0;
}