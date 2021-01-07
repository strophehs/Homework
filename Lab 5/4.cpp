#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
const int N = 1e3 + 5;
int G[N][N], n, m;
bool vis[N];
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
	stack<int> st;
	st.push(start);
	int size = 1;
	cout << start << ",";
	while (!st.empty())
	{
		int u = st.top();
		vis[u] = 1;
		int i;
		for (i = 1; i <= n; i++)
		{
			if (G[u][i] && !vis[i])
			{
				vis[i] = 1;
				st.push(i);
				size++;
				cout << i << ",";
				break;
			}
		}
		if (i == n + 1)
			st.pop();
	}
}