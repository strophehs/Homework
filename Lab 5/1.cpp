#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
const int N = 1e3 + 5;
int G[N][N], n, m;
int main()
{
	cin >> n >> m;
	while (m--)
	{
		int u, v, w;
		cin >> u >> v >> w;
		G[u][v] = w;
	}
}