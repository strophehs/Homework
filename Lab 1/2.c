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
void Sort(OList *L)
{
	int l = 0, r = L->size - 1;
	while (l < r && l < L->size && r > -1)
	{
		while (L->data[l] % 2 == 1)
			l++;
		while (L->data[r] % 2 == 0)
			r--;
		if (l >= r)
			break;
		int t = L->data[l];
		L->data[l] = L->data[r];
		L->data[r] = t;
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
	OList *OrderedList;
	int n;
	scanf("%d", &n);
	OrderedList = CreateOrderedList(n);
	Sort(OrderedList);
	PrintList(OrderedList);
}