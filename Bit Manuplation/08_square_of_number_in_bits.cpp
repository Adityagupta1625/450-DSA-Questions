// Given an integer n, calculate the square of a number without using *, / and pow().

// Examples :

// Input: n = 5
// Output: 25

// Input: 7
// Output: 49

// Input: n = 12
// Output: 144

// Probelm link: https://www.geeksforgeeks.org/calculate-square-of-a-number-without-using-and-pow/

#include <iostream>
using namespace std;
// int square(int n){
//     if(n==0)
//         return 0;
    
//     int x=n>>1;

//     if(n&1)
//         return (square(x)<<2)+(x<<2)+1;
//     else
//         return square(x)<<2;

// }
int square(int n){
    int times=n;
    int result=0;
    while(times>0){
        int shift=0;
        int curr=1;
        while((curr<<1)<=times){
            curr=curr<<1;
            shift++;
        }
        result+=(n<<shift);
        times=times-curr;
    }
    return result;
}
int main()
{
    for (int n = 10; n <= 15; n++)
        cout << "n = " << n << ", n^2 = " << square(n)
             << endl;
    return 0;
}