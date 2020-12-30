#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

const int maxn = 1e6 + 5, mod = 1e9 + 7;
struct Data
{
    int l, r, id;
    Data() {}
    Data(int l, int r, int id): l(l), r(r), id(id) {}
};
int n, q, L, a[maxn], mp[maxn];
Data d[maxn];
long long ans[maxn];


bool block(int x, int y)
{
    return x / L == y / L;
}
bool cmp(Data x, Data y)
{
    if (!block(x.l, y.l)) 
        return x.l / L < y.l / L;
    else return x.r < y.r;
}
void process(int l, int r, long long &res, int val)
{
    for(int i=l; i<=r; ++i) {
        int &temp = mp[a[i]];
        res -= 1LL * temp * temp * a[i];
        temp += val;
        res += 1LL * temp * temp * a[i];
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> q;
    L = sqrt(n);
    for(int i=1; i<=n; ++i) {
        cin >> a[i];
    }
    for(int i=1; i<=q; ++i){
        int l, r; cin >> l >> r;
        d[i] = Data(l, r, i);
    }
    sort(d + 1, d + q + 1, cmp);
    for(int i=d[1].l; i<=d[1].r; ++i) mp[a[i]]++;
    for(int i=1; i<maxn; ++i) ans[d[1].id] += 1LL * mp[i] * mp[i] * i;
    for(int i=2; i<=q; ++i) {
        long long res = ans[d[i-1].id];
        int l = d[i-1].l, r = d[i-1].r;
        if (l < d[i].l) process(l, d[i].l - 1, res, -1);
            else process(d[i].l, l - 1, res, 1);
        if (r < d[i].r) process(r + 1, d[i].r, res, 1);
            else process(d[i].r + 1, r, res, -1);
        ans[d[i].id] = res;
    }
    for(int i=1; i<=q; ++i) cout << ans[i] << '\n';
    return 0;
}
