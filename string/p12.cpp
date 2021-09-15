// Convert a sentence into its equivalent mobile numeric keypad sequence

// Given a sentence in the form of a string, convert it into its equivalent mobile numeric keypad sequence. 

// Input : GEEKSFORGEEKS
// Output : 4333355777733366677743333557777
// For obtaining a number, we need to press a
// number corresponding to that character for 
// number of times equal to position of the 
// character. For example, for character C, 
// we press number 2 three times and accordingly.

// Input : HELLO WORLD
// Output : 4433555555666096667775553
#include <iostream>
#include <string>
using namespace std;
string printSequence(string s[], string inp)
{
    string result="";

    for (int i = 0; i < inp.length(); i++)
    {
        
        result=result+s[inp[i]-'A'];
    }
    return result;
}
int main()
{
    // storing the sequence in array

    string str[] = {"2", "22", "222",
                    "3", "33", "333",
                    "4", "44", "444",
                    "5", "55", "555",
                    "6", "66", "666",
                    "7", "77", "777", "7777",
                    "8", "88", "888",
                    "9", "99", "999", "9999"};
    string input = "HELLOWORLD";
    cout << printSequence(str, input);
    return 0;
}
