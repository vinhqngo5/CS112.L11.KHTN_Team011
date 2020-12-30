#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

const int maxn = 2e5 + 5, mod = 1e9 + 7;
const long long oo = 1e15;
vector<int> a[maxn];
int cost[maxn], b[maxn], c[maxn], n, t1[maxn], t2[maxn];
long long ans;

void DFS(int u, int p = -1, int m = 2e9)
{
    if (b[u] != c[u]) {
        t1[u] += (b[u] == 0);
        t2[u] += (b[u] == 1);
    }
    for(int v: a[u]) if (v != p) {
        DFS(v, u, min(m, cost[u]));
        t1[u] += t1[v];
        t2[u] += t2[v];
    }
    if (cost[u] < m) {
        int x = min(t1[u], t2[u]);
        ans += 1LL * x * 2 * cost[u];
        t1[u] -= x;
        t2[u] -= x;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i=1; i<=n; ++i) {
        cin >> cost[i] >> b[i] >> c[i];
    }
    for(int i=1; i<n; ++i) {
        int u, v; cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    DFS(1);
    if (t1[1] || t2[1]) return cout << -1,0;
    cout << ans;
    return 0;
}
