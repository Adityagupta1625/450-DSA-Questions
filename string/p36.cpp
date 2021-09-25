// Program to generate all possible valid IP addresses from given string

// Given a string containing only digits, restore it by returning all possible valid IP address combinations.
// A valid IP address must be in the form of A.B.C.D, where A, B, C, and D are numbers from 0-255. The numbers cannot be 0 prefixed unless they are 0.

// Examples :

// Input: 25525511135
// Output: [“255.255.11.135”, “255.255.111.35”]
// Explanation:
// These are the only valid possible
// IP addresses.

#include <iostream>
#include <string>
#include <sstream>
using namespace std;
int isvalid(string s)
{
    if (s.length() > 3)
        return 0;
    if (s[0] == '0')
        return 0;
    stringstream geek(s);

    int x = 0;
    geek >> x;
    if (x < 0 || x > 255)
        return 0;
    return 1;
}
void convert(string s)
{
    string list[100];
    string first, second, third, fourth;
    int l = 0;
    for (int i = 1; i <= 3; i++)
    {
        string st = "";
        string str = "";
        st = s.substr(0, i);
        if (isvalid(st))
        {
            first = st;
            for (int j = 1; j <= 3; j++)
            {
                st = s.substr(i, j);
                if (isvalid(st))
                {
                    second = st;
                    for (int k = 1; k <= 3; k++)
                    {
                        st = s.substr(i + j, k);

                        if (isvalid(st))
                        {
                            third = st;

                            st = s.substr(i + j + k, s.length());

                            if (isvalid(st))
                            {
                                fourth = st;
                                str = first + '.' + second + '.' + third + '.' + fourth;
                                cout << str << endl;
                            }
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i < l; i++)
    {
        cout << list[i] << endl;
    }
}
int main()
{

    string A = "25525511135";
    string B = "25505011535";

    convert(A);
    convert(B);
    return 0;
}