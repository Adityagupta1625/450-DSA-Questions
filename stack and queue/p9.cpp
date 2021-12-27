// Given a string of balanced expression, find if it contains a redundant parenthesis or not. A set of parenthesis are redundant if the same sub-expression is surrounded by unnecessary or multiple brackets. Print ‘Yes’ if redundant, else ‘No’.
// Note: Expression may contain ‘+‘, ‘*‘, ‘–‘ and ‘/‘ operators. Given expression is valid and there are no white spaces present.
// Example: 
// Input: 
// ((a+b))
// (a+(b)/c)
// (a+b*(c-d))
// Output: 
// Yes
// Yes
// No
// Probelm link: https://www.geeksforgeeks.org/expression-contains-redundant-bracket-not/

#include <iostream>
#include <stack>
using namespace std;

// Function to check redundant brackets in a
// balanced expression
bool checkRedundancy(string str)
{
    stack<char> s;
    int n = str.length();
    bool flag=false;
    for (int i = 0; i < n; i++)
    {
        if (str[i] == ')')
        {   
           flag=true;
           char top=s.top();
           s.pop();
           while(!s.empty() && top!='('){
                
                if(top=='+' ||
                top=='-' ||
                top=='*' ||
                top=='/' ){
                    flag=false;
                }
                top=s.top();
                s.pop();
            }
            if(flag)
                return flag;
        }
        else
        {
            s.push(str[i]);
        }
    }
    return flag;
}

// Function to check redundant brackets
void findRedundant(string &str)
{
    bool ans = checkRedundancy(str);
    if (ans == true)
        cout << "Yes\n";
    else
        cout << "No\n";
}

// Driver code
int main()
{
    string str = "((a+b))";
    findRedundant(str);

    str = "(a+(b)/c)";
    findRedundant(str);

    str = "(a+b*(c-d))";
    findRedundant(str);

    return 0;
}