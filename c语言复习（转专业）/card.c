#include<stdio.h>
int main(void) {
    int a[10] = { 0 };
    int i;
    for (i = 0;; i++)
    {
        int temp = i;
        while (temp)
        {
            a[temp % 10]++;
            temp /= 10;//·ÖÀë
        }
        for (int j = 0; j <= 9; j++)
        {
            if (a[j] > 2021)
                break;
        }
    }
    int s = i - 1;
    printf("%d", s);

    return 0;
}