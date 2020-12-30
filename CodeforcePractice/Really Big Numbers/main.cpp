#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

const int maxn = 2e5 + 5, mod = 1e9 + 7;
int a[maxn];

long long change(long long r)
{
    long long t = 1e18, ans = 0;
    --t; 
    bool ok = false;
    for(; t>0; t/=10) {
        if (r / t >= 1) {
            ans = ans * 10 + r / t;
            r %= t;
            ok = true;
        } else if (ok) ans = ans * 10;
    }
    return ans * 10;
}

int main()
{
    long long a, b;
    cin >> a >> b;
    long long r = (b / 9) + (b % 9 != 0);
    r = r * 9;
    r = change(r);
    cout << max(a - r + 1, 1LL*0);
    return 0;
}

