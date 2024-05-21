#include<stdio.h>
int main()
{
    int i = 0, n;
    scanf_s("%d", &n);
    while (n) {
        printf("%d ",n);
        n /= 2;

    }
    
        

    return 0;
}