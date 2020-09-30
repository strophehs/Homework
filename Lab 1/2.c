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
	int l = 0, r = n - 1;
	for (int i = 0; i < n; i++)
	{
		int x;
		scanf("%d", &x);
		if (x % 2 == 1)
			L->data[l++] = x;
		else
			L->data[r--] = x;
		L->size++;
	}
	return L;
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
	scanf("%d", &n);
	OrderedList = CreateOrderedList(n);
	PrintList(OrderedList);
}