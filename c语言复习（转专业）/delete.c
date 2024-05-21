#include<stdio.h>
#include<stdlib.h>
int removeDuplicates(int* nums, int numsSize) {
    int i, j,temp, l;
    for (i = 0; i < numsSize; i++) 
    {
        for (j =i+1; j < numsSize; j++) 
        {
            if (nums[i] == nums[j]) 
            {
                temp = j;
                for (l = temp; l < numsSize; l++) 
                {
                    nums[temp] = nums[temp + 1];
                    temp++;
                }
                nums[numsSize - 1] = 0;
                numsSize--;
            }
        }
    }
    return numsSize;
}
int main()
{
    int k;
    int* a;
    int n;
    printf("please input the number of elements\n");
    scanf_s("%d", &n);
    a = (int*)calloc(n, sizeof(int));
    printf("please input every element\n");
    for (int i = 0; i < n; i++) {
        scanf_s("%d", &a[i]);
    }
    k = removeDuplicates(a, n);
    printf("there are %d element(s)\nand they are:", k);
    for (int i = 0; i < k; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}