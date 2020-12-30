#include <bits/stdc++.h>

using namespace std;
const int maxn = 50 + 5;
char a[maxn][maxn];

int main()
{
    int test; cin >> test;
    while(test--){
        int n; cin >> n;
        bool ok = true;
        for(int i=1; i<=n; ++i)
            for(int j=1; j<=n; ++j) cin >> a[i][j];
        for(int i=n-1; i>=1; --i)
            for(int j=n-1; j>=1; --j) if (a[i][j] == '1')
                if (a[i][j+1] == '0' && a[i+1][j] != '1') ok = false; 
            
        if (ok) cout << "YES\n";
        else cout << "NO\n";
    }
}


