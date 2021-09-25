// Recursively print all sentences that can be formed from list of word lists
// Given a list of word lists How to print all sentences possible taking one word from a list at a time via recursion?
// Example:

// Input: {{"you", "we"},
//         {"have", "are"},
//         {"sleep", "eat", "drink"}}

// Output:
//   you have sleep
//   you have eat
//   you have drink
//   you are sleep
//   you are eat
//   you are drink
//   we have sleep
//   we have eat
//   we have drink
//   we are sleep
//   we are eat
//   we are drink

#include <iostream>
#include <string>
#include <vector>
#define R 3
#define C 3
using namespace std;
void printUtil(string s[R][C], string output[R], int n, int m)
{
    output[n] = s[n][m];
    if (n == R - 1)
    {
        for (int i = 0; i < R; i++)
        {
            cout << output[i] << " ";
        }
        cout << endl;
        return;
    }
    for (int i = 0; i < C; i++)
    {
        if (s[n + 1][i] != ""){
            printUtil(s, output, n + 1, i);
        }
    }
}
void print(string s[R][C])
{
    string out[R];
    for (int i = 0; i < C; i++)
    {
        if(s[0][i]!=""){
            
            printUtil(s, out, 0, i);
        }

    }
}

int main()
{
    string arr[R][C]  = {{"you", "we"},
                        {"have", "are"},
                        {"sleep", "eat", "drink"}};
    print(arr);
    return 0;
}

