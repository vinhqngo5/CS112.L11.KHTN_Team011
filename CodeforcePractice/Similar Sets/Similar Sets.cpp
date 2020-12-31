#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 5;
int n, deg[N], cnt[N];
vector<int> G[N], G2[N];
int tot;
map<int, int> id;
int get(int x)
{
	if (!id.count(x))
	{
		id[x] = ++tot;
		return tot;
	}
	return id[x];
}
bool cmp(int x, int y) { return deg[x] < deg[y] || (deg[x] == deg[y] && x < y); }
void solve()
{
	scanf("%d", &n);
	for (int i = 1; i <= tot; i++) deg[i] = cnt[i] = 0, G[i].clear(), G2[i].clear();
	id.clear();
	tot = n;
	vector<pair<int, int>> edges;
	for (int i = 1; i <= n; i++)
	{
		int k; scanf("%d", &k);
		for (int j = 1, x; j <= k; j++)
		{
			scanf("%d", &x);
			x = get(x);
			G[i].push_back(x); G[x].push_back(i);
			deg[x]++, deg[i]++;
			edges.emplace_back(x, i);
		}
	}
	for (auto it : edges)
		if (cmp(it.first, it.second)) G2[it.first].push_back(it.second);
		else G2[it.second].push_back(it.first);
	for (int u = 1; u <= tot; u++)
	{
		for (int v : G[u])
			for (int w : G2[v])
				if (cmp(u, w))
				{
					if (cnt[w])
					{
						if (u <= n) printf("%d %d\n", u, w);
						else printf("%d %d\n", v, cnt[w]);
						return;
					}
					else cnt[w] = v;
				}
		for (int v : G[u])
			for (int w : G2[v])
				if (cmp(u, w)) cnt[w] = 0;
	}
	puts("-1");
}
int main()
{
	int _; scanf("%d", &_);
	while (_--) solve();
	return 0;
}