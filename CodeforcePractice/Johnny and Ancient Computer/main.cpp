#include<bits/stdc++.h>

using namespace std;

long long ans(long long x)
{
    int y = log2(x);
    if (1LL << y != x) return -1;
    int res = 0;
    res += y/3 + (y % 3 != 0);
    return res;
}

int main()
{
    int test; cin >> test;
    while (test--){
        long long a, b; cin >> a >> b;
        long long x = max(a, b), y = min(a, b);
        if (x % y != 0) cout << "-1\n";
        else {
            x /= y;
            cout  << ans(x) << "\n";
        }
    }
}
