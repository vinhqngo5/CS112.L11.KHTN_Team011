#include <bits/stdc++.h>
#define debug(x) cerr << #x << " = " << x << "\n";
using namespace std;

int main()
{
    int test; cin >> test;
    while (test--){
        int n; cin >> n;
        string t, s; bool ok = true, lem = false;
        cin >> s >> t;
        vector<int> cs(27, 0), ct(27, 0);
        for(auto c: s) cs[c-'a']++;
        for(auto c: t) ct[c-'a']++;
        for(int i=0; i<27; ++i) if (cs[i] != ct[i]) {
            ok = false;
            break;
        }
        if (!ok) {
            cout << "NO\n";
            continue;
        }
        for(int i=0; i<27; ++i) if (cs[i] > 1) {
            lem = true;
            break;
        }
        if (lem) {
            cout << "YES\n";
            continue;
        }
        int inv1 = 0, inv2 = 0;
        for(int i=0; i<n-1; ++i)
            for(int j=i+1; j<n; ++j) inv1 += (s[i] > s[j]);
        for(int i=0; i<n-1; ++i)
            for(int j=i+1; j<n; ++j) inv2 += (t[i] > t[j]);
        if (inv1 % 2 == inv2 % 2) cout << "YES\n";
        else cout << "NO\n";
    }
}

