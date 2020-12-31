#include<bits/stdc++.h>
using namespace std;
#define pi pair<int,int>
#define F first
#define S second
const int N=1000005;
int n,m,k,X,Y,x,y,a[N],st[N][2],fa[N],sz[N],top,tp,i,b[N];
long long ans;
map<pi,vector<pi> >mp;
int find(int x){return x==fa[x]?x:find(fa[x]);}
void merge(int x,int y){
	if((x=find(x))==(y=find(y))) return;
	if (sz[x]>sz[y]) swap(x,y);
	fa[x]=y,sz[y]+=sz[x],st[++top][0]=x,st[top][1]=y;
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for (i=1;i<=n;i++) scanf("%d",&a[i]);
	for (i=1;i<=n*2;i++) fa[i]=i,sz[i]=1;
	for (i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		X=a[x],Y=a[y];
		if (X>Y) swap(X,Y);
		if (X==Y){
			merge(x+n,y),merge(x,y+n);
			if (find(x)==find(y) && !b[X]) b[X]=1,k--;
		}else mp[{X,Y}].push_back({x,y});
	}
	ans=1ll*k*(k-1)/2;
	for (auto it:mp){
		if (b[it.F.F] || b[it.F.S]) continue;
		tp=top;
		for (auto p:it.S){
			x=p.F,y=p.S;
			merge(x+n,y),merge(x,y+n);
			if (find(x)==find(y)){
				ans--;
				break;
			}
		}
		while (top>tp) fa[st[top][0]]=st[top][0],sz[st[top][1]]-=sz[st[top][0]],top--;
	}
	printf("%lld",ans);
}