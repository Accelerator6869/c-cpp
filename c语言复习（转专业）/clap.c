#include<stdio.h>
#include<stdlib.h>
int Seven(int n)//含有7or是7的倍数则返回1，否则返回0
{
    int b[100] = { 0 };
    int temp = n, i = 0, j = 0;
    while (temp)
    {
        b[i++] = temp % 10;
        temp /= 10;
    }
    while (b[j++])
    {
        if (b[j] == 7)
            return 1;
    }
    if (!n % 7)
    {
        return 1;
    }
    return 0;
}
int ClapTimes(int n, int m, int k, int* a, int* b)//一共n个人，编号为m的人第k次拍手
{
    int s = 0;//报数
    a = (int*)calloc(n, sizeof(int));//a储存每个人报的数
    b = (int*)calloc(n, sizeof(int));//b储存拍手次数
    while (1) {
        for (int i = 0; i < n - 1; i++)
        {
            a[i] = ++s;
            if (Seven(a[i]))
            {
                b[i]++;
            }
        }
        for (int j = n - 1; j > 0; j--)
        {
            a[j] = ++s;
            if (Seven(a[j]))
            {
                b[j]++;
            }
        }
        if (b[m - 1] == k)
        {
            free(a);
            free(b);
            return s;
        }
    }
}
int main()
{
    int n, m, k, c[100], i = 0;//一共n个人，编号为m的人第k次拍手,c[]储存拍手时本应该报的数
    int* a=NULL;
    int* b=NULL;
    do {
        scanf_s("%d%d%d", &n, &m, &k);
        c[i++] = ClapTimes(n, m, k, a, b);
    } while (n || m || k);
    int j = 0;
    while (c[j++])
    {
        printf("%d", c[j]);
    }
    return 0;
}