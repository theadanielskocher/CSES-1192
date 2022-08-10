#include<bits/stdc++.h>
using namespace std;

#define int long long
const int maxN = 1e5 + 5;

vector<int>nodes[maxN];
vector<int>result;
vector<bool>vis(maxN, false);


void dfs (int node)
{
	vis[node] = true;
	for (auto v : nodes[node])
	{
		if (vis[v] == false)
		{
			dfs(v);
		}
	}
}

signed main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int u, v;
		cin >> u >> v;
		nodes[u].push_back(v);
		nodes[v].push_back(u);
	}
	for (int i = 1; i <= n; i++)
	{
		if (vis[i] == false)
		{
			result.push_back(i);
			dfs(i);
		}
	}
	cout << result.size() - 1 << endl;
    for (int i = 0; i < result.size() - 1; i++) {
      cout << result[i] << " " << result[i + 1] << endl;
    }
}
