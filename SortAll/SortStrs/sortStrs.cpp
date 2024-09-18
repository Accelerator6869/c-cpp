#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 100  // 每个字符串的最大长度
#define MAX_STR_COUNT 100  // 最大字符串数量

// 定义一个字符串数组结构体，用于存储字符串和长度
typedef struct Sqlist
{
    char **strings; // 用于存储字符串的指针数组
    int length;     // 记录字符串数组长度
} Sqlist;

// 初始化字符串数组，读取文件中的字符串
void initArrayFromFile(Sqlist *L, const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        perror("无法打开文件");
        exit(EXIT_FAILURE);
    }

    L->strings = (char **)malloc(MAX_STR_COUNT * sizeof(char *)); // 为字符串指针数组分配内存
    char buffer[MAX_STR_LEN];
    int count = 0;

    while (fgets(buffer, MAX_STR_LEN, file) != NULL)
    {
        buffer[strcspn(buffer, "\n")] = 0; // 去除换行符
        L->strings[count] = (char *)malloc(strlen(buffer) + 1); // 分配内存给每个字符串
        strcpy(L->strings[count], buffer); // 复制字符串
        count++;
    }

    L->length = count; // 设置字符串数量
    fclose(file); // 关闭文件
}

// 找出字符串数组中 l 到 r 之间最小的字符串，并返回其下标
int findMin(Sqlist *L, int l, int r)
{
    int minIndex = l;
    for (int i = l + 1; i <= r; i++)
    {
        if (strcmp(L->strings[i], L->strings[minIndex]) < 0)
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

// 希尔排序，用于对字符串数组进行排序
void shellSort(Sqlist *L)
{
    int gap = L->length;
    while (gap > 1)
    {
        gap /= 2;
        for (int i = gap; i < L->length; i++)
        {
            char *temp = L->strings[i];
            int j = i;
            while (j >= gap && strcmp(L->strings[j - gap], temp) > 0)
            {
                L->strings[j] = L->strings[j - gap];
                j -= gap;
            }
            L->strings[j] = temp;
        }
    }
}

// 输出字符串数组到文件
void outputToFile(Sqlist *L, const char *filename)
{
    FILE *file = fopen(filename, "w");
    if (file == NULL)
    {
        perror("无法打开文件");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < L->length; i++)
    {
        fprintf(file, "%s\n", L->strings[i]);
    }

    fclose(file);
}

// 释放内存
void freeArray(Sqlist *L)
{
    for (int i = 0; i < L->length; i++)
    {
        free(L->strings[i]);
    }
    free(L->strings);
}

int main()
{
    Sqlist L;

    // 从文件中读取字符串
    const char *inputFile = "input.txt";
    const char *outputFile = "output.txt";
    initArrayFromFile(&L, inputFile);

    // 对字符串进行排序
    shellSort(&L);

    // 将排序后的字符串输出到文件
    outputToFile(&L, outputFile);

    // 释放内存
    freeArray(&L);

    return 0;
}
