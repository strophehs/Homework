#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
const int N = 1e3 + 5;
int G[N][N], n, m;
bool vis[N];
void dfs(int x)
{
	if (vis[x])
		return;
	vis[x] = 1;
	cout << x << ",";
	for (int i = 1; i <= n; i++)
	{
		if (i == x)
			continue;
		else if (G[x][i])
			dfs(i);
	}
}
int main()
{
	cin >> n >> m;
	while (m--)
	{
		int u, v;
		cin >> u >> v;
		G[u][v] = 1;
	}
	int start;
	cin >> start;
	dfs(start);
}