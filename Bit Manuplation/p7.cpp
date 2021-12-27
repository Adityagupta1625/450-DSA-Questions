// Given a two integers say a and b. Find the quotient after dividing a by b without using multiplication, division and mod operator.

// Example: 

// Input : a = 10, b = 3
// Output : 3

// Input : a = 43, b = -8
// Output :  -5 

// Probelm Link: https://www.geeksforgeeks.org/divide-two-integers-without-using-multiplication-division-mod-operator/

#include <iostream>

using namespace std;
int divide(long long dividend, long long divisor)
{
  long long temp = 0, quotient = 0;
  int sign = 0;
  if (dividend < 0 || divisor < 0)
    sign = 1;

  dividend = abs(dividend);
  divisor = abs(divisor);

  for (int i = 31; i >= 0; i--)
  {
    if ((temp + (divisor << i)) <= dividend)
    {
      temp += divisor << i;
      quotient+= 1 << i;
    }
  }
  if (sign)
    return -quotient;
  return quotient;
}

// Driver code
int main()
{
  int a = 10, b = 3;
  cout << divide(a, b) << "\n";

  a = 43, b = -8;
  cout << divide(a, b);

  return 0;
}