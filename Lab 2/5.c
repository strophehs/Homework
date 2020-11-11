#include <stdio.h>
#include <stdlib.h>
typedef struct slist
{
	int data;
	struct slist *next;
} slist;
slist *initnode()
{
	slist *s = (slist *)malloc(sizeof(slist));
	s->next = NULL;
	return s;
}
void Push(slist *s, int x)
{
	slist *p = initnode();
	p->data = x;
	p->next = s->next;
	s->next = p;
}
void Pop(slist *s)
{
	slist *p = s->next;
	s->next = p->next;
	free(p);
}
int gettop(slist *s)
{
	slist *p = s->next;
	return p->data;
}
int isempty(slist *s)
{
	int cnt = 0;
	slist *p = s;
	while (p->next != NULL)
	{
		p = p->next;
		cnt++;
	}
	if (cnt != 0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
void display(slist *s)
{
	slist *p = s;
	while (p->next != NULL)
	{
		p = p->next;
		printf("%c ", (char)p->data);
	}
	printf("\n");
}
void trans(slist *op, char exp[], char postexp[])
{
	char ch;
	int i = 0, j = 0;
	ch = exp[i];
	i++;
	while (ch != '\0')
	{
		switch (ch)
		{
		case '(':
			Push(op, (int)ch);
			break;
		case ')':
			while ((char)gettop(op) != '(')
			{
				postexp[j] = gettop(op);
				j++;
				Pop(op);
			}
			Pop(op);
			break;
		case '+':
		case '-':
			while (!isempty(op) && gettop(op) != '(')
			{
				postexp[j] = gettop(op);
				j++;
				Pop(op);
			}
			Push(op, (int)ch);
			break;
		case '*':
		case '/':
			while (!isempty(op) && gettop(op) != '(' && (gettop(op) == '*' || gettop(op) == '/'))
			{
				postexp[j] = gettop(op);
				j++;
				Pop(op);
			}
			Push(op, (int)ch);
			break;
		case ' ':
			break;
		default:
			while (ch >= '0' && ch <= '9')
			{
				postexp[j] = ch;
				j++;
				ch = exp[i];
				i++;
			}
			i--;
			postexp[j] = '#';
			j++;
		}
		ch = exp[i];
		i++;
	}
	while (!isempty(op))
	{
		postexp[j] = gettop(op);
		j++;
		Pop(op);
	}
	postexp[j] = '\0';
}
float compvalue(slist *st, char postexp[])
{
	float d;
	char ch;
	int i = 0, m, n;
	ch = postexp[i];
	i++;
	while (ch != '\0')
	{
		switch (ch)
		{
		case '+':
			m = gettop(st);
			Pop(st);
			n = gettop(st);
			Pop(st);
			Push(st, (int)n + m);
			break;
		case '-':
			m = gettop(st);
			Pop(st);
			n = gettop(st);
			Pop(st);
			Push(st, (int)n - m);
			break;
		case '*':
			m = gettop(st);
			Pop(st);
			n = gettop(st);
			Pop(st);
			Push(st, (int)n * m);
			break;
		case '/':
			if (gettop(st) != 0)
			{
				m = gettop(st);
				Pop(st);
				n = gettop(st);
				Pop(st);
				Push(st, (int)n / m);
				break;
			}
			else
			{
				printf("No.\n");
				exit(0);
			}
			Pop(st);
			break;
		default:
			d = 0;
			while (ch >= '0' && ch <= '9')
			{
				d = 10 * d + ch - '0';
				ch = postexp[i];
				i++;
			}
			Push(st, d);
		}
		ch = postexp[i];
		i++;
	}
	return gettop(st);
}
int main()
{
	char exp[20];
	scanf("%s", exp);
	char postexp[30];
	float f = 0.0;
	slist *op = initnode(), *st = initnode();
	trans(op, exp, postexp);
	f = compvalue(st, postexp);
	printf("%s = %.2f\n", exp, f);
	return 0;
}
