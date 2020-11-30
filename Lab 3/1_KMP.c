#include <stdio.h>
#include <string.h>
int len1, len2, next[1000005];
char a[1000005], b[1000005];
void getnext(char s[])
{
	for (int i = 2, j = 0; i <= len2; i++)
	{
		while (j && s[i] != s[j + 1])
			j = next[j];
		if (s[i] == s[j + 1])
			j++;
		next[i] = j;
	}
}
void kmp(char s[], char t[])
{
	for (int i = 1, j = 0; i <= len1; i++)
	{
		while (j && s[i] != t[j + 1])
			j = next[j];
		if (s[i] == t[j + 1])
			j++;
		if (j == len2)
			printf("%d\n", i - len2 + 1);
	}
}
int main()
{
	scanf("%s%s", a + 1, b + 1);
	len1 = strlen(a + 1);
	len2 = strlen(b + 1);
	getnext(b);
	kmp(a, b);
	for (int i = 1; i <= len2; i++)
		printf("%d ", next[i]);
}