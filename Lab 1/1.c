#include <stdio.h>
#include <stdlib.h>
#define alloc_node (OList *)malloc(sizeof(OList))
typedef struct OrderedList
{
	int data[100000];
	int size;
} OList;
OList *CreateOrderedList(int n)
{
	OList *L = alloc_node;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &L->data[i]);
		L->size++;
	}
	return L;
}
int Find(OList *L, int x)
{
	int pos = -1;
	if (L == NULL)
		return -1;
	for (int i = 0; i < L->size; i++)
	{
		if (L->data[i] == x)
		{
			pos = i;
			return pos;
		}
		else
			pos++;
	}
	return -1;
}
void Insert(OList *L, int n, int x)
{
	for (int i = L->size - 1; i >= n; i--)
		L->data[i + 1] = L->data[i];
	L->data[n] = x;
	L->size++;
}
void Delete(OList *L, int n)
{
	for (int i = n; i < L->size; i++)
		L->data[i] = L->data[i + 1];
	L->size--;
}
void PrintList(OList *L)
{
	int size = L->size;
	for (int i = 0; i < size; i++)
		printf("%d ", L->data[i]);
	printf("\n");
}
int main()
{
	OList *OrderedList;
	int op, n, x;
	while (scanf("%d", &op))
	{
		switch (op)
		{
		case 1:
			scanf("%d", &n);
			OrderedList = CreateOrderedList(n);
			break;
		case 2:
			scanf("%d", &x);
			int pos = Find(OrderedList, x);
			if (pos == -1)
				printf("Cannot find\n");
			else
				printf("%d\n", pos);
			break;
		case 3:
			scanf("%d%d", &n, &x);
			if (OrderedList->size < 10000 - 1)
				Insert(OrderedList, n, x);
			else
				printf("OrderedList has been full. Cannot insert any element.\n");
			break;
		case 4:
			scanf("%d", &n);
			if (n < 0 || OrderedList->size <= n)
				printf("Cannot delete.\n");
			else
				Delete(OrderedList, n);
			break;
		case 0:
			PrintList(OrderedList);
			break;
		}
	}
}