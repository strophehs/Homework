#include <stdio.h>
#include <stdlib.h>
typedef struct
{
	char a[50];
	int top;
} STACK_char;
void Init_char(STACK_char *s)
{
	s->top = -1;
}
void Push_char(STACK_char *s, char *c)
{
	s->top++;
	s->a[s->top] = *c;
}
char Pop_char(STACK_char *s)
{
	if (s->top == -1)
	{
		printf("empty\n");
		return 0;
	}
	s->top--;
	return (s->a[s->top + 1]);
}
typedef struct
{
	int a[50];
	int top;
} STACK_int;
void Init_int(STACK_int *s)
{
	s->top = -1;
}
void Push_int(STACK_int *s, int *c)
{
	s->top++;
	s->a[s->top] = *c;
}
int Pop_int(STACK_int *s)
{
	if (s->top == -1)
	{
		printf("empty\n");
		return 0;
	}
	s->top--;
	return (s->a[s->top + 1]);
}

int priority(char x)
{
	if (x == '+' || x == '-')
		return 1;
	else
		return 2;
}
int yunsuan(int x, int y, char z)
{
	if (z == '+')
		return x + y;
	else if (z == '-')
		return x - y;
	else if (z == '*')
		return x * y;
	else
		return x / y;
}
int main()
{
	char str[100];
	scanf("%s", str);
	STACK_int A;
	STACK_char B;
	Init_int(&A);
	Init_char(&B);
	int i;
	i = 0;
	while (1)
	{
		if (str[i] == '@')
		{
			while (A.top != 0)
			{
				int w, x, y;
				char z;
				x = Pop_int(&A);
				y = Pop_int(&A);
				z = Pop_char(&B);
				w = yunsuan(y, x, z);
				Push_int(&A, &w);
			}
			int q = Pop_int(&A);
			printf("%d", q);
			break;
		}
		if (str[i] == '*' || str[i] == '/' || str[i] == '+' || str[i] == '-')
		{
			if (B.top == -1)
				Push_char(&B, &str[i]);
			else if (priority(str[i]) >= priority(B.a[B.top]))
				Push_char(&B, &str[i]);
			else
			{
				int w;
				char z;
				int m;
				int y;
				w = Pop_int(&A);
				y = Pop_int(&A);
				z = Pop_char(&B);
				m = yunsuan(y, w, z);
				Push_int(&A, &m);
				Push_char(&B, &str[i]);
			}
		}
		else
		{
			int w;
			w = str[i] - '0';
			Push_int(&A, &w);
		}
		i++;
	}
}