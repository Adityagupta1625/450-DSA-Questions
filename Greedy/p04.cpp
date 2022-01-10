// In a stock market, there is a product with its infinite stocks. The stock prices are given for N days, where arr[i] denotes the price of the stock on the ith day. There is a rule that a customer can buy at most i stock on the ith day. If the customer has an amount of k amount of money initially, find out the maximum number of stocks a customer can buy. 

// For example, for 3 days the price of a stock is given as 7, 10, 4. You can buy 1 stock worth 7 rs on day 1, 2 stocks worth 10 rs each on day 2 and 3 stock worth 4 rs each on day 3.

//  probelm link: https://www.geeksforgeeks.org/buy-maximum-stocks-stocks-can-bought-th-day/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
// Return the maximum stocks
int buyMaximumProducts(int n, int k, int price[])
{
    vector<pair<int, int> > v;
    
    for(int i=0;i<n;i++)
        v.push_back({price[i],i+1});
    
    sort(v.begin(),v.end());

    int cnt=0;
    for(int i=0;i<n;i++){
        if(v[i].first*v[i].second<=k){
            cnt=cnt+v[i].second;
            k=k-v[i].first;
        }
        else{
            int unit=k/v[i].first;
            cnt=cnt+unit;
            k=k-unit*v[i].first;
        }

    }
    return cnt;
    
}
 
// Driven Program
int main()
{
    int price[] = { 7, 10, 4};
    int n = sizeof(price)/sizeof(price[0]);
    int k = 45;
 
    cout << buyMaximumProducts(n, k, price) << endl;
 
    return 0;
}