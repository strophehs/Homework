#include <stdio.h>
#include <stdlib.h>
#define alloc_node (LNode *)malloc(sizeof(LNode))
typedef struct LNode
{
	int data;
	struct LNode *next;
} LNode;
LNode *HeadCreate(int n)
{
	LNode *L = alloc_node;
	for (int i = 0; i < n; i++)
	{
		LNode *tmp = alloc_node;
		scanf("%d", tmp->data);
		L->next = tmp->next;
		tmp->next = L;
	}
	return L;
}
LNode *TailCreate(int n)
{
	LNode *L = alloc_node;
	for (int i = 0; i < n; i++)
	{
		LNode *tmp = alloc_node;
		scanf("%d", &tmp->data);
		L->next = tmp;
		L = tmp;
	}
	L->next = NULL;
	return L;
}
void Sort(LNode *L)
{
	int flag = 1;
	LNode *p1, *p2, *t;
	t = L->next;
	p1 = L->next;
	p2 = p1->next;
	while (p2 != NULL)
	{
		if (flag % 2)
		{
			L->next = p2;
			p1->next = p2->next;
			p2->next = t;
			t = L->next;
			p2 = p1->next;
			flag ^= 1;
		}
		else
		{
			p1 = p1->next;
			p2 = p2->next;
			flag ^= 1;
		}
	}
}
void PrintList(LNode *L)
{
	LNode *p = L->next;
	while (p != NULL)
	{
		printf("%d ", &p->data);
		p = p->next;
	}
	printf("\n");
}
int main()
{
	LNode *L = alloc_node;
	int n, op;
	scanf("%d%d", &n, &op);
	if (op)
		L = HeadCreate(n);
	else
		L = TailCreate(n);
	PrintList(L);
	Sort(L);
	PrintList(L);
}