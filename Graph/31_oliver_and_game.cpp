#include<bits/stdc++.h>
using namespace std;

vector<int> intime;
vector<int> outime;
int timer=1;
void resize(int n){
	intime.resize(n+1);
	outime.resize(n+1);
}
void dfs(vector<int> graph[],int src,int par){

	intime[src]=timer++;
	for(auto x: graph[src]){
		if(x!=par){
			dfs(graph,x,src);
		}
	}
	outime[src]=timer++;
}

// x below y
bool check(int x,int y){
	if(intime[x]>intime[y] && outime[x]<outime[y])
		return true;
	return false;
}
int main() {
    
    int n;
    cin >> n;
    timer = 1;
    vector<int> g[n + 1];
    for (int i = 0;i < n - 1;i++) {
        int x, y;
        scanf("%d %d",&x,&y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
	resize(n);
	
    dfs(g,1,0);
	
	int q;
	cin>>q;
	while(q--){
		int type,x,y;
		scanf("%d %d %d",&type,&x,&y);

		if(!check(x,y) && !check(y,x)){
			printf("NO\n");
			continue;
		}
		else if(type==0){
			if(check(y,x))
				printf("YES\n");
			else 
				printf("NO\n");
		}
		else if(type==1){
			if(check(x,y))
				printf("YES\n");
			else 
				printf("NO\n");
		}
	}

    return 0;
}