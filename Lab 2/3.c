#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct Node
{
	char data;
	struct Node *next;
} Node, *LinkStack;
int palindrome(char *str)
{
	int i = 0;
	char ch;
	Node *tmp = NULL, *p;
	while (true)
	{
		ch = str[i++];
		if (ch == '\0')
			break;
		p = (Node *)malloc(sizeof(Node));
		p->data = ch;
		p->next = tmp;
		tmp = p;
	}
	i = 0;
	while (tmp != NULL)
	{
		p = tmp;
		ch = p->data;
		tmp = tmp->next;
		free(p);
		if (ch != str[i++])
			return 0;
	}
	return 1;
}
void main()
{
	char s[100000];
	scanf("%s", s);
	if (palindrome(s))
		printf("Yes\n");
	else
		printf("No\n");
}