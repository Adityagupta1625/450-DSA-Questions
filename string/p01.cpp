// Reverse a string 
#include <iostream>
#include <vector>
using namespace std;
void reverseString(vector<char> &s)
{
    int n = s.size();
    for (int i = 0; i < n / 2; i++)
    {
        swap(s[i], s[n - i - 1]);
    }
}
int main()
{   
    vector <char> s={'h','e','l','l','o'};
    for (int i = 0; i < s.size(); i++)
    {
        /* code */
        cout<<s[i];
    }
    
    return 0;
}