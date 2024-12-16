#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 声明结构体记录数组的元素和长度
typedef struct Sqlist
{
    int *nums;  // 定义一个指针指向数组所在内存空间
    int length; // 记录数组长度
} Sqlist;

// 初始化数组，赋予length个单位的内存空间,并生成随机数来填充数组
void initArray(Sqlist *L, int length)
{
    L->length = length;                                 // 初始化数组长度
    L->nums = (int *)malloc(sizeof(int) * (L->length)); //// 申请内存空间
    srand(time(NULL));

    for (int i = 0; i < L->length; i++)
    {
        L->nums[i] = rand() % 2000; // 限制随机数的范围，生成0~1999之间的随机数
    }
}

// 找出数组里l,r之间最小的数并返回下标
int findMin(Sqlist *L, int l, int r)
{
    int minIndex = l; // 初始化最小的数的下标
    for (int i = l + 1; i <= r; i++)
    {
        // 如果发现更小的数
        if (L->nums[i] < L->nums[minIndex])
        {
            minIndex = i;
        }
    }
    return minIndex;
}

// 交换两个数的值
void Swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 选择排序
void selectSort(Sqlist *L)
{
    for (int i = 0; i < L->length - 1; i++)
    {
        int minNum = findMin(L, i, L->length - 1); // 找到l和l->length之间最小的数组下标
        if (minNum != i)
        {
            Swap(&(L->nums[minNum]), &(L->nums[i]));
        }
    }
}

// 希尔排序
void shellSort(Sqlist *L)
{
    int gap = L->length; // 初始间隔为数组长度
    while (gap > 1)
    {
        gap /= 2;                             // 间隔减半
        for (int i = gap; i < L->length; i++) // 从 gap 开始
        {
            int temp = L->nums[i]; // 暂存要插入的值
            int j = i;             // 记录要插入的位置

            /*j >= gap：
            确保比较的是合法范围内的元素，不越界。*/
            /*L->nums[j - gap] > temp：
            比较当前元素 temp 和前 gap 位置的元素（L->nums[j - gap]），
            如果当前元素较小，则继续后移 gap 个位置，直到找到正确的位置。*/
            while (j >= gap && L->nums[j - gap] > temp) // 按 gap 比较元素
            {
                L->nums[j] = L->nums[j - gap]; // 后移元素
                j -= gap;
            }
            L->nums[j] = temp; // 插入正确位置
        }
    }
}

// 按照每行十个输出数组
void outPut(Sqlist *L)
{
    int cnt = 0;
    for (int i = 0; i < L->length; i++)
    {
        printf("%4d ", L->nums[i]);
        cnt++;
        if (cnt % 10 == 0)
        {
            printf("\n");
        }
    }
    printf("\n");
}

int main()
{
    Sqlist L;           // 声明结构体
    initArray(&L, 100); // 初始化数组

    // 输出排序前的数组
    printf("Array before sorting:\n");
    outPut(&L);

    // 排序
    // selectSort(&L);
    shellSort(&L);

    // 输出排序后的数组
    printf("Array after sorting:\n");
    outPut(&L);

    // 释放内存空间
    free(L.nums);
    return 0;
}
