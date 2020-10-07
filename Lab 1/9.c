#include <stdio.h>
#include <stdlib.h>
#define alloc_node (BList *)malloc(sizeof(BList))
typedef struct Bidirectional_Linklist
{
	int data;
	struct Bidirectional_Linklist *next[2];
} BList;
BList *headL[2];
int DIR = 0;
void CreateLinklist(int n)
{
	headL[0] = alloc_node;
	headL[1] = alloc_node;
	headL[0]->next[0] = headL[1]->next[0] = headL[0]->next[1] = headL[1]->next[1] = NULL;
	BList *prev = headL[0];
	BList *tmp = alloc_node;
	for (int i = 1; i <= n; i++)
	{
		tmp = alloc_node;
		scanf("%d", &tmp->data);
		prev->next[0] = tmp;
		tmp->next[1] = prev;
		prev = tmp;
	}
	tmp->next[0] = headL[1];
	headL[1]->next[1] = tmp;
	tmp = alloc_node;
}
void PrintList(BList *L, int n)
{
	BList *tmp = L;
	int sum = 0;
	while (tmp->next[DIR] != NULL && sum < n)
	{
		tmp = tmp->next[DIR];
		printf("%d ", tmp->data);
		sum++;
	}
	printf("\n");
}
int main()
{
	int n;
	scanf("%d", &n);
	CreateLinklist(n);
	PrintList(headL[DIR], n);
	DIR ^= 1;
	PrintList(headL[DIR], n);
}