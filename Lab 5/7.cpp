#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, int> P;
const int N = 1e5 + 5, M = 2e5 + 5;
int n, m, s, d[N], head[M], cnt;
bool vis[M];
struct edge
{
	int v, w, next;
} e[M];
struct node
{
	int idx, dis;
	bool operator<(const node &a) const
	{
		return a.dis < dis;
	}
};
void add(int u, int v, int w)
{
	e[++cnt].next = head[u];
	head[u] = cnt;
	e[cnt].v = v;
	e[cnt].w = w;
}
priority_queue<P, vector<P>, greater<P>> q;
void dijkstra()
{
	q.push(P(0, s));
	while (!q.empty())
	{
		P p = q.top();
		q.pop();
		int now = p.second;
		if (vis[now])
			continue;
		vis[now] = 1;
		for (int i = head[now]; i; i = e[i].next)
		{
			int v = e[i].v, w = e[i].w;
			if (d[v] > d[now] + w)
			{
				d[v] = d[now] + w;
				if (!vis[v])
					q.push(P(d[v], v));
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> m >> s;
	for (int i = 1, u, v, w; i <= m; i++)
	{
		cin >> u >> v >> w;
		add(u, v, w);
	}
	memset(d, 0x3f, sizeof(d));
	d[s] = 0;
	dijkstra();
	for (int i = 1; i <= n; i++)
		cout << d[i] << " ";
}