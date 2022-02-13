#include <iostream>
#include <algorithm>
using namespace std;
int maxProfit(int arr[], int n)
{
  int *profit = new int[n];
  profit[n - 1] = 0;
  int maxprice = arr[n - 1];
  for (int i = n - 2; i >= 0; i--)
  {
    /* code */
    maxprice = max(arr[i], maxprice);

    profit[i] = max(profit[i + 1], maxprice - arr[i]);
  }
  
  int minprice=arr[0];
  for (int i = 1; i < n; i++)
  {
    /* code */
    if(minprice>arr[i]){
      minprice=arr[i];
    }
    profit[i]=max(profit[i-1],profit[i]+(arr[i]-minprice));

  }
  int maxprof = profit[n-1];
  delete[] profit;
  return maxprof;
}
int main()
{
  int price[] = {2, 28, 15, 10, 35, 25, 80};
  int n = sizeof(price) / sizeof(price[0]);
  cout << "Maximum Profit = " << maxProfit(price, n);
  return 0;
}