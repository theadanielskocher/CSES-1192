#include<bits/stdc++.h>
using namespace std;

#define int long long
const int maxN = 1e3 + 5;

char a[maxN][maxN];
int d[maxN][maxN];
bool vis[maxN][maxN];
int n, m, sx, sy, ex, ey;
int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};
char moveChar[]={'R','L','D','U'};


void bfs (int sx, int sy)
{
	for (int i = 1; i <= n; i++)
	{
		fill_n(d[i],m+1,0);
		fill_n(vis[i],m+1,false);
	}
	queue<pair<int,int>>q;
	q.push({sx, sy});
	vis[sx][sy] = true;
	while(!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		if (a[x][y] == 'B') return;
		for (int i = 0; i < 4; i++)
		{
			int u = x + moveX[i];
			int v = y + moveY[i];
			if (u > n || u < 1) continue;
			if (v > m || v < 1) continue;
			if (a[u][v] == '#') continue;
			
			if (!vis[u][v])
			{
				d[u][v] = d[x][y] + 1;
				vis[u][v] = true;
				a[u][v]=moveChar[i];
				q.push({u,v});
			}
		}
	}
}

signed main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> a[i][j];
			if (a[i][j] == 'A')
			{
				sx = i;
				sy = j;
			}
			if (a[i][j] == 'B')
			{
				ex = i;
				ey = j;
			}
		}
	}
	bfs(sx, sy);
	if (d[ex][ey] > 0) { cout << "YES\n";
	cout << d[ex][ey] << '\n';
	string ans = "";
	int c = ex;
	int currj = ey;
	while(!(c == sx && currj == sy)){
        ans += a[c][currj];
        switch(a[c][currj]){
            case 'D':
                c--;
                break;
            case 'U':
                c++;
                break;
            case 'R':
                currj--;
                break;
            case 'L':
                currj++;
                break;
        }
    }
    reverse(ans.begin(),ans.end());
    cout <<ans;}
    else cout << "NO";
}
