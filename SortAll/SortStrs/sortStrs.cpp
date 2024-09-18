#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// 定义一个字符串数组结构体，用于存储字符串和长度
typedef struct Sqlist
{
    char **strings; // 用于存储字符串的指针数组
    int length;     // 记录字符串数组长度
} Sqlist;

// 生成指定长度的随机字符串
void generateRandomString(char *str, int length)
{
    for (int i = 0; i < length - 1; i++)
    {
        str[i] = 'A' + rand() % 26; // 生成 A-Z 之间的随机字符
    }
    str[length - 1] = '\0'; // 字符串结束符
}

// 初始化字符串数组，生成 `count` 个字符串，每个字符串长度为 `strLength`
void initArray(Sqlist *L, int count, int strLength)
{
    L->length = count;                                    // 初始化数组长度
    L->strings = (char **)malloc(count * sizeof(char *)); // 为字符串指针数组分配内存
    srand(time(NULL));

    for (int i = 0; i < count; i++)
    {
        L->strings[i] = (char *)malloc(strLength * sizeof(char)); // 为每个字符串分配内存
        generateRandomString(L->strings[i], strLength);           // 生成随机字符串
    }
}

// 找出字符串数组中 l 到 r 之间最小的字符串，并返回其下标
int findMin(Sqlist *L, int l, int r)
{
    int minIndex = l; // 初始化最小字符串的下标
    for (int i = l + 1; i <= r; i++)
    {
        if (strcmp(L->strings[i], L->strings[minIndex]) < 0) // 使用 strcmp 比较字符串
        {
            minIndex = i;
        }
    }
    return minIndex;
}

// 交换两个字符串
void Swap(char **a, char **b)
{
    char *temp = *a;
    *a = *b;
    *b = temp;
}

// 选择排序，用于对字符串数组进行排序
void selectSort(Sqlist *L)
{
    for (int i = 0; i < L->length - 1; i++)
    {
        int minNum = findMin(L, i, L->length - 1); // 找到 l 到 L->length 之间最小的字符串下标
        if (minNum != i)
        {
            Swap(&(L->strings[minNum]), &(L->strings[i]));
        }
    }
}

// 希尔排序，用于对字符串数组进行排序
void shellSort(Sqlist *L)
{
    int gap = L->length; // 初始间隔为数组长度
    while (gap > 1)
    {
        gap /= 2;                             // 间隔减半
        for (int i = gap; i < L->length; i++) // 从 gap 开始
        {
            char *temp = L->strings[i]; // 暂存要插入的字符串
            int j = i;
            while (j >= gap && strcmp(L->strings[j - gap], temp) > 0) // 使用 strcmp 按 gap 比较字符串
            {
                L->strings[j] = L->strings[j - gap]; // 后移字符串
                j -= gap;
            }
            L->strings[j] = temp; // 插入正确位置
        }
    }
}

// 输出字符串数组
void outPut(Sqlist *L)
{
    for (int i = 0; i < L->length; i++)
    {
        printf("%s\n", L->strings[i]);
    }
    printf("\n");
}

// 释放内存
void freeArray(Sqlist *L)
{
    for (int i = 0; i < L->length; i++)
    {
        free(L->strings[i]); // 释放每个字符串的内存
    }
    free(L->strings); // 释放字符串指针数组的内存
}

int main()
{
    Sqlist L;                             // 声明结构体
    initArray(&L, 10, 6);                 // 初始化字符串数组，生成 10 个长度为 6 的字符串

    // 输出排序前的字符串数组
    printf("Strings before sorting:\n");
    outPut(&L);

    // 排序
    // selectSort(&L);
    shellSort(&L);

    // 输出排序后的字符串数组
    printf("Strings after sorting:\n");
    outPut(&L);

    // 释放内存空间
    freeArray(&L);
    return 0;
}
