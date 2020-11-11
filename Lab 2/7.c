#include <stdio.h>
#include <stdlib.h>
typedef struct list
{
	int data;
	struct list *next;
} list;
list *initnode()
{
	list *l = (list *)malloc(sizeof(list));
	l->data = 0;
	l->next = NULL;
	return l;
}
void initlist(list *l)
{
	list *q = l;
	int n;
	scanf("%d", &n);
	while (n--)
	{
		list *r = initnode();
		scanf("%d", &r->data);
		q->next = r;
		q = r;
	}
	list *r = initnode();
	q->next = r;
}
void display(list *l)
{
	list *p = l;
	while (p->next != NULL)
	{
		p = p->next;
		printf("%d ", p->data);
	}
	printf("\n");
}
list *func(list *l, int x, int y)
{
	list *q = l;
	if (q->next == NULL)
	{
		printf("%d%d", x, y);
		return;
	}
	if (q->data > x)
	{
		x = q->data;
	}
	y++;
	return func(q->next, x, y);
}
int main()
{
	list *l = initnode();
	initlist(l);
	display(l);
	func(l, 0, 0);
	return 0;
}
