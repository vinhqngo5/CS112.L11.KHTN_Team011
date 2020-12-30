#include <bits/stdc++.h>

using namespace std;
const int N= 1e5+1;
int s[N], n, q, cnt[N];
struct interval{
      int st[4*N], lazy[4*N];
      void build(int node, int l, int r, int c)
      {
            lazy[node]= -1;
            if (l==r) {
                  st[node]= (s[l]==c);
                  return;
            }
            int mid= (l+r)/2;
            build(node*2, l, mid, c);
            build(node*2+1, mid+1, r, c);
            st[node]= st[node*2]+ st[node*2+1];
      }
      void down(int node, int l, int r)
      {
            if (lazy[node]==-1) return ;
            int mid= (l+r)/2;
            lazy[node*2]= lazy[node];
            st[node*2]= (mid-l+1)*lazy[node];
            lazy[node*2+1]= lazy[node];
            st[node*2+1]= lazy[node]*(r-mid);
            lazy[node]= -1;
      }
      void update(int node, int l, int r, int u, int v, int val)
      {
            if (l>v|| r<u) return;
            if (u<=l&& r<=v) {
                  lazy[node]= val;
                  st[node]= lazy[node]*(r-l+1); return;
            }
            down(node, l, r);
            int mid= (l+r)/2;
            update(node*2, l, mid, u, v, val);
            update(node*2+1, mid+1, r, u, v, val);
            st[node]= st[node*2]+ st[node*2+1];
      }
      int get(int node, int l, int r, int u, int v)
      {
            if (l>v|| r<u) return 0;
            if (u<=l&& r<=v) return st[node];
            down(node, l, r);
            int mid= (l+r)/2;
            return get(node*2, l, mid, u, v)+ get(node*2+1, mid+1, r, u, v);
      }
};

interval IT[26];
int main()
{
      cin >> n >> q;
      for (int i=1; i<=n; ++i) {
            char c; cin >> c;
            s[i]= c-'a';
      }
      for (int i=0; i<26; ++i) IT[i].build(1, 1, n, i);
      while (q--){
            int l, r, type;
            cin >> l >> r >> type;
            for (int i=0; i<26; ++i) cnt[i]= IT[i].get(1, 1, n, l, r);
            if (type== 1) {
                  for (int i=0; i<26; ++i) if (!cnt[i]) continue; else{
                        IT[i].update(1, 1, n, l, l+cnt[i]-1, 1);
                        l+= cnt[i];
                  }
            } else for (int i=25 ;i>=0; --i) if (!cnt[i]) continue; else{
                        IT[i].update(1, 1, n, l, l+cnt[i]-1, 1);
                        l+= cnt[i];
                  }
      }
      for (int i=1; i<=n; ++i)
            for (int j=0; j<26; ++j) {
            int ok= IT[j].get(1, 1, n, i,i);
            if (ok==1) {
                  cout << char(j+ 'a');
                  break;
            }
      }
}
