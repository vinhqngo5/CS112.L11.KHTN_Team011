#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void solve(){
	ll n;
	cin>>n;
	set<ll> edges[n+1];
	for(int i=1;i<=n;i++){
		int a,b;
		cin>>a>>b;
		edges[a].insert(b);
		edges[b].insert(a);
	}
	queue<ll> q;
	for(int i=1;i<=n;i++){
		if(edges[i].size()==1){
			q.push(i);
		}
	}
	vector<ll> v(n+1,1);
	while(!q.empty()){
		int x=q.front();
		q.pop();
		int par=*edges[x].begin();
		v[par]+=v[x];
		v[x]=0;
		edges[x].clear();
		edges[par].erase(x);
		if(edges[par].size()==1){
			q.push(par);
		}
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		ans+=(v[i]*(v[i]-1))/2;
		ans+=v[i]*(n-v[i]);
	}
	cout<<ans<<endl;
}
int main(){
	int t=1;
	cin>>t;
	while(t--){
		solve();
	}
}