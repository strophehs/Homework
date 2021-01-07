#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
const int N = 1e5 + 5;
vector<int> G[N];
bool vis[N];
int main()
{
	int n, m;
	cin >> n >> m;
	while (m--)
	{
		int u, v;
		cin >> u >> v;
		G[u].emplace_back(v);
	}
	queue<int> q;
	int start;
	cin >> start;
	q.push(start);
	vis[start] = 1;
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		cout << u << ",";
		for (int i = 0; i < G[u].size(); i++)
		{
			if (!vis[G[u][i]])
			{
				q.push(G[u][i]);
				vis[G[u][i]] = 1;
			}
		}
	}
}