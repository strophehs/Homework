#include <stdio.h>
#include <stdlib.h>
#define alloc_node (LNode *)malloc(sizeof(LNode))
typedef struct LNode
{
	int data;
	struct LNode *next;
} LNode;
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
int Insert(LNode *L, int n, int x)
{
	int pos = 0;
	LNode *tmp = L;
	while (tmp->next != NULL && pos < n)
	{
		pos++;
		tmp = tmp->next;
		if (pos == n)
		{
			LNode *p = alloc_node;
			p->data = x;
			p->next = tmp->next;
			tmp->next = p;
			return 1;
		}
	}
	return -1;
}
int Size(LNode *L)
{
	int size = 0;
	LNode *tmp = L;
	while (tmp->next != NULL)
	{
		size++;
		tmp = tmp->next;
	}
	return size;
}
void ReverseList(LNode *L, int l, int r)
{
	if (l<=0 || l >= r || r>=Size(L))
		return;
	LNode *h = alloc_node;
	h->next = L;
	LNode *pre = h;
	for (int i = 0; i < l - 1; ++i)
		pre = pre->next;
	LNode *pne = h;
	for (int i = 0; i < r + 1; i++)
		pne = pne->next;
	LNode *p1 = pre->next;
	LNode *p2 = p1->next;
	LNode *p3;
	while (p2 && p2 != pne)
	{
		p3 = p2->next;
		p2->next = p1;
		p1 = p2;
		p2 = p3;
	}
	pre->next->next = pne;
	pre->next = p1;
	L = h->next;
	return;
}
int main()
{
	int n, l, r;
	LNode *Linklist = alloc_node;
	scanf("%d", &n);
	Linklist = TailCreateList(n);
	PrintList(Linklist);
	scanf("%d", &l);
	scanf("%d", &r);
	ReverseList(Linklist, l, r);
	PrintList(Linklist);
}