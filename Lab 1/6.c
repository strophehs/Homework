#include <stdio.h>
#include <stdlib.h>
#define alloc_node (LNode *)malloc(sizeof(LNode))
typedef struct LNode
{
	int data;
	struct LNode *next;
} LNode;

LNode *HeadCreateList(int n)
{
	LNode *head = alloc_node;
	LNode *tmp = head;
	tmp->next = NULL;
	for (int i = 1; i <= n; i++)
	{
		LNode *p = alloc_node;
		scanf("%d", &p->data);
		p->next = tmp->next;
		tmp->next = p;
	}
	return head;
}
LNode *TailCreateList(int n)
{
	LNode *tail = alloc_node;
	LNode *tmp = tail;
	tmp->next = NULL;
	for (int i = 1; i <= n; i++)
	{
		LNode *p = alloc_node;
		scanf("%d", &p->data);
		tmp->next = p;
		tmp = p;
	}
	tmp->next = NULL;
	return tail;
}
void PrintList(LNode *L)
{
	LNode *p = L;
	while (p->next != NULL)
	{
		p = p->next;
		printf("%d ", p->data);
	}
	printf("\n");
}
int Find(LNode *L, int x)
{
	int pos = 0;
	LNode *tmp = L;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
		pos++;
		if (x == tmp->data)
			return pos;
	}
	return -1;
}
int main()
{
	int op, n, x;
	LNode *Linklist = alloc_node;
	while (scanf("%d", &op))
	{
		switch (op)
		{
		case 1:
			scanf("%d", &n);
			Linklist = HeadCreateList(n);
			break;
		case 2:
			scanf("%d", &n);
			Linklist = TailCreateList(n);
			break;
		case 3:
			scanf("%d", &x);
			printf("%d\n", Find(Linklist, n - k + 1));
			break;
		case 0:
			PrintList(Linklist);
			break;
		}
	}
}