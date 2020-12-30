#include <bits/stdc++.h>

using namespace std;
const int maxn = 3005;
typedef pair<int, int> ii;
int n, f[maxn][maxn][2];

struct Tree
{
    int n, m, h[maxn], height, s[maxn], p[maxn][20];
    vector<int> a[maxn];
    void input(int t)
    {
        memset(h, 0, sizeof(h));
        memset(s, 0, sizeof(s));
        m = t;
        cin >> n;
        for(int i=2; i<=n; ++i){
            int x; cin >> x;
            a[x].push_back(i);
        }
        for(int i=1; i<=m; ++i) cin >> s[i];
    }
    void DFS(int u, int H = 0)
    {
        h[u] = H; height = max(height, H);
        for(int v: a[u]) {
            DFS(v, H + 1);
            p[v][0] = u;
        }
    }
    void initLCA()
    {
        memset(p, 255, sizeof(p));
        DFS(1);
        int k = log2(height);
        for(int j=1; j<=k; ++j)
            for(int i=1; i<=n; ++i) 
        if (p[i][j-1] != -1) p[i][j] = p[p[i][j-1]][j-1];
    }
    int getlca(int u, int v)
    {
        if (h[u] < h[v]) swap(u, v);
        int k = log2(h[u]);
        for(int i=k; i>=0; --i) 
            if (h[u] - (1 << i) >= h[v]) u = p[u][i];
        if (u == v) return u;
        for(int i=k; i>=0; --i)
        if (p[u][i] != p[v][i] && p[u][i] != -1){
            u = p[u][i];
            v = p[v][i];
        }
        return p[u][0];
    }
};
Tree T1, T2;

int cost(int type, int u, int v)
{
    if (v == 0) return 0;
    if (!type) {
        if (u == 0) return T1.h[v];
        int lca = T1.getlca(u, v);
        return T1.h[v] - T1.h[lca];
    }
    if (u == 0) return T2.h[v];
    int lca = T2.getlca(u, v);
    return T2.h[v] - T2.h[lca];
}

int dp(int i, int prev, int type)
{
    if (i == n) return 0;
    int &res = f[i][prev][type];
    if (res != -1) return res;
    if (!type) {
        res = dp(i + 1, prev, 0) + cost(0, T1.s[i], T1.s[i+1]);
        res = min(res, dp(i + 1, i, 1) + cost(1, T2.s[prev], T2.s[i+1]));
    } else {
        res = dp(i + 1, prev, 1) + cost(1, T2.s[i], T2.s[i+1]);
        res = min(res, dp(i + 1, i, 0) + cost(0, T1.s[prev], T1.s[i+1]));
    }
    return res;
}
int main()
{
    cin >> n;
    T1.input(n); T2.input(n);
    T1.initLCA(); T2.initLCA();
    memset(f, 255, sizeof(f));
    int ans = min(dp(1, 0, 0) + T1.h[T1.s[1]], dp(1, 0, 1) + T2.h[T2.s[1]]);
    cout << T1.n + T2.n - 2 - ans;
    return 0;
}
