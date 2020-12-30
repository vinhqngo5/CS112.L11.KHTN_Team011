#include <bits/stdc++.h>

using namespace std;
const int maxn = 5e4 + 5;
int a[maxn];
int main()
{
    int n; cin >> n;
    cout << "? 1 2 " << endl; int A1; cin >> A1;
    cout << "? 2 3 " << endl; int A2; cin >> A2;
    cout << "? 1 3 " << endl; int A3; cin >> A3;
    int sum = (A1 + A2 + A3)/2;
    a[1] = sum - A2;
    a[2] = sum - A3;
    a[3] = sum - A1;
    for(int i=4; i<=n; ++i){
        cout << "? 1 " << i << endl;
        cin >> sum;
        a[i] = sum - a[1];
    }
    cout << "! ";
    for(int i=1; i<=n; ++i) cout << a[i] << " ";
}


