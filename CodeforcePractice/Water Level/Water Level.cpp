#include <bits/stdc++.h>
 
using namespace std;
 
int main(int argc, char *argv[])
{
	long long k, l, r, t, x, y;
	cin >> k >> l >> r >> t >> x >> y;
	set<pair<long long, long long>> s;
	for (long long d = 1; t > 0; ) {
		if (s.count({d, k}) > 0) {
			t = 0;
			break;
		}
		s.insert({d, k});
		long long c = (r - k) / y;
		k += min(d, c) * y;
		d = (k - l) / x;
		if (d <= 0) break;
		k -= d * x;
		if (k < l) break;
		t -= d;
	}
	cout << (t <= 0 ? "Yes" : "No") << endl;
 
	return 0;
}