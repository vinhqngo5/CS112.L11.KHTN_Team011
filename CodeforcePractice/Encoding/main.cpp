#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

const int maxn = 2e5 + 5, mod = 1e9 + 7, p = 1e6 + 1;
int n, m, power[maxn];
string s, t;
vector<int> T(26, 0), S(26, 0), ans;

int POW(int a, int b)
{
    if (b == 1) return a;
    int temp = POW(a, b / 2);
    temp = (1LL * temp * temp) % mod;
    if (b & 1) temp = (1LL * temp * a) % mod;
    return temp;
}

bool check(int pos)
{
    vector<int> Sfake = S;
    for(int i=0; i<26; ++i) Sfake[i] = (1LL * Sfake[i] * POW(power[pos - 1], mod - 2)) % mod;
    for(int i=0; i<26; ++i) if (Sfake[i] != 0) {
        bool ok = false;
        for(int j=0; j<26; ++j) 
            if (Sfake[i] == T[j] && T[i] == Sfake[j]) {
                ok = true;
                break;
            }
        if (!ok) return false;
    }
    return true;
}

int main()
{
    cin >> n >> m >> s >> t;
    s = ' ' + s;
    t = ' ' + t;
    power[0] = 1;
    for(int i=1; i<=n; ++i) power[i] = (1LL * power[i-1] * p) % mod;
    for(int i=1; i<=m; ++i) 
        T[t[i] - 'a'] = (T[t[i] - 'a'] + power[i]) % mod;
    for(int i=1; i<=m; ++i) 
        S[s[i] - 'a'] = (S[s[i] - 'a'] + power[i]) % mod;

    if (check(1)) ans.push_back(1);

    int prev = 1, cur = m;
    for(int i=2; i<=n - m + 1; ++i){
        S[s[prev] - 'a'] = (S[s[prev] - 'a'] - power[prev] + 1LL * mod * mod) % mod;
        S[s[cur + 1] - 'a'] = (S[s[cur + 1] - 'a'] + power[cur + 1]) % mod;
        if (check(i)) ans.push_back(i);
        prev++; cur++; 
    }
    cout << ans.size() << "\n";
    for(int i : ans) cout << i << " ";
}
