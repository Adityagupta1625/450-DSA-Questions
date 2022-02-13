#include <iostream>
#include <queue>
#include <vector>
using namespace std;
 
// function to calculate kth largest element
// in contiguous subarray sum
int kthLargestSum(int arr[], int n, int k)
{
      priority_queue<int, vector<int>, greater<int> > pq;
    vector<int> sum;
    sum.push_back(0);
    sum.push_back(arr[0]);
    for(int i=2;i<=n;i++){
        sum[i]=sum[i-1]+arr[i-1];
    }
    
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){

            int x=sum[j]-sum[i-1];
            cout<<x<<endl;
            if(pq.size()<k)
                pq.push(x);
            
            else if(pq.top()<x){
                pq.pop();
                pq.push(x);
            }
        }
    }
    return 0;
}
 
// Driver program to test above function
int main()
{
    int a[] = { 10, -10, 20, -40 };
    int n = sizeof(a) / sizeof(a[0]);
    int k = 6;
 
    // calls the function to find out the
    // k-th largest sum
    cout << kthLargestSum(a, n, k);
    return 0;
}
