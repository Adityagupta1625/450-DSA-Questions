#include<bits/stdc++.h>
using namespace std;

int find(vector<int> parent,int i){
    if(parent[i]==i)
        return i;
   	return find(parent,parent[i]);
}
void Union(vector<int>& parent,int i,int j){
    int a=find(parent,i);
    int b=find(parent,j);
    
     parent[a]=parent[b];
    
}

int main() {
    // Write your code here
    int v,e;
    cin>>v>>e;
    
    vector<pair<int,pair<int,int>>> adj;
    int ei,ej,wi;
    
    for(int i=0;i<e;i++){
        cin>>ei>>ej>>wi;
        adj.push_back({wi,{ei,ej}});
    }
    
    sort(adj.begin(),adj.end());
    
    vector<int> parent(v,0);
    for(int i=0;i<v;i++){
        parent[i]=i;
    }
    
    vector<pair<int,pair<int,int>>> ans;
    for(auto x: adj){
        int wt=x.first;
        int a=x.second.first;
        int b=x.second.second;
        
        if(find(parent,a)!=find(parent,b)){
            ans.push_back({wt,{a,b}});
            Union(parent,a,b);
        }
    }
    sort(ans.begin(),ans.end());
    for(auto x: ans){
        if(x.second.first<=x.second.second)
        	cout<<x.second.first<<" "<<x.second.second<<" "<<x.first<<endl;
        else
            cout<<x.second.second<<" "<<x.second.first<<" "<<x.first<<endl;
    }
}