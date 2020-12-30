#include <bits/stdc++.h>

using namespace std;
const int maxn = 132000;
int n, m, st[maxn*4], a[maxn];

void build(int id, int l, int r, int depth)
{
    if (l == r) {
        st[id] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(id*2, l, mid, depth - 1);
    build(id*2+1, mid+1, r, depth - 1);
    if (depth&1) st[id] = st[id*2] | st[id*2+1];
    else st[id] = st[id*2] ^ st[id*2+1];
}
void update(int id, int l, int r, int u, int val, int depth)
{
    if (u > r || l > u) return;
    if (l == r){
        st[id] = val;
        return;
    }
    int mid = (l + r) >> 1;
    update(id*2, l, mid, u, val, depth - 1);
    update(id*2+1, mid+1, r, u, val, depth - 1);
    if (depth&1) st[id] = st[id*2] | st[id*2+1];
    else st[id] = st[id*2] ^ st[id*2+1];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i=1; i<=(1 << n); ++i) cin >> a[i];
    build(1, 1, 1 << n, n);
    while (m--){
        int u, v; cin >> u >> v;
        update(1, 1, (1 << n), u, v, n);
        cout << st[1] << "\n";
    }
    return 0;
}


