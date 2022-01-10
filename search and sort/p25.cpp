// Roti parta probelm Spoj
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <math.h>
#define ll long long
using namespace std;
int findSum(vector<int> v,int mid){
	int cnt=0;
	for(int i=0;i<v.size();i++){
		int j=1;
		int mul=v[i]*j;
		while(mul<=mid){
			cnt++;
			j++;
			mul+=v[i]*j;
		}
	}
	return cnt;	
}
int main()
{
	int t;
	cin>>t;
	while (t--)
	{

		int l, p;
		cin >> p;
		cin >> l;
		vector<int> v;
		
		for (int i = 0; i < l; i++)
		{
			int x;
			cin >> x;
			v.push_back(x);
			
		}
		int lo = 0, hi = 1e8;
		int ans = 0;
		while (lo <= hi)
		{
			int m = (lo + hi) / 2;
			int sum=findSum(v,m);
			if(sum>=p){
				ans=m;
				hi=m-1;
			}
			else{
				lo=m+1;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}