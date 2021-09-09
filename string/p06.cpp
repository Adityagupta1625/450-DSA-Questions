#include <iostream>
using namespace std;
bool isShuffledSubstring(string str1, string str2)
{
    int h1[26] = {0}, h2[26] = {0};
    for (int i = 0; i < str1.length(); i++)
    {

        h1[str1[i] - 'a']++;
    }
    int j=0;
    while (j+str1.length()-1<str2.length())
    {
       for (int i = j; i < str1.length()+j-1; i++)
       {
           h1[str2[i]-'a']--;
       }
       
       
    }
    
}
int main()
{

    string str1 = "geekforgeeks";
    string str2 = "ekegorfkeegsgeek";

    bool a = isShuffledSubstring(str1, str2);

    if (a)
        cout << "YES";
    else
        cout << "NO";
    cout << endl;
    return 0;
}