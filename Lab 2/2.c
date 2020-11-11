#include <stdio.h>
#include <malloc.h>
#define MAX 100
typedef struct
{
	int *base;
	int *top;
} Stack;
int init(Stack *S)
{
	S->base = (int *)malloc(MAX * sizeof(Stack));
	if (S->base == NULL)
		return 0;
	S->top = S->base;
	return 1;
}
int empty(Stack *S)
{
	if (S->top == S->base)
		return 1;
	else
		return 0;
}
int Push(Stack *S, int e)
{
	if (S->top - S->base == MAX)
		return 0;
	*(S->top) = e;
	S->top++;
	return 1;
}
int Pop(Stack *S, int *e)
{
	if (empty(&S) == 0)
	{
		(S->top)--;
		*e = *(S->top);
		return 1;
	}
	else
		return 0;
}
void conversion(Stack S, int n, int r)
{
	int e;
	init(&S);
	while (n)
	{
		Push(&S, n % r);
		n = n / r;
	}
	while (!empty(&S))
	{
		Pop(&S, &e);
		printf("%d", e);
	}
}
void main()
{
	int n, r;
	Stack S;
	scanf("%d%d", &n, &r);
	conversion(S, n, r);
}