
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    long long int c;
    cin >> c;
    long long int r=1;
    while (r<=c)
    {
        long long int n,k,b,t;
        cin >> n>>k>>b>>t;

        vector<long long int> v; // speed
        vector<long long int> x; // distance
        for(long long int i=0;i<n;i++){
            long long int y;
            cin>>y;
            x.push_back(y);
        }
        for(long long int i=0;i<n;i++){
            long long int y;
            cin>>y;
            v.push_back(y);
        }
        long long int count=0,penalty=0,swaps=0;
        for (long long int i = n-1; i>=0; i--)
        {
            long long int distance_possible=v[i]*t;
            long long int distance_required=b-x[i];

            if(distance_possible>=distance_required){
                count++;
                swaps+=penalty;
            }
            else
                penalty++;
            
            if(count>=k)
                break;
        }
        
        if(count>=k)
            cout<<"Case #"<<r<<": "<<swaps<<endl;
        else
            cout<<"Case #"<<r<<": "<<"IMPOSSIBLE"<<endl;
        r++;
    }
    return 0;
}