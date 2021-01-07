#include <bits/stdc++.h>
#define in(x, y) (x > 0 && x <= n && y > 0 && y <= n)
#define nx (x + dx[i])
#define ny (y + dy[i])
using namespace std;
int n, m, cnt, f[1005][1005], vis[1005][1005], sum[1000005];
char a[1005][1005];
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
void dfs(int x, int y, int o)
{
	if (vis[x][y])
		return;
	f[x][y] = o;
	vis[x][y] = 1;
	sum[o]++;
	for (int i = 0; i < 4; i++)
		if (in(nx, ny) && a[nx][ny] != a[x][y])
			dfs(nx, ny, o);
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%s", a[i] + 1);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (f[i][j] == 0)
				dfs(i, j, ++cnt);
	for (int i = 1; i <= m; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		printf("%d\n", sum[f[x][y]]);
	}
}