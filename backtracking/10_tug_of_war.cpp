#include <iostream>
#include <vector>
#include <string>
using namespace std;
void helper(int *arr, int n, int i, vector<int> set1,
            vector<int> set2, int sum1, int sum2,
            int &min_diff, string &ans1, string &ans2)
{
    if (i == n)
    {

        int diff = abs(sum1 - sum2);
        if (diff < min_diff)
        {
            ans1="";
            ans2="";
            for(auto x:set1)
                ans1=ans1+" "+to_string(x);
            for(auto x: set2)
                ans2=ans2+" "+to_string(x);

            min_diff = diff;
        }
        return;
    }

    if (set1.size() < (n + 1) / 2)
    {
        set1.push_back(arr[i]);
        helper(arr, n, i+1, set1, set2, sum1 + arr[i], sum2, min_diff, ans1, ans2);
        set1.pop_back();
    }
    if (set2.size() < (n + 1) / 2)
    {
        set2.push_back(arr[i]);
        helper(arr, n, i+1, set1, set2, sum1, sum2 + arr[i], min_diff, ans1, ans2);
        set2.pop_back();
    }
}
void tugOfWar(int *arr, int n)
{
    vector<int> set1, set2;
    int i = 0;
    int min_diff = INT_MAX;
    string ans1;
    string ans2;

    helper(arr, n, i, set1, set2, 0, 0, min_diff, ans1, ans2);
    
    cout<<ans1<<endl<<ans2<<endl;
}

int main()
{
    int arr[] = {23, 45, -34, 12, 0, 98, -99, 4, 189, -1, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    tugOfWar(arr, n);
    return 0;
}