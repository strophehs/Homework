#include <bits/stdc++.h>
using namespace std;
const int INF = INT_MAX;
int G[1000][1000], n, m;
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (i == j)
				G[i][j] = 0;
			else
				G[i][j] = INF;
	for (int i = 1; i <= m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		G[u][v] = w;
	}
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (G[i][j] > G[i][k] + G[k][j])
					G[i][j] = G[i][k] + G[k][j];
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			cout << G[i][j] << " ";
		putchar('\n');
	}
}