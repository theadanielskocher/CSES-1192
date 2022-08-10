#include<bits/stdc++.h>
using namespace std;

#define int long long

bool went[1005][1005];
bool San[1005][1005];

void DFS (int i, int j)
{
	went[i][j] = true;
	if (San[i + 1][j] == true && went[i + 1][j] == false) DFS(i+1,j);
	if (San[i - 1][j] == true && went[i - 1][j] == false) DFS(i-1,j);
	if (San[i][j + 1] == true && went[i][j + 1] == false) DFS(i,j+1);
	if (San[i][j - 1] == true && went[i][j - 1] == false) DFS(i,j-1);
}

signed main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
  {
  	for (int j = 1; j <= m; j++)
  	{
  		char c;
  		cin >> c;
  		if (c == '.') San[i][j] = true;
	}
  }
  int res = 0;
  for (int i = 1; i <= n; i++)
  {
  	for (int j = 1; j <= m; j++)
  	{
  		if (San[i][j] == true && went[i][j] == false)
  		{
  			res++;
  			DFS(i,j);
		}
	}
  }
  cout << res;
  
}
