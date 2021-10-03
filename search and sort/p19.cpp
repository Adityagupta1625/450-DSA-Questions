// Probelm link: https://www.hackerearth.com/practice/algorithms/searching/binary-search/practice-problems/algorithm/kth-smallest-number-again-2/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
		long long int n,q;
		cin>>n>>q;
		vector<vector<long long int>> v;
		for(int i=0;i<n;i++){
			long long int x,y;
			cin>>x>>y;
			v.push_back({x,y});
		}
		sort(v.begin(),v.end());
		int idx=0;
		for(int i=1;i<n;i++){
			if(v[idx][1]>=v[i][0]){
				v[idx][1]=max(v[idx][1],v[i][1]);
			}
			else{
				idx++;
				v[idx]=v[i];
			}
		}
		long long int h;
		for(int i=0;i<q;i++){
			cin>>h;
			long long int ans=-1;
			for(int j=0;j<=idx;j++){
				if(h<=v[j][1]-v[j][0]+1){
					ans=v[j][0]+h-1;
					break;
				}
				else{
					h=h-(v[j][1]-v[j][0]+1);
				}
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}