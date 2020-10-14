#include <stdio.h>
#include <stdlib.h>
#define alloc_node (cNode *)malloc(sizeof(cNode))
typedef struct cNode
{
    int base;
    int pow;
    struct cNode *next;
} cNode;
cNode *HeadCreate(int n)
{
	cNode *L = alloc_node;
	for (int i = 0; i < n; i++)
	{
		cNode *tmp = alloc_node;
		scanf("%d%d", &tmp->base, &tmp->pow);
		L->next = tmp->next;
		tmp->next = L;
	}
	return L;
}
cNode *TailCreate(int n)
{
    cNode *L;
    L = alloc_node;
    for (int i = 0; i < n; i++)
    {
        cNode *tmp=alloc_node;
        scanf("%d%d", &tmp->base, &tmp->pow);
        L->next = tmp;
        L = tmp;
    }
    L->next=NULL;
    return L;
}
void Divide(cNode *L)
{
    cNode *q, *p, *rear;
    int i = 0;
    rear = L;
    q = L->next;
    p = L;
    while (rear->next != L)
    {
        rear = rear->next;
        if (rear->pow % 2 == 0)
            i++;
    }
    while (i)
    {
        if (q->pow % 2 == 0)
        {
            p->next = q->next;
            q->next = L;
            rear->next = q;
            rear = q;
            q = p->next;
            i--;
        }
        else
        {
            p = p->next;
            q = p->next;
        }
    }
}
void view(cNode *L)
{
    cNode *p;
    p = L->next;
    printf("Odd：\n");
    int flag = 0;
    while ((p->pow) % 2 != 0)
    {
        if (!flag)
            printf("%dx^%d", p->base, p->pow);
        else
            printf("+%dx^%d", p->base, p->pow);
        p = p->next;
        flag ^= 1;
    }
    printf("\n");
    printf("Even：\n");
    while (p != L)
    {
        printf("%dx^%d", p->base, p->pow);
        if (p->next != L)
            printf("+");
        p = p->next;
    }
    printf("\n");
}
int main()
{
    cNode *L;
    int n, op;
    scanf("%d%d", &n, &op);
    if (op)
        L = HeadCreate(n);
    else
        L = TailCreate(n);
    Divide(L);
    view(L);
}
