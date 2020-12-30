#include<bits/stdc++.h>

using namespace std;
const int maxn = 5e3 + 5, mod = 1e9 + 7, base = 307;
int n, a, b, f[maxn]; string s;
bool w[maxn][maxn];
long long p[maxn], h[maxn];

void process(int m)
{
    f[m] = f[m - 1] + a;
    string t = s.substr(1, m) + ' ';
    reverse(t.begin(), t.end());
    vector<int> z(m + 1, 0);
    int l = 0, r = 0;
    z[1] = 1;
    for(int i=2; i<=m; ++i) {
        if (i <= r) z[i] = min(z[i - l + 1], r - i + 1);
        while (i + z[i] <= m && t[i + z[i]] == t[z[i] + 1]) ++z[i];
        if (i + z[i] - 1 > r) l = i, r = z[i] + i - 1;
        if (z[i] < i) f[m] = min(f[m - z[i]] + b, f[m]);
    } 
}

int main()
{
    cin >> n >> a >> b >> s;
    s = ' ' + s;
    for(int i=1; i<=n; ++i) process(i);
    cout << f[n];
    return 0;
}
