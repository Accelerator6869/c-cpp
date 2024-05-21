#include<stdio.h>
int main()
{
    int i, n, sign = 1;
    double sum = 0, x;
    scanf_s("%d", &n);
    for (i = 0; i < n; i++)
    {
        x = sign * 1.0 / (3 * i+1);
        sign = -sign;
        sum += x;
    }
    printf("%lf", sum);
    return 0;
}