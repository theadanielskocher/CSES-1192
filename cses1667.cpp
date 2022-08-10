#include<bits/stdc++.h>
using namespace std;

#define int long long

const int maxN = 1e5 + 5;

int d[maxN];
vector<int>node[maxN];
int path[maxN];
int n, m;

void BFS (int z)
{
	queue<int>q;
	d[z] = 0;
	q.push(z);
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		for (auto v : node[u])
		{
			if (d[v] == -1)
			{
				d[v] = d[u] + 1;
				path[v] = u;
				q.push(v);
			}
		}
	}
}


signed main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= m; i++)
  {
  	int u, v;
  	cin >> u >> v;
  	node[u].push_back(v);
  	node[v].push_back(u);
  }
  fill(d+1,d+1+n,-1);
  BFS(1);
  if (d[n] == -1) cout << "IMPOSSIBLE\n";
  else
  {
  	vector<int>result;
  	int x = n;
  	while (x != 1)
  	{
  		result.push_back(x);
  		x = path[x];
	}
	result.push_back(1);
	reverse(result.begin(), result.end());
	cout << result.size() << '\n';
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << " ";
	}
   }
   return 0;
}
