#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100000
typedef struct stack
{
	char ch[50];
	int top;
} Stack;
int Pop(Stack *st)
{
	if (st->top == 0)
	{
		printf("Stack empty\n");
		return 0;
	}
	st->top--;
	return st->ch[st->top];
}
void Push(Stack *st, char c)
{
	if (st->top == MAX)
	{
		printf("Stack overflow\n");
		return;
	}
	st->ch[st->top] = c;
	st->top++;
}
void check(Stack *st, char *a)
{
	Push(st, a[0]);
	for (int i = 1; i < strlen(a); i++)
	{
		if ((a[i] == ']' && st->ch[st->top - 1] == '[') || (a[i] == ')' && st->ch[st->top - 1] == '(') || (a[i] == '}' && st->ch[st->top - 1] == '{'))
			Pop(st);
		else
			Push(st, a[i]);
	}
	if (st->top == 0)
		printf("Yes\n");
	else
		printf("No\n");
}
void main()
{
	char s[10000];
	Stack *st = (Stack*)malloc(sizeof(Stack));
	scanf("%s", s);
	check(st, s);
}