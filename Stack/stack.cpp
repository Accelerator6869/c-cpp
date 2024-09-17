#include <iostream>
#include <stdlib.h>

typedef struct stack
{
    int top;      // 最后一个元素的下标
    int maxSize;  // 能容纳的最多元素个数
    int *elsment; // 指针指向一片连续的内存空间，用来储存元素
} stack;

// 创造一个容纳mSize个元素的空堆栈
void Create(stack *s, int mSize)
{
    s->maxSize = mSize;
    s->elsment = (int *)malloc(sizeof(int) * mSize);
    s->top = -1;
}

// 销毁已经存在的堆栈
void Destroy(stack *s)
{
    s->maxSize = 0;
    free(s->elsment);
    s->top = -1;
}

// 判断是否为空栈
bool IsEmpty(stack *s)
{
    return s->top == -1;
}

// 判断栈是否已满
bool IsFull(stack *s)
{
    return s->top == s->maxSize - 1;
}

// 获取栈顶元素,并通过*x返回
bool GetTop(stack *s, int *x)
{
    // 空栈
    if (IsEmpty(s))
        return false;
    *x = s->elsment[s->top];
    return true;
}

// 在栈顶插入元素
bool Push(stack *s, int x)
{
    // 溢出
    if (IsFull(s))
    {
        return false;
    }
    s->top++;
    s->elsment[s->top] = x;
    return true;
}

// 删除栈顶元素
bool Delete(stack *s)
{
    // 空栈
    if (IsEmpty(s))
        return false;
    s->top--;
    return true;
}

// 清除堆栈全部元素，但不释放空间
void Clear(stack *s)
{
    s->top = -1;
}


