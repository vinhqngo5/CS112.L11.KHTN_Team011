#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int t;
  cin>>t;
  while(t--){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>g(n+10);
    while(m--){
      int x,y;
      cin>>x>>y;
      g[y].push_back(x);
    }
    vector<int>dp(n+10);
    vector<int>ans;
    for(int i=1;i<=n;i++){
      for(int j:g[i]){
        if(dp[j]<2)dp[i]=max(dp[i],dp[j]+1);
      }
      if(dp[i]==2)ans.push_back(i);
    }
    cout<<ans.size()<<endl;
    for(int i:ans)cout<<i<<' ';
    cout<<endl;
  }
}