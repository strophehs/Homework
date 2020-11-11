#include <stdio.h>
struct node
{
	int x, y;
} b[1001];
int a[101][101], flag;
const int x[8] = {0, -1, 0, 1, 1, 1, -1, -1}, y[8] = {-1, 0, 1, 0, 1, -1, 1, -1};
void print(int n)
{
	flag = 1;
	for (int i = 1; i <= n; i++)
	{
		if (i < n)
			printf("(%d,%d)->", b[i].x, b[i].y);
		else
			printf("(%d,%d)\n", b[i].x, b[i].y);
	}
}
void search(int n, int x1, int y1, int x2, int y2)
{
	for (int i = 0; i < 8; i++)
	{
		a[x1][y1] = 0;
		x1 += x[i];
		y1 += y[i];
		if (a[x1][y1])
		{
			b[n].x = x1;
			b[n].y = y1;
			if (x1 == x2 && y1 == y2)
				print(n);
			else
				search(n + 1, x1, y1, x2, y2);
		}
		x1 -= x[i];
		y1 -= y[i];
		a[x1][y1] = 1;
	}
}
int main()
{
	int n, m, x1, y1, x2, y2;
	scanf("%d%d", &m, &n);
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			scanf("%d", &a[i][j]);
	scanf("%d %d\n%d %d", &x1, &y1, &x2, &y2);
	b[1].x = x1;
	b[1].y = y1;
	search(2, x1, y1, x2, y2);
	if (!flag)
		printf("-1");
}