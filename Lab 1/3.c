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
void Delete(OList *L, int n)
{
	for (int i = n; i < L->size; i++)
		L->data[i] = L->data[i + 1];
	L->size--;
}
void Unique(OList *L)
{
	int pos = 1;
	while (pos < L->size)
	{
		if (L->data[pos] == L->data[pos - 1])
			Delete(L, pos);
		else
			pos++;
	}
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
	freopen("0.txt", "r", stdin);
	OList *OrderedList;
	int n;
	scanf("%d", &n);
	OrderedList = CreateOrderedList(n);
	Unique(OrderedList);
	PrintList(OrderedList);
}