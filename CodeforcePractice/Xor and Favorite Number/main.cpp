#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

const int maxn = 1e5 + 5, mod = 1e9 + 7;
struct Data
{
    int l, r, id, k;
    Data() {}
    Data(int l, int r, int id, int k): l(l), r(r), id(id), k(k) {}
};
int n, q, L, Time, ans[maxn], mau[maxn], idx[maxn], cnt[maxn], f[maxn], inp[maxn], out[maxn];
Data d[maxn];
vector<int> a[maxn];

bool block(int x, int y)
{
    return x / L == y / L;
}
bool cmp(Data x, Data y)
{
    if (!block(x.l, y.l)) 
        return x.l / L < y.l / L;
    else if (x.l / L & 1) return x.r < y.r;
    else return x.r > y.r;
}
void add(int l, int r, int k)
{
    for(int i=l; i<=r; ++i) {
        f[++cnt[mau[idx[i]]]]++;
    }
}
void rem(int l, int r, int k)
{
    for(int i=l; i<=r; ++i) {
        --f[cnt[mau[idx[i]]]--];
    }
}
void DFS(int u, int p = -1)
{
    inp[u] = ++Time;
    idx[Time] = u;
    for(int v: a[u]) 
        if (v != p) DFS(v, u);
    out[u] = Time;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> q;
    for(int i=1; i<=n; ++i) cin >> mau[i];
    L = sqrt(n);
    for(int i=2; i<=n; ++i) {
        int u, v; 
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    DFS(1);
    for(int i=1; i<=q; ++i){
        int v, k; cin >> v >> k;
        d[i] = Data(inp[v], out[v], i, k);
    }
    
    sort(d + 1, d + q + 1, cmp);
    f[0] = n;
    add(d[1].l, d[1].r, d[1].k);
    ans[d[1].id] = f[d[1].k];
    for(int i=2; i<=q; ++i){
        int l = d[i-1].l, r = d[i-1].r;
        if (l < d[i].l) rem(l, d[i].l - 1, d[i].k);
            else add(d[i].l, l - 1, d[i].k);
        if (r < d[i].r) add(r + 1, d[i].r, d[i].k);
            else rem(d[i].r + 1, r, d[i].k);
        ans[d[i].id] = f[d[i].k];
    }
    for(int i=1; i<=q; ++i) cout << ans[i] << '\n';
    return 0;
}
