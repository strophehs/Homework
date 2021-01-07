#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 5, M = 2e5 + 5;
const int inf = 0x3f3f3f3f;
struct edge
{
	int v, w, next;
} e[M << 1];
int head[N], dis[N], cnt, n, m, tot, now = 1, ans;
bool vis[N];
void add(int u, int v, int w)
{
	e[++cnt] = (edge){v, w, head[u]};
	head[u] = cnt;
}
void init()
{
	cin >> n >> m;
	for (int i = 1; i <= m; ++i)
	{
		int u, v, w;
		cin >> u >> v >> w;
		add(u, v, w), add(v, u, w);
	}
}
int prim()
{
	memset(dis, 0x3f, sizeof dis);
	for (int i = head[1]; i; i = e[i].next)
		dis[e[i].v] = min(dis[e[i].v], e[i].w);
	while (++tot < n)
	{
		int minn = inf;
		vis[now] = 1;
		for (int i = 1; i <= n; ++i)
		{
			if (!vis[i] && minn > dis[i])
			{
				minn = dis[i];
				now = i;
			}
		}
		ans += minn;
		for (int i = head[now]; i; i = e[i].next)
		{
			int v = e[i].v;
			if (dis[v] > e[i].w && !vis[v])
				dis[v] = e[i].w;
		}
	}
	return ans;
}
int main()
{
	init();
	cout << prim();
}