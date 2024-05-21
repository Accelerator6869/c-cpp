#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int f(int a[], int n)
{
	//创建链表
	struct node
	{
		int info;
		struct node *next;
	}*h=NULL,*q=NULL,*p;
	int i;
	//将数组输入链表
	for (i = 0; i < n; i++)
	{
		p = (struct node*)malloc(sizeof(struct node));
		p->info = a[i];
		if (q != NULL)
			q->next = p;
		else
			h = p;
		q = p;
	}
	q->next=NULL;
	//判断是否递减
	q = h;
	if (q == NULL || q->next == NULL)//空链表或者只有一个节点的链表
		return 1;
	p = q->next;
	while ((p != NULL) && (p->info <= q->info))
	{
		q = p;
		p = p->next;//链表传递
	}
	if (p == NULL)return 1;
	return 0;
}
int main()
{
	int i,n,j;
	printf("请输入数组中元素个数:\n");
	scanf_s("%d", &n);
	int *a;
	a = (int*)malloc(sizeof(n * sizeof(int)));
	printf("请输入%d个元素",&n);
	for (i = 0; i < n; i++)
	{
		scanf_s("%d", a[i]);
	}
	j = f(a, n);
	printf("%s", j ? "yes" : "no");
}