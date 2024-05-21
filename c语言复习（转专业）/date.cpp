//按照年月日输入日期并进行排序，然后输出
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct date
{
    int y, m, d;
}date;
void sort(date* a, int n)
{
    int i;
    date t; 
    for (i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[j].y * 10000 + a[j].m * 100 + a[j].d > a[i].y * 10000 + a[i].m * 100 + a[i].d);
            {
                t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        printf("%d-%d-%d\n", a[i].y, a[i].m, a[i].d);
    }
}
int main()
{
    date* a;
    int n;
    printf("请输入数组的元素个数\n");
    scanf("%d", &n);
    a = (date*)malloc(n * sizeof(date));
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d %d", &a[i].y, &a[i].m, &a[i].d);
    }
    sort(a, n);
    return 0;
}