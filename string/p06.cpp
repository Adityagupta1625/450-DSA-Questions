// Check if the given string is shuffled substring of another string

// Input: str1 = “onetwofour”, str2 = “hellofourtwooneworld” 
// Output: YES 

// Explanation: str1 is substring in shuffled form of str2 as 
// str2 = “hello” + “fourtwoone” + “world” 
// str2 = “hello” + str1 + “world”, where str1 = “fourtwoone” (shuffled form) 
// Hence, str1 is a substring of str2 in shuffled form.

#include <iostream>

using namespace std;
int compare(int h1[],int h2[]){
    for (int i = 0; i < 26; i++)
    {
        
        if (h1[i]==h2[i])
        {
            return 1;
        }
    }
    return 0;
    
}
bool isShuffledSubstring(string str1, string str2)
{
    int h1[26] = {0}, h2[26] = {0};
    for (int i = 0; i < str1.length(); i++)
    {

        h1[str1[i] - 'a']++;
        h2[str2[i]-'a']++;    
    }
   
    int j=0;
    while (j<str2.length())
    {
       
       if (compare(h1,h2))
       {
           /* code */
           return true;
       }
       h2[str2[j]-'a']++;
       h1[str1[j-str1.length()]]--;
       j++;
    }
    return false;
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