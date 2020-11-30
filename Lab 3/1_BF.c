#include <stdio.h>
#include <string.h>
char a[1000005], b[1000005];
int lena, lenb;
int main()
{
	scanf("%s%s", a + 1, b + 1);
	lena = strlen(a + 1), lenb = strlen(b + 1);
	for (int i = 1; i <= lena; i++)
	{
		bool f = 0;
		for (int j = 1; j <= lenb; j++)
		{
			if (a[i + j - 1] == b[j])
				continue;
			else
			{
				f = 1;
				break;
			}
		}
		if (!f)
			printf("%d\n", i);
	}
}