#include <stdio.h>
#include <string.h>
char x[1005], y[1005];
int b[1005][1005], c[1005][1005], lena, lenb;
void dp()
{
	for (int i = 1; i <= lena; i++)
		for (int j = 1; j <= lenb; j++)
		{
			if (x[i - 1] == y[j - 1])
			{
				c[i][j] = c[i - 1][j - 1] + 1;
				b[i][j] = 0;
			}
			else if (c[i - 1][j] >= c[i][j - 1])
			{
				c[i][j] = c[i - 1][j];
				b[i][j] = 1;
			}
			else
			{
				c[i][j] = c[i][j - 1];
				b[i][j] = -1;
			}
		}
}
void print(int i, int j)
{
	if (i == 0 || j == 0)
		return;
	if (b[i][j] == 0)
	{
		print(i - 1, j - 1);
		printf("%c ", x[i - 1]);
	}
	else if (b[i][j] == 1)
		print(i - 1, j);
	else
		print(i, j - 1);
}

int main()
{
	scanf("%s%s", x, y);
	lena = strlen(x);
	lenb = strlen(y);
	dp();
	print(lena, lenb);
}