#include <stdio.h>
#include <stdlib.h>
int f(int m, int n)
{
	return m == 0 ? 0 : f(m - 1, 2 * n) + n;
}
int ff(int m, int n)
{
	return (1 << m - 1) * n;
}
int main()
{
	int m, n;
	scanf("%d%d", &m, &n);
	printf("%d\n", f(m, n));
	printf("%d\n", ff(m, n));
}
