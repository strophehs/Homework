#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
const int N = 1e5 + 5;
struct node
{
	int v, w;
};
vector<node> G[N];
int main()
{
	int n, m;
	cin >> n >> m;
	while (m--)
	{
		int u, v, w;
		cin >> u >> v >> w;
		G[u].emplace_back((node){v, w});
	}
}