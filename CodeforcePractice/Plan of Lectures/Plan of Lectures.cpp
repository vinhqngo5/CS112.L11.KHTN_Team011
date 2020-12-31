#include<bits/stdc++.h>
using namespace std;
const int N=3e5;
vector<int>G[N+10];
int deg[N+10],id[N+10],pre[N+10],fa[N+10];
bool vis[N+10];
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>fa[i];
	}
	while(m--){
		int u,v;cin>>u>>v;
		pre[u]=v;vis[v]=true;
	}
	int u=0;
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		for(int j=i;j;j=pre[j]){
			id[j]=i;
			if(fa[j]&&id[fa[j]]!=i){
				G[fa[j]].push_back(i);
				deg[i]++;
			} 
		}
		if(!deg[i])u=i;
	}
	queue<int>q;
	if(u)q.push(u);
	vector<int>ans;
	while(!q.empty()){
		u=q.front();
		q.pop();
		for(;u;u=pre[u]){
			ans.push_back(u);
			for(auto& v:G[u]){
				if(!(--deg[v]))q.push(v);
			}
		}
	}
	if(ans.size()==n){
		for(auto& i:ans)cout<<i<<' ';
	}
	else cout<<0;
}