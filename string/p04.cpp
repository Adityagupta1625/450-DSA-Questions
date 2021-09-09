// Check whether string is rotation of one another or not

#include <iostream>
#include <string>

using namespace std;
int areRotations(string str1,string str2){
    string str3=str1+str1;
    if (str3.find(str2) != string::npos)
    {
        return 1;
    }
    return 0;
}
int main()
{
   string str1 = "AACD", str2 = "ACDA";
   if (areRotations(str1, str2))
     printf("Strings are rotations of each other");
   else
      printf("Strings are not rotations of each other");
   return 0;
}