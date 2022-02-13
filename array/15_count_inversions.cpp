#include <iostream>
using namespace std;

class Solution
{
public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int merge(long long int array[], long long int left, long long int mid, long long int right, long long temp[])
    {

        long long int i, j, k;
        long long int inv_cnt = 0;

        i = left;
        j = mid;
        k = left;
        while (i <= mid-1 && j <= right)
        {
            if (array[i] <= array[j])
            {
                temp[k] = array[i];
                i++;
                k++;
            }
            else
            {
                temp[k] = array[j];
                inv_cnt = inv_cnt + (mid - i);
                j++;
                k++;
            }
            
        }

        while (i <= mid-1)
        {
            temp[k] = array[i];
            i++;
            k++;
        }

        while (j <= right)
        {
            temp[k] = array[j];
            j++;
            k++;
        }
        long long int c;
        for (c = left; c <= right; c++)
        {
            array[c] = temp[c];
        }
        return inv_cnt;
    }

    long long int mergeSort(long long int array[], long long int begin, long long int end, long long int temp[])
    {
        long long int inv_cnt = 0;
        long long int mid;
        if (begin<end)
        {
            mid = (begin + end) / 2;
            inv_cnt += mergeSort(array, begin, mid, temp);
            inv_cnt += mergeSort(array, mid + 1, end, temp);
            inv_cnt += merge(array, begin, mid, end, temp);
        }
        return inv_cnt;
    }
    long long int inversionCount(long long arr[], long long n)
    {
        // Your Code Here
        long long int temp[n];
        long long int cnt = mergeSort(arr, 0, n - 1, temp);
        return cnt;
    }
};
int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
        
    }
    return 0;
}