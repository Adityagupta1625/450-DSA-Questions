// Finding duplicate in an string

#include <iostream>
using namespace std;
void printDups(char str[])
{
    int h[26]={0};
    for (int i = 0; str[i]!='\0'; i++)
    {
        
        h[str[i] - 'a']++;
        
    }
    for (int i = 0; i < 26; i++)
    {
        
        if (h[i] > 1)
        {

            cout <<(char)(i+97)<<" ";
        }
    }
}
int main()
{
    char str[] = "teststring";
    printDups(str);
    return 0;
}