#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;          // 结点的数据域
    struct node *next; // 结点的指针域
} node;

typedef struct SingleList
{
    node *first; // 头结点
    int n;       // 结点个数
} SingleList;

int init(SingleList *L)
{
    L->first = NULL;
    L->n = 0;
    return 1;
}

// 查找ai的值
int find(SingleList *L, int i, int *x)
{
    node *p;
    int j;

    // 对i进行越界检查
    if (i < 0 || i > L->n - 1)
    {
        return 0;
    }

    p = L->first;

    // 从头开始查找ai
    for (j = 0; j < i; j++)
    {
        p = p->next;
    }

    // 通过x返回ai的值
    *x = p->data;

    return 1;
}

// 找到对应数据的下标并返回，如果没有则返回-1
int search(SingleList *L, int x)
{
    node *p;
    int i = 0; // 下表初始为0
    p = L->first;

    while (p->data != x)
    {
        p = p->next;
        i++;
    }

    // 如果存在该数，则返回第一个数的位置
    if (i >= 0 && i < L->n)
    {
        return i;
    }
    // 如果没找到，返回-1
    else
    {
        return -1;
    }
}

int Delete(SingleList *L, int i)
{
    int j;
    node *p, *q;

    // 如果链表为空
    if (!L->n)
    {
        return 0;
    }

    // 如果i超出范围
    if (i < 0 || i > L->n - 1)
    {
        return 0;
    }

    q = L->first;
    p = L->first;

    for (j = 0; j < i - 1; j++)
    {
        q = q->next;
    }

    // 如果删除的是头结点
    if (i == 0)
    {
        L->first = L->first->next; //?
    }
    else
    {
        p = q->next;       // p指向ai
        q->next = p->next; // 从单链表中删除p所指向的结点
    }

    // 释放p所指结点的储存空间
    free(p);

    L->n--;
    return 1;
}

int destroy(SingleList *L)
{

    node *p;
    while (L->first)
    {
        p = L->first->next; // 保留后继结点地址，防止“断链”
        free(L->first);     // 释放first所指结点的存储空间
        L->first = p;
    }
}

int output(SingleList *L)
{
    node *p;

    // 判断顺序表是否为空
    if (!L->n)
    {
        return 0;
    }

    p = L->first;

    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    return 1;
}

int insert(SingleList *L, int i, int x)
{
    node *p, *q;
    int j;

    // 判断i是否越界，若越界，则返回error
    if (i < -1 || i > L->n - 1)
    {
        return 0;
    }

    p = L->first; // 头节点

    // 从头结点开始查找ai，第一个是a0，p指向ai
    for (j = 0; j < i; j++)
    {
        p = p->next;
    }

    // 赋予新结点内存空间和值
    q = (node *)malloc(sizeof(node));
    q->data = x;

    // 新结点插在p所指结点之后,因此插入位置是i+1
    if (i > -1)
    {
        // 二者顺序不能颠倒
        q->next = p->next;
        p->next = q;
        // q是第i+1个
    }
    // 新结点在头节点之前，成为新的头节点
    else
    {
        // 二者顺序不能颠倒
        q->next = L->first;
        L->first = q;
        // q是第0+1个
    }
    L->n++;
    return 1;
}

int main()
{
    int i;
    int x;

    // 创建链表
    SingleList *list;

    // 初始化链表
    init(list);

    // 线性表中插入1，2，3，4……
    for (i = 0; i < 9; i++)
    {
        insert(list, i - 1, i);
    }

    printf("the linklist is:\n");

    // 输出链表
    output(list);

    // 查找某个位置的元素并打印出来
    find(list, 0, &x);
    printf("the value is:\n");
    printf("%d ", x);

    // 销毁list
    destroy(list);
    return 0;
}
