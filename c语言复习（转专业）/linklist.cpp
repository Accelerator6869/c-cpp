#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int f(int a[], int n)
{
	//��������
	struct node
	{
		int info;
		struct node *next;
	}*h=NULL,*q=NULL,*p;
	int i;
	//��������������
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
	//�ж��Ƿ�ݼ�
	q = h;
	if (q == NULL || q->next == NULL)//���������ֻ��һ���ڵ������
		return 1;
	p = q->next;
	while ((p != NULL) && (p->info <= q->info))
	{
		q = p;
		p = p->next;//������
	}
	if (p == NULL)return 1;
	return 0;
}
int main()
{
	int i,n,j;
	printf("������������Ԫ�ظ���:\n");
	scanf_s("%d", &n);
	int *a;
	a = (int*)malloc(sizeof(n * sizeof(int)));
	printf("������%d��Ԫ��",&n);
	for (i = 0; i < n; i++)
	{
		scanf_s("%d", a[i]);
	}
	j = f(a, n);
	printf("%s", j ? "yes" : "no");
}