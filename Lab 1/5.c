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
int Modify(LNode *L, int n, int x)
{
	int pos = 0;
	LNode *tmp = L;
	while (tmp->next != NULL && pos < n)
	{
		pos++;
		tmp = tmp->next;
		if (pos == n)
		{
			tmp->data = x;
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
int DeleteNode(LNode *L, int n)
{
	int pos = 0;
	LNode *tmp = L;
	while (tmp->next != NULL & pos < n - 1)
	{
		pos++;
		tmp = tmp->next;
	}
	LNode *target = tmp->next;
	if (target == NULL)
		return -1;
	else if (tmp->next->next == NULL)
	{
		tmp->next = NULL;
		free(target);
		target = NULL;
	}
	else
	{
		tmp->next = tmp->next->next;
		free(target);
		target = NULL;
	}
	return 1;
}
int ClearWholeList(LNode *L)
{
	free(L);
	L = NULL;
	return 1;
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
			printf("%d\n", Find(Linklist, x));
			break;
		case 4:
			scanf("%d%d", &n, &x);
			Insert(Linklist, n, x);
			break;
		case 5:
			scanf("%d%d", &n, &x);
			Modify(Linklist, n, x);
			break;
		case 6:
			printf("%d\n", Size(Linklist));
			break;
		case 7:
			scanf("%d", &n);
			DeleteNode(Linklist, n);
			break;
		case 8:
			ClearWholeList(Linklist);
			break;
		case 0:
			PrintList(Linklist);
			break;
		}
	}
}